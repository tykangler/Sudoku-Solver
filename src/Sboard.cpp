#include "Sboard.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

void print_borders();

Sboard::Sboard() : board{new int*[SIZE]}, nfilled{0} {
   for (int i = 0; i < SIZE; i++) {
      board[i] = new int[SIZE];
      for (int j = 0; j < SIZE; j++) {
         board[i][j] = 0;
      }
   }
} 

Sboard::Sboard(std::ifstream &&file) : Sboard{} {
   int row{};
   int col{};
   int val{};
   while (file >> row) {
      file >> col;
      file >> val;
      this->fill(row - 1, col - 1, val);
   }
}

Sboard::~Sboard() {
   for (int i = 0; i < SIZE; i++) {
      delete[] board[i];
   }
   delete[] board;
}

bool Sboard::filled(int row, int col) { 
   return board[row][col] > 0; 
}

bool Sboard::solved() { 
   return nfilled == SIZE * SIZE; 
}

// checks if a given value at a given row and column is a safe value
bool Sboard::safe(int row, int col, int val) {
   return check_box(row, col, val) && check_col(col, val) && check_row(row, val);
} 

// checks for a given value in the box of the given row and column 
bool Sboard::check_box(int row, int col, int val) {
   int rowstart = row - row % 3;
   for (int i = rowstart; i < rowstart + 3; i++) {
      int colstart = col - col % 3;
      for (int j = colstart; j < colstart + 3; j++) {
         if (board[i][j] == val) {
            return false;
         }
      }
   }
   return true;
}

// checks for the value in the given row
bool Sboard::check_row(int row, int val) {
   for (int i = 0; i < SIZE; i++) {
      if (board[row][i] == val) {
         return false;
      }
   }
   return true;
}

// checks for the value in the given column
bool Sboard::check_col(int col, int val) {
   for (int i = 0; i < SIZE; i++) {
      if (board[i][col] == val) {
         return false;
      }
   }
   return true;
}

// removes a value at a given row and column
void Sboard::remove(int row, int col) {
   board[row][col] = 0;
   nfilled--;
}

// fills a spot at the given row and column with the given value.
void Sboard::fill(int row, int col, int val) {
   board[row][col] = val;
   nfilled++;
}

// prints the sudoku board with all currently filled values.
void Sboard::print() {
   print_borders();
   for (int i = 0; i < SIZE; i++) {
      std::cout << '|';
      for (int j = 0; j < SIZE; j++) {
         std::cout << ' ';
         if (board[i][j] > 0) {
            std::cout << board[i][j];
         } else {
            std::cout << ' ';
         }
         std::cout << " |";
         if ((j + 1) % 3 == 0 && (j + 1) != SIZE) {
            std::cout << "   |";
         }
      }
      std::cout << '\n';
      if ((i + 1) % 3 == 0 && (i + 1) != SIZE) {
         print_borders();
         std::cout << '\n';
      }
      print_borders();
   }
}

// prints the top and bottom borders of the board.
void print_borders() {
   std::cout << '+';
   for (int j = 0; j < Sboard::SIZE; j++) {
      std::cout << "---+";
      if ((j + 1) % 3 == 0 && (j + 1) != Sboard::SIZE) {
         std::cout << "   +";
      }
   }
   std::cout << '\n';
}
