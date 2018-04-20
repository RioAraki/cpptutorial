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

##### 2.5.2 The auto type specifier

