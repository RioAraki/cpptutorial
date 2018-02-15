enum Example: unsigned char {
	A, B, C // A = 0, B = 1, C =2
}

int example[5];
int* ptr = example

example[2] = 5;
*(ptr + 2) = 6;
// ptr + 2 means add 2 * datatype size, in this case it moves 8 bytes forward 


int example[5];
// ends when we finish current function
int* another = new int[5];
// on heap, end when we finish the whole program
delete[] another

sizeof(example) / siezeof(int) // only use with stack based array

std::string name = "Cherno" + " hello!"; // we cannot do this because we try to add two const char arrays, we cant add two pointers together

std::string name = "Cherno";
name += "hello!"; //name is a string, not a pointer here; += is a method overloaded in string library to let you do concatenation

std::string name = std::string("Cherno") + "hello!";
// calling a string constructor in this way, "cherno" becomes a string, not a pointer