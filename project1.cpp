#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
		
		public:
			void menu();
			void administrator();
			void buyer();
			void add();
			void show();
			void edit();
			void rem();
			void list();
			void receipt();
			
};

void shopping :: menu()
{
	m:
	int choice;
	string email;
	string password;
	cout<<"***************************************\n";
	cout<<"        Supermarket Main Menu       \n\n";
	cout<<"***************************************\n";
	cout<<"  1) Administrator   \n";
	cout<<"  2) Buyer           \n";
	cout<<"  3) Exit            \n";
		cout<<"\n        Please select! ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<"\n\n********Please Login******** \n";
			cout<<"\n Enter Email : ";
			cin>>email;
			cout<<" Password : ";
			cin>>password;
			
			if(email=="raj@gmail.com" && password=="raj123")
			{
				administrator();
			}
			else
			{
				cout<<"Invalid email/password";
			}
			break;
	
	
	case 2:
		{
			buyer();
		}
	
	case 3:
		{
			exit(0);
		}
		
		default :
			{
				cout<< "Please select from the given options";
			}
}
goto m;
}

void shopping:: administrator()
{
	m:
	int choice;
	cout<<"\n\n********Administrator menu********";
	cout<<"\n\n 1) Add the product";
	cout<<"\n 2) Modify the product";
	cout<<"\n 3) Delete the product";
	cout<<"\n 4) Show all products";
    cout<<"\n 5) Back to main menu";
    
    cout<<"\n\n Please enter your choice ";
    cin>>choice;
    
    switch(choice)
    {
    	case 1:
    		add();
    		break;
    		
    	case 2:
    		edit();
    		break;
    		
    	case 3:
    		rem();
    		break;
    		
        case 4:
        	show();
        	break;
        	
    	case 5:
    		menu();
    		break;
    		
    	default :
    		cout<<"Invalid choice!";
    		
	}
	goto m;
}

void shopping:: buyer()
{
	m:
	int choice;
	cout<<"\n\n********Buyer********\n";
	cout<<" 1) Buy product \n";
	cout<<" 2) Go back     \n";
	cout<<" Enter your choice : ";
	
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
			
		case 2:
			menu();
			
		default :
			
			cout<<"invalid choice";
			
	}
	
	goto m;
	
	
}

void shopping ::add()
{
	m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	
	cout<<"\n\n********Add new product********";
	cout<<"\n\n Product code of the product ";
	cin>>pcode;
	cout<<"\n Name of the product : ";
	cin>>pname;
	cout<<"\n Price of the product : ";
	cin>>price;
	cout<<"\n Discount on product : ";
	cin>>dis;
	
	data.open("database.txt",ios::in);
	
	if(!data)
	{
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	else
	{
		data>>c>>n>>p>>d;
		
		while(!data.eof())
		{
			if(c ==pcode)
			{
				token++;
				
			}
			data>>c>>n>>p>>d;
		}
		data.close();
		
		
	
	
	if(token==1)
	 goto m;
	else{
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
		
	}
}
	cout<<"\n        Record inserted !";
}

void shopping :: show()
{
		fstream data;
	data.open("database.txt",ios::in);
	cout<<"\nProNo\t\tName\t\tPrice\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
}

void shopping ::edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\n********Modify the record********";
	cout<<"\n Product code :";
	cin>>pkey;
	
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\nFile doesn't exist! ";
	}
	else{
		
		data1.open("database1.txt", ios::app|ios::out);
		
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n Product new code :";
				cin>>c;
				cout<<"\n Name of the product :";
				cin>>n;
				cout<<"\n Price :";
				cin>>p;
				cout<<"\n Discount :";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\nd edited ";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record not found sorry!";
		}
	}
}
void shopping::rem()
{
	
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\n********Delete product********";
	cout<<"\n Product code :";
	cin>>pkey;
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<"File doesnt exist";
		
	}
	
	else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n Product deleted succesfully";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record not found";
		}
	}
}

void shopping:: list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\nProNo\t\tName\t\tPrice\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
}

void shopping::receipt() 
	{
		system("cls");
		fstream data;
		
		int arrc[100],arrq[100];
		char choice;
		int c=0;
		float amount=0;
		float dis=0;
		float total=0;
		cout<<"\n\n\t\t\t Receipt ";
		data.open("database.txt",ios::in);
		if(!data)
		{
			cout<<"\n\n Empty database";
		}
		else
		{
			data.close();                                   
			list();
			cout<<"\n********Please place the order********";
			do
			{
				m:
				cout<<"\n\n Product Code : ";
				cin>>arrc[c];
				cout<<"\n Product Quantity : ";
				cin>>arrq[c];
				for(int i=0;i<c;i++)
				{
					if(arrc[c] == arrc[i])
					{
						cout<<"\n\n Duplicate Product Code. Please try again!";
						goto m;
					}
				}
				c++;             
				cout<<"\n\n Want to buy another product? Press y for yes and n for no : ";
				cin>>choice;	
			}
			
			while(choice == 'y');
			system("cls");
	
			cout<<"\nProduct Num.\tProduct Name\tQuantity \tPrice \tAmount \tAmount with discount\n";
			
			
			for(int i=0;i<c;i++) 
			{
				data.open("database.txt",ios::in);
				data>>pcode>>pname>>price>>dis;
				while(!data.eof())
				{
					if(pcode == arrc[i])   
					{
						amount = price*arrq[i];
						dis = amount - (amount*dis/100);
						total =total+ dis;
						cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;	
					}
					   data>>pcode>>pname>>price>>dis;  
				}
				data.close();
			}
			cout<<"\n\n----------------------------------------";
			cout<<"\n Total Amount : "<<total;
		}
	}
int main()
{
	shopping s;
	s.menu();
}
