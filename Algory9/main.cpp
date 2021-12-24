#include <iostream>
#include "class.h"

int main()
{
	Triangle one{ Point(2,3), Point(1,1), Point(-3,4) };		//area - 5.5
	Triangle two{ Point(2,3), Point(1,2), Point(-3,4) };		//area - 3

	std::cout << two.getPerimeter();
	std::cout << std::endl;
	std::cout << two.getSemiPerimetr();
}