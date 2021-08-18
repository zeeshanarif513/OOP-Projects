#include<iostream>
using namespace std;
const int ROWS = 10;
const int COLS = 10;
void input(int[][COLS], int, int);
void display(int[][COLS], int, int);
void dlete(int[][COLS], int&, int, int);
void dlete(int[][COLS], int, int&, int);
int main()
{
	int matrix[ROWS][COLS];
	int currRows, currCols, num1, num2;
	char choice;
	cout << "Enter the no. of rows in the matrix: ";
	cin >> currRows;
	while (currRows <= 0 || currRows > ROWS)
	{
		cout << "Bad Input." << endl;
		cout << "Please enter the no. of rows between 1 and " << ROWS << " :";
		cin >> currRows;
	}
	cout << "Enter the no. of columns in the matrix: ";
	cin >> currCols;
	while (currCols <= 0 || currCols > ROWS)
	{
		cout << "Bad Input." << endl;
		cout << "Please enter the no. of columns between 1 and " << COLS << " :";
		cin >> currCols;
	}
	input(matrix, currRows, currCols);
	cout << "Entered matrix is" << endl;
	display(matrix, currRows, currCols);
	cout << "Press C or c if you want to delete a column." << endl;
	cout << "Press R or r if you want to delete a row." << endl;
	cin >> choice;
	switch (choice)
	{
	case 'R': case 'r':
		cout << "Enter row number: ";
		cin >> num1;
		while (num1 < 0 || num1 >= currRows)
		{
			cout << "Bad Input." << endl;
			cout << "Please enter the no. of row between 0 and " << currRows - 1 << " :";
			cin >> num1;
		}
		dlete(matrix, currRows, currCols, num1);
		cout << "Array after deletion: " << endl;
		display(matrix, currRows, currCols);
		break;
	case 'C': case 'c':
		cout << "Enter col number: ";
		cin >> num1;
		while (num1 < 0 || num1 >= currCols)
		{
			cout << "Bad Input." << endl;
			cout << "Please enter the no. of column between 0 and " << currCols - 1 << " :";
			cin >> num1;
		}
		dlete(matrix, currRows, currCols, num1);
		cout << "Array after deletion: " << endl;
		display(matrix, currRows, currCols);
		break;
	}
	system("pause");
	return 0;
}
void input(int array[][COLS], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			cout << "Enter element at matrix[" << i << "][" << j << "]: ";
			cin >> array[i][j];
		}
	}
}
void display(int array[][COLS], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			cout << array[i][j] << '\t';
		}
		cout << endl;
	}
}

void dlete(int array[][COLS], int& row, int col, int n)
{
	int i, j;
	for (i = n; i <row; i++)
	{
		for (j = 0; j < col; j++)
		{
			array[i][j] = array[i + 1][j];
		}
	}
	row--;
}
void dlete(int array[][COLS], int row, int& col, int n)
{
	int i, j;
	for (i = n; i < col; i++)
	{
		for (j = 0; j < row; j++)
		{
			array[j][i] = array[j][i + 1];
		}
	}
	col--;
}

