 #include <iostream>
 using namespace std;
 
 char b[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
 char turn='X';
 int row,column;
 bool draw=false;
 
 void show_b()
 {
 	system("cls");
 	cout<<"\t\t Tic Tac Toe Game\n\n";
 	 
 	 cout<<"   Player1 = [X]\n";
 	 cout<<"   Player2 = [O]\n\n";
 	 
 	 cout<<"\t\t     |     |     \n"; 
 	 cout<<"\t\t "<<b[0][0]<<"   | "<<b[0][1]<<"   | "<<b[0][2]<<"    \n"; 
 	 cout<<"\t\t_____|_____|_____\n"; 	 
 	 cout<<"\t\t     |     |     \n";
 	 cout<<"\t\t "<<b[1][0]<<"   | "<<b[1][1]<<"   | "<<b[1][2]<<"    \n"; 	 
 	 cout<<"\t\t_____|_____|_____\n";	 
 	 cout<<"\t\t     |     |     \n";
 	 cout<<"\t\t "<<b[2][0]<<"   | "<<b[2][1]<<"   | "<<b[2][2]<<"    \n";
 	 cout<<"\t\t     |     |     \n";
 }
 
 void player_turn()
 {
 		int c;
 		
 	if(turn=='X')	
 	cout<<"\n    Player1 [X] Turn: ";
 	
 	if(turn=='O')	
 	cout<<"\n    Player2 [O] Turn: ";
 	
 	 cin>>c;
 	 
 	 switch(c)
 	 {
 	 	case 1: row = 0; column = 0; break;
		case 2: row = 0; column = 1; break;
		case 3: row = 0; column = 2; break;
		case 4: row = 1; column = 0; break;
		case 5: row = 1; column = 1; break;
		case 6: row = 1; column = 2; break;
		case 7: row = 2; column = 0; break;
		case 8: row = 2; column = 1; break;
		case 9: row = 2; column = 2; break;    	  	 
		default:
			cout<<"Invalid Move";
			break;	   	  	  	  	
	  }
	  if(turn=='X' && b[row][column]!='X' && b[row][column]!='O')
	  {
	  	b[row][column]='X';
	  	turn='O';
	  }
	  else if(turn=='O' && b[row][column]!='O' && b[row][column]!='X')
	  {
	  	b[row][column]='O';
	  	turn='X';
	  }
	  else
	  {
	  	cout<<"   box already filled...\n    please try again!..\n\n";
	  	player_turn();
	  }
	  show_b();
 }
 
 bool gameover()
 {
 	// check wins for rows and column wise....
 	
 	for(int i=0;i<3;i++)
 	if(b[i][0]==b[i][1] && b[i][0]==b[i][2] || b[0][i]==b[1][i] && b[0][i]==b[2][i])
 	return false;
 	
 	// check for diagonal wins...
 	if(b[0][0]==b[1][1] && b[0][0]==b[3][3] || b[0][2]==b[1][1] && b[0][2]==b[2][0])
 	return false;
 	
 	// If there any box not filled....
 	for(int i=0;i<3;i++)
 	for(int j=0;j<3;j++)
 	if(b[i][j]!='X' && b[i][i]!='O')
 	return true; 
 	
 	// draw scenario....
 	draw=true;
 	return false;
 }
 
 int main()
 {
 	while(gameover())
 	{
	 
 		show_b(); 
 		player_turn(); 
 		gameover();
 	}
 	
 	if(turn=='X' && draw == false)
 	cout<<"\t Player2 [O] wins...\n\t Congratulations....";
 	else if(turn=='O'&& draw == false)
 	cout<<"\t Player1 [X] wins...\n\t Congratulations....";
 	else
 	cout<<" Match Draw ";
 }
