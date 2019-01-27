#include <iostream>

#include "Sboard.hpp"
#include "Catalog.hpp"

void solve_board(Sboard &board, int row, int col);
void explore(Sboard &board, int &row, int &col);
void congratulations();

int main() {
   Sboard board{Catalog::prompt_for_board()};
   board.print();
   std::cout << "press any button to solve!\n";
   std::cin.get();
   std::cin.get();
   solve_board(board, 0, 0);
   std::cin.get();
}

// solves the sudoku board
void solve_board(Sboard &board, int row, int col) {
   if (board.solved()) {
      congratulations();
      board.print();
   } else {
      explore(board, row, col);
      for (int val = 1; val <= Sboard::SIZE; val++) {
         if (board.safe(row, col, val)) {
            board.fill(row, col, val);
            if (col >= Sboard::SIZE - 1) {
               solve_board(board, row + 1, 0);
            } else {
               solve_board(board, row, col);
            }
            board.remove(row, col);
         }
      }
   }
}  

// finds an unassigned value in the given board. Assigns the row and column value to their 
// respective parameters if one exists.
void explore(Sboard &board, int &row, int &col) {
   while (board.filled(row, col)) {
      col++;
      if (col >= Sboard::SIZE) {
         row++;
         col = 0;
      }
   }
}

// prints congratulations message
void congratulations() {
   std::cout << "---------------------------------------------\n";
   std::cout << "+++++++++++++++|BOARD  SOLVED|+++++++++++++++\n";
   std::cout << "---------------------------------------------\n\n";
}