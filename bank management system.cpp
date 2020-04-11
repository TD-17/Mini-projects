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
	    void change();
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
    type=toupper(type);
            
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
void record::change()
{
	cout<<"Account number"<<acc_no<<endl;
	
	cout<<"Enter you first name"<<endl;
	cin>>firstName;
		
	cout<<"Enter your last name"<<endl;
	cin>>lastName;
			
    cout<<"Enter account type"<<endl;
    cin>>type;
    type=toupper(type);
            
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
		cout<<"This account number does not exist"<<endl;
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
		cout<<"Error in opening the file"<<endl;
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
			cout<<"Your record has updated"<<endl;
			flag=true;
			break;
		}
	}
	file.close();
	if(flag==false)
	 cout<<"Record with account number "<<n<<" is not found"<<endl;
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
    	cout<<"Error in opening of record file"<<endl;
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
		cout<<"Record deleted"<<endl;
	}
	else
	{
		cout<<"Record not found"<<endl;
	}

}

int main()
{
//	create_account();
//	create_account();
//	show_account(1);
//	show_account(2);
//	modify(1);
//	show_account(1);
//	modify(4);
//	modify(5);
delete_record(1);
delete_record(2);
delete_record(4);
	return 0;
}

