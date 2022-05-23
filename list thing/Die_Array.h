#pragma once
template <typename t> class anytype_array {
private:
	t* ptr;
	int s;
public:
	anytype_array(std::initializer_list<t> list) {
		ptr = (t*)malloc(list.size() * sizeof(t));//allocates size of array, malloc, i believe, should only be used in
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
		ptr = (t*)realloc(ptr, (s + 1) * sizeof(t));//OH (t*) is to typecast into correct type!
		ptr[s] = val;//said dereferencing null pointer, does that mean im not pushing shit to this? - fixed
		// i was doing s +1 as the index which is obviously wrong because indexes start at 0 not 1
		if (!ptr) {
			exit(139);
		}
		s = s + 1;

	}
	void pop() {
		if (!ptr) {
			exit(139);//bigger than allocated size 
		}
		else {
			ptr = (t*)realloc(ptr, (s - 1) * sizeof(t));
			s = s - 1;
		}
	};
	void swap(int index1, int index2) {
		if (ptr[index1] == NULL or ptr[index2] == NULL) {
			
			exit(139);
		}
		else {
			t temp;
			temp = ptr[index1];
			ptr[index1] = ptr[index2];
			ptr[index2] = temp;
			
		}
	};
	t operator [](std::size_t index) {//returns individual values
		if (index >= s) {
			std::cout << " exceeded array index, fuck off\n";
			exit(139);
			return NULL;
		}
		return ptr[index];
	};
};
