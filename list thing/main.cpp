#include <iostream>
#include <memory>
#include "Die_Array.h"


int main() {
	anytype_array<int> thing({ 1,2,3,5 });
	thing.pushback(6);//functioning properly 
	std::cout << thing[1] << std::endl;
	thing.pop();//functioning properly
	thing.pushback(5);
	thing.swap(1, 4);//working
	std::cout << thing[4] << std::endl;
	


	
	//this is working, but im NOT pushing correctly??? - fixed 
	//std::cout << thing[1] << "is the second value\n";


}