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


void PrintString(std::string string)
// wrong, because we create a copy of the original string, it would not affect the orginal string
void PrintString(const std::string& string)
// correct, pass by const (not modify anything) reference (same as original copy), if it is read only

const char string[7] = "Cherno" // cannot edit because of const
char* string = "Cherno" // cannot edit because it is in heap, read only memory
char string[7] = "Cherno" // can edit

const char* name = "Cherno"; //u8"Cherno" 1 byte utf 8
const wchar_t* name2 = L"Cherno"; // 2 bytes
const char16_t* name3 = u"Cherno"; // 2 bytes utf 16
const char16_t* name4 = U"Cherno"; // 4 bytes utf32

using namespace std::string_lieterals; // work after c++14
std::string name0 = "Cherno"s + " hello";
// s is an operator function that returns a standard string (no longer string literal, could modify)
const char* example = R"(Line1 
Line2
Line3
Line4)"
// ignore esacpe character

int* a = new int; // you can do two things
*a = 2; // dereference a and change its content
a = &MAX_AGE; // change which memory address it points to

const int* a = new int; // you cannot change the content of the pointer
int const* a = new int; // works the same as before
a = &MAX_AGE; // but you can change where pointer it points to

int* const a = new int; // you cannot change the pointer itself
*a = 2; // but you can change the content of pointer

const int* const a = new int; // both

ClassName() : variable_name("Unknown") {}
Entity() : m_Name("Unknown"), m_Score(0) {}

if (level > 5)
	speed = 10;
else
	speed = 5;
// ternary operator
speed = level > 5 ? 10 : 5
speed = level > 5 ? level > 10 ? 15 : 10 : 5 

//stack
Entity entity;
Entity entity = Entity("Cherno");
Entity entity("Cherno");

//heap
Entity* entity = new Entity("Cherno");
// the pointer points to the location on the heap where the entity object is being allocated

class Entity {
private:
	std::string m_Name;
	int m_Age;
public:
	explicit Entity(const std::string& name)
		: m_Name(name), m_Age(-1) {}
	Entity(int age)
		: m_Name("Unknown"), m_Age(age) {}
};

void PrintEntity(const Entity& entity) {}

int main() {
	PrintEntity(33); // invalid, explicit keyword
	PrintEntity("Cherno"); // invalid, "cherno" here is a string literal, not a string
	PrintEntity(std::string("Cherno")); // valid 

	Entity a = "Cherno";
	Entity b = 22;
}