/*Dynamic Inventory Management (1D Dynamic Array)
Background: You are building an inventory management system for a small store. The store sells a
variable number of products, and the inventory needs to be updated dynamically.
Task:
1. Ask the user to input the number of products in the store.
2. Dynamically allocate a 1D array to store the quantity of each product.
3. Populate the array with initial quantities (user input).
4. Implement the following features:
	• Add a new product to the inventory (resize the array).
	• Remove a product from the inventory (resize the array).
	• Update the quantity of a specific product.
	• Display the current inventory.
5. Deallocate the memory after use.
Real-world connection: This scenario reflects real-world inventory systems where products are
added or removed dynamically, and quantities need to be updated.*/

#include<iostream>
#include<iomanip>
using namespace std;
void display(int[], int);
void display(int p[], int size)
{
	// display
	
 	for (int i = 0; i <  size; i++)
 		cout<<"\nProduct "<<i<<" >> "<<p[i];	
}
 int main()
 {  
//1. Ask the user to input the number of products in the store.
 	int no_p, new_size;
 	cout<<"\nEnter number of products available in the store: ";
 	cin>>no_p;
 	
//2. Dynamically allocate a 1D array to store the quantity of each product.
 	
 	int *products = new int[no_p];
 	

//3. Populate the array with initial quantities (user input).
 	cout<<"\nInput the Quantity of Products:";
 	for (int i = 0; i <  no_p; i++)
 	{
 		cout<<"\nProduct "<<i<<"  ";
 		cin>>products[i];
	 }
	
	
	display(products, no_p);	 

//4. Implement the following features:
//	• Add a new product to the inventory (resize the array).

	char a;
	int addProducts;
	cout<<"\nWant to add more product Quantity[y,n] ";
	cin>>a;
	if (a == 'y')
	{		
		// input size of new array
		cout<<"\nInput the number of products you want to add: ";
		cin>>addProducts;
		new_size = addProducts + no_p;
		if ( addProducts > 0)
		{		
		// creating a new array
		int* new_products = new int[new_size];
		
		// copying existing products to the new array
		for(int i = 0; i < no_p; i ++)
			new_products[i]= products[i] ;
		
		// taking input for the newly created space in array
		for(int i = no_p; i < new_size; i++)
		{
			cout<<"\n Add new quantity at "<<i<<" ";
			cin>>new_products[i];
		}
		// de allocate products
		delete[] products;
		
		// renaming 
		products = new_products;
		no_p = new_size;
		
		// displaying again
		display(products, no_p);
		} 
		else cout<<"\nNumber of products to be added must be greater than zero";// end of size checking 
	}  // end of yes no if condition 
	
	

//• Remove a product from the inventory (resize the array).

	char remove;
	int rem;
	cout<<"\nDo you want to remove a products quantity [y,n] ";
	cin>>remove;
	if (remove == 'y')
	{
		cout<<"\nEnter index of value to remove ";
		cin>>rem;
		if(rem >-1 && rem < no_p) // valid index checking 
		{
		// removing value
		
		int newSize = no_p -1;
		int* new_products = new int[newSize];
		
		// copying existing products to the new array
		int newIndex = 0;
		for(int i = 0; i < no_p ; i ++)
		{
			if (i != rem)
			{
				new_products[newIndex] = products[i] ;
				newIndex++;
			}
							
		}
		cout << "Product removed successfully." << endl;
		delete[] products;
    	products = new_products;
    	no_p = newSize;
		
		}// end of rem 	
		else
			cout<<"\nIndex not Found";
			   	    		
	} // end of yes no remove
	// display again
	cout<<"\nData at present";
	display(products, no_p);
	
	//////////////////////update///////////////////
	
	char update;
	cout<<"\nDo you want to update the products data? [y/n] ";
	cin>>update;
	if (update == 'y')
	{	
	int index;	 
	cout<<"\nUpdate data";
	cout<<"\nEnter the index of quantity you want to update:";
	cin>>index;
	if(index >-1 && index < no_p) 
	{
		for (int i = 0; i < no_p; i++)
		{
		if (index == i)
			{
			cout<<"\nEnter Updated quantity: ";
			cin>>products[i];			
			}
		}
	}
	else
	cout<<"\nNo product exists with this index ";
	} // end yes  no 
	

	cout<<"\nDisplaying again";
	display(products, no_p); 
	
//5. Deallocate the memory after use.
	delete[] products;
 	return 0; 	
 }