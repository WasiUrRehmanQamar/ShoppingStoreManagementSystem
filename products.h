#include<iostream>
#include<iomanip>
#include<cstdio>
#include<stdio.h>
#include<fstream>		//for file handling purpose, ifstream & ofstream functions.
#include<string>
#include<conio.h>
#include<Windows.h>		//header (for sleep function here)

using namespace std;

class P_Node{
	
	private:		
		int data ;
		Node* Next ;
	
	public:

		int GetData();
		Node* GetNext();
		void SetData(int);
		void SetNext(Node*);
};



int P_Node::GetData(){
	return data;
}

Node* P_Node::GetNext(){
	return Next;
}

void P_Node::SetData(int data ){
	this->data = data ;
}

void P_Node::SetNext(Node* next){
	this->Next = next;
}

class Product{
	private:
		Node* CurrentLocation;
	public:
		     Product();
		     void InsertProduct();
             void DeleteProduct();
             void UpdateProduct();
             int SearchProduct(string search);
             void PrintProduct();
             void PurchaseProduct();
};

Product::Product(){
this->CurrentLocation = NULL;
}

void Product::InsertProduct(){
	int data;
	char y;
	do{
		string ProductName = "";
		double ProductPrice = 0, ProductQuantity = 0;
		system("cls");
		cout <<endl<<endl;
		cout<<"\t\t----------------------------"<<endl<<endl;
		cout<<"\t\t  Products Data Entry  "<<endl<<endl;
		cout<<"\t\t----------------------------"<<endl<<endl<<endl<<endl;

		cout<<"\t\tProduct_Name :\t";	cout <<endl;
		cin >> ProductName;
		cout<<"\t\t  Price      :\t";	cout <<endl;
		cin >> ProductPrice;
		cout<<"\t\tQuantity     :\t";	cout <<endl;
		cin >> ProductQuantity;
		
		Product obj;
		int u = obj.SearchProduct(ProductName);
		if(u==0){
			//Creating new node and setting Data and Next fields
			Node* newNode= new Node();
			newNode->SetData(data);
			newNode->SetNext(NULL);
			
			Node* temp = CurrentLocation;
			
			ofstream file;
			file.open("Products.txt",ios::app);
			if(!file){
				cout<<"\n\n\tError in opening File.";
			}
			file << ProductName << "\t"  << ProductPrice << "\t" << ProductQuantity <<endl;
			file.close();
		
			
			if (temp != NULL){
				
				while (temp->GetNext() != NULL){
					temp = temp->GetNext();
								
				}
				temp->SetNext(newNode);
						
			}
			else{
				CurrentLocation = newNode;
			}	
			cout << endl<<endl;
			cout<<"\t\t\t---------------------------------- "<<endl;
			cout<<"\t\t\t  Data Entered Successfully.		"<<endl;
			cout<<"\t\t\t----------------------------------	"<<endl<<endl;
		}
		else {
			cout <<"\n\t\t"<< ProductName << " Already exists ..."<<endl<<endl;
		}
		cout << "\n\n\tDo you want to enter more Data :\t";
		cin >> y;
	}
	while (y=='y');
}

void Product::DeleteProduct(){

	string ProductName = "";
	double ProductPrice = 0, ProductQuantity = 0;
	int j=0, k=0, data;

	system("cls"); system ("color 7C");
	cout <<endl<<endl<<endl;
	cout << "\t ----------------------------------------"<<endl;
    cout<<"\t\t  Delete Product Data  "<<endl<<endl;
	cout << "\t ----------------------------------------"<<endl;
	
	string P_Name = "";
	cout<<"\t\t  Product_Name :\t";
	cin >> P_Name;
	
	fstream in("Products.txt");
    if( !in ){
        cout << "\n\n\t\tInput file failed to open ..."<<endl<<endl;
    }	    

	else{
	    ofstream out("temp.txt");
		while (in >> ProductName >> ProductPrice >> ProductQuantity){
			k++;
    		if( P_Name != ProductName ){
				out << ProductName << "\t"  << ProductPrice << "\t" << ProductQuantity <<endl;
    		    j++;
    		}
		}
		if(j==k-1){
		cout <<endl<<endl<<endl;
		cout << "\t ----------------------------------------"<<endl;
		cout <<"\t\t  Data_Has_Been_Deleted_Successfully.  "<<endl;
		cout << "\t ----------------------------------------"<<endl;
		}
		else{
		cout <<endl<<endl;
		cout << "\t ----------------------------------------"<<endl;
		cout<<"\t\t  " << P_Name << " Does Not Match with any of Product(s)."<<endl<<endl;
		cout << "\t ----------------------------------------"<<endl;
		}
	    in.close();
		out.close();
		remove("Products.txt");
		rename("temp.txt","Products.txt");
	}
}

void Product::UpdateProduct(){

	string ProductName = "";
	double ProductPrice = 0, ProductQuantity = 0;
	string P_Name = "";
	double NewPrice = 0, NewQuantity = 0; 
	int j=0, k=0;
	system("cls");
	cout <<endl<<endl;
	cout << "\t ----------------------------------------"<<endl;
    cout<<"\t\t\t  Update_Product_Data_Menue  "<<endl<<endl;
	cout << "\t ----------------------------------------"<<endl;
	
	cout << "\t\t  Product_Name :\t";
	cin >> P_Name;
	
	fstream in("Products.txt");
    if( !in ){
        cout << "\n\n\t\tInput file failed to open ..."<<endl<<endl;
	}
	else{
	    ofstream out("temp.txt");
		while(in >> ProductName >> ProductPrice >> ProductQuantity){
			k++;
    		if( P_Name != ProductName ){
				out << ProductName << "\t"  << ProductPrice << "\t" << ProductQuantity <<endl;
    		    j++;
    		}
    		else {
    			cout <<"\n\n\t\t"<< P_Name << " Exists in the Product List..."<<endl<<endl;
    			cout << "\n\tEnter New Name     :\t";
    			cin >> P_Name;
    			cout << "\n\tPrevious Price     : \t" << ProductPrice;
    			cout << "\n\tEnter New Price    :\t";
    			cin >> NewPrice;
    			cout << "\n\tPrevious Quantity  : \t" << ProductQuantity;
    			cout << "\n\tEnter New Quantity :\t";
    			cin >> NewQuantity;
    			
    			out << P_Name << "\t" << NewPrice << "\t" << NewQuantity <<endl;
    		}
		}
		if(j==k-1){
			cout <<endl<<endl;
			cout << "\t ----------------------------------------"<<endl;
			cout <<"\t\t  Data_Has_Been_Updated_Successfully.  "<<endl;
			cout << "\t ----------------------------------------"<<endl;

		}
		else{
		cout <<endl<<endl;
		cout << "\t ----------------------------------------"<<endl;
		cout<<"\t\t  " << P_Name << " Does Not Match with any of Product(s)."<<endl;
		cout << "\t ----------------------------------------"<<endl;
		}
	    in.close();
		out.close();
		remove("Products.txt");
		rename("temp.txt","Products.txt");
	}
}


int Product::SearchProduct(string search){
	string ProductName = "";
	double ProductPrice = 0, ProductQuantity = 0;
	int j, k;
	int found=0, data, price;
	ifstream input("Products.txt");
	while (input >> ProductName >> ProductPrice >> ProductQuantity){
		k++;
		if(search == ProductName){

			found++;	
			j++;
		}
	}
	input.close();

	if(found==0){	return 0;	}
	else 		{	return 1;	}

}

void Product::PrintProduct(){

	string ProductName = "";
	double ProductPrice = 0, ProductQuantity = 0;
	int k;

	ifstream input("Products.txt");
	if (!input){
		cout << "\n\n\t\tFile Failed to open ..."<<endl<<endl;
	}

	else {
		
		cout <<endl<<endl;
		cout << "\t-----------\t-------------\t---------------"<<endl<<endl;
		cout << "\tProduct Name\tProduct Price\tProduct Quantity"<<endl<<endl;
		cout << "\t-----------\t-------------\t---------------"<<endl<<endl;
		while (input >> ProductName >> ProductPrice >> ProductQuantity){
			
			cout << "\t"<< ProductName << "\t\t"  << ProductPrice << "\t\t" << ProductQuantity <<endl;
			k++;
		}
		cout << "\n\t-------------------------------------------------"<<endl<<endl;
	}
	input.close();
}

void UpdateAfterPerchase(string P_Name, double Quantity){

	string ProductName = "";
	double ProductPrice = 0, ProductQuantity = 0;

	int j=0, k=0;
	
	fstream in("Products.txt");
    if( !in ){
        cout << "\n\n\t\tInput file failed to open ..."<<endl<<endl;
	}
	else{
	    ofstream out("temp.txt");
		while(in >> ProductName >> ProductPrice >> ProductQuantity){
			k++;
    		if( P_Name != ProductName ){
				out << ProductName << "\t"  << ProductPrice << "\t" << ProductQuantity <<endl;
    		    j++;
    		}
    		else {
    			    			
    			out << P_Name << "\t" << ProductPrice << "\t" << ProductQuantity - Quantity <<endl;
    		//	return 1;
    		}
		}
	    in.close();
		out.close();
		remove("Products.txt");
		rename("temp.txt","Products.txt");
	}
}

void Product::PurchaseProduct()
{
	char y;
	string P_Name = "";
	double ItemPrice = 0, P_Quantity = 0;

	do
	{
		system("color 7C");
		string ProductName = "";
		double ProductPrice = 0, ProductQuantity = 0;
		int j=0, k=0, found=0, data=0;

		cout <<endl<<endl;
		cout << "\t ------------------------------"<<endl<<endl;
		cout << "\t\t BUY PRODUCT"<<endl<<endl;
		cout << "\t ------------------------------"<<endl;			

		cout << endl << "Product Name : ";
		cin >> P_Name;
		cout << "Quantity : ";
		cin >> P_Quantity;
		
		ifstream input("Products.txt");
		
		while (input >> ProductName >> ProductPrice >> ProductQuantity)
		{
			k++;
			if(P_Name == ProductName && P_Quantity < ProductQuantity)
			{
				ItemPrice = ProductPrice;
				found++;	
				j++;
			}
		}
		
		input.close();
	
		if(found==0)
		{
			cout << endl<<endl;
			cout << "\t\t-------------------------------------------------"<<endl;
			cout << "\t\t       Product ( " << P_Name << " ) Does not Exist"<<endl;
			cout << "\t\t-------------------------------------------------"<<endl<<endl;
		}
		else
		{
			cout << "\n\t\tItem Purchased ..."<<endl<<endl;
			
			UpdateAfterPerchase(P_Name, P_Quantity);
			
			ofstream out;
			out.open("purchase.txt", ios::app);
			if(!out){"\n\n\tError in opening File.";}
			else 
			{
				
				out << P_Name << "\t" << ItemPrice << "\t" << P_Quantity <<endl;
			}
			out.close();
		}
		
		cout << "Do you want to Purchase more Items (Y OR N) : ";
		cin >> y;
	}
	while (y=='y'||y=='Y');
	
	system ("color 7C");
	cout <<endl<<endl;

	
	double sum = 0;
	ifstream in("purchase.txt");
	cout << "\t\t------------\t----------\t--------"<<endl;
	cout << "\t\tProduct_Name\tItem Price\tQuantity"<<endl;
	cout << "\t\t------------\t----------\t--------"<<endl<<endl;

	while(in >> P_Name >> ItemPrice >> P_Quantity){

		cout << "\n\t\t" << P_Name << "\t\t" << ItemPrice << "\t\t" << P_Quantity;
		cout << "\n\t\t----------------------------------------";
		
		double price = 0;
		price = ItemPrice * P_Quantity;
		sum += price;
	}
	in.close();	
	cout << "\n\t\t\t\tTotal Bill :\t"<< sum <<endl;
	cout << "\t\t\t\t------------------------"<<endl;
	cout << "\n\t\t\tThanks for Shopping with us ..."<<endl<<endl;
	remove("purchase.txt");
}
