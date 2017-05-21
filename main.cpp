#include <iostream>
#include "functions.hpp"
using namespace std;
int main()
{
	cout << "Welcome to the XO game." << endl;
	bool turn = coinflip(); //true=user starts
	bool win = false;
	bool govr =false;
	//initializing table
	char table[]={'1','2','3','4','5','6','7','8','9'};
	char* ptable=table;
	couttable(ptable);
	
	while (win==false && govr==false){
		if(turn==true){
			cout<<"Pick the location number of your next move: ";
			makemove(ptable);
		}else{
			cout<<"Now the computer will make a move..."<<endl;
			automove(ptable);
		}
		turn=!turn;
		win=checkwin(ptable);
		govr=gameover(ptable);
	}
	if (win==true&&turn==true){
		cout << "The computer won. and it was doing random moves..."<<endl;
	}else if (win==true&&turn==false){
		cout<<"Congrats, you won, great accomplishment." << endl;
	}else{cout<<"GAME OVER. No one won."<<endl;}
	return 0;
}
