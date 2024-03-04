// System Libraries

#include "iostream"
#include "iomanip"
#include "cstdio"
#include "stdio.h"
#include "fstream"
#include "string"
#include "conio.h"
#include "windows.h"

using namespace std;

class Node {
	private :
		int data ;
		Node* Next ;
		
	public:
		Node();
		int GetData();
		Node* GetNext();
		void SetData(int);
		void SetNext(Node*);
};

Node::Node()
{
	
}
int Node::GetData()
{
	return data;
}
Node* Node::GetNext()
{
	return Next;
}
void Node::SetData(int data)
{
	this->data = data ;
}
void Node::SetNext(Node* next)
{
	this->Next = next;
}


class User {
	private:
		Node* CurrentLocation;
		
	public:
		User();
		void InsertData();
        void DeleteData();
        void UpdateData();
        int SearchData(double);
        void PrintData();
        int AuthenticUser();
        int AuthenticUser1();
             
};

User::User()
{
	this->CurrentLocation = NULL;
}

int User::AuthenticUser()
{
	system ("cls");
	system("color 7C");
	cout << "\t ----------------------------------------"<<endl;
	cout << "\t ONLINE SHOPPING STORE MANAGEMENT SYSTEM"<<endl;
	cout << "\t ----------------------------------------"<<endl;
	
	ifstream in("user.txt",ios::in);
	
	string UserName = "", SecurityAnswer = "", U_name = "";
	double UserPassword = 0, CardNumber=0, U_Pass = 0;
	
	char ch;
	
	cout << endl << "\t Username : ";
	cin >> U_name;
	cout << "\t Password : ";
	cin >> U_Pass;
	
	if(!in)
	{
		cout<<"\n\n\t\tFile cannot be Opened"<<endl<<endl;
	}
	else
	{
		while(in >> UserName >> CardNumber >> UserPassword >> SecurityAnswer)
		{
			if(U_name == UserName && U_Pass == UserPassword)
			{
				return 1;
			}
        }
	}
}

int User::AuthenticUser1()
{
	system ("cls");
	system("color 7C");
	cout << "\t ----------------------------------------"<<endl;
	cout << "\t ONLINE SHOPPING STORE MANAGEMENT SYSTEM"<<endl;
	cout << "\t ----------------------------------------"<<endl;
	
	ifstream in("admin.txt",ios::in);
	
	string UserName = "", SecurityAnswer = "", U_name = "";
	double UserPassword = 0, CardNumber=0, U_Pass = 0;
	
	char ch;
	
	cout << endl << "\t Username : ";
	cin >> U_name;
	cout << "\t Password : ";
	cin >> U_Pass;
	
	if(!in)
	{
		cout<<"\n\n\t\tFile cannot be Opened"<<endl<<endl;
	}
	else
	{
		while(in >> UserName >> CardNumber >> UserPassword >> SecurityAnswer)
		{
			if(U_name == UserName && U_Pass == UserPassword)
			{
				return 1;
			}
        }
	}
}

void User::InsertData()
{
	
	int data, price;
	char y;
	do
	{
		string UserName = "", SecurityAnswer = "";
		double UserPassword = 0, CardNumber=0;
		
		system("cls");
		cout <<endl<<endl;
		cout << "\t ----------------------------------------"<<endl;
		cout << "\t USER DATA ENTRY"<<endl;
		cout << "\t ----------------------------------------"<<endl;
		
		cout << "\t Username : "<<endl;
		cin >> UserName;
		
		cout << "\t Card Number : "<<endl;
		cin >> CardNumber;
		
		cout << "\t Password : "<<endl;
		cin >> UserPassword;
		
		cout << "\t ----- > Security Question : "<<endl;
		cout << "\t Nickname : " <<endl;
		cin >> SecurityAnswer;
		
		User obj;
		int u = obj.SearchData(CardNumber);
		if(u==0)
		{
			Node* newNode= new Node();
			newNode->SetData(data);
			newNode->SetNext(NULL);
			
			Node* temp = CurrentLocation;
			
			ofstream file;
			file.open("user.txt",ios::app);
			
			if(!file)
			{
				cout<<"\n\n\tError in opening File.";
			}
			
			file << UserName << "\t"  << CardNumber << "\t" << UserPassword << "\t" << SecurityAnswer <<endl;
			file.close();
		
			
			if (temp != NULL)
			{
				while (temp->GetNext() != NULL)
				{
					temp = temp->GetNext();
								
				}
				temp->SetNext(newNode);		
			}
			else
			{
				CurrentLocation = newNode;
			}	
			
			cout << endl<<endl;
			cout << "\t ----------------------------------------"<<endl;
			cout << "\t Data Has Been Entered Successfully"<<endl;
			cout << "\t ----------------------------------------"<<endl;
		}
		else 
		{
			cout << "\n\tSorry, " << CardNumber << " Already exists"<<endl<<endl;
		}
		
		cout << "\n\n\t\tDo you want to enter more Data : \t";
		cin >> y;
	}
	while (y=='y');
}

void User::DeleteData()
{
		double C_Number = 0;

		string UserName = "", SecurityAnswer = "";
		double UserPassword = 0, CardNumber=0;
		int j=0, k=0;
		
		system("cls");
		cout <<endl<<endl<<endl<<endl;
		cout << "\t ----------------------------------------"<<endl;
	    cout << "\t DELETE USER DATA"<<endl;
		cout << "\t ----------------------------------------"<<endl;
		
		cout<<"\t\t\t  Card Number :\t";
		cin >> C_Number;
		
		fstream in("user.txt");
		
	    if( !in )
		{
	        cout << "\n\n\t\tInput file failed to open ..."<<endl<<endl;
	    }	    

		else
		{
		    ofstream out("temp.txt");
			while (in >> UserName >> CardNumber >> UserPassword >> SecurityAnswer)
			{
				k++;
	    		if(C_Number != CardNumber)
				{
					out << UserName << "\t"  << CardNumber << "\t" << UserPassword << "\t" << SecurityAnswer <<endl;
	    		    j++;
	    		}
	    		else
				{
	    			cout << UserName << "\t"  << CardNumber << "\t" << UserPassword << "\t" << SecurityAnswer <<endl;	    			
	    		}
			}
			if(j==k-1)
			{
				cout <<endl<<endl<<endl;
				cout << "\t ----------------------------------------"<<endl;
				cout << "\t Data Has Been Deleted Successfully"<<endl;
				cout << "\t ----------------------------------------"<<endl;
			}
			else
			{
				cout <<endl<<endl;
				cout << "\t ----------------------------------------"<<endl;
				cout<<"\t\t  " << C_Number  <<" Does Not Exists "<<endl;
				cout << "\t ----------------------------------------"<<endl;
			}
		    in.close();
			out.close();
			remove("user.txt");
			rename("temp.txt","user.txt");
		}
}
void User::UpdateData()
{
	
	string UserName = "", SecurityAnswer = "";
	double CardNumber=0, UserPassword = 0 ;
	double C_Number;
	int j=0, k=0;
	cout <<endl<<endl;
	cout << "\t ----------------------------------------"<<endl<<endl;
    cout << "\t UPDATE USER DATA"<<endl<<endl;
	cout << "\t ----------------------------------------"<<endl<<endl;

	cout << "\t Card Number : ";
	cin >> C_Number;
	
	fstream in("user.txt");
    if( !in )
	{
        cout << "\n\n\t\tInput file failed to open ..."<<endl<<endl;
	}
	else{
	    ofstream out("temp.txt");
		while (in >> UserName >> CardNumber >> UserPassword >> SecurityAnswer)
		{
			k++;
    		if( C_Number != CardNumber )
			{
				out << UserName << "\t"  << CardNumber << "\t" << UserPassword << "\t" << SecurityAnswer <<endl;
    		    j++;
    		}
    		else {
    			string NewName = "", NewAnswer="";
    			double NewCardNumber=0, NewPassword=0;
    			cout << "\n\t"<< C_Number << " Exists in the List..."<<endl;
    			cout << "\n\tPrevious Name             :\t" << UserName;
    			cout << "\n\tEnter New Name            :\t";		cin >> NewName;
    			cout << "\n\tPrevious Card Number       :\t" << C_Number;
    			cout << "\n\tEnter New Card Number      :\t";		cin >> NewCardNumber;
    			cout << "\n\tPrevious Password         :\t" << UserPassword;
    			cout << "\n\tEnter New Password        :\t";		cin >> NewPassword;
    			cout << "\n\tPrevious Security Answer  :\t" << SecurityAnswer;
    			cout << "\n\tEnter New Security Answer :\t";		cin >> NewAnswer;

    			out << NewName << "\t" << NewCardNumber << "\t" << NewPassword << "\t" << NewAnswer <<   endl;
    		}
		}
		if(j==k-1)
		{
			cout <<endl<<endl;
			cout << "\t ----------------------------------------"<<endl;
			cout <<"\t\t  Data Has Been Updated Successfully.  "<<endl;
			cout << "\t ----------------------------------------"<<endl;

		}
		else
		{
				cout <<endl<<endl;
				cout << "\t ----------------------------------------"<<endl;
				cout<<"\t\t  " << C_Number  <<" Does Not Exists "<<endl;
				cout << "\t ----------------------------------------"<<endl;
		}
	    in.close();
		out.close();
		remove("user.txt");
		rename("temp.txt","user.txt");
	}
	getch();
}

int User::SearchData(double search)
{

	string UserName = "", SecurityAnswer = "";
	double CardNumber=0, UserPassword = 0 ;
	int j, k;
	int found=0, data, price;
	ifstream input("user.txt");
	while (input >> UserName >> CardNumber >> UserPassword >> SecurityAnswer)
	{
		k++;
		if(search == CardNumber)
		{
			found++;	
			j++;
		}
	}
	
	input.close();

	if(found==0)
	{
		return 0;
	}
	else 
	{	
		return 1;
	}

}
void User::PrintData()
{

	string UserName = "", SecurityAnswer = "";
	double CardNumber=0, UserPassword = 0 ;

	int data, price, k;
	ifstream input("user.txt");
	if (!input)
	{
		cout << "\n\n\t\tFile Failed to open ..."<<endl<<endl;
	}
	else 
	{
		system("cls"); cout <<endl<<endl;
		cout << "\t---------\t-----------\t-------------\t--------------"<<endl<<endl;
		cout << "\tUser_Name\tCard_Number\tUser_Password\tSecurityAnswer"<<endl<<endl;
		cout << "\t---------\t-----------\t-------------\t--------------"<<endl<<endl<<endl;

		while (input >> UserName >> CardNumber >> UserPassword >> SecurityAnswer)
		{
			cout << "\t" << UserName << "\t\t"  << CardNumber << "\t\t" << UserPassword << "\t\t" << SecurityAnswer <<"\t---> NULL"<<endl;
			k++;
		}
	}
	input.close();
}
