#pragma once

#define EXIT -1

#define SUPER_FILE_NAME "SuperMarket.bin"

#define CUSTOMER_FILE_NAME "Customers.txt"

#define SUPER_FILE_NAME_COMPRESS "super_compress.bin"

#define COMPRESS 


typedef enum
{
	eShowSuperMarket, eAddProduct, eAddCustomer, eCustomerDoShopping,
	ePrintProductByType,eSortProduct,eSearchProduct, eNofOptions
} eMenuOptions;

const char* menuStrings[eNofOptions];

int menu();