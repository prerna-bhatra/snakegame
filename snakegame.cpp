#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;
bool gameover;
const int width=50;
const int height=30;
int x,y,fruitx,fruity,score;
enum eDirection{STOP=0,
LEFT,RIGHT,UP,DOWN
};
  eDirection dir;
void setup()
{
	

 gameover=false;
 dir=STOP;
 x=width/2;
 y=height/2;	
 fruitx=rand() % width;
 fruity=rand() % height;
 score=0;
 
}
void draw()
{
	
		
	
	
  system("cls");
  int i,j;
  cout<<"SNAKE GAME\n";
  cout<<"a FOR LEFT,d FOR RIGHT,s for DOWN,w for UP,x FOR END GAME\n\n\n";
  cout<<"\n";
  for(i=0;i<width;i++)
      cout<<"#";
 cout<<"\n";
  	for(i=0;i<height;i++)
  	{
  		for(j=0;j<width;j++)
  		{
		  
  		if(j==0)
  	      	cout<<"#";
  		else if(i==y&&j==x)
  		
  		cout<<"o";
  	
  		else if(i == fruity && j == fruitx)
  		
		  
  		cout<<"F";
  	
  		else
  		
		  
  		cout<<" ";
  	
  	 
	   	if(j==width-3)
  		cout<<"#";
  		
  	}
  		cout<<"\n";
  		
	  }
  	for(i=0;i<width;i++)
  	{
	  
  	cout<<"#";
  }
  	
  	
  	cout<<" \t \t \t \t \t \t \t score="<<score<<"\n";
 	
}
void input()
{
 if(_kbhit())
 {
 	switch(_getch())
 	{
 		case 'a':
 			dir=LEFT;
 			break;
 			case  'd':
 				dir=RIGHT;
 					break;
 					case  'w':
 				dir=UP;
 					break;
 				 case 's':
 				 	dir=DOWN;
 					break;
 		       	case 'x':
 				 		gameover=true;
 				 		break;
 				 		
 			}
 		
   	 }	
	
	
}
void logic()
{
	
	
		switch(dir)
 	{
 		case LEFT:
 			x--;
 			break;
 			case RIGHT:
 				x++;
 				break;
 					case  UP:
 				y--;
 				break;
 				 case DOWN:
 				 	y++;
 				 	break;
 				 }
		if(x>width ||x<0||y>height||y<0)
		{
		
 			gameover=true;
 			cout<<"OPPS!\n";
 			cout<<"GAMEOVER\n";
 		}
       if(x==fruitx && y==fruity)
       {
       	int m=9;
       	m=m--;
       	Sleep(m);
   	     score=score+10;
     	 fruitx=rand() % width;
         fruity=rand() % height;
       }
	
}
int main()
{
 	 setup();
 while(!gameover)
 {
 	draw();
 	input();
 	logic();
 	 Sleep(40);
 	
	 }
	
	 	
}
