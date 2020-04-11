#include<iostream>
#include<fstream>
#include <iomanip>

using namespace std;

class record
{
	int acc_no;
	char name[50];
	char type;
	int deposit;
	public:
		void write_account();
	    int show_no() const;
	    void display() const;
	    void change();
	    void show_all() const;
	    void dep(int);
	    void withdraw(int);
	    int show_deposit() const;
	    char show_type() const;
};

void record::write_account()
{
	cout<<"\nEnter account number"<<endl;
	cin>>acc_no;

	cout<<"\nEnter you name"<<endl;
	cin.ignore();
	cin.getline(name,50);
		
    cout<<"\nEnter account type (C/S)"<<endl;
    cin>>type;
    type=toupper(type);
            
	cout<<"\nEnter the initial ammount (for S account atleast 500 and for C account atleast 1000)"<<endl;
	cin>>deposit;		
}
int record::show_no() const
{
	return acc_no;
}
void record::display() const
{
	cout<<"\nYour account number "<<acc_no<<endl;
	cout<<"\nYour name "<<name<<endl;
	cout<<"\nAccount type "<<type<<endl;
	cout<<"\nYour balance "<<deposit<<endl;
}
void record::change()
{
	cout<<"\nAccount number"<<acc_no<<endl;
	
	cout<<"\nEnter your name"<<endl;
	cin>>name;
			
    cout<<"\nEnter account type"<<endl;
    cin>>type;
    type=toupper(type);
            
	cout<<"\nEnter the initial ammount"<<endl;
	cin>>deposit;		
}
void record::show_all() const
{
	cout<<setw(4)<<acc_no<<setw(20)<<name<<setw(8)<<type<<setw(8)<<deposit<<endl;
}
void record::dep(int amt)
{
	deposit+=amt;
}
void record::withdraw(int amt)
{
	deposit-=amt;
}
int record::show_deposit() const
{
	return deposit;
}
char record::show_type() const
{
	return type;
}


void create_account()
{
	record r;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	r.write_account();
	outFile.write(reinterpret_cast<char *> (&r), sizeof(record));
	outFile.close();
}
void show_account(int n)
{
	record r;
	bool flag=false;
	ifstream infile;
	infile.open("account.dat",ios::binary);
	if(!infile)
	{
		cout<<"\nError in opening the file"<<endl;
		return;
	}
	cout<<"\n.....Here are your details....."<<endl;
	while(infile.read(reinterpret_cast<char *>(&r),sizeof(record)))
	{
		if(r.show_no()==n)
		{
			r.display();
			flag=true;
			break;
		}
	}
	infile.close();
	if(flag==false)
	{
		cout<<"\nThis account number does not exist"<<endl;
	}
	
}
void modify(int n)
{
	record r;
	bool flag=false;
	fstream file;
	file.open("account.dat",ios::binary|ios::in|ios::out);
	if(!file)
	{
		cout<<"\nError in opening the file"<<endl;
		return;
	}
	while(file.read(reinterpret_cast<char *>(&r),sizeof(record)))
	{
		if(r.show_no()==n)
		{
			int pos;
			r.change();
			pos=(-1)*static_cast<int>(sizeof(record));
			file.seekp(pos,ios::cur);
			file.write(reinterpret_cast<char *>(&r),sizeof(record));
			cout<<"\nYour record has updated"<<endl;
			flag=true;
			break;
		}
	}
	file.close();
	if(flag==false)
	 cout<<"\nRecord with account number "<<n<<" is not found"<<endl;
}
void delete_record(int n)
{
	bool flag=false;
	record r;
    ifstream fin;
    ofstream fout;
    fin.open("account.dat",ios::binary);
    fout.open("temp.dat",ios::binary);
    if(!fin)
    {
    	cout<<"\nError in opening of record file"<<endl;
    	return;
	}
	fin.seekg(0,ios::beg);
	while(fin.read(reinterpret_cast<char *>(&r),sizeof(record)))
	{
		if(r.show_no()==n)
		{
			flag=true;
		}
		if(r.show_no()!=n)
		{
			fout.write(reinterpret_cast<char *>(&r),sizeof(record));
		}
	}
	fin.close();
	fout.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	if(flag==true)
	{
		cout<<"\nRecord deleted"<<endl;
	}
	else
	{
		cout<<"\nRecord not found"<<endl;
	}

}
void display()
{
	record r;
	ifstream fin;
	fin.open("account.dat",ios::binary);
	if(!fin)
	{
		cout<<"\nError in opening the file"<<endl;
		return;
	}
	cout<<"\n\nHere is the whole record"<<endl;
	cout<<"****************************************************\n";
	cout<<"A/c No.        Name           Type  Balance\n";
	cout<<"****************************************************\n";
	while(fin.read(reinterpret_cast<char *>(&r),sizeof(record)))
	{
		r.show_all();
	}
	fin.close();
	
}
void withdraw_deposit(int n,int ch)
{
	record r;
	int amt;
	fstream file;
	bool flag=false;
	file.open("account.dat",ios::binary|ios::in|ios::out);
	if(!file)
	{
		cout<<"\nError in opening of the file"<<endl;
		return;
	}
	while(file.read(reinterpret_cast<char *>(&r),sizeof(record)))
	{
		if(r.show_no()==n)
		{
			r.display();
			if(ch==1)
			{
				cout<<"\nENTER THE AMOUNT YOU WANT TO DEPOSIT IN YOUR ACCOUNT"<<endl;
				cin>>amt;
				r.dep(amt);
			}
			if(ch==2)
			{
				cout<<"\nENTER THE AMOUNT YOU WANT TO WITHDRAW FROM YOUR ACCOUNT"<<endl;
				cin>>amt;
				int bal=r.show_deposit()-amt;
				if((bal<500 && r.show_type()=='S') || (bal<1000 && r.show_type()=='C'))
				{
				 cout<<"\nInsufficient balance"<<endl;
				 return;	
				}
				 
				else 
				 r.withdraw(amt);
			}
			int pos=(-1)*static_cast<int>(sizeof(r));
			file.seekp(pos,ios::cur);
			file.write(reinterpret_cast<char *> (&r), sizeof(record));
			cout<<"\n\n Record Updated"<<endl;
			flag=true;
		}
	}
	file.close();
	if(flag==false)
	cout<<"\n Record Not Found "<<endl;
}

int main()
{
	int num;
	char choice;
	do
	{
		cout<<"\n\n\n\t\t\t\tMAIN MENU"<<endl;
		cout<<"\t\t\t\t=========";
		cout<<"\n\n\t\t\t\t1. NEW ACCOUNT";
		cout<<"\n\n\t\t\t\t2. DEPOSIT AMOUNT";
		cout<<"\n\n\t\t\t\t3. WITHDRAW AMOUNT";
		cout<<"\n\n\t\t\t\t4. BALANCE ENQUIRY";
		cout<<"\n\n\t\t\t\t5. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t\t\t\t6. CLOSE AN ACCOUNT";
		cout<<"\n\n\t\t\t\t7. MODIFY AN ACCOUNT";
		cout<<"\n\n\t\t\t\t8. EXIT";
		cout<<"\n\n\t\t\t\tSelect the Option (1-8) "<<endl;
		cout<<"\t\t\t............................................\n\n";
		cin>>choice;
		switch(choice)
		{
		case '1':
			create_account();
			break;
		case '2':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			withdraw_deposit(num, 1);
			break;
		case '3':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			withdraw_deposit(num, 2);
			break;
		case '4': 
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			show_account(num);
			break;
		case '5':
			display();
			break;
		case '6':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			delete_record(num);
			break;
		 case '7':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			modify(num);
			break;
		 case '8':
			cout<<"\n\n\tThank You :)"<<endl;
			break;
		 default :cout<<"\a";
		}
	}while(choice!='8');
	return 0;
}

