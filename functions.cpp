//compile in terminal with g++ main.cpp functions.cpp -o main.o
//execute with ./main.o
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
bool coinflip()
{
	//this function is to determine who starts first, user or computer
	srand(time(0));
	int i = rand();
	bool turn;
	if(i%2==0){turn=true;cout<<"You will begin the game"<<endl;}
	else{turn=false;cout<<"The computer will begin the game"<<endl;}
	return turn;
}
bool checkwin(char * table)
{	
	for(int i=0;i<9;i=i+3){
		if(table[i]==table[i+1]&&table[i]==table[i+2]){
			return true;
		}	
	}
	for(int i=0;i<3;i++){
		if(table[i]==table[i+3]&&table[i]==table[i+6]){
			return true;
		}
	}
	if(table[0]==table[4]&&table[0]==table[8]){return true;}
	if(table[2]==table[4]&&table[2]==table[6]){return true;}
	return false;
}
void couttable(char * table)
{
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout <<" "<< table[3*i+j];
			if(j!=2){cout<<" |";}
		}
		cout <<endl;
	}
	return;
}
bool validmove(char * table, char loc)
{	
	for(int i=0;i<9;i++){
		if(loc!='X'&&loc!='O'&&loc==table[i]){
			return true;
		}
	}
	return false;
}
void makemove(char * table)
{
	int loc;
	cin>>loc;
	char move='0'+loc;
	bool valid=validmove(table,move);
	while(valid==false){
		cout<<endl<<"The move you entered is not valid. Please enter another one: ";
		cin>>loc;
		move='0'+loc;
		valid=validmove(table,move);
	}
	table[loc-1]='X';
	couttable(table);
}
void automove(char * table)
{
	int i;char move;
	bool valid = false;
	while(valid==false){
		srand(time(0));	
		i = rand()%9+1;
		move='0'+i;
		valid= validmove(table, move);
	}
	cout << "The computer chose location "<<i<<"."<<endl;
	table[i-1]='O';
	couttable(table);
	return;
}
bool gameover(char * table)
{	
	bool gameover= true;
	for(int i=0;i<9;i++){
		if(table[i]!='X' && table[i]!='O'){
			gameover=false;
		}
	}
	return gameover;
}
