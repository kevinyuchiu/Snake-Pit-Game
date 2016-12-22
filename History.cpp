#include "History.h"
#include <iostream>
using namespace std;
History::History(int nRows, int nCols)
{
	m_Rows = nRows;
	m_Cols = nCols;
	for (int r = 0; r < m_Rows; r++)
	{
		for (int c = 0; c < m_Cols; c++)
			Grid[r][c] = 0;
	}
}

bool History::record(int r, int c)
{
	if (r > m_Rows || c > m_Cols || r < 1 || c < 1)
		return false;
	else
		Grid[r-1][c-1]++;
	return true;
}

void History::display() const
{
	char RealGrid[MAXROWS][MAXCOLS];
	for (int r = 0; r < m_Rows; r++)
	{
		for (int c = 0; c < m_Cols; c++)
		{
			if (Grid[r][c] >= 26)
				RealGrid[r][c] = 'Z';
			else if (Grid[r][c] == 0)
				RealGrid[r][c] = '.';
			else if (Grid[r][c] > 0 && Grid[r][c] < 26)
				RealGrid[r][c] = (Grid[r][c] + 64);
		}
	}
	clearScreen();
	for (int r = 0; r < m_Rows; r++)
	{
		for (int c = 0; c < m_Cols; c++)
			cout << RealGrid[r][c];
		cout << endl;
	}
	cout << endl;
	
}