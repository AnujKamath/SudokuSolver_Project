#include<iostream>
using namespace std;
void print(int table[9][9]) //to print the solved Sudoku table
{
    cout<<"The Answer is ="<<endl;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<" "<<table[i][j];
            if(j==2||j==5)
                cout<<"  | ";
        }
        cout<<"\n";
        if(i==2||i==5)
        {for(int k=0;k<27;k++)
                cout<<"_";
        cout<<"\n";}
    }
}
bool check(int num,int table[9][9],int row, int col)
{
    /*to check whether the number num satisfies the
    condition to be inserted in the position(row,column)
    of the table for the number to be inserted in the position(row,column)
    the value of num should not be present in the same row, column
    and the grid*/

    for(int i = 0;i < 9;i++)//checks the column
		if (table[row][i] == num)
			return false;
	for(int i = 0;i < 9;i++)//checks the row
		if (table[i][col] == num)
			return false;

	int startrow = row - row % 3;
	int startcol = col - col % 3;

    /*starting row and column position of the grid
    where the element will be inserted*/

	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 3;j++)
			if (table[i + startrow][j + startcol] == num)
				return false;
    return true;
}

bool search_empty(int table[9][9], int& row, int& col)
{
    /*searches for empty or unassigned element in the table
    and stores its position in the variable row and col*/
	for (row = 0; row < 9; row++)
		for (col = 0; col < 9; col++)
			if (table[row][col] == 0)
				return true;
	return false;//if no spot is empty or unassigned
}
bool solveSudoku(int table[9][9])
{
    int row,col;
    if(!search_empty(table, row, col))
		return true;/*successfully solved the sudoku table since no empty location is available*/
    for(int num = 1; num <= 9; num++)
	{
		if(check(num,table, row, col))
		{
			table[row][col] = num;
			if(solveSudoku(table))
				return true;
		}
		table[row][col] = 0;//unassigns the location
	}
	return false;
}

int main()
{
    int table[9][9]={  { 3, 0, 6,  5, 0, 8,  4, 0, 0 },
                       { 5, 2, 0,  0, 0, 0,  0, 0, 0 },
                       { 0, 8, 7,  0, 0, 0,  0, 3, 1 },

                       { 0, 0, 3,  0, 1, 0,  0, 8, 0 },
                       { 9, 0, 0,  8, 6, 3,  0, 0, 5 },
                       { 0, 5, 0,  0, 9, 0,  6, 0, 0 },

                       { 1, 3, 0,  0, 0, 0,  2, 5, 0 },
                       { 0, 0, 0,  0, 0, 0,  0, 7, 4 },
                       { 0, 0, 5,  2, 0, 6,  3, 0, 0 }};
    if(solveSudoku(table))
        print(table);
    else
        cout<<"No solution exists"<<endl;
    return 0;
}
