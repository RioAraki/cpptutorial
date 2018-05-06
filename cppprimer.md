# Some notes from reading c++prime
--------------------------------------
## Chapter 1  Getting started

basic stuff

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

Object that is initialized gets the specified value at the moment its created. Initialization and assignment are DIFFERENT in C++, not a form of assignment. There are several forms of initializations

##### list initializaion

```
int i = 0;
int units_sold = {0};
int units_sold {0};
int units_sold (0);
```
all four above mean the same
use curly brace for list initialization
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

##### Null pointers

does not point to any object. Let pointer equals to : `nullptr` (most direct approach, C++11 std), `0` (not int 0),`NULL` (old, as a preprocessor variable, as part of std::) can make a null pointer.

Recommend to initialize all pointers even with nullptr.

##### Assignment and pointers

Both reference and pointer give indirect access to other object, but the difference is that **reference is not an object** and we cannot refer a reference to a different object, we always get the object to what we initially bound.

##### Other pointer operations

Pointer could be true and false (if null).  Two pointers hold the same address if they both null.

##### void* Pointers

void*, special pointer type that holds address of any object, type of the object at that address is unknown. There are only limited things we can do with void* pointer:
	- compare with another pointer
	- pass it to or return it from a function
	- assign it to another void* pointer
	- We **Cannot** use a void* to operate on the object it addresses since we don’t know object's type and type determines operation
We use a void* pointer to deal with memory as memory rather than using the pointer to access the object stored in that memory.

#### 2.3.3 Understanding Compound Type Declarations

A single definition might define variables of different types: `int i = 1024, *p = &i, &r = i` , i is int, p is a pointer to int, r is reference to int.

##### Defining multiple variables

`int* p`, remember `int*` is not a type, `int` is. `*` just modifies the type but says nothing about any other objects that might be declared in the same statement.
`int* p1, p2`, p1 is a pointer to int, p2 is an int
`int* p1, *p2`, both are pointer
These style might be confusing, it is important to choose one  and use it consistently.

##### Pointer to pointers

pointer to pointer **!=** pointer in terms of type:
```
int i = 1024;
int *pi = &i;
int **ppi = &pi;
```

##### References to pointers

Again we cannot have a pointer to a reference, but pointer is an object, we can define a reference to a pointer.
```
int i = 42;
int *p;                 // p -> pointer to int
int *&r = p;        // r is a reference to the pointer p
r = &i;                 // r refers to pointer p, assign &i to r makes p points to i
*r = 0;                 // dereference r yields i, changes i to 0
```
syntax of `r` is wired. Easiest way to interpret is to read the definition from **RIGHT to LEFT**. `r` then `&` then `*` then `int`,  symbol closest to name of variable (`&`) has the immediate effect. Thus we know `r` is a reference. Rest of the decorator determines the type `r` refers. `*` in this case, means `r` refers to a pointer type, and `int` for int pointer.

### 2.4 Const Qualifier

`const`: Variable whose value cannot be changed. const object must be initialized as we cannot change the value of it.

##### Initialization and const

The const type means we cannot change the object, but we can use it for initialize other object. it wont bring the constness to the variable it assigned.

##### By default, const objects are local to a file

Compiler would usually replace the use of CONST to its corresponding value. When we split a program into multiple files, every file uses that const must have access to its initializer, to see the initializer, the variable must be defined in every file that wants to use the variable's value. **To avoid multiple definitions of the same variable, const variables are local to the file.** If we don’t want this, we could define const in one file and declare it in other files that use that object by using keyword `extern`
```
// from file_1.cc
extern const int bufSize = fcn();
// file_1.h
extern const int bufSize; // same var bufSize as defined in file_1.cc
```

#### 2.4.1 References to const

we can bind a reference to an object of a const type. Unlike ordinary reference, a reference to const cannot be used to change the object to which reference is bound.
```
const int ci = 1024;
//int &ri = ci; // error: binding 'const int' to reference of type 'int&' discards qualifiers
const int &ri = ci;
```
some wording, const reference == reference to const, though **technically speaking there isnt a const reference since reference is not an object.**

##### Initialization and references to const

**We can initialize a reference to const from any expression that can be converted to the type of the reference. In particular, we can bind a reference to const to a nonconst object, a literal, or a more general expression**:
```
int i = 42;
const int &r1 = i; // okconst int &r2 = 42; // ok
const int &r3 = r1 * 2; // ok
int &r4 = r * 2

double dval = 3.14;
const int &ri = dval; // valid, but must be const
```

##### A reference to const may refer to an object that is not const

Binding a reference to const to an object says nothing about whether the underlying object itself is const.
```
int i = 42;
int &r1 = i; // bound to i
const int &r2 = i; // bound to i, but cannot be used to change i
r1 = 0; //r1 is not const; i is now 0 
cout << r2; // r2 is 0, being changed cause r1 bound to i and i is assigned to 0
r2 = 0; // error: r2 is const
```

#### 2.4.2 Pointers and const

We can define pointers point to either const or nonconst types. A pointer to const may not be used to change the object to which the pointer points.
```
const double pi = 3.14;
double *ptr = &pi; // error, cannot use a plain pointer to point const
const double *cptr = &pi; // ok
*cptr = 42; // cannot assign to *cptr
```
As with reference, we can use a **pointer to const** to point to a **nonconst** object. A pointer to const says nothing about whether the object to which the pointer points is const. There is no guarantee that an object pointed to by a pointer to const won't change.

##### const pointers

Unlike references, pointers are objects, so we can have a pointer that is itself const. Indicating pointer is const by putting const after *.
```
int e = 0;
int *const pe = &e;
const double pi = 3.14;
const double *const pip = &pi;
* pe = 0; // ok, we only reset the value of the object to which curErr is bound, 
```

#### 2.4.3 Top-level const

Top-level const: The const that specifies that an object may not be changed.
Low-level const: A const that is not top-level. Integral to the type and are never ignored.

We use the term top-level const to indicate that the **pointer itself is a const**. When a pointer can point to a **const object**, we refer to that const as a low-level const. Top-level const indicates that an object itself is const. Low level const appears in the base type of compound types such as pointers or references. 
```
int i = 0;
int *const p1 = &i; // can change *p1, cannot change p1, const is top-level
const int ci = 42; // cannot change ci, const is top-level
const int *p2 = &ci; // we can change p2, cannot change *p2,const is low-level
const int *const p3 = p2 // 1st const is low-level, means the value it points to is const, 2nd const is top-level, means the pointer itself is also const
const int &r = ci; // const in reference is always low -level

i = ci; // ok, copy value of i, top-level const is ignored
p2 =p3; //ok, p2's const is low-level, since p3 is const it is satisfied.
p2 = &i; // error, i is not const, does not match p2's low level const
int &r = ci; // error: cannot bind int& to const int
const int &r2 = i; // ok: can bind const int& to plain int 
```

#### 2.4.4 constexpr and Constant Expressions

A constant expression is an expression whose **value cannot change and that can be evaluated at compile time**, such as literal. A const object that is initialized from a const expression is also a const expression.
```
const int max_files = 20; //max files is a const expression
const int limit = max_files + 1; // limit is a const expression
int staff_size =27; // staff_size is not a const expression
const int sz = get_size(); // sz not const expression
```
staff_size is initialized from a literal, but its not a const expression because it is a plain int, not a const int. Even sz is a cnst, the value of its initializer is now known until runtime, so sz not const expression

##### constexpr Variables

In C++ 11, we can ask compiler to verify that a variable is a const expression by declaring the variable in a `constexpr` declaration. Variable declared as `constexpr` are implicitly const and must be inialized by const expressions.
```
constexpr int mf = 20; //ok
constexpr int limit = mf+1; //ok
constexpr int sz = size(); // only if size is a constexpr function
```
Generally it is a good idea to use `constexpr` for vars you intend to use as constant expressions.

##### Literal types

The type we can use in a `constexpr` is called literal types, they are simple enough to have literal values. arithmetic, reference, pointer types are literal types. string types are not. There are other kinds of literal types.

Although we can define pointers and references as `constexpr`s, the objects we use to initialize them are strictly limited. We can initialize a `constexpr` pointer from the `nullptr` literal or 0. We can also point to an object remains at a fixed address.

Variables defined **inside** a function ordinarily are not stored at a fixed address. Hence we cannot use a `constexpr` pointer to point to such variables. Variables defined **outside** a function is a const expression

##### Pointers and constexpr

```
const int *p = nullptr; \\ p is a pointer to const int
constexpr int *q = nullptr; \\ q is a const pointer to int
```
p is a pointer to const, q is a const pointer. Th difference is a consequence of the fact that constexpr imposes a tpo-level const on the object it defines.
```
constexpr int *np = nullptr; // np is a const pointer to int that is null
int j = 0;
constexpr int i = 42; // type of i is const int
constexpr const int *p = &i; // p is a const pointer to the const int i
constexpr int *p1 = &j; // p1 is a const pointer to the int j
```

### 2.5 Dealing with Types

Type could get complicate, hard to spell correctly, obscure its purpose or meaning.

2.5.1 Type Aliases

Type aliases is a synonym for another type by using `typedef`
```
typedef double wages; // now wages is a type, means double
typedef wages base, *p; // base is a synonym for double, p for double*
``` 
Or by alias declaration:
```
using SI = Sales_item; SI is a synonym for sales_item
```

##### Pointers, const, and Type Aliases
```
typedef char *pstring;
const pstring cstr = 0; // cstr is a const pointer to char
const pstring *ps; // ps is a pointer to a constant pointer to char
```
the base type in these declarations is cont pstring. Type pstring is "pointer to char", so const pstring is a constant pointer to char - not a pointer to const char. So don’t just simply replace pstring to char *.

#### 2.5.2 The `auto` type specifier

Let compiler figure out the type for us by using `auto` type specifier. By implication, a variable that uses auto as its type specifier must have an initializer (otherwise compiler has no clue to deduct type). If initialize multiple variables, they must have same type.

##### Compound types, const, and auto

The compiler may adjust the type to conform to normal initialization rules:
	1. Reference: auto takes the type of object which reference refers to
	2. auto ignores top-level consts, we have to say explicitly
```
const int ci  = i, &cr = ci;
auto b = ci; // b is an int, (top level const in ci is dropped)
auto c = cr; // c is an int (cr is an alias for ci whose const is top-level)\
auto d = &i; // d is an int*
auto e = &ci; // e is const int* (& of a const object is low-level const) 
const auto f = ci; // deduced type of ci is int, f has type const int
auto &g = ci; // g is a const int&, bound to ci
auto&h = 42; // error: we cannot bind a plain reference to a literal
const auto &j = 42; // ok: we can bind a const reference to a literal
```
We can also specify we want a reference to the auto-deduced type. Top-level consts in the initializer are not ignored. **Consts are not top-level when we bind a reference to an inializer**.

#### 2.5.3 The `decltype` type specifier

Sometimes we want to define a variable with a type that the compiler deduces from an expression **but do not want to use that expression to initialize the variable**. C++ 11 introduces `decltype`, returns the type of its operand.
```
decltype(f()) sum = x; // sum has whatever type f returns.
```
compiler does not call `f`, only uses the type that such a call would return as the type of sum. `decltype` handles top-level const and references differs subtly from the way `auto` does (include top-level const and references).
```
const int ci = 0, &cj = ci;
decltype(ci) x = 0; // x has type const int
decltype(cj) y = x; // y has type const int& and is bound to x
decltype(cj) z; // error, z is a reference and must be initialized.
```
`decltype` is the only context in which variable defined as a reference is not retreated a synonym for the object to which it refer.

##### decltype and References

Some expression will cause `decltype` to yield a reference type.
```
int i = 42, *p = &i, &r = i;
decltype (r + 0) b; // ok: addition yields and int; b is an uninitiliazed int
decltype (*p) c; // error : c is int& and must be initialized
```
`r` here is a reference, if we want the type to which `r` refers, we should use `r` in an expression like `r+0` so it yields a value that has non reference type. 

The **dereference operator is an example of an expression of which `decltype` returns a reference.** When we deference a pointer, we get the object to which the pointer points. Moreover, we can assign to that object. Thus, the type deduced by `decltype (*p)` is `int&`, not plain `int`. (This explanation does not makes sense to me why it’s a reference but not that object itself.)

Enclosing the name of a variable in parentheses affect the type returned by `decltype`. The compiler would evalutate the operand as an expression. It is always in reference type.
```
int i = 42;
decltype((i))  d; // error, d is int& and must be initialized
decltype(i) e; // ok: e is an (initialized) int
```
Assignment provides reference type
```
int a = 1, b = 2;
decltype(a = b) d = a;
```

### 2.6 Defining our own data structures (`struct`)

Data structure is a way to group together related data elements and a strategy for using those data. In C++, use `class` to group data. 

#### 2.6.1 Defining the Sales_data type

Class: users will be able to access the data elements directly and must impment needed operations for themselves. We name our class `sales_data` to distinguish from `sales_item` as it does not support any operations.
```
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double_revenue = 0.0;
};
```
Need `;` in the end because we can define variables after curly bracket, though its not a good style.

##### Class Data Members

Defined in class as we define normal variables. C++ 11 supply in-class initializer. When creating objects, in class initializer will initialize the data member (or default initialize) 

#### 2.6.2 Using the Sales_data Class

Pretty basic practical code, i would skip

##### Adding two `sales_data` objects

Some practices

##### Reading data into a `sales_data` object

#### 2.6.4 Writing our own header files

In order to ensure that the class definition is the same in each file, classes are usually defined in header files.

Headers (usually) contain entities (such as class definitions and const and constexpr variables) that can be defined only once in any given file. We need to write our headers in a way that is safe even if the header is included multiple times.

##### A brief introduction to the preprocessor

Preprocessor is a program that runs before the compiler and changes the source text of our programs. `#include` is a preprocessor facility, it replaces `#include` with the content of the specified header.

**Header guards** rely on preprocessor variables which have two states `defined` or `not defined`, using keyword: 
- `#ifdef`: if the preprocessor variable is defined
- `#ifndef`: not
- `#endif`: end
- `#define`: take the name as preprocessor variable
Preprocessor variables must be unique throughout the program. We ensure uniqueness by basing the guard's name on the name of a class in the header and in uppercase.

## Chapter 3 Strings, Vectors, and Arrays

The built-in types are defined directly by C++ as they mostly are implemented directly by computer hardware. The standard library defines a number of additional types of higher-level nature that hardware does not implement directly.

### 3.1 Namespace using Declarations

`std::cin`, `::` is a scope operator, it says compiler should look in the scope of the left-hand operand for the name of the right hand operand. An easier way to use namespace members is `using` declaration.
```
using std::cin;
…
cin >> i;
```
##### Headers should not include using declarations

Because header is copied into the `include` program's text, then every program includes the same `using` declaration. As a result, a program that didn’t intend to use the specified library name might **encounter unexpected name conflicts**.

### 3.2 Library string type

String is a variable-length sequence of characters.

#### 3.2.1 Defining and initializing strings

A class defines how objects of its type can be initialized. A class may define many different ways to initialize objects of its type and each way must be distinguished from the others either by the number of initializers or by types of those initializers.

##### Direct and copy forms of initialization

When we initialize a variable using `=`, compiler copy initialize the object by copying the initializer. Otherwise, we omit the `=`, and use direct initialization.

```
string s1; //default initialization, s1 is an empty string
string s2(s1); // s2 is a copy of s1, direct initialization
string s2 = s1; // same as above, s2 copy of s1, copy initialization
string s3("value"); // s3 is a copy of string literal, not including the null terminator, direct initialization
string s4 (n, 'c'); // initialize s4 with n copies of the char 'c', direct initialization
string s5 = "hiya";  // copy
string s7 = string(10, 'c') // copy initialization
```

#### 3.2.2 Operations on strings

Class defines how objects are created and initialized, also defines the operations that objects of the class type could perform. A class could define operations that are called by name (function/ method), class. A class could also define various operator symbols (overload)
```
<<; output
>>; input
getline(string, source);
string.empty();
string.size();
s[n]; // return the reference to the char at position n in s;
s1+s2;
s1 = s2;
s1 == s2/ s1 != s2;
<,<=,>,>=;
``` 

##### Reading and Writing strings

We use iostream library and the same IO operator to read and write strings

##### Reading an unknown number of strings

Use a while loop `while (cin >> string)` and read all input to a string until the end of file

##### Using getline to read an entire line

Use getline function instead of >> when we do not want to ignore whitespace in our input.
```
while (getline(cin, line))…
```
##### The string empty and size operations

`string.empty()`: returns a bool indicating whether the string is empty
`string.size()`: returns the length of string 

##### The `string::size_type` Type

The return value of size() is actually `string::size_type`, not int or unsigned. The string class (and most other library types) defines several companion types which make it possible to **use the library types in a machine independent manner.**

`string::size_type` is unsigned, and can hold the size of any string. It might be tedious to type `string::size_type`, but we have `auto` or `decltype`.

##### Comparing strings

`string` class defines several operators to compare strings.:
- `==, !=` decides if two strings are equal or unequal
- `<, <=, >, >=` compare two strings: compare each char in strings and see which char has the greater alphabetic order

##### Assignment for strings

```
string st1(10, 'c'), st2;
st1 = st2;
```

##### Adding two strings

+=

##### Adding literals and strings

At least one side of the + operand must be string, cannot add to literals together like `"hello" + "world" (TODO: watch cherno's series for string to get an idea why)

#### 3.2.3 Dealing with the characters in a string

Often we need to deal with the individual chars in a string, so we need to know  how er gain access to the characters themselves. We have a library dealing with this, which is defined in the cctype header:
```
isalnum(c);
isalpha(c);
several more...
```

##### Use **Range-Based** for to process every char (C++ 11)
```
for (declaration : expression)
	statement
```
Expression is an object of a type that represents a sequence. Declaration defines the variable used to access the underlying elements in the sequence. Each interation variable in declaration is initialized from a value of the next element in expression.
```
string str("some thing");
for (auto &c : str)
	c = toupper(c);
```

##### Processing only some chars

There are two ways to access individual chars in a string: subscript or iterator. Subscript operator([] operator) takes a `string::size_type` which represents the index. The operator returns a reference to the char at ge given position.
```
s[0] = 'a'; // set the first char for string s
```

##### Using a Subscript for iteration
```
for (decltype(s.size())) index = 0; index != s.size() && !issace(s[index]); ++ index) {
	s[index] = toupper(s[index]);
}
```

### 3.3 Library `vector` type 

Vector is a collection of objects, all of which have the **SAME** type with associated index. A vector is often referred as a container because it contatins other objects.

Vector is a **class template**. Templates are not themselves functions or classes. Instead, they are instructions to the compiler for generating classes or functions. The process that compiler uses to create classes or functions from templates is called **instantiate**.
```
vector<int> ivec;
vector<vector<string>> file;
```
Compiler would generate two distinct types.

Note that vector is a template, **Not a type**. Types generated from vector must include the element type like `vector<int>` .

We can have vectors to hold most nonreference (reference not object) built-in types and most class types, even including vectors.

#### 3.3.1 Defining and initalizing vectors

```
vector<T> v1; // default initialization
vector<T> v2(v1); // v2 has a copy of each element in v1, direct 
vector<T> v3(n, val); // v3 has n elements with value val
vector<T> v4{a,b,c,…}; // as many elements as there are initializers, list initialization
```
##### List initializing a vector

Under C++ 11 we could list initialize a vector from a list of zero or more initial element values enclosed in curly braces. When we use the copy initialization form (when we use =), w esupply only a single initializer

##### Creating a specified number of elements
```
vector<int> ivec(10, -1); // ten int elements, each initialized to -1
```

##### Value initialization

We can usually omit the value and supply only a size, in this case the library creates a value-initialized element initializer for us. If the vector holds a bulit-in type, such as `int`, we have value 0; `string` we have null as default initialized.

Two restrictions: some classses require we always supply explicit initializer, so we cannot default initialize, then we must supply an initial element value; The second restriction is that when we supply an element with direct form not copy form
```
vector<int>vi(10); // ten elements, each initialized to 0
vector<int> vi = 10; // error, must use direct initialization to supply a size
```

##### List initializer or element count
```
vector<int> v1(10); // ten elements with value 0
vector<int> v2{10}; // 1 element with value 10
vector<int> v3(10, 1); // ten elements with value 1
vector<int> v4{10, 1}; // two elements 10 and 1
```
parentheses -> all value we supply are to be used to construct the object
curly braces -> if possible, we want to list initialize the object
```
vector<string> v5{"hi!"}; // list initialization: v5 has one element
vector<string> v6("hi!"); //error: cannot construct a vector from a string literal
vector<string> v7{10}; // ten deault-initialized elements
vector<string> v8{10, "hi!"}; // ten elements with value "hi"
```
Among v5-v8, only v5 is list initialized. In order to list initialize, the values inside braces must match the element type. **If list initialization is not possible, the compiler looks for other ways to initialize the object from the given values**.

#### 3.3.2 Adding Elements to a vector

More commonly we don’t know how many elements are there in a vector when we initialize it, so we need a method to add vector member which is called `vector.push_back(element);`

Vector grows efficiently, it is often unnecessary to define a vector of a specific size. Exception is if all the elements actually need the same value. If requiring different values, **it is usually more efficient to define an empty vector and add elements as the values at run time**.

##### Programming implications of adding elements to a vector

We cannot use a range for if the body of llop adds elements to the vector. The body of a range for must not change the size of the sequence over which it is iterating.

#### 3.3.3 Other vector operations
```
v.empty();
v.size();
v.push_back();
v[n]; // returns a **reference** to the element at position n in v
v1 =v2; v1 = {a,b,c,…};
v1 == v2; v1 != v2; // equal if two vectors have same amount of element and each pair same
<=, <, >, >=; // normal meanings using dictionary ordering
```

##### Computing a vector index

a program which uses a series of grade as input, output the grade interval with every 10 score as cluster.
```
vector<unsigned> scores(11, 0); // 11 clusters ,all starts with 0
unsigned grade;
while (cin >> grade) {
	if (grade <= 100)
		++scores[grade/10];
}
```

##### Subscripting does not add elements 

the subscript operator on vector (and string) fetches an existing element, does not add an element.

### 3.4 Introducing iterators

There is more general mechanism to access elements of string/ vectors -- iterators. All of the library containers have iterators, but only a few of the support the subscript operator. Like pointers, iterators give us **indirect access** to an object. We can use an iterator to fetch an element and iterators have operations to move from one element to another. Valid iterator denotes an element or denotes a position one past the last element in a container.

#### 3.4.1 Using iterators

We use iterator's membet `begin` and `end` to access iterator. `begin` member returns an iterator that denotes the first element, `end` denotes an iterator positioned one past the end of the container. Used as a marker indicating we have processed all elements.

##### Iterator operations
```
*iter;  // returns a `reference to the element denoted by the iterator iter
iter->mem; // dereferences iter and fetches the member 
++iter , --iter; 
iter1 == iter2 , iter != iter2;
```
We can only dereference valid iterator. Dereference invalid iterator/ off-the-end iterator has undefined behavior. 
```
string s("some string");
if (s.begin() != s.end()) {
	auto it = s.begin();
	*it = toupper(*it);
}
```
##### Moving iterators from one element to another
```
for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
	*it = toupper(*it);
```
##### Iterator types
We generally do not know and do not need to know the precise tpye of an iterator. The library types that have iterators define types named `iterator` and `const_iterator` that represent actual iterator types.
```
vector<int>::iterator it;
string::iterator it2;
vector<int>::const_iterator it3;
string::const_iterator it4;
```
##### The begin and end operations

If object is const, `begin` and `end` return a `const_iterator`, otherwise return an `iterator`.

##### Combining dereference and member access
```
(*it).empty() // dereference the iterator and calls member empty()
```

##### Some vector operations invalidate iterators
Any operations that changes the size of a vector potentially invalidates all iterators into that vector.

#### 3.4.2 Iterator arithmetic#### 3.4.2 Iterator arithmetic
Increment iterator and move the iterator one element at a time.
```
iter + n; // yields an iterator n elements forward/ backward
iter1 += n; // assign iter1 to iter1+n
iter1 - iter2; 
>, >=, <, <=; // one iterator is less than another if it refers to an element that appears in the container before the one referred to by the other iterator.
```
##### Arithmetic operations on iterators
```
auto mid = it.begin() + it.size() / 2;
if ( vi < mid) {…}
```
##### Using iterator arithmetic
binary search uses iterator arithmetic
```
auto beg = text.begin(), end = text.end();
auto mid = text.begin() + (end- beg)/2;
while (mid != end && *mid != seek) {
	if (seek < *mid)
		end =mid;
	else
		beg = mid +1;
	mif = beg + (end-beg) / 2;
}
```
### 3.5 Arrays

Similar to the library vector type but **offers a different trade off between performance and flexibility&**. An array is also a container of unnamed objects of a single type that we access by position. Unlike vector, **arrays have fixed size**. Unable to add elements to an array. Because arrays have fixed size, they sometimes offer better run-time performance for specialized applications as the cost of lost flexibility.

#### 3.5.1 Defining and initializing built-in arrays
An array declarator has the form a[d], a is the name being defined d is the dimensin of array. **The number of elements in an array is part of the array's type**. As a result, the dimension must be known at compile time, which means the dimension must be constant expression.
```
unsigned cnt = 42;
constexpr unsigned sz = 42;

itn arr[10]; // array of 10 ints
int *parr[sz];  // array of 42 pointers to int
string bad[cnt]; // error: cnt is not a const expr
string strs[get_size()]; // ok if get_size if constepxr, error otherwise
```
##### Explicitly initializing array elements

List initialize the elements in an array. We omit the dimension when we do so, the compiler infers it from the number of initializers. The number of initializers must not exceed the specified size if we specify a dimension. If too many dimensions, rest are default initialized
```
const unsigned sz = 3;
int ia1[sz] = {0,1,2}; // three ints with values 0,1,2
int a2[] = {0,1,2}; // same
int a3[5] = {0,1,2}; // equivalent to a3[] = {0,1,2,0,0}
string a4[3] = {"hi", "bye"}; // same as a4[] = {"hi","bye",""}
int a5[2] = {0,2,1}; // error
```

##### char arrays are special
Char arrays have additional form of initialization: we can initialize such array from a string literal. String literal uses double quotation mark and ends with a null terminator.
```
char a1[] = {'C','+','+'};  // list initialization ,no null
char a2[] = {'C','+','+','\0'}; // list initialization, explicit null
char a3[] = "C++"; // null terminator added automatically
const char a4[6] = "Daniel"; // error: no space for null terminator
```

##### No copy or assignment
We cannot initialize an array as a copy of another array, nor it is legal to assign one array to another.
```
int a[] = {0, 1, 2};
int a2[] = a; // error: cannot initialize one arry with another
a2 = a; // error, cannot assign one array to another
```

##### Understanding complicated array declarations
Array can hold objects of most any type like pointers. Because array is an object, we can define both pointers and references to arrays. Define arrays that hold pointers is straightforward, define a pointer or reference to an array is a bit more complicated.
```
int *ptrs[10]; // ptrs is an array of ten pointers to int
int &refs[10] = xx; // error: we cannot define an array of references
int (*Parray)[10] = &arr; // Parray points to an array of ten ints
int (&arrRef)[10] = arr; // arrRef refers to an array of ten ints 

int *(arry)[10] = ptrs; // arry is a reference to an array of ten pointers.
```
Type modifiers bind right to left. We see we define an array of size10, names it ptrs, that holds pointers to int. Reading def of Parry right to left isnt as helpful, shall rather read **from inside out**. 

#### 3.5.2 Accessing the elements of an array
We use subscript operator to access elements. We define the variable we used to define variable with type `size_t`, a machine-specific unsigned type that is guaranteed to be large enough to hold the size of any object in memory. 
```
// remind the score cluster algorithm in vector 
vector<unsigned> scores(11, 0); // 11 buckets, all initially 0
// Array version of scores
unsigned scores[11] = {};
// rest are the same
```
It is still good to use range for when we want to traverse entire array as we did in vector and string
`for (auto i: scores)`

3.5.3 Pointers and arrays

In C++ pointers and arrays are closely intertwined, when we use an array the compiler ordinarily converts the array to a pointer.

Arrays have a special property, when we use array the compiler automatically substitutes a pointer to the first element.
```
string nums[] = {"one","two","three"};
string *p = &nums[0]; // p points to the first element in nums
string *p2 = nums; // equivalent to p2 = &nums[0]

int ia[] = {0,1,2,3,4};
auto ia2 (ia);  // ia2 is an int* that points to the first element in ia
ia2 = 42; // error: ia2 is a pointer, not int
decltype(ia) ia3 = {2,3,4,5,6};  // decltype returns int array of 5
``` 

##### Pointers are iterators

Pointers that address elements in an array also support the same operations as iterators on vectors and strings
```
int arr[] = {0,1,2,3,4}
int *p = arr; // p points to the first element of arr
++p; // p points to arr[1] 

// when reaching off-the-end iterator we cannot dereference or increment it (can only get the address)
int *e = &arr[10]
for (int *b = arr; b != e; ++b) {/…/};
```
##### the library begin and end functions

Easier and safer to use pointers: use `begin` and `end` functions.
```
int ia[] = {0,1,2,3};
int *beg = begin(ia);
int *last = end(ia);

while (beg != end && *beg >= 0) {…}
```

##### Pointer arithmetic

When we add/ subtract integral value to pointer, the result is new pointer which points to the element of given number ahead of the original pointer.
```
constexpr size_t sz = 5;
int arr[sz] = {1,2,3,4,5};
int *ip = arr; // arr[0]
int *ip2 = ip + 4; // arr[4]
```
subtracting two pointers gives us the distance between those pointers. Pointers must point to elements in the same array. Result is a library type named `ptrdiff_t`, like `size_t`, is a machine-specific type. Since subtraction might yield negative distance, it is a signed intergal type.
 
##### Interaction between dereference and pointer arithmetic
```
int ia[] = {0,2,4,6,8}
int last = *(ia + 4); // ia[4]
last = *ia + 4;  // ia[0] +4
```

##### Subscripts and pointers
```
int ia[] = {0,1,2,3,4};
int i = ia[2];
int *p = ia;
i = *(p+2);

int *p = &ia[2];
int j = p[1]; // equivalent to *(p+1), same as ia[3]
int k = p[-2]; // same as ia[0]
```
Note that subscript operator bwteen array and library type such as vector/ string is different. The library types force index used with a subscript to be an unsigned value. The build-in subscript operator does not. Index used with the built-in subscript operator can be a negative value.

####  3.5.4 C-Style character strings

Warning: It is not encouraged to use C-style string as it is likely to cause bugs and many security problems, harder to use.

Char string literals are an instance of a more general construct C++ inherits from C: C style character strings. C-style strings are not a type. Instead, they are a convention for how to represent and use character strings.

##### C library string functions
```
strlen(p);  \\ return length of p, not counting the null
strcmp(p1, p2);  \\ compares p1 and p2 for equality.
strcat(p1, p2);  \\ append p2 to p1, returns p1.
strcpy(p1, p2); \\ copies p2 into p1, returns p1.
```
##### Comparing Strings
Different from how we compare library strings. We use normal relational or equality operators when compare library strings:
```
string s1 = "A string example";
string s2 = "A different string";
if (s1 < s2) // false: s2 is less than s1
```
Using relational operator on similarly defined C-style string **compares the pointer value**, not the string themselves.
```
const char ca1[] = "A string example";
const char ca2[] = "A different string";
if (ca1 < ca2) // undefined: compares two unrelated
```
To compare c-style string, we use `strcmp`
```
if (strcmp(ca1, ca2) < 0) // same as string comparison s1 < s2
```

##### Caller is responsible for size of a destination string

concatenating or copying C-style strings is also very different from the same operations on library strings
```
// library strings
string largeStr = s1 + " " + s2;

// c-style string, it would be disastrous if we miscalculated the size of largeStr
strcpy(largeStr, ca1); // copies ca1 into largestr
strcat(largeStr, " "); // adds a space at the end of largeStr
strcat(largeStr, ca2); // concatenates ca2 onto largeStr
```

#### 3.5.5 Interfacing to older code

Programs written in modern C++ may interface uses arrays or old C-style character strings. C++ library offers facilities to make the interface easier to manage.

##### Mixing library strings and C-style strings

We can initialize string from string literal. More generally, we can use a null-terminated char array anywhere we can use a string literal.
- null-terminated char array could initialize or assign a string
- null-terminated char array as string addition operation

There is no reverse way, we cannot direct use a library string when a C-style string is required, for example, there is no way to initialize a character pointer from a string, there is a string member function named c_str that we can often use to accomplish what we want
```
string s("Hello World");  // s holds hello world

char *str = s; // error: cannot initialize a char* from a string
const char *str = s.c_str*();
```
c_str() returns a C-style character string, the return type is const char because by appending or modifing this char pointer may invalidate this array.

##### Using an array to initialized a vector

We noted that we cannot initialized a built-in array from another array. Nor can we initialize an array **from** a vector. However, we can use an array to initialize a vector by specifying the address of the first and last element we wish to copy.

The specified range can be a subset of the array.
```
int int_arr[] = {0,1,2,3,4,5};
vector<int> ivec(begin(int_arr), end(int_arr));

// copies three elements int_arr[1], 2, 3
vector<int> subvec(int_arry + 1, int_arry + 4);
```
Advice: Use library types instead of arrays since pointers and arrays are error-prone. Modern C++ programs should use vectors and iterators instead of built-in arrays and pointers, and use strings rather than c-style array-based char strings.

### 3.6 Multidimensional arrays

We commonly referred multidimensional arrays are actually arrays of arrays.  We define an array whose element are arrays by providing two arrrays, the dimension of the array itself and the dimension of its elements.
```
int arr[10][20][30] = {0}
```

##### Initializing the elements of a multidimensional array
```
int ia[3][4] = {
	{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12}
};

// which is equivalent to
int ia[3][4] = {1,2,3,…,12};

// explicitly initialize only element 0 in each row
int ia[3][4] = {{ 0 },{ 4 },{ 8 }}

// only initialize row 0, remainingh are value initialized.
int ix[3][4] = {0,3,6,9};
```

##### Subscripting a multidimensional array
```
ia[2][3] = arr[0][0][0];
int (&row) [4] = ia[1];
```
We define row as a reference to an array of four ints and we bind that reference to the seocnd row in ia.

##### Using a range for with multidimentionsal arrays
```
size_t cnt = 0;
for (auto &row : ia){
	for (auto &col: row) {
		col = cnt;
		++cnt;
	}
}
```

We cannot neglect the `&` here and run the loop as:
```
for (auto row : ia) {
	for (auto col: row) {
		…
	}
}
```
Without the reference, row would be the type of element in array ia which is an array but be regarded as int* because compiler also regard array as the pointer of the first element of the array. And `auto col: row` cannot go on because it cannot iterate over an int*

##### Pointers and multidimensional arrays

As with any array, when we use the name of a multidimensional array it is auto converted to a pointer to the first element in the array. Since multidimensional array is an array of arrays the pointer type to which the array converts is **a pointer to the first inner array**.
```
int ia[3][4];  // array of size 3 with each element in array of ints of size 4
int (*p)[4] = ia;  // p points to an array of four ints
p = &ia[2];  // p now points to the last element in ia
```

Note the difference between:
```
int *ip[4];  // arry of pointers to int
int (*ip)[4]; // pointers to an array of four ints
```

Actively use `begin`, `end`, `auto`, `decltype` would make the operation to multidimensional array much easier.

##### Tpe aliases simplify pointers to multidimensional arrays
```
using int_array = int[4]; // now int[4] equals to int_array
typedef int int_array[4]; // now int[4] equals to int_array
```

### Chapter summary

Two most library types: vector, string. A string is a variable-length sequence of chars. A vector is a container of objects of a single type. 

Iterators allow indirect access of objects stored in a container. Iterator are used to access and navigate between the elements in strings and vectors.

Arrays and pointers to array provide low-level analogs to the vector and string libraries. 

## Chapter 4 Expressions

C++ provides a rich set of operators and defines what these operators do when applied to to operands of built-in type. It also allows us to define the meaning of most of the operatos when applied to operands of class types.

An expression is composed of one or more operands and yields a result when it is evaluated. The simplest form of an expression is a single literal or variable, the result if the avlue of the literal or variable. More complicated expressions are formed from an operator and one or more operands.

### 4.1 Fundamentals

#### 4.1.1 Basic concepts

Unary operators: address of (&) and dereference (*) act as one operand.
Binary operators: equality (==) and multiplication (*) act as two operands.
There is also ternary operator and even some takes unlimited number of operands.

##### Grouping operators and operands  
Understand the precedence and associativity -> order of evaluation of the operands.

##### Operand conversions
Operands are often converted from one type to another.

##### Overloaded operators
We can define most operators mean when applied to class types which is called overloaded operators. (ie: `<<`, `>>` used in io library)

##### Lvalues and Rvalues

Every expression in C++ is either an rvalue or an lvalue. Lvalue stands on the left-hand side of an assignment while rvalue stands on right side. The distinction of L/Rvalue in C++ is less simple compare to C. 

Roughly speaking, **when we use an object as an rvalue, we use the object's value (its contents), when we use an object as lvalue, we use the object's identity (its location in memory)** .

We can use an lvalue when an rvalue is required, but we cannot use rvalue when an lvalue is required. When we use an lvalue in place of an rvalue, the object's content are used.

```
int i = 1; // here we use lvalue i to create rvalue 1
int x = i; // i is lvalue, but here it is implicitly translate to rvalue

int v[3];
*(v+2)  = 4; // here  v+2 is a rvalue, but by dereference it we get a lvalue and can assign it to another rvalue.
```

#### 4.1.2 Precedence and Associativity

An expression with two or more operators is a compound expression. Precedence and associativity determine how the operands are grouped. Operands with higher precedence group more tightly than lower precedence. Accociativity  determines how to group operands with the same precedence. 

##### Parentheses override precendence and associativity

#### 4.1.3 Order of evaluation

Precedence only specifies how the operands are grouped, not about the order in which the operands are evaluated. For operator that do not specify evaluation order, it is an error for expression to refer to and change the same object, otherwise it wold have undefined behavior.
```
int i = 0;
cout << i << ++i << endl; // undefined because << does not specify i or ++i is executed first.
```
There are four operators guarantee the order in which operands are evaluated :
- `&&` logical and: guarantee left-hand operand first and right hand is evaluated only if the left-hand operand is true.
- `||` logical or
- `?:` conditional
- `,` comma

##### Order of evaluation, precedence and associativity
`f() + g()*h()+j()`: precedence guarantees g() and h() are multiplied, associativity guarantees f() is added to product of g() and h() and that the result of that addition is added to the value of j(). There is no guarantees of the order

### 4.2 Arithmetic operators
+/- as unary operator, */%, +/-

### 4.3 Logical and relational operator
`i,<,<=,>,>=,==,!=,&&,||`

##### Logical and and or operators
learnt before

##### Logical not operator
!

##### The relational operators
`<, <=, >, >=`
chaining the operator together has different meaning
```
if (i < j < k) // if k is greater than 1 or 0, equals to if ((i<j)<k)
if (i<j && j<k) // if i is smaller than j and j is smaller than k
```
##### Eqaulity tests and bool literals

### 4.4 Assignment operators
