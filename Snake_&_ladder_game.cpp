//Two players can play this game and the player who cross 100 first is the winner.
#include<iostream>




using namespace std;
class snakeLadder
{
	int n,score,p1,p2;
	char ch,name1[50],name2[50],ch;
	public:
		void draw_line(int n, char ch);
		void board();
		void gamescore(char name1[],char name2[],int p1,int p2)
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
	drwa_line(50,'-');
	cout<<"\n\t\t LADDER AT POSITION\n";
	draw_line(50,'-');
	cout<<"\n\tFrom 8 to 26\n\tFrom 21 to 82\n\tFrom 43 to 77\n\tFrom 50 to 91\n\tFrom 62 to 96\n\tFrom 66 to 87\n\tFrom 80 to 100\n";
	draw_line(50,'-');
	cout<<endl;
} 

