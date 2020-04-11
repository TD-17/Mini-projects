#include<iostream>
#include<fstream>

using namespace std;

class record
{
	int acc_no;
	char firstName[50];
	char lastName[50];
	char type;
	int deposit;
	public:
		void write_account();
	
};

void record::write_account()
{
	cout<<"Enter account number"<<endl;
	cin>>acc_no;
	
	cout<<"Enter you first name"<<endl;
	cin>>firstName;
		
	cout<<"Enter your last name"<<endl;
	cin>>lastName;
			
    cout<<"Enter account type"<<endl;
    cin>>type;
            
	cout<<"Enter the initial ammount"<<endl;
	cin>>deposit;		
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
void show_account()
{
	
}

int main()
{
	create_account();
	return 0;
}

