//this program is compiled in dev c++
//before compiling it select TDM-GCC 4.9.2 32-bit Release
#include<iostream>
#include<fstream>
#include<graphics.h>
#include<iomanip>
using namespace std;

class book
{
char name[20];
char author[20];
int a;
public:
void getdata();
void show();
};
void book::getdata()
{
 cout<<"\nENTER DETAILS ABOUT BOOK U WANT TO PURCHASE  :\t";
 cout<<"\n\n\n\t\tEnter Name Of Book  :\t";
 cin>>name;
 cout<<"\n\t\tEnter Name Of Author    :\t";
 cin>>author;
 cout<<"\n\t\tEnter No. Of Copies  :\t";
 cin>>a;
}
void book::show()
{
 
cout<<"BOOK    :"<<name<<endl;
cout<<"AUTHOR  :"<<author<<endl;
cout<<"COPIES  :"<<a<<endl;
}

int main()
{
	cout<<"hi there";
}

