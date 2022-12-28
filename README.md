# Supermarket_Management_System

## This project made during my "introduction to operating systems" course.

### Subject that this project deal with:
    * Data types and Conversion.
    * Variables and constants.
    * Functions. 
    * Random Number.
    * Standard Libraries.
    * Pointers and pointers arithmetics.
    * Strings.
    * Structures.
    * Union & enum.
    * Dynamic allocations.
    * Pointer to functions.
    * Binary Files + text file
    * Bitwise operators.
    * Bit fields in structures.
    * Linked lists.
    * Macros.
    * Parameters to main.
    * Variadic functions.
    
## Project explenation:

* Functions that must be implemented in each struct:
    * Receiving values from the user function.
    * Printing function.
    * Allocation free function if needed.
    * Functions that will enable the correct implementation of the system as 
      will be explained later while thinking correctly about a proper software 
      structure as learned in the object-oriented programming course.
      
## In the first part of the project we were asked to do the following:
   * Create **Address** struct with the fieldes:
    	- House number.
    	- Dynamic string for street, can be made with several words and in unknown size
    	- Dynamic string for city, can be made with several words and in unknown size.
      
   * Create **Product** struct with the fieldes:
    	- Name, string with constant size of 20 chars or less.
    	- Barcode, string with constant size of exactly 7 chars, must include only capital latters and digits, with
		  at least 3 digits and no more than 5.
    	- Type, with the options: Shelf, Frozen, Fridge, FruitVegtable.
    	- Price, float.
    	- Units in Stock. 
    
   * Create **Customer** struct with the fieldes:
    	- Customer name, a dynamic string with unknown size.
    
   * Create **ShoppingItem** struct with the fieldes:
    	- Name, a dynamic string.
    	- price, float.
    	- The amount in the shopping cart of this product.
    
   * Create **ShoppingCart** struct with the fieldes:
    	- An array of unknown size. In each cell in the array there is a pointer to **ShoppingItem**.
    	- The amount of different products in the shopping cart.
    	- Functions that receive arguments as i wish that:
    		1. Calculation of the total amount to be paid for the shopping cart.
    		2. Adding a product to the shopping cart.  
    
   * Create **SuperMarket** struct with the fieldes:
    	- Store name, dynamic string with unknown size.
    	- Store address, Later it will be explained how the address is received from the user.
    	- Array of customers, an array of unknown size. Each cell in the array has a customer.
    	- The number of customers in the array.
    	- Array of products of unknown size. In each cell there is a pointer to the product.
    	- The number of products in the array.
    	- Functions that receive arguments as i wish that:
    		1. initial the grocery store. It is assumed that in the begining there are no products and no customers in the store.
    		2. Print the store details.
    		3. Adding product to the store, You can add a new product or an existing product. If you add a product that already
			   exists, ask the user only for the quantity that is available Add to stock and update the quantity.
    		4. Adding a customer, it can be assumed that the user will not enter the name of an already registered customer.
    		5. Buying in a supermarket, the process will be explained later.
    		6. Printing all products in a supermarket of a certain type according to the user's choice.
    		
   * Receiving the grocery store address:
    	- The address data must be requested from the user as a long string. You can temporarily assume in the function which 
		  perceives that the entire string is no longer than 254 characters. The fields will be in the following 
		  order: street, house number, city. Between each field of the structure will appear in the string the character '!'.
    	- After the reception, the city and street data must be changed as follows:
    		1. If a data consists of several words, add the character # between the words.
    		2. In each input, the first letter in each word will be a capital letter and the rest of the letters will be
			   lowercase.
			   If there is only one word in the name it will end with a capital letter.
    		3. There must not be a space at the beginning and end of the input.
    	
	![image](https://user-images.githubusercontent.com/100000990/209677673-d11a4dc2-3ab2-4ecf-8f37-fe6ee70c5f76.png)

   * Buying process:
    	- Only one customer at a time makes a purchase at the food store.
    	- The user will enter the name of the customer who starts making a purchase. Make sure he is a registered customer.
    	- For convenience we will print all the products available in the supermarket.
    	- As long as the customer wishes to continue buying, we will allow him to choose a product by inserting a 
		  valid barcode of an existing product.
    	- After the customer has chosen a product, we will allow him to put a number of such products in the cart, but no
		  more than what is available in the store.
    	- The customer can buy the same product in different rounds of the purchase and then we will only update the quantity
		  existing in the cart of this product.
    	- After putting the product in the cart according to the quantity the customer chose, the remaining quantity must be 
		  updated in store stock for the same product.
    	- After the purchase process is finished, we will print the contents of the cart as well as the amount the customer
		  has to pay.
    	- After payment (printing to the screen) - all allocations created during the purchase must be released.
    
   * The main program:
    	- After the initial boot, a menu should be displayed that allows the following actions:
    		1. Printing the grocery store data.
    		2. Adding a product.
    		3. Adding a customer.
    		4. Shopping in the store.
    		5. Printing all existing products in the store of a certain type.
    		6. Exit the program. Be sure to free any dynamically allocated memory.

   * In the main function there will be no logic and variable definition except for the food store, only reading to main
	  functions and printing an error output if it occurs.
    
   * General demands:
    	- The length of all strings is unknown unless a specific length is specified. Temporarily for the purpose of receiving
		  a string from the user within a specific function, a string of 255 characters can be defined.
    	- Input correctness checks must be observed.
    	- Const pointers must be used when the function does not change values in the pointer.
    	- You must make sure that the product barcode is unique at the time of receipt.

## In the second part of the project we were asked to do the following:
   * Linked lists:
    
   * Supermarket:
    
   * Binary files:
    
   * Text files:
    
   * Pointers to functions:
   
   * Changes in main:
    













  
