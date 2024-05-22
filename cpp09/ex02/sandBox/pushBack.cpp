#include <vector>
#include <iostream>

void pushBack(std::vector<int>* v, int n) {
	v->push_back(n);
}

// error: no matching function for call to ‘std::vector<int>::push_back(int*)’
// void pushBackNew(std::vector<int>* v, int n) {
// 	v->push_back(new int(n));
// }

void pushBackNew(std::vector<int*>* v, int n) {
	v->push_back(new int(n));
}

template <typename T>
void	print(std::vector<T>* v) {
	std::cout << "___________________________________" << std::endl;
	for (typename std::vector<T>::iterator it = v->begin(); it != v->end(); ++it) {
		std::cout << "[" << &(*it) << "](" << *it << ")" << std::endl;
	}
	std::cout << "-----------------------------------" << std::endl;
}

void	pPrint(std::vector<int*>* v) {
	std::cout << "___________________________________" << std::endl;
	for (std::vector<int*>::iterator it = v->begin(); it != v->end(); ++it) {
		std::cout << "[" << &(*it) << "](" << *it << ")(" << *(*it) << ")" << std::endl;
	}
	std::cout << "-----------------------------------" << std::endl;
}

int main() {
	std::vector<int>	v1;
	pushBack(&v1, 1);
	pushBack(&v1, 2);
	pushBack(&v1, 3);

	// error: no matching function for call to ‘pushBack(std::vector<int>*, int)’
	// std::vector<int>	v2;
	// pushBackNew(&v2, 1);
	// pushBackNew(&v2, 2);
	// pushBackNew(&v2, 3);

	std::vector<int*>	v2;
	pushBackNew(&v2, 1);
	pushBackNew(&v2, 2);
	pushBackNew(&v2, 3);


	std::vector<int>*	v3 = new std::vector<int>();
	pushBack(v3, 1);
	pushBack(v3, 2);
	pushBack(v3, 3);

	std::vector<int*>*	v4 = new std::vector<int*>();
	pushBackNew(v4, 1);
	pushBackNew(v4, 2);
	pushBackNew(v4, 3);

	print(&v1);
	pPrint(&v2);
	print(v3);
	pPrint(v4);
}
