// System Libraries

#include "iostream"
#include "iomanip"
#include "cstdio"
#include "stdio.h"
#include "fstream"
#include "string"
#include "conio.h"
#include "windows.h"

// Header Files

#include "user.h"
#include "products.h"

using namespace std;

int main() {

	User UserObject;
	Product ProductObject;

	char y;
	
	do {
		
		int Choice;
			
		system ("cls");	
		system ("color 7C");	
		cout << "\t ----------------------------------------"<<endl;
		cout << "\t ONLINE SHOPPING STORE MANAGEMENT SYSTEM"<<endl;
		cout << "\t ----------------------------------------"<<endl;
		cout << "\t 1 \t User Login"<<endl;		 
		cout << "\t 2 \t Admin Panel"<<endl;		 
		cout << "\t 3 \t Exit"<<endl;	
		cout << "\t ----------------------------------------"<<endl;	 

		cout << endl << "Please Enter Choice : ";
		cin >> Choice;
		
		if (Choice == 1) 
		{
			int a = UserObject.AuthenticUser();
			
			if (a==1)
			{
				char u;
				do
				{
					system("cls");
					system("color 7C");
					cout << "\t ----------------------------------------"<<endl;
					cout << "\t ONLINE SHOPPING STORE MANAGEMENT SYSTEM"<<endl;
					cout << "\t ----------------------------------------"<<endl;
					cout << "\t 1 \t Buy Product"<<endl;
					cout << "\t 2 \t Search Product"<<endl;
					cout << "\t 3 \t Print Products List"<<endl;
					
					cout << endl << "Please Enter Choice : ";
					int b;
					cin >> b;
					
					if(b==1)
					{
						ProductObject.PurchaseProduct();				
					}
					else if(b==2)
					{
						string SearchProduct;
						cout << endl << "Please Enter Product Name : ";
						cin >> SearchProduct;
						int x = ProductObject.SearchProduct(SearchProduct);
						if(x==1)
						{
							cout << endl << "\t\t Yes, ( "<< SearchProduct << " ) Exists in the Store"<<endl;
						}
						else
						{
							cout << endl << "\t\t No, ( "<< SearchProduct << " ) Does Not Exist in the Store"<<endl;
						}
					}
					else if(b==3)
					{
						
						ProductObject.PrintProduct();
						
					}
					else
					{
						cout <<endl<<endl<<endl;
						cout << "\t ----------------------------------------"<<endl;
						cout << "\t\t  You Have Entered Wrong Choice   "<<endl;
						cout << "\t\t  Select Your Choice From (1,2,3) "<<endl;
						cout << "\t ----------------------------------------"<<endl;
					}
					
					cout << endl << "Do you want to Stay at User panel (Y OR N): ";
					cin >> u;
				}
				while(u=='y'||y=='Y');				
			}
			else
			{
				cout <<endl;
				cout << "\t Username OR Password Invalid !"<<endl<<endl;
			}
		}
		else if(Choice == 2)
		{	
			char q;
			int a = UserObject.AuthenticUser1();
			if (a==1){
				do{
					system ("cls");
					system ( "color 7C" );
					
					cout << "\t\t --------------------------------------------------------"<<endl;
					cout << "\t\t\t ONLINE SHOPPING STORE MANAGEMENT SYSTEM"<<endl;
					cout << "\t\t --------------------------------------------------------"<<endl<<endl;
		
					cout << "\t\t U: Update User Data     **	u: Update Product"<<endl<<endl;
					cout << "\t\t D: Delete User          **	d: Delete Product"<<endl<<endl;
					cout << "\t\t A: Add User             **	a: Add Product"<<endl<<endl;
					cout << "\t\t S: Search User          **	s: Search Product"<<endl<<endl;
					cout << "\t\t P: Print Data           **	p: Print Product Data"<<endl<<endl<<endl;
								
					char a;
					cout << "\t\tEnter Your Choice :\t";	cin >> a;
					 
					/************************************************
					    User Functions Calling Starts From Here.
					*************************************************/
					
					if(a == 'U'){
						
						UserObject.UpdateData();
					}
					else if(a == 'D'){
						
						UserObject.DeleteData();
					}
					else if(a == 'A'){
		
						UserObject.InsertData();
					}
					else if(a == 'S'){
						
						double Card_No=0;
						cout << "\n\t\tPlease Enter Card number :\t";
						cin >> Card_No;
						int x = UserObject.SearchData(Card_No);
						
						if(x==1){
							cout << "\n\t\tYes, User Having Card Number (" << Card_No << ") Exists..."<<endl<<endl;
						}
						else{
							cout << "\n\t\tSorry, User Having Card Number (" << Card_No << ") Does Not Exists..."<<endl<<endl;
						}
					}
					else if(a == 'P'){
						
						UserObject.PrintData();
					}
					
													/************************************************
													    Product Functions Calling 
													*************************************************/
		
					else if(a == 'u'){
						
						ProductObject.UpdateProduct();
					}
					else if(a == 'd'){
						
						ProductObject.DeleteProduct();
					}
					else if(a == 'a'){
						
						ProductObject.InsertProduct();
					}
					else if(a == 's'){
						
						string SearchProduct;
						cout << "\n\t\tPlease Enter Product Name :\t";
						cin >> SearchProduct;
						int x = ProductObject.SearchProduct(SearchProduct);
						if(x==1){
							cout << "\n\tYes, ("<< SearchProduct << ") Exists in the Store..."<<endl<<endl;
						}
						else{
							cout << "\n\tNo, ("<< SearchProduct << ") Does Not Exist in the Store..."<<endl<<endl;
						}
					}				// Search Product Function Ends here.
					else if(a == 'p'){
						
						ProductObject.PrintProduct();
					}
				
					else {
						cout <<endl<<endl<<endl<<endl;
						cout << "\t ----------------------------------------"<<endl;
						cout << "\t\t  You Have Entered Wrong Choice   "<<endl<<endl;
						cout << "\t\t      Select Your Choice From     "<<endl<<endl;
						cout << "\t\t      (U, D, A, S, u, d, a, s)    "<<endl<<endl;
						cout << "\t ----------------------------------------"<<endl;
					}								// else condition ends here.
			
					cout << "Do you want to Stay at Admin Panel (Y OR N) : ";
					cin >> q;
				}
				while (q=='y'||y=='Y');											// else if(Choice==2) ends here
			}
			else{
				cout <<endl;
				cout << "\t Username OR Password Invalid !"<<endl<<endl;
			}
			

}

		else if(Choice == 3){				// else if(Choice==3) starts from here


			break;
		}	
										// else if(Choice==3) ends here
		else {								// else condition starts from here
			cout <<endl<<endl<<endl<<endl;
			cout << "\t ----------------------------------------"<<endl;
			cout << "\t\t  You Have Entered Wrong Choice	"<<endl<<endl;
			cout << "\t\t   Enter a Choice b/w ( 1-4 ).		"<<endl<<endl;
			cout << "\t ----------------------------------------"<<endl;
		}								// else condition ends here.
		
		cout <<endl<< "Press N to Exit OR Press Y To Go Back : ";
		cin >> y;
	}	
								// do while from start ends here.
	while (y=='y' || y == 'Y');

		

			
}										//  Main ends here.

