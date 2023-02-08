/* cell.h  */
#ifndef CELL_H
#define CELL_H
#include <string>
#include <iostream>

struct Year { int year; };
struct Month { int month; };
struct Day { int day; };

struct Date
{
	Year year;
	Month month;
	Day day;
};

enum class Color { white, red, green, blue, black };

class Cell
{
private:
	std::string m_value;
	Color m_color { Color::white };
public:
	Cell () {}
	Cell (const std::string& value);
	Cell (const std::string value, Color color); 
	void set_collor (const Color col);
	void set_value (const std::string& value);
	Color get_collor () const;
	std::string get_value () const;
	int to_int ();
	void reset ();
};

#endif // CELL_H
