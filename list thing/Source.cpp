#include <iostream>
#include <memory>
template <typename t> class anytype_array {
private:
	t* ptr;
	int s;
public:
	anytype_array(std::initializer_list<t> list) {
		ptr = (t*)malloc(list.size() * sizeof( t));//allocates size of array, malloc, i believe, should only be used in
		// the constructor, realloc should be used in appending and shrinking array
		//ptr = (t*)realloc(ptr, sizeof(t) * (s + 1));
		int temp = 0;
		s = int(list.size());
		for (auto elem : list) {
			ptr[temp] = elem;
			temp += 1;
		};
	};
	int size() {
		return s;
	}
	void pushback(t val) {
		ptr = (t*)realloc(ptr,(s+1)*sizeof(t));//OH (t*) is to typecast into correct type!
		ptr[s] = val;//said dereferencing null pointer, does that mean im not pushing shit to this?
		// i was doing s +1 as the index which is obviously wrong because indexes start at 0 not 1
		if (!ptr) {
			std::cout << "ptr is null! error\n";
			exit(0);
		}
		s = s + 1;
		
	}
	t operator [](std::size_t index) {//returns individual values
		return ptr[index];
	};
};



int main() {
	anytype_array<int> thing({ 1,2,3,5 });
	thing.pushback(3);
	std::cout << thing[1] << std::endl;
	std::cout << thing[4];
	std::cout << typeid(thing[4]).name();//this is working, but im NOT pushing correctly???
	//std::cout << thing[1] << "is the second value\n";


}