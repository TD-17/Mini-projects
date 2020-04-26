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

void graph()
{
	int x,y;
	x=getmaxx()/2;
	y=getmaxy()/2;
	setcolor(4);
	circle(x,y,80);
	setfillstyle(SOLID_FILL,YELLOW);
	floodfill(x,y,4);
	setfillstyle(SOLID_FILL,BLACK);
	fillellipse(x-30,y-35,12,20);
	fillellipse(x+30,y-35,12,20);
	setfillstyle(SOLID_FILL,WHITE);
	fillellipse(x-30,y-35,5,10);
	fillellipse(x+30,y-35,5,10);

	int i;
	for(i=0;i<=35;i++)
	{
		ellipse(x,y,180,360,60,20+i);
		delay(100);
	}


}

int main()
{
	initwindow(800,800,"Book-Shop");
	graph(); 
	
	getch();
	return 0;
}

