//13. Find a Sudoku puzzle in the local newspaper. Write a program to solve the puzzle.
//
//
#include<iostream>
using namespace std;
#define UNDEFINED 0
#define N 9

bool findUnassignedLocation(int grid[N][N], int &row, int &col){
	for(row = 0; row < N ; row++){
		for(col=0;col<N;col++){
			if(grid[row][col]==UNDEFINED)
				return true;
		}
	}
	return false;
}

bool isUsedInRow(int grid[N][N], int row, int num){
	for(int col=0;col<N;col++){
		if(grid[row][col]==num){
			return true;
		}
	}
	return false;
}
bool isUsedInCol(int grid[N][N], int col, int num){
	for(int row=0;row<N;row++){
		if(grid[row][col]==num){
			return true;
		}
	}
	return false;
}
bool isUsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(grid[i+boxStartRow][j+boxStartCol]==num){
				return true;
			}
		}
	}
	return false;
}

bool isNumSafe(int grid[N][N], int row, int col, int num){
	//check in row
	return 
		!isUsedInRow(grid,row,num) &&
		!isUsedInCol(grid,col,num) &&
		!isUsedInBox(grid,row-row%3,col-col%3,num) &&
		grid[row][col]==UNDEFINED;
}
// print the grid
void printGrid(int grid[N][N]){
        for (int row = 0; row < N; row++){
                for (int col = 0; col < N; col++)
                        cout << grid[row][col] << " ";
                cout << endl;
        }
}
//sudoku solver
bool solveSudoku(int grid[N][N]){
	int row, col;
	//check if there is unassigned location 
	if(!findUnassignedLocation(grid,row,col)){		
		return true; // success
	}
	
	for(int num=1;num<=9;num++){
		// check if the number has conflict at row col
		if(isNumSafe(grid,row, col, num)){
			grid[row][col]=num;
			
			//cout << "##### next step ######" << endl ;
			//printGrid(grid);
			//cout << endl;

			if(solveSudoku(grid))
				return true;

			grid[row][col]=UNDEFINED;
		}
	}
	return false;
}
int main(){
	int grid[N][N] = 
		{{3, 0, 6, 5, 0, 8, 4, 0, 0},  
        {5, 2, 0, 0, 0, 0, 0, 0, 0},  
        {0, 8, 7, 0, 0, 0, 0, 3, 1},  
        {0, 0, 3, 0, 1, 0, 0, 8, 0},  
        {9, 0, 0, 8, 6, 3, 0, 0, 5},  
        {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
		{1, 3, 0, 0, 0, 0, 2, 5, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 7, 4},  
		{0, 0, 5, 2, 0, 6, 3, 0, 0}};
	if(solveSudoku(grid)==true){
		printGrid(grid); 
	}
	else {
		cout << "Grid can't be solved" << endl;
	}
	return 0;
}
