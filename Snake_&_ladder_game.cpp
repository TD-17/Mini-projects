//Two players can play this game and the player who cross 100 first is the winner.
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <ctime>
#include<cstring>
using namespace std;
class snakeLadder
{

	public:
		void draw_line( int n,char ch);
		void board();
		void gamescore( string name1, string name2,int p1,int p2);
		void play_dice(int &score);
};

void snakeLadder::draw_line(int n,char ch)
{
	for(int i=0;i<n;i++)
	{
		cout<<ch;
	}
	
}
void snakeLadder::board()
{
	cout<<"\n\n";
	draw_line(50,'-');
	cout<<"\n\t\tSNAKE AT POSITION\n";
	draw_line(50,'-');
	cout<<"\n\tFrom 98 to 28 \n\tFrom 95 to 24\n\tFrom 92 to 51\n\tFrom 83 to 19\n\tFrom 73 to 1\n\tFrom 69 to 33\n\tFrom 64 to 36\n\tFrom 59 to 17\n\tFrom 55 to 7\n\tFrom 52 to 11\n\tFrom 48 to 9\n\tFrom 46 to 5\n\tFrom 44 to 22\n\n";
	draw_line(50,'-');
	cout<<"\n\t\t LADDER AT POSITION\n";
	draw_line(50,'-');
	cout<<"\n\tFrom 8 to 26\n\tFrom 21 to 82\n\tFrom 43 to 77\n\tFrom 50 to 91\n\tFrom 62 to 96\n\tFrom 66 to 87\n\tFrom 80 to 100\n";
	draw_line(50,'-');
	cout<<endl;
} 
void snakeLadder::gamescore(string name1,string name2,int p1,int p2)
{
	cout<<"\n";
	draw_line(50,'~');
	cout<<"\n\t\tGAME STATUS\n";
	draw_line(50,'~');
	if(p1>=100)
	{
		p1=100;
	}
	if(p2>=100)
	{
		p2=100;
	}
	cout<<"\n\t--->"<<name1<<" is at position "<<p1<<endl;
	cout<<"\t--->"<<name2<<" is at position "<<p2<<endl;
	draw_line(50,'_');
	cout<<endl;
}
void snakeLadder::play_dice(int &score)
{
	int dice;
	dice = 1 + (rand() % 6);
	cout<<"\nYou got "<<dice<<" point !! ";
	score=score+dice;
	cout<<"Now you are at position "<<score;
	switch(score)
	{
		
    case 98:
        score = 28;
        break;
    case 95:
        score = 24;
        break;
    case 92:
        score = 51;
        break;
    case 83:
        score = 19;
        break;
    case 73:
        score = 1;
        break;
    case 69:
        score = 33;
        break;
    case 64:
        score = 36;
        break;
    case 59:
        score = 17;
        break;
    case 55:
        score = 7;
        break;
    case 52:
        score = 11;
        break;
    case 48:
        score = 9;
        break;
    case 46:
        score = 5;
        break;
    case 44:
        score = 22;
        break;
    case 8:
        score = 26;
        break;
    case 21:
        score = 82;
        break;
    case 43:
        score = 77;
        break;
    case 50:
        score = 91;
        break;
    case 54:
        score = 93;
        break;
    case 62:
        score = 96;
        break;
    case 66:
        score = 87;
        break;
    case 80:
        score = 100;
	}
	
}
int main()
{
	snakeLadder l;
	int player1=0,player2=0,lastPosition;
	string playerName1,playerName2;
	char ch;
	srand((unsigned) time(0));
	l.draw_line(50,'=');
	cout << "\n\n\n\n\t\tSNAKE LADDER GAME\n\n\n\n";
    l.draw_line(50, '=');
    cout<<"\n\n\n Enter the name of first player => ";
    getline(cin,playerName1);
    cout<<"\n\n\n Enter the name of second player => ";
    getline(cin,playerName2);
    while(player1 <100 && player2 <100)
    {
    	l.board();
    	l.gamescore(playerName1, playerName2, player1, player2);
    	cout << "\n\n--->" << playerName1 << " it's your Turn >> Press 'S' to throw the dice ";
        cin>>ch;
        lastPosition=player1;
        l.play_dice(player1);
        if(player1>=100)
         break;
        if (player1 < lastPosition)
            cout << "\n\aOops!! Snake found you !! You are at postion " << player1 <<endl;
        else if (player1 > lastPosition + 6)
            cout << "\nYippee!! you got a ladder !! You are at position " << player1 <<endl;
        cout << "\n\n--->" << playerName2 << " it's' your Turn >> Press 'S' key to throw the dice ";
        cin>>ch;
        lastPosition = player2;
        l.play_dice(player2);
        if(player2>=100)
         break;
        if (player2 < lastPosition)
            cout << "\n\n\aOops!! Snake found you !! You are at position " << player2 << "\n";
        else if (player2 > lastPosition + 6)
            cout << "\n\nYippee!! you got a ladder !! You are at position " << player2 << "\n";
    	
	}
	system("cls");
    cout << "\n\n\n";
    l.draw_line(50, '+');
    cout << "\n\n\t\tRESULT\n\n";
    l.draw_line(50, '+');
    cout << endl;
    l.gamescore(playerName1, playerName2, player1, player2);
    cout << "\n\n\n";
    if (player1 >= player2)
        cout <<"  HURRAY!! "<< playerName1 << " won !!\n\n";
    else
        cout <<"  HURRAY!! "<< playerName2 << " won !!\n\n";
    l.draw_line(50, '+');
	
	return 0;
}

