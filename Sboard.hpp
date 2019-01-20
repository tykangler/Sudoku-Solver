#ifndef SboardHPP
#define SboardHPP

static const int SIZE = 9;

class Sboard {
	private:
		int nfilled;
		int **board;
		bool check_box(int, int, int);
		bool check_row(int, int);
		bool check_col(int, int);
	public:
		Sboard() : board{new int*[SIZE]}, nfilled{0} {
			for (int i = 0; i < SIZE; i++) {
				board[i] = new int[SIZE];
				for (int j = 0; j < SIZE; j++) {
					board[i][j] = 0;
				}
			}
		} 

		~Sboard() {
			for (int i = 0; i < SIZE; i++) {
				delete[] board[i];
			}
			delete[] board;
		}

		bool filled(int row, int col) { 
			return board[row - 1][col - 1] > 0; 
		}

		bool solved() { 
			return nfilled == SIZE * SIZE; 
		}
		
		void fill(int row, int col, int val);
		void remove(int row, int col);
		void print();
		bool safe(int row, int col, int val);
};

#endif
