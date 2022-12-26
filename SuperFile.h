#pragma once

#include <stdio.h>
#include "Supermarket.h"


int		saveSuperMarketToFile(const SuperMarket* pMarket, const char* fileName,
	const char* customersFileName, int compress);

int		saveCustomerToTextFile(const SuperMarket* pMarket, const char* customersFileName);

int		loadSuperMarketFromFile(SuperMarket* pMarket, const char* fileName, const char* customersFileName, int compress);

int		loadCustomerFromTextFile(SuperMarket* pMarket, const char* customersFileName);

int		loadProductFromTextFile(SuperMarket* pMarket, const char* fileName);

int		readProdNumSortOptNameFromCompressFile(SuperMarket* pMarket, FILE* fp);

int		saveSuperMarketToFileCompress(const SuperMarket* pMarket, FILE* fp);