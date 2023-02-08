/* spreadsheet.h   */

#ifndef SPREADSHEET_H
#define SPREADSHEET_H
#include <iostream>
#include "cell.h" 

class Spreadsheet
{
public:
	Spreadsheet ();
	Spreadsheet (const int row, const int column);
	~Spreadsheet ();
	void set_cell_at (const int row, const int column, const Cell& cell); 
	Cell get_cell_at (const int row, const int column) const; 
	int get_row() const;
	int get_column() const;
	void add_row (const int row);
	void remove_row (const int row);
	void add_column (const int column);
	void remove_column (const int column);
	void swap_row (const int row1, const int row2);
	void swap_column (const int column1,const int column2);
	void free_memory (Cell** cells, const int row, const int column);
	void move_cells (Cell& c1, Cell& c2);
private:
	Cell** m_cells;
	int m_row;
	int m_column;
};

#endif // SPREADSHEET_H
