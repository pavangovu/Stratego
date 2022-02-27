int main()
{
   Status shipType; // 2D game board implemented as enum type
   int maxTries; // maximum number of shots available to user
   printStudentInfo(); // display student info
   printIntro(maxTries); // print game information and get max shots
   cout << "Initializing board..." << endl;
   initBoard(board, SIZE); // initialize board
   cout << "Assigning vessels..." << endl;
   assignShips(board, SIZE, shipType); // randomly assign 2 vessels to game board
      do
      {
         printBoard(playerboard, SIZE); // print updated game board
         with 2 vessels
         torpedo();
         failure(board, maxTries);
         get(board, playerboard);
         Testingboard();
         maxTries--;
      }while( gameover == false );
   return 0;
}