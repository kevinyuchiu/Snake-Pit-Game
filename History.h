#ifndef History_Here
#define History_Here
#include "globals.h"
class History
{
public:
	History(int nRows, int nCols);
	bool record(int r, int c);
	void display() const;
private:
	int m_Rows;
	int m_Cols;
	int Grid[MAXROWS][MAXCOLS];
};
#endif