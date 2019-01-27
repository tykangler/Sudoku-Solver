#include <fstream>
#include <iostream>

#include "Sboard.hpp"
#include "Catalog.hpp"

void solve_board(Sboard &s, int row, int col);
void explore(Sboard &s, int &row, int &col);
void congratulations();

int main() {
   Sboard s{Catalog::prompt_for_board()};
   s.print();
   std::cout << "press any button to solve!\n";
   std::cin.get();
   std::cin.get();
   solve_board(s, 0, 0);
   std::cin.get();
}

// solves the sudoku board
void solve_board(Sboard &s, int row, int col) {
   if (s.solved()) {
      congratulations();
      s.print();
   } else {
      explore(s, row, col);
      for (int val = 1; val <= Sboard::SIZE; val++) {
         if (s.safe(row, col, val)) {
            s.fill(row, col, val);
            if (col >= 8) {
               solve_board(s, row + 1, 0);
            } else {
               solve_board(s, row, col);
            }
            s.remove(row, col);
         }
      }
   }
}  

// finds an unassigned value in the given board. Assigns the row and column value to their 
// respective parameters if one exists.
void explore(Sboard &s, int &row, int &col) {
   while (s.filled(row, col)) {
      col++;
      if (col >= 9) {
         row++;
         col = 0;
      }
   }
}

// prints congratulations message
void congratulations() {
   std::cout << "---------------------------------------------\n";
   std::cout << " /\\_/\\_/\\_/\\_/\\|BOARD  SOLVED|/\\_/\\_/\\_/\\_/\\\n";
   std::cout << "---------------------------------------------\n\n";
}