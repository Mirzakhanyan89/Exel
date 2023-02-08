/* cell.cpp  */
#include "cell.h"

Cell::Cell (const std::string value, const Color color) 
	: m_value {value}, m_color {color}  {}
	
Cell::Cell (const std::string& value)
	: m_value {value}  {}

void Cell::set_collor (const Color color) 
{ 
	m_color = color;
}
	
void Cell::set_value (const std::string& value) 
{ 
	m_value = value; 
}
	
std::string Cell::get_value () const 
{ 
	return m_value; 
}
		
Color Cell::get_collor () const
{ 
	return m_color; 
}

int Cell::to_int () 
{
	int num {};
	for (size_t i{}; i<m_value.size(); ++i)
	{
		if (m_value[i] >= '0' and m_value[i] <= '9')
		{
			num = 10 * num + (m_value[i] - '0');
		}
		else
		{
			std::cout<< "It isn't integer.";
			return -1;
		}
	}
	return num;
}
	
void Cell::reset ()
{
	m_value = "";
	m_color = Color::white;
}

std::ostream& operator<< (std::ostream& os, const Color color)
{
	if (color == Color::white) 
	{
		os << "white";
	}
	if (color == Color::red) 
	{
		os << "red";
	}
	if (color == Color::green) 
	{
		os << "green";
	}
	if (color == Color::blue) 
	{
		os << "blue";
	}
	if (color == Color::black) 
	{
		os << "black";
	}
	return os;
}
