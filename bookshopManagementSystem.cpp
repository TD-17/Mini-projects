//this program is compiled in dev c++
//before compiling it select TDM-GCC 4.9.2 32-bit Release
#include<iostream>
#include<fstream>
#include<graphics.h>
#include<iomanip>
#include<conio.h>
using namespace std;

class book
{
public:
char name[20];
char author[20];
int a;
void getdata();
void show();
void change();
};
void book::getdata()
{
 cout<<"\nENTER DETAILS ABOUT BOOK U WANT TO PURCHASE  :\t";
 cout<<"\n\n\n\t\tEnter Name Of Book      :\t";
 cin>>name;
 cout<<"\n\t\tEnter Name Of Author    :\t";
 cin>>author;
 cout<<"\n\t\tEnter No. Of Copies     :\t";
 cin>>a;
}
void book::show()
{ 
cout<<"BOOK    :"<<name<<endl;
cout<<"AUTHOR  :"<<author<<endl;
cout<<"COPIES  :"<<a<<endl;
}
void book::change()
{
 cout<<"\nENTER NEW DETAILS FOR THIS BOOK  :\t";	
 cout<<"\n\n\n\t\tEnter new name Of Book                  :\t";
 cin>>name;
 cout<<"\n\t\tEnter new name Of Author                :\t";
 cin>>author;
 cout<<"\n\t\tEnter new value of number Of Copies     :\t";
 cin>>a;
}


void graph()
{
	int x,y;
	setcolor(YELLOW);
	rectangle(0,0,760,30);
	setfillstyle(XHATCH_FILL,RED);
	floodfill(230,15,YELLOW);
	rectangle(760,0,800,760);
	setfillstyle(XHATCH_FILL,RED);
	floodfill(780,230,YELLOW);
	rectangle(30,760,800,800);
	setfillstyle(XHATCH_FILL,RED);
	floodfill(385,780,YELLOW);
	rectangle(0,30,30,800);
	setfillstyle(XHATCH_FILL,RED);
	floodfill(15,385,YELLOW);
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
		if(i==5)
		{
			setcolor(WHITE);
	        settextstyle(9,0,8);
            outtextxy(160,90,"Welcome");
		}
		if(i==15)
		{
	        settextstyle(9,0,6);
            outtextxy(365,210,"to");
		}
		if(i==30)
		{
			setcolor(WHITE);
	        settextstyle(9,0,8);
            outtextxy(60,600,"BOOK-SHOP");
		}
		delay(80);
		setcolor(RED);
	}
	setcolor(WHITE);
	settextstyle(9,0,2);
    outtextxy(650,766,"Press Enter");
	getch();
	clearviewport();
}

int main()
{
	z:
	initwindow(800,800,"Book-Shop");
	graph();
    setcolor(WHITE);
    rectangle(10,10,780,780);
    setfillstyle(10,YELLOW);
    floodfill(400,400,WHITE);
    settextstyle(10,HORIZ_DIR,6);
    outtextxy(70,15,"WHAT DO U WANT TO DO:");
    settextstyle(SANS_SERIF_FONT,0,3); 
	outtextxy(250,100,"1 . TO BUY");
    outtextxy(250,200,"2 . TO SHOW ALL BOOKS");
    outtextxy(250,300,"3 . TO CHECK AVAILABILITY");
    outtextxy(250,400,"4 . TO MODIFY");
    outtextxy(250,500,"5 . TO DELETE");
    outtextxy(250,600,"6 . TO EXIT");
    setcolor(3);
    settextstyle(7,0,6);
    delay(1000);
    outtextxy(140,720, "PRESS ENTER:");
    getch(); 
    closegraph();
	int a; 
	cout<<"************************************************************************"<<endl; 
    cout<<"Enter your choice"<<endl;
	cout<<"************************************************************************"<<endl;  
    cin>>a;
    book b;
    switch(a)
    {
    	case 1:
    	{
		 ofstream outFile;
	     outFile.open("book.dat",ios::binary|ios::app);
	     b.getdata();
	     outFile.write(reinterpret_cast<char *> (&b), sizeof(book));
	     outFile.close();
	     char ans;
		 cout<<"Do you want to continue(y/n)"<<endl;
		 cin>>ans;
		 if(ans=='Y' || ans=='y')
		 goto z;
		 else
		 break; 		
		}
    
     	 
		case 2:
		{
		 ifstream fin;
	     fin.open("book.dat",ios::binary);
	     if(!fin)
	      {
		    cout<<"\nError in opening the file"<<endl;
		    break;
	      }
       	 cout<<"\n\nHere is the whole record"<<endl;
	 
	     while(fin.read(reinterpret_cast<char *>(&b),sizeof(book)))
      	 {
	    	b.show();
	     }
	     fin.close();
	     char ans;
		 cout<<"Do you want to continue(y/n)"<<endl;
		 cin>>ans;
		 if(ans=='Y' || ans=='y')
		 goto z;
		 else
		 break;
	    } 
	    
	    
	    case 3:
	    {
	      book b;
	      char name1[20];
	      bool flag=false;
	      fstream file;
	      file.open("book.dat",ios::binary|ios::in|ios::out);
	      if(!file)
	      {
		    cout<<"\nError in opening the file"<<endl;
		    break;
	      }
	        cout<<"\n\n\n          Enter book name whose record you want to see :";
            cin>>name1;
	      while(file.read(reinterpret_cast<char *>(&b),sizeof(book)))
	      {
		    if(strcmp(name1,b.name)==0)
		    {
		    	cout<<"*****THIS BOOK IS AVAILABLE*****"<<endl;
		        b.show();
		    	flag=true;
			    break;
		    }
	      }
	     file.close();
	     if(flag==false)
	         cout<<"\nThis book is not found"<<endl;
	         
	     char ans;
		 cout<<"Do you want to continue(y/n)"<<endl;
		 cin>>ans;
		 if(ans=='Y' || ans=='y')
		 goto z;
		 else
		 break;
 	
		}
		
		
		case 4:
		{
			book b;
			char name1[20];
	        bool flag=false;
	        fstream file;
	        file.open("book.dat",ios::binary|ios::in|ios::out);
	        if(!file)
         	{
		      cout<<"\nError in opening the file"<<endl;
		      break;
	        }
	        cout<<"\n\n\n          Enter book name whose record you want to update  :";
	        fflush(stdin);
            cin>>name1;
	        while(file.read(reinterpret_cast<char *>(&b),sizeof(book)))
	        {
		      if(strcmp(name1,b.name)==0)
		      {
			    int pos;
			    b.change();
			    pos=(-1)*static_cast<int>(sizeof(book));
			    file.seekp(pos,ios::cur);
			    file.write(reinterpret_cast<char *>(&b),sizeof(book));
			    cout<<"\nDetails have updated"<<endl;
			    flag=true;
			    break;
	          }
	        }
	        file.close();
	        if(flag==false)
	        cout<<"\nThis book is not found"<<endl;
	        char ans;
		    cout<<"Do you want to continue(y/n)"<<endl;
		    cin>>ans;
		    if(ans=='Y' || ans=='y')
		    goto z;
		    else
		    break;	
	    }	
	    
	    
	    case 5:
	    {
	        bool flag=false;
	        book b;
	        char name1[20];
            ifstream fin;
            ofstream fout;
            fin.open("book.dat",ios::binary);
            fout.open("temp.dat",ios::binary);
            if(!fin)
            {
    	        cout<<"\nError in opening of record file"<<endl;
    	        break;
	        }
	        cout<<"\n\n\n          Enter book name whose record you want to delete  :";
	        fflush(stdin);
            cin>>name1;
	        fin.seekg(0,ios::beg);
	        while(fin.read(reinterpret_cast<char *>(&b),sizeof(book)))
	        {
		      if(strcmp(name1,b.name)==0)
		      {
			    flag=true;
		      }
	          if(strcmp(name1,b.name)!=0)
		      {
			    fout.write(reinterpret_cast<char *>(&b),sizeof(book));
		      }
	       }
	       fin.close();
	       fout.close();
	       remove("book.dat");
           rename("Temp.dat","book.dat");
	       if(flag==true)
	       {
		       cout<<"\nBook record deleted"<<endl;
	       }
	       else
	       {
		       cout<<"\nBook record not found"<<endl;
	       }
	       char ans;
		   cout<<"Do you want to continue(y/n)"<<endl;
		   cin>>ans;
		   if(ans=='Y' || ans=='y')
		   goto z;
		   else
		   break;	
		}
		
		
		
            
			
	}
  
	return 0;
}

