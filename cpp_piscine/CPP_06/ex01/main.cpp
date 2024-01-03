#include <iostream>

struct Data {};

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

int main() {
	Data* data = reinterpret_cast<Data*>(42);
	Data* data1 = deserialize(serialize(data));
	if (data1 == data)
		std::cout << "Same pointer : " << data << std::endl;
	else
		std::cout << data1 << std::endl;
}