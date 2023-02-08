/* main_with_test.cpp  */

#include <iostream>
#include "cell.h"
#include "spreadsheet.h"

struct Test
{	
	void _set_get_value (Cell&); 
	void _set_get_color (Cell&); 
	void _to_int (Cell&);
	void _add_remove_row ();
	void _add_remove_column ();
};

int main()
{
	Cell cell("Hello", Color::black);
	Cell cell2("789", Color::red);
	Spreadsheet sp(3, 4);
	Test test;
	test._set_get_value ( cell);
	test._set_get_color (cell);
	test._to_int (cell2);

	test._add_remove_row (); 
	test._add_remove_column ();
	sp.add_row (1);
	sp.add_column (2);
	sp.swap_row (1, 2);
	sp.swap_column (2, 3);
	sp.remove_row (2);
	sp.remove_column (1);

return 0;
}

void Test::_set_get_value (Cell& cell) 
{
	if (cell.get_value() == "Hello")
	{
		std::cout<< "Good \n";
	}
	else
	{	
		std::cout<< "Failed \n"; 
	}
}

void Test::_set_get_color (Cell& cell) 
{
	if (cell.get_collor() == Color::black)
	{
		std::cout<< "Good \n";
	}
	else
	{	
		std::cout<< "Failed \n"; 
	}
}

void Test::_to_int (Cell& cell) 
{ 
	if (cell.to_int() == 789 )	
	{
		std::cout<< "Good \n";
	}
	else
	{	
		std::cout<< "Failed \n"; 
	}
}

void Test::_add_remove_row ()
{
	Spreadsheet sp(3, 2);
	sp.add_row(1);
	sp.add_row(1);
	if (sp.get_row() == 5 )	
	{
		std::cout<< "Good \n";
	}
	else
	{	
		std::cout<< "Failed \n"; 
	}
	sp.remove_row(1);
	sp.remove_row(1);
	sp.remove_row(1);
	if (sp.get_row() == 2 )	
	{
		std::cout<< "Good \n";
	}
	else
	{	
		std::cout<< "Failed \n"; 
	}
}

void Test::_add_remove_column ()
{
	Spreadsheet sp(3, 2);
	sp.add_column(1);
	sp.add_column(1);
	if (sp.get_column() == 4 )	
	{
		std::cout<< "Good \n";
	}
	else
	{	
		std::cout<< "Failed \n"; 
	}
	sp.remove_column(1);
	sp.remove_column(1);
	sp.remove_column(1);
	if (sp.get_column() == 1 )	
	{
		std::cout<< "Good \n";
	}
	else
	{	
		std::cout<< "Failed \n"; 
	}
}
