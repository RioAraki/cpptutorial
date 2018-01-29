# include <iostream>
# include "Log.h"

int main() {

	int a = 8;
	a++;
	const char* string = "Hello";

	for (int i = 0; i < 5; i++) {
		const char c = string[i];
		std::cout << c << std::endl;
	}

	Log("Hello World!");
	std::cin.get();
}