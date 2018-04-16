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

char literal in '', string literal in "" which is an array of constant chars and compiler would append a null character '/0' to the end of string literal
Escape sequence for some nonprintable chars (eg: newline -> \n)

##### Specifying the type of a literal

override the default type of an int, float point or char (eg: u8"hi!")

##### Boolean and pointer literals

the word true and false are literals of type bool, the word nullptr is a pointer literal

### 2.2 Variables

named storage our program can manipulate. Each variable has a type, which determines the size and layout of the variable's memory, the set of operations that can be applied. variable and objects in C++ are interchangable. (object: a region of memory that has a type)

#### 2.2.1 Variable definitions

simple definition: type specifier, variable names, semicolon.
library type (std::)

##### Initializers

Object that is initialized gets the specified value at the moment its created. Initialization and assignment are DIFFERENT in C++, not a form of assignment. There are several forms of initializations on same type but with different meaning

##### list initializaion

`int units_sold = {0}` : use curly brace for list initialization
In C++ 11, list initialization would cause error if initializer lead to loss of information, eg: 
```
long double ld = 3.1415926
int a {ld} // error: narrwing conversion required, long to int is likely to lose data
int c (ld) // ok: value will be truncated
```

##### default initializaion

define a variable without initializer, the variable is default initialized and have default value (depends on type and where the variable is defined). Variable defined **outside any function** body are initialized to zero. **Inside function** -> uninitialized, value of uninitialized is undefined. It is an error to copy or try to access the value of a variable whose value is undefined.

The class decides if we can define objects of that type without an initializer. If we can, the class determines what value the resulting object will have. Most classes let us define objects without explicit initializers such classes supply an appropriate default value for us. Some classes require every object be explicitly initialized. Compiler would complain if not.

#### 2.2.2 Variable declarations and definitions

separate compilation: split program into several files, each of which compiled independely. (think about library). to support separate compilation, we have declaration and definition:
declaration: make the name known to the program, specifiy var name and type -> **extern** keyword to not provide explicit initializer.
definition: creates the associated entity. definition IS a declaration, it includes a explicit initializer.

static typing: types are checked at compile time -> type checking. 

#### 2.2.3 Identifiers

how to name your variable: letters, digits, underscore. Must begin with underscore or letter. Case sensitive. Don't use the same name as keywords (char, long). identifiers outside a function may not begin with undersocre. No two consecutive underscore.

##### Conventions for variable names

variable name: lowercase, aa_bb/ aaBb if with multiple words
classes: begin with uppercase

#### 2.2.4 Scope of a name

global scope: accessible throughout the program
block scope: in the range of bracket

##### Nested scope

scope can contain other scope, inner scope/ outer scope
```
int a = 42;
int main() {
	print a; // output 42
	int a = 100; // new local object
	print a; // output 100, refer to local a
	print ::a; // explicitly refer to global a
}
```
in practice, almost always a bad idea to defind a local variable with the same name as a global variable

### 2.3 Compound Types

compound type is a type defined in terms of another type -> References and pointers. As weve seen beofre, declaration is a base type + list of declarators, each  declarator names a variable and give the variable a type that is related to the base type.

#### 2.3.1 References

A reference defines an alternative name for an object. A reference type "refers to" another type. A reference ** bind** to the original initial object. There is **NO** way to rebind a reference to refer to a different object. A reference is an alias. Reference is **NOT** an object. We may not define a reference to a reference.

#### 2.3.2 Pointers

A pointer is a compound type that "points to" another type, used for indirect access to other objects. Pointer is an object in its own right. Pointers can be assigned and copied. Single pointer can point to several different objects over lifetime. Pointer need **NOT** be initialized at the time it is defined. Pointers defined at block scope have undefined value if they are not initialized.

##### Taking the address of an object

Pointer holds address of another object by using address-of operator (&). Here the & is different from reference. Still type must match,
```
int ival = 42;
int *p = &ival; // p holds address of ival; p is a pointer to ival
```
we cannot define a pointer to a reference as refernce is not object and does not have memory address. Types of the pointer and the object it points must match.

##### Pointer value

the value stored in a pointer can be in one of the four states:
	1. point to an object
	2. point to the location just immediately past the end of an object
	3. null pointer (not bound to any object)
	4. invalid (error to copy or access, uninialized variable)

##### Using a pointer to access an object

when a pointer points to an object, use the **derefernce** operator (*) to access the object. We may only dereference a valid pointer that points to an object

##### Null pointer
