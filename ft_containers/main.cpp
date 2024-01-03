#include "tester/tester.hpp"
#include "containers/set.hpp"
int  main() {
	const clock_t begin_time = clock();
	global_error = 0;
	testAllVector();
	std::cout << std::endl << std::endl;
	testAllStack();
	std::cout << std::endl << std::endl;
	testAllMap(); // 2 LEAKS
	std::cout << std::endl << std::endl;
	testAllSet(); // 1 LEAKS
	std::cout << std::endl << std::endl;
	float time = float(clock () - begin_time) / CLOCKS_PER_SEC;
	std::cout << "time executed: " << time << "s" << std::endl;
	std::cout << "max time for ft : " << time * 20 << "s" << std::endl;
}
