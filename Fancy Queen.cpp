// Dai, Fanng
// Dumb Queen

#include <iostream>
using namespace std;

// Returns true if the board configuration is ok.  You must check all of the queens, not just one.
bool ok( int q[ ][8] ) 
{
    int count = 0;#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
   for (int i = 0; i < c; ++i)
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
         return false;
   return true;
}

void print(int q[]) {
   static int solution = 0;
   int i, j, k, l;
   typedef char box[5][7];   // box is now a data type: a 5x7 2D array of characters
   box bb, wb, *board[8][8]; // bb and wb are boxes (5x7 arrays).  board is an 8x8 array of pointers to boxes.
                             // You don't have to clean up the board after printing, because it's not static,
                             // so it'll be reinitialized the next time you call the funtion.

   // Fill in bb (black box) and wb (white box).  They each represent a square of the chessboard.
   // You only need to create one of each, since the chessboard can contain many pointers to the same box.
   for (i=0; i<5; i++)
      for (j=0; j<7; j++) {
         bb[i][j] = ' ';
         wb[i][j] = char(219);
      }
   
   // Create 2 more boxes to represent the queens, by drawing a picture of each queen in the 2D array.
   static box bq = { {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
                     {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),char(219),char(219),char(219),char(219),char(219),char(219)} };
               
   static box wq = { {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
                     {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      } };

   // Fill board with pointers to bb and wb in alternate positions.
   for(i=0; i<8; i++)
      for(j=0; j<8; j++)
         if((i+j)%2 == 0)
            board[i][j] = &wb;
         else
            board[i][j] = &bb;
   
   // Set up the current solution on the chessboard by placing pointers to bq and wq in the appropriate squares.
   // Place black queens on white squares and white queens on black squares, so that you will be able to see them when printing.
   // Write the code.
    for (int i = 0; i<8; i++)
    {
        for (int j = 0; j<8; j++)
        {
            if ( q[j] == i && board[i][j] == &wb )
                board[i][j] = &bq;
            if ( q[j] == i && board[i][j] == &bb )
                board[i][j] = &wq;
        }
    }


   cout << "Solution #" << ++solution << ":\n ";
   
   // Print upper border
   for (i=0; i<7*8; i++)
      cout << '_';
   cout << "\n";

   // Print the board
   for (i=0; i<8; i++)          // for each board row
      for (k=0; k<5; k++) {     // for each box row
         cout << char(179);
         for (j=0; j<8; j++)    // for each board column
            for (l=0; l<7; l++) // for each box column
               // board[i][j] is the box pointer in the ith row, jth column of the board.
               // *board[i][j] is the box being pointed to.
               // (*board[i][j])[k][l] is the kth row, lth column of the box.
               cout << (*board[i][j])[k][l];
         cout << char(179) << "\n";
      }

   // Print lower border
   cout << " ";
   for (i=0; i<7*8; i++)
      cout << char(196);
   cout << "\n\n";
}

void next(int q[], int c) {
   if (c == 8)
      print(q);
   else for (q[c] = 0; q[c] < 8; ++q[c])
      if (ok(q, c))
         next(q, c+1);
}

int main() {
   int q[8];
   next(q, 0);
   return 0;
}
    
    // For each queen on the chessboard
    // Figure out the position of the queen in that column
    for ( int row = 0; row < 8; row ++ )
    {
         for ( int col = 0; col < 8; col++ )
         {
            // Perform the 3 tests (row, up-diagonal, down-diagonal), and if any of the tests fail, return false
            if ( q[ row ][ col ] == 1) count ++;
            if ( count > 1 ) return false;
            
            // diagonal up left
            for( int i = 1; ((col - i) >= 0) && ((row - i) >= 0); i++ )
            {
                if( q[ row - i ][ col - i ] == 1 && q[ row ][ col ] == 1 ) 
                    return false;
            }
            
            // diagonal down left
            for( int j = 1; ((col - j) >= 0) && ((row + j) < 8); j++ )
            {
                if( q[ row + j ][ col - j ] == 1 && q[ row ][ col ] == 1 ) 
                    return false;
            }
         }
         // reset count for different row
         count = 0;
    }
   // Return true after all of the tests pass for every queen
    return true;
}

void print(int q[ ][8]) 
{
   static int solution = 0;
   cout << "Solution #" << ++solution << ":\n";
   for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j)
         cout << q[i][j];
      cout << "\n";
   }
   cout << endl;
}

int main() {
   int q[8][8] = {};
   // i0 is the position of the queen in column #0, i1 is the position of the queen in column #1, etc.
   // You are testing all 8^8 possible board configurations (with the restriction of 1 queen per column),
   // as opposed to the backtracking version where you test only a small portion of the board configurations.
   for (int i0 = 0; i0 < 8; ++i0)
      for (int i1 = 0; i1 < 8; ++i1)
         for (int i2 = 0; i2 < 8; ++i2)
            for (int i3 = 0; i3 < 8; ++i3)
               for (int i4 = 0; i4 < 8; ++i4)
                  for (int i5 = 0; i5 < 8; ++i5)
                     for (int i6 = 0; i6 < 8; ++i6)
                        for (int i7 = 0; i7 < 8; ++i7) {
                            // Place the 8 queens on the chessboard:
                            q[i0][0] = 1; // place a queen in position i0 of column 0
                            q[i1][1] = 1; // place a queen in position i1 of column 1
                            q[i2][2] = 1; // ...
                            q[i3][3] = 1;
                            q[i4][4] = 1;
                            q[i5][5] = 1;
                            q[i6][6] = 1;
                            q[i7][7] = 1;
                           
                            if (ok(q))
                                print(q);
                           
                           // Remove the 8 queens from the chessboard:
                            q[i0][0] = 0;              // remove a queen from position i0 of column 0
                            q[i1][1] = 0;              // remove a queen from position i1 of column 1
                            q[i2][2] = 0;             // ...
                            q[i3][3] = 0;
                            q[i4][4] = 0;
                            q[i5][5] = 0;
                            q[i6][6] = 0;
                            q[i7][7] = 0;
                            
                        }
   return 0;   
}