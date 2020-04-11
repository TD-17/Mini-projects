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
	    int show_no();
	    void display();
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
int record::show_no()
{
	return acc_no;
}
void record::display()
{
	cout<<"Your account number "<<acc_no<<endl;
	cout<<"Your name "<<firstName<<" "<<lastName<<endl;
	cout<<"Account type "<<type<<endl;
	cout<<"Your balance "<<deposit<<endl;
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
		cout<<"Error in opening the file"<<endl;
		return;
	}
	cout<<"Here are your details....."<<endl;
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
		cout<<"This account number does not exist"<<endl;
	}
	
}

int main()
{
	create_account();
	create_account();
	show_account(1);
	show_account(2);
	return 0;
}

