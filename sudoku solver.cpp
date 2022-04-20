#include <iostream>

using namespace std;

// N je velicina 2D matrice (N*N)
#define N 9

// ispis matrice
void print(int arr[N][N]){
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

// Proverava da li se moze
// dodeliti broj za dati 
// red (row) i kolonu (col)
bool isSafe(int grid[N][N], int row, int col, int num){
	
	// Proverava da li nalazimo isti broj u istom redu
	// ako da, vraca false
	for (int x = 0; x <= 8; x++)
		if (grid[row][x] == num)
			return false;

	// Proverava da li nalazimo isti broj u istoj koloni
	// ako da, vraca false
	for (int x = 0; x <= 8; x++)
		if (grid[x][col] == num)
			return false;

	// Proverava da li nalazimo isti broj u odredjenoj 3*3 matrici
	// ako da, vraca false
	int startRow = row - row % 3,
			startCol = col - col % 3;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (grid[i + startRow][j +
							startCol] == num)
				return false;

	return true;
}


bool solveSudoku(int grid[N][N], int row, int col)
{
	
	if (row == N - 1 && col == N)
		return true;

	
	if (col == N) {
		row++;
		col = 0;
	}

	
	if (grid[row][col] > 0)
		return solveSudoku(grid, row, col + 1);

	for (int num = 1; num <= N; num++)
	{
		
		
		if (isSafe(grid, row, col, num))
		{
			
		
			grid[row][col] = num;
		
			
			if (solveSudoku(grid, row, col + 1))
				return true;
		}
	
		
		grid[row][col] = 0;
	}
	return false;
}

int main()
{
	// UNOS inicijalne matrice koja treba da se resi, 0 su prazna polja
	int grid[N][N] = {{0, 0, 7, 0, 5, 2, 0, 0, 6},
                      {0, 0, 2, 7, 8, 0, 0, 0, 9},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 5, 4, 3, 1, 0, 0},
                      {0, 7, 3, 1, 9, 0, 0, 0, 0},
                      {0, 0, 0, 6, 2, 0, 0, 0, 0},
                      {0, 8, 5, 9, 0, 0, 0, 0, 0},
                      {0, 0, 0, 2, 6, 1, 8, 0, 0},
                      {2, 0, 9, 0, 0, 5, 0, 6, 7}};
	
	//
	if (solveSudoku(grid, 0, 0))
		print(grid);
	else
		cout << "no solution exists " << endl;

	return 0;
}

