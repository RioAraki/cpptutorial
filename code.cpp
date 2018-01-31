void Increment(int& value) { // pass by reference
	value++;  
}

int main() {
	int a = 5;
	Increment(a);  
	log(a);
}

int a = 5;
int b = 8;
int& ref = a;
int& ref1; // invalid, you cant refer it to nothing
ref = b; // it means a = b, not you change the ref to reference b
//a = 8, b = 8

int a = 5;
int b = 8;
int* ref = &a // a pointer which record the memory address of a
*ref = 2 // dereference the memory address of a, and change the value to 2
ref = &b // change the pointer, points to memory address of b
*ref = 1// dereference the memory address of b, and change the value to 1
// a = 2, b = 1