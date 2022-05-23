#include <iostream>
#include <memory>
#include "Header.h"


int main() {
	anytype_array<int> thing({ 1,2,3,5 });
	thing.pushback(3);
	std::cout << thing[1] << std::endl;
	std::cout << thing[4];
	std::cout << typeid(thing[4]).name();//this is working, but im NOT pushing correctly???
	//std::cout << thing[1] << "is the second value\n";


}