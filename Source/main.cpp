#include "../Header/UR5.h"
#include <iostream>

int main()
{
	UR5 *ur = new UR5();
	// std::cout << ur.getDO() << std::endl;
	ur->movePiece(0, 0, 200);
	std::cout << "Moved to piece" << std::endl;
	ur->movePiece(3, 3, 200);
	std::cout << "Moved to corner" << std::endl;
	return 0;
	hej
}
