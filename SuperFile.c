#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Address.h"
#include "General.h"
#include "fileHelper.h"
#include "SuperFile.h"
#include "myMacros.h"


int	saveSuperMarketToFile(const SuperMarket* pMarket, const char* fileName,
	const char* customersFileName, int compress)
{
	FILE* fp;
	fp = fopen(fileName, "wb");
	if (!fp) {
		printf("Error open supermarket file to write\n");
		return 0;
	}

	if (compress)
	{
		if(!saveSuperMarketToFileCompress(pMarket, fp))
		{
			fclose(fp);
			return 0;
		}
	}
	else {
		if (!writeStringToFile(pMarket->name, fp, "Error write supermarket name\n"))
		{
			fclose(fp);
			return 0;
		}

		if (!saveAddressToFile(&pMarket->location, fp))
		{
			fclose(fp);
			return 0;
		}

		if (!writeIntToFile((int)pMarket->sortOpt, fp, "Error write sort option\n"))
		{
			fclose(fp);
			return 0;
		}

		if (!writeIntToFile(pMarket->productCount, fp, "Error write product count\n"))
		{
			fclose(fp);
			return 0;
		}
	}

	for (int i = 0; i < pMarket->productCount; i++)
	{
		if (compress)
		{
			if(!saveProductToFileCompress(pMarket->productArr[i], fp))
			{
				fclose(fp);
				return 0;
			}
		}

		else if (!saveProductToFile(pMarket->productArr[i], fp))
		{
			fclose(fp);
			return 0;
		}
	}

	fclose(fp);

	saveCustomerToTextFile(pMarket, customersFileName);

	return 1;
}


int	loadSuperMarketFromFile(SuperMarket* pMarket, const char* fileName, const char* customersFileName, int compress)
{
	FILE* fp;
	fp = fopen(fileName, "rb");
	if (!fp)
	{
		printf("Error open company file\n");
		return 0;
	}

	pMarket->productArr = NULL;

	if (compress)
	{
		if (!readProdNumSortOptNameFromCompressFile(pMarket, fp))
		{
			fclose(fp);
			printf("Error in reading profuct amount, sort option and name/n");
			return 0;
		}

		if (!readAddressFromCompressFile(&pMarket->location, fp))
		{
			fclose(fp);
			return 0;
		}
	}

	else {
		pMarket->name = readStringFromFile(fp, "Error reading supermarket name\n");
		if (!pMarket->name)
		{
			fclose(fp);
			return 0;
		}

		if (!loadAddressFromFile(&pMarket->location, fp))
		{
			free(pMarket->name);
			fclose(fp);
			return 0;
		}

		int opt;
		if (!readIntFromFile(&opt, fp, "Error reading sort option\n"))
		{
			free(pMarket->name);
			fclose(fp);
			return 0;
		}

		pMarket->sortOpt = (eSortOption)opt;

		if (!readIntFromFile(&pMarket->productCount, fp, "Error reading product count\n"))
		{
			free(pMarket->name);
			fclose(fp);
			return 0;
		}
	}

	if (pMarket->productCount > 0)
	{
		pMarket->productArr = (Product**)malloc(pMarket->productCount * sizeof(Product*));
		CHECK_NULL_MSG_FREE_CLOSE_FILE_RETURN_0(pMarket->productArr, pMarket->name, fp);
		/*if (!pMarket->productArr)
		{
			printf("Allocation error\n");
			free(pMarket->name);
			fclose(fp);
			return 0;
		}*/
	}

	for (int i = 0; i < pMarket->productCount; i++)
	{
		pMarket->productArr[i] = (Product*)calloc(1, sizeof(Product));
		if (!pMarket->productArr[i])
		{
			printf("Allocation error\n");
			for (int j = 0; j < i; j++) //free all that was allocated
				free(pMarket->productArr[j]);
			free(pMarket->productArr);
			free(pMarket->name);
			fclose(fp);
			return 0;
		}

		if (compress)
		{
			if (!readProductFromCompressFile(pMarket->productArr[i], fp))
			{
				for (int i = 0; i < pMarket->productCount; i++) //free all that was allocated
					free(pMarket->productArr[i]);
				free(pMarket->productArr);
				free(pMarket->name);
				fclose(fp);
				return 0;
			}
		}
		else if (!loadProductFromFile(pMarket->productArr[i], fp))
		{
			for (int i = 0; i < pMarket->productCount; i++) //free all that was allocated
				free(pMarket->productArr[i]);
			free(pMarket->productArr);
			free(pMarket->name);
			fclose(fp);
			return 0;
		}
	}

	fclose(fp);

	return	loadCustomerFromTextFile(pMarket, customersFileName);
}


int	saveCustomerToTextFile(const SuperMarket* pMarket, const char* customersFileName)
{
	FILE* fp;

	fp = fopen(customersFileName, "w");
	if (!fp) {
		printf("Error open customers file to write\n");
		return 0;
	}

	fprintf(fp, "%d\n", pMarket->customerCount);
	for (int i = 0; i < pMarket->customerCount; i++)
	{
		fprintf(fp, "%s\n", pMarket->customerArr[i].name);
	}
	fclose(fp);
	return 1;
}


int		loadCustomerFromTextFile(SuperMarket* pMarket, const char* customersFileName)
{
	FILE* fp;

	fp = fopen(customersFileName, "r");
	if (!fp) {
		printf("Error open customers file to write\n");
		return 0;
	}
	pMarket->customerArr = NULL;
	fscanf(fp, "%d\n", &pMarket->customerCount);
	if (pMarket->customerCount > 0)
	{
		pMarket->customerArr = (Customer*)malloc(pMarket->customerCount * sizeof(Customer));
		CHECK_NULL_CLOSE_FILE_RETURN_0(pMarket->customerArr, fp);
		/*if (!pMarket->customerArr)
		{
			fclose(fp);
			return 0;
		}*/
		for (int i = 0; i < pMarket->customerCount; i++)
		{
			pMarket->customerArr[i].name = readDynStringFromTextFile(fp);
			if (!pMarket->customerArr[i].name)
			{
				for (int j = 0; j < i; j++)
					free(pMarket->customerArr[j].name);
				free(pMarket->customerArr);
				fclose(fp);
				return 0;
			}
		}
	}

	fclose(fp);
	return 1;
}


int		loadProductFromTextFile(SuperMarket* pMarket, const char* fileName)
{
	FILE* fp;

	fp = fopen(fileName, "r");
	int count;
	fscanf(fp, "%d\n", &count);

	pMarket->productArr = (Product**)realloc(pMarket->productArr, (pMarket->productCount + count) * sizeof(Product*));

	Product p;
	for (int i = 0; i < count; i++)
	{
		myGets(p.name, MAX_STR_LEN, fp);
		myGets(p.barcode, MAX_STR_LEN, fp);
		fscanf(fp, "%d %f %d\n", &p.type, &p.price, &p.count);
		pMarket->productArr[pMarket->productCount] = (Product*)calloc(1, sizeof(Product));
		*pMarket->productArr[pMarket->productCount] = p;
		pMarket->productCount++;
	}

	fclose(fp);
	return 1;
}


int		readProdNumSortOptNameFromCompressFile(SuperMarket* pMarket, FILE* fp)
{
	BYTE data[2];

	if (fread(&data, sizeof(BYTE), 2, fp) != 2)
		return 0;

	pMarket->productCount = (data[1] >> 7) | (data[0] << 1);
	pMarket->sortOpt = (data[1] >> 4) & 0x07;
	int superMarketNameLen = data[1] & 0x0f;

	pMarket->name = (char*)calloc(superMarketNameLen + 1, sizeof(char));
	CHECK_RETRUN_0(pMarket->name);
	/*if (!pMarket->name)
		return 0;*/

	if (fread(pMarket->name, sizeof(char), superMarketNameLen, fp) != superMarketNameLen)
	{
		free(pMarket->name);
		return 0;
	}

	return 1;
}


int		saveSuperMarketToFileCompress(const SuperMarket* pMarket, FILE* fp)
{
	BYTE data[2];
	int superMarketNameLen = (int)strlen(pMarket->name);

	data[0] = pMarket->productCount >> 1;
	data[1] = (pMarket->productCount << 7) | (pMarket->sortOpt << 4) | (superMarketNameLen);

	if (fwrite(&data, sizeof(BYTE), 2, fp) != 2)
		return 0;

	if (fwrite(pMarket->name, sizeof(char), superMarketNameLen, fp) != superMarketNameLen)
		return 0;

	BYTE addressData[2];
	int cityNameLen = (int)strlen(pMarket->location.city);
	int streetNameLen = (int)strlen(pMarket->location.street);

	addressData[0] = (pMarket->location.num << 1) | (cityNameLen >> 3);
	addressData[1] = (cityNameLen << 5) | (streetNameLen);

	if (fwrite(&addressData, sizeof(BYTE), 2, fp) != 2)
		return 0;

	if (fwrite(pMarket->location.city, sizeof(char), cityNameLen, fp) != cityNameLen)
		return 0;

	if (fwrite(pMarket->location.street, sizeof(char), streetNameLen, fp) != streetNameLen)
		return 0;

	return 1;
}