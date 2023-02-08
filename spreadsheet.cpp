/* spreadsheet.cpp   */
#include "spreadsheet.h"
#include "cell.h"

Spreadsheet::Spreadsheet () 
{
	m_cells = nullptr;
}

Spreadsheet::Spreadsheet (const int row, const int column)
	: m_row {row}, m_column {column} 
{
	if (row < 1)
	{
		m_row = 1;
	}
	if (column < 1)
	{
		m_column = 1;
	}
	m_cells = new Cell*[m_row];
	for (size_t i{}; i<m_row; ++i)
	{
		m_cells[i] = new Cell[m_column];
	}
}

Spreadsheet::~Spreadsheet () 
{
	free_memory (m_cells, m_row, m_column);
}

void Spreadsheet::set_cell_at (const int row, const int column, const Cell& cell) 
{
	if (row >= 0 and row < m_row and column >= 0 and column < m_column) 
	{
		m_cells[row][column] = cell;
	}
	else
	{ 
		std::cout<< "you cann't refer to that cell (set_cell_at).\n";
	}
}

int Spreadsheet::get_row() const
{
	return m_row;
}

int Spreadsheet::get_column() const 
{
	return m_column;
}

Cell Spreadsheet::get_cell_at (const int row, const int column) const
{ 
	if (row < 0 or row >= m_row or column < 0 or column >= m_column)
	{
		std::cout<< "You cant refer to that cell, it's not m_cells place.(get_cell_at) \n";
	return m_cells[0][0];
	}
	return m_cells[row][column];
}

void Spreadsheet::add_row (const int row) 
{
	if (row < 0 or row > m_row)
	{
		std::cout<< "You cant ade that row, it's not m_cells place.(add_row) \n";
	}
	else
	{
		// Allocation for new Cell** tmp
		++m_row;
		Cell** tmp { new Cell*[m_row] };
		for (size_t i{}; i<m_row; ++i)
		{
			tmp[i] = new Cell[m_column];
		}
		// Initialization for new Cell** tmp
		for (size_t i{}; i<m_row; ++i)
		{
			for (size_t j{}; j< m_column; ++j)
			{
				if (i == row)
				{
					tmp[i][j].set_value("");
				}
				else if (i < row)
				{
					tmp[i][j] = m_cells[i][j];
				}
				else if (i > row)
				{
					tmp[i][j] = m_cells[i-1][j];
				} 
			}
		}
		free_memory (m_cells, m_row-1, m_column);
		m_cells = tmp;
	}
}
void Spreadsheet::remove_row (const int row) 
{
	if (row < 0 or row >= m_row)
	{
		std::cout<< "You cant remove that row, it's not m_cells place.(remove_row) \n";
	}
	else
	{
		// Allocation for new Cell** tmp
		--m_row;
		Cell** tmp { new Cell*[m_row] };
		for (size_t i{}; i<m_row; ++i)
		{
			tmp[i] = new Cell[m_column];
		}
		// Initialization for new Cell** tmp
		for (size_t i{}; i<m_row+1; ++i)
		{
			for (size_t j{}; j< m_column; ++j)
			{
				if (i == row)
				{
					break;
				}
				else if (i < row)
				{
					tmp[i][j] = m_cells[i][j];
				}
				else if (i > row)
				{
					tmp[i-1][j] = m_cells[i][j];
				}
			}
		}
		free_memory (m_cells, m_row+1, m_column);
		m_cells = tmp;
	}
}

void Spreadsheet::add_column (const int column) 
{
	if (column < 0 or column >= m_column)
	{
		std::cout<< "You cant add that row, it's not m_cells place.(add_column) \n";
	}
	else
	{	
		// Allocation for new Cell** tmp
		++m_column;
		Cell** tmp { new Cell*[m_row] };
		for (size_t i{}; i<m_row; ++i)
		{
			tmp[i] = new Cell[m_column];
		}
		// Initialization for new Cell** tmp
		for (size_t i{}; i<m_row; ++i)
		{
			for (size_t j{}; j< m_column; ++j)
			{
				if (j == column)
				{
					tmp[i][j].set_value("");
				}
				else if (j < column)
				{
					tmp[i][j] = m_cells[i][j];
				}
				else if (j > column)
				{
					tmp[i][j] = m_cells[i][j-1];
				} 
			}
		}
		free_memory (m_cells, m_row, m_column-1);
		m_cells = tmp;
	}
}

void Spreadsheet::remove_column (const int column) 
{
	if (column < 0 or column >= m_column)
	{
		std::cout<< "You cant remove that column, it's not m_cells place.(remove column) \n";
	}
	else
	{	
		// Allocation for new Cell** tmp
		--m_column;
		Cell** tmp { new Cell*[m_row] };
		for (size_t i{}; i<m_row; ++i)
		{
			tmp[i] = new Cell[m_column];
		}
		// Initialization for new Cell** tmp
		for (size_t i{}; i<m_row; ++i)
		{
			for (size_t j{}; j< m_column +1; ++j)
			{
				if (j == column)
				{
					break;
				}
				else if (j < column)
				{
					tmp[i][j] = m_cells[i][j];
				}
				else if (j > column)
				{
					tmp[i][j-1] = m_cells[i][j];
				} 
			}
		}
		free_memory (m_cells, m_row, m_column+1);
		m_cells = tmp;
	}
}

void Spreadsheet::swap_row (const int row1, const int row2)
{
	if (row1 < 0 or row1 >= m_row or row2 < 0 or row2 >= m_row or row1 == row2)
	{
		std::cout<< "You cant refer to that rows, (or not e sense swap the same element) it's not m_cells place.(swap_row) \n";
	}
	else
	{
		int min = row1 >= row2 ? row1 : row2;
		int max = row1 >= row2 ? row1 : row2;
		for (size_t i{}; i<m_row; ++i)
		{
			if (i == min)
			{
				for (size_t j{}; j<m_column; ++j)
				{
					move_cells (m_cells[i][j], m_cells[max][j]);
				}
			}
			continue;
		}
	}
}

void Spreadsheet::swap_column (const int column1, const int column2) 
{
	if (column1 < 0 or column1 >= m_column or column2 < 0 or column2 >= m_column or column1 == column2)
	{
		std::cout<< "You cant refer to that column, (or not e sense swap the same element) it's not m_cells place.(swap_column) \n";
	}
	else
	{
		int min = column1 > column2 ? column1 : column2;
		int max = column1 > column2 ? column1 : column2;
		for (size_t i{}; i<m_row; ++i)
		{
			for (size_t j{}; j<m_column; ++j)
			{
				if (j == min)
				{	
					move_cells (m_cells[i][j], m_cells[i][max]);
					break;
				}
			}
		}
	}
}

void Spreadsheet::free_memory (Cell** cells, const int row, const int column)
{	
	for (size_t i{}; i< row; ++i)
	{
		delete[] cells[i]; 
	}
	delete[] cells;
	cells = nullptr;
}

void Spreadsheet::move_cells (Cell& c1, Cell& c2)
{
	std::string tmp = c1.get_value();
	c1.set_value(c2.get_value());
	c2.set_value(tmp);

	Color tmp1 = c1.get_collor();
	c1.set_collor(c2.get_collor());
	c2.set_collor(tmp1);
}


