/*
   Name: hw6func.cpp
   Author: Pavan Kumar Govu
   Due Date: 06 December 2017
   Description: This specific program will hold the 
   local include directive for the header file as well 
   as all function definitions (not including main, of 
   course) used in the program.   
*/

#include "hw6prgm.h"

void initializeBoard(piece pieces[][columns], int height)
{
   cout << "Initializing game board..." << endl;

   //initialize pieces
   for(int row=0; row<height; row++)
   {
      for(int column=0; column<columns; column++)
      {
         pieces[row][column].rank=EMPTY;//blank space
         pieces[row][column].color=NONE;//no color
      }
   }
   return;
}

void assignPieces(piece pieces[][columns], int height)
{
   cout << "Assigning BLUE pieces to board..." << endl;
   cout << "Assigning RED pieces to board..." << endl;

   //seed random number generator
   srand(time(NULL));

   int randomRow=0;//holds a randomly generated row number
   int randomColumn=0;//holds a randomly generated column number
   int randomNumber=0;//holds a randomly generated number (multipurpose)
      
   //assign blue flag
   do
   {
      randomColumn=(rand()%5);
   }
   while((pieces[0][randomColumn].rank)!=EMPTY);
   pieces[0][randomColumn].rank=FLAG;
   pieces[0][randomColumn].color=BLUE;
   pieces[0][randomColumn].moveable=false;    
   
   //assign red flag
   do
   {
      randomColumn=(rand()%5);
   }
   while((pieces[4][randomColumn].rank)!=EMPTY);
   pieces[4][randomColumn].rank=FLAG;
   pieces[4][randomColumn].color=RED;
   pieces[0][randomColumn].moveable=false;
   
   //assign blue bombs
   for(int bombs=1; bombs<=3; bombs++)
   {
      do
      {
         randomRow=(rand()%2);
         randomColumn=(rand()%5);
      }
      while((pieces[randomRow][randomColumn].rank)!=EMPTY);
      pieces[randomRow][randomColumn].rank=BOMB;
      pieces[randomRow][randomColumn].color=BLUE;
      pieces[randomRow][randomColumn].moveable=false;
   }
   
   //assign red bombs
   for(int bombs=1; bombs<=3; bombs++)
   {
      do
      {
         randomRow=(rand()%2)+3;
         randomColumn=(rand()%5);
      }
      while((pieces[randomRow][randomColumn].rank)!=EMPTY);
      pieces[randomRow][randomColumn].rank=BOMB;
      pieces[randomRow][randomColumn].color=RED;
      pieces[randomRow][randomColumn].moveable=false;
   }
   
   //assign either marshall or general (blue in both cases)
   randomNumber=(rand()%2);
   do
   {
      randomRow=(rand()%2);
      randomColumn=(rand()%5);
   }
      while((pieces[randomRow][randomColumn].rank)!=EMPTY);
   if(randomNumber==0)
   {
      pieces[randomRow][randomColumn].rank=MARSHAL;
      pieces[randomRow][randomColumn].color=BLUE;
      pieces[randomRow][randomColumn].moveable=false;
   }
   if(randomNumber==1)
   {
      pieces[randomRow][randomColumn].rank=GENERAL;
      pieces[randomRow][randomColumn].color=BLUE;
      pieces[randomRow][randomColumn].moveable=false;
   }
   
   //assign either marshall or general (red in both cases)
   randomNumber=(rand()%2);
   do
   {
      randomRow=(rand()%2)+3;
      randomColumn=(rand()%5);
   }
      while((pieces[randomRow][randomColumn].rank)!=EMPTY);
   if(randomNumber==0)//marshal
   {
      pieces[randomRow][randomColumn].rank=MARSHAL;
      pieces[randomRow][randomColumn].color=RED;
   }
   if(randomNumber==1)//general
   {
      pieces[randomRow][randomColumn].rank=GENERAL;
      pieces[randomRow][randomColumn].color=RED;
   }
   
   //assign blue miner
   do
   {
      randomRow=(rand()%2);
      randomColumn=(rand()%5);
   }
      while((pieces[randomRow][randomColumn].rank)!=EMPTY);
   pieces[randomRow][randomColumn].rank=MINER;
   pieces[randomRow][randomColumn].color=BLUE;
   pieces[randomRow][randomColumn].moveable=false;
   
   //assign red miner
   do
   {
      randomRow=(rand()%2)+3;
      randomColumn=(rand()%5);
   }
      while((pieces[randomRow][randomColumn].rank)!=EMPTY);
   pieces[randomRow][randomColumn].rank=MINER;
   pieces[randomRow][randomColumn].color=RED;
   
   //assign blue spy
   do
   {
      randomRow=(rand()%2);
      randomColumn=(rand()%5);
   }
      while((pieces[randomRow][randomColumn].rank)!=EMPTY);
   pieces[randomRow][randomColumn].rank=SPY;
   pieces[randomRow][randomColumn].color=BLUE;
   pieces[randomRow][randomColumn].moveable=false;
   
   //assign red spy
   do
   {
      randomRow=(rand()%2)+3;
      randomColumn=(rand()%5);
   }
      while((pieces[randomRow][randomColumn].rank)!=EMPTY);
   pieces[randomRow][randomColumn].rank=SPY;
   pieces[randomRow][randomColumn].color=RED;

   
   //assign colonels, majors, captains, lieutentants, or sergeants (blue in all cases)
   for(int characters=1; characters<=3; characters++)
   {
      randomNumber=(rand()%5);
      do
      {
         randomRow=(rand()%2);
         randomColumn=(rand()%5);
      }
      while((pieces[randomRow][randomColumn].rank)!=EMPTY);
      if(randomNumber==0)//colonel
      {
         pieces[randomRow][randomColumn].rank=COLONEL;
         pieces[randomRow][randomColumn].color=BLUE;
         pieces[randomRow][randomColumn].moveable=false;
      }
      else if(randomNumber==1)//major
      {
         pieces[randomRow][randomColumn].rank=MAJOR;
         pieces[randomRow][randomColumn].color=BLUE;
         pieces[randomRow][randomColumn].moveable=false;
      }
      else if(randomNumber==2)//captain
      {
         pieces[randomRow][randomColumn].rank=CAPTAIN;
         pieces[randomRow][randomColumn].color=BLUE;
         pieces[randomRow][randomColumn].moveable=false;
      }
      else if(randomNumber==3)//lieutentant
      {
         pieces[randomRow][randomColumn].rank=LIEUTENTANT;
         pieces[randomRow][randomColumn].color=BLUE;
         pieces[randomRow][randomColumn].moveable=false;
      }
      else if(randomNumber==4)//sergeant
      {
         pieces[randomRow][randomColumn].rank=SERGEANT;
         pieces[randomRow][randomColumn].color=BLUE;
         pieces[randomRow][randomColumn].moveable=false;
      }
   }
   
   //assign colonels, majors, captains, lieutentants, or sergeants (red in all cases)
   for(int characters=1; characters<=3; characters++)
   {
      randomNumber=(rand()%5);
      do
      {
         randomRow=(rand()%2)+3;
         randomColumn=(rand()%5);
      }
      while((pieces[randomRow][randomColumn].rank)!=EMPTY);
      if(randomNumber==0)//colonel
      {
         pieces[randomRow][randomColumn].rank=COLONEL;
         pieces[randomRow][randomColumn].color=RED;
      }
      else if(randomNumber==1)//major
      {
         pieces[randomRow][randomColumn].rank=MAJOR;
         pieces[randomRow][randomColumn].color=RED;
      }
      else if(randomNumber==2)//captain
      {
         pieces[randomRow][randomColumn].rank=CAPTAIN;
         pieces[randomRow][randomColumn].color=RED;
      }
      else if(randomNumber==3)//lieutentant
      {
         pieces[randomRow][randomColumn].rank=LIEUTENTANT;
         pieces[randomRow][randomColumn].color=RED;
      }
      else if(randomNumber==4)//sergeant
      {
         pieces[randomRow][randomColumn].rank=SERGEANT;
         pieces[randomRow][randomColumn].color=RED;
      }
   }
   
   return;   
}

bool updateBoard(piece pieces[][columns], int height, int oldX, int oldY, int newX, int newY)
{ 
   if(pieces[newX-65][newY].rank=='F')
      return true;
   if(pieces[oldX-65][oldY].rank<pieces[newX-65][newY].rank)
      swapPieces(pieces, oldX, oldY, newX, newY);
   return false;
}

void swapPieces(piece pieces[][columns], int x1, int y1, int x2, int y2)
{
   piece temp;
   temp.rank=pieces[x1-65][y1].rank;
   //temp.color=pieces[x1-65][y1].color;
   temp.moveable=pieces[x1-65][y1].moveable;
   
   pieces[x1-65][y1].rank=pieces[x2-65][y2].rank;
   //pieces[x1-65][y1].color=pieces[x2-65][y2].rank;
   pieces[x1-65][y1].moveable=pieces[x2-65][y2].rank;
   
   pieces[x2-65][y2].rank=temp.rank;
   //pieces[x2-65][y2].rank=temp.color;
   pieces[x2-65][y2].moveable=temp.moveable;
}

void displayGameIntroduction()
{
	//Basic details and rules of the game:
   cout << endl << "<><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
   cout << "             WELCOME TO 1030 STRATEGO           " << endl;
   cout << "<><><><><><><><><><><><><><><><><><><><><><><><><>" << endl << endl;
   
   cout << endl << "-------------" << endl;
   cout << "INTRODUCTION: " << endl;
   cout << "-------------" << endl;	
   
   cout << "This program will set up a 5x5 game board for a 1030 version of the game" << endl;
   cout << "of Stratego. One player will compete against the computer, each assigned" << endl;
   cout << "10 total pieces consisting of the following: " << endl;
   
   cout << "\t1 FLAG (F)" << endl;
   cout << "\t3 BOMB (B)" << endl;
   cout << "\t1 MARSHAL (1) or GENERAL (2)" << endl;
   cout << "\t3 COLONEL (3), MAJOR (4), CAPTAIN (5), LIEUTENANT (6), or SERGEANT (7)" << endl;
   cout << "\t1 MINER (8)" << endl;
   cout << "\t1 SPY (S)" << endl;
   
   cout << endl << endl << "--------------" << endl;
   cout << "GENERAL RULES: " << endl;
   cout << "--------------" << endl;
   
   cout << "For the most part, the game will follow the standard Stratego rules, al-" << endl;
   cout << "though there are some exceptions." << endl;
   
   cout << "1.\tBoth players (BLUE and RED) will have all of their 10 game pieces as-" << endl;
   cout << "  \tsigned randomly with the only requirement being that the FLAG must be" << endl;
   cout << "  \tplaced in the back row. RED will start the game first." << endl;

   cout << "2.\tHigher ranked pieces can capture lower ranked pieces in the following" << endl;
   cout << "  \torder: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> S, meaning that 1 (the" << endl;
   cout << "  \tMARSHAL) can remove 2 (the GENERAL) and so forth. The MINER (8) piece" << endl;
   cout << "  \tmay strike a BOMB and remove it to occupy the now unoccupied space. A" << endl;
   cout << "  \tSPY (S), although the lowest ranked piece, may remove the MARSHAL (1)" << endl;
   cout << "  \tor the GENERAL (2). When pieces have equal rank, then both pieces are" << endl;
   cout << "  \tremoved." << endl;
   
   cout << "3.\tThe FLAG and BOMBs are not moveable while all of the other pieces may" << endl;
   cout << "  \tmove one square at a time forward, backward, or sideward, but not di-" << endl;
   cout << "  \tagonally to an open square." << endl;
   
   cout << "4.\tA player must either move or strike on his/her turn." << endl;
   
   cout << "5.\tThe game ends when a player strikes his/her opponent's flag." << endl;
   
   cout << endl << endl << "------" << endl;
   cout << "BEGIN: " << endl;
   cout << "------" << endl;
   
   return;
}

void printStudentInformation()
{
	//Student Information
   cout << endl << "**************************************************" << endl;
   cout << "        Computer Science and Engineering        " << endl;
   cout << "        CCSCE 1030 - Computer Science I         " << endl;
   cout << "   Pavan Kumar Govu pkg0033 pkg0033@my.unt.edu  " << endl;
   cout << "**************************************************" << endl << endl;	
	
   return;
}

void displayBoard(piece pieces[][columns], int height, bool reveal)
{
   char character;//stores the colored,character version of the piece

   //display the playing board
   cout << endl << "    1 2 3 4 5" << endl; 
   cout << "  +-----------+" << endl; 
   for(int row=0; row<rows; row++)
   {
      cout << static_cast<char>(row+65) << " | ";//0+65=65 (ASCII Value of 'A')
      for(int column=0; column<height; column++)
      {
         if(reveal==true&&row<2)//reveal computer's pieces
         {
            character=static_cast<char>((pieces[row][column].rank));
         } 
         else if(reveal==false&&row<2)//hide computer's pieces
         {
            character='X';
         }
         else//always show user's pieces
         {
            character=static_cast<char>((pieces[row][column].rank));
         }
         if(pieces[row][column].color==BLUE)//blue character
         {
            /*printf("\033[1;34m%c\033[0m", static_cast<char>(character));
            cout << " ";*/
            cout << character << " ";
         }
         if(pieces[row][column].color==RED)//red character
         {
            /*printf("\033[1;31m%c\033[0m", static_cast<char>(character));
            cout << " ";*/
            cout << character << " ";
         }
         if(pieces[row][column].color==NONE)//blank space
         {
            cout << character << " ";
         }
      }
      cout<<"|"<<endl;
   }
   
   cout << "  +-----------+" << endl;

   return;
}