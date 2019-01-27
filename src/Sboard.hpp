#ifndef SBOARDHPP
#define SBOARDHPP

#include <fstream>

class Sboard {
	public:
		static const int SIZE = 9;
		Sboard(); 
		Sboard(std::ifstream&&);
		~Sboard();
		bool filled(int row, int col);
		bool solved();
		void fill(int row, int col, int val);
		void remove(int row, int col);
		void print();
		bool safe(int row, int col, int val);
	private:
		int nfilled;
		int **board;
		bool check_box(int, int, int);
		bool check_row(int, int);
		bool check_col(int, int);
};

#endif
