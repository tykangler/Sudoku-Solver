#include <fstream>
#include <iostream>
#include "Sboard.hpp"

void fill_board(Sboard &s);
void solve_board(Sboard &s, int row, int col);
void explore(Sboard &s, int &row, int &col);
void congratulations();

int main() {
   Sboard s;
   fill_board(s);
   s.print();
   std::cout << "press any button to solve!";
   std::cin.get();
   solve_board(s, 1, 1);
   std::cin.get();
}

// fills the board with predetermined values from a text file
void fill_board(Sboard &s) {
   std::string fname;
   int row;
   int col;
   int val;
   std::cout << "Pick a sudoku file: ";
   std::cin >> fname;
   std::ifstream input(fname, std::ios::in);
   while (input >> row) {
      input >> col;
      input >> val;
      s.fill(row, col, val);
   }
}

// solves the sudoku board
void solve_board(Sboard &s, int row, int col) {
   if (s.solved()) {
      congratulations();
      s.print();
   } else {
      explore(s, row, col);
      for (int val = 1; val <= SIZE; val++) {
         if (s.safe(row, col, val)) {
            s.fill(row, col, val);
            solve_board(s, row, col);
            s.remove(row, col);
         }
      }
   }
}  

// finds an unassigned value in the given board. Assigns the row and column value to their 
// respective parameters if one exists.
void explore(Sboard &s, int &row, int &col) {
   for (int i = 1; i <= SIZE; i++) {
      for (int j = 1; j <= SIZE; j++) {
         if (!s.filled(i, j)) {
            row = i;
            col = j;
         }
      }
   }
}

// prints congratulations message
void congratulations() {
   std::cout << "-------------------------------------------------\n";
   std::cout << "DONE DONE DONE DONE DONE DONE DONE DONE DONE DONE\n";
   std::cout << "-------------------------------------------------\n";
}