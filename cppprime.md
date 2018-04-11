# Part 1 the basics

## Chapter 2 vairables and basic types

Program's most fundamental feature:
	- built-in types
	- variables
	- expressions and statements to manipulate values of these types
	- control flow
	- functions that let us define callable units of computation

C++: type of an object determines operations. C++ checks type at compile time (Python checks type at runtime).

### 2.1 Primitive built-in types

Types determine the meaning of the data and operations in our program.

#### Arithmetic types 

Arithemetic types-> char, int, bool, float/ and void type | can also be regard as:  integral types (char, bool)/ floating-point types
Type's size may varies.

Signed and unsigned types:

	- signed: negative or positive, int/ short/ long/ long long, add unsigned to the type to get an unsigned version
	- unsigned: value >= 0, in unsigned type, all bits represent the value
	
use unsigned type if you know values cannot be negative
char could be signed or unsigned depends on computer, so caculate between char may not be a good idea.use double to do floating point calculation because float is not precise enough and cost is not that much different

#### Type conversions

Ability to convert objects of the given type to other, related types, automatically. 

#### Expressions involving unsigned types

int - unsigned -> unsigned
Bad idea: assign negative value to an unsigned type, a negative value in unsigned would turns to be really big (wrap around)

while modify the value before go into the loop (for modify value after the loop)

#### 2.1.3 Literals

Literal: its value self-evident. All literal has a type, form and value of a literal detemine its type.

##### integer and floating-point literals

decimal, octal (int begins with 0), hexadecimal (begin with 0x or 0X) notation
decimal lieteral chooses smallest type of int, long, long long in which the literal's value fits. Techincally the decimal lieteral is never negative, the negative sign is an operator.
octal/ hexadecimal chooses smallest of int, unsigned int, long, unsigned… in which it fits
These can be overrided using a suffix

##### character and character string literals


