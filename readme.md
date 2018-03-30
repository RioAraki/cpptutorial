# A note for youtube video series: https://www.youtube.com/watch?v=18c3MTX0PK0&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb


1. Native language 通过不同的 compiler 直接翻译成 machine code，更加底层
2. linker，负责把不同 file 的 function 连接到一起，而引用一个别的 file 的 function 只需要 declaration，compiler 会无条件相信你
3. C++本质上就是text file, 而从text file 变成 exe 大抵需要两部 一是 compile 二是 linking。compiler就是把 c++ text 变为 obj file为之后link做准备的过程。
4. 有关 file 和 translation unit: c++不看重file，file只是一种满足 compiler需求的格式，而被compile后的cpp 可以称之为 translation unit，有时一个cpp file 对应一个 translation unit，而当你用一个 cpp file include 一大堆别的file时，这些东西整体被称为一个 translation unit (因为你只compile了一次)
5. 处理 header file 的过程是 preprocess 的过程，而proprocess所做的就是把 header file 直接搬运到 cpp 里，之后再对这个 cpp 做 compile。以下是几种典型的 preprocessing：
	1. #define a b, 会自动把所有的 a 改成 b
	2. #if <condition> … #endif  根据逻辑执行或者跳过代码
	3. #include <library> 把整个 library 全部放到 cpp 对应位置
6. Compile 的过程到底是什么：
	1. Obj file 到底是什么 -> machine code 二进制编码 -> 可以通过设置 output 为 Assembly only listing 将其翻译成汇编
	2. Compiler optimize: max speed -> 会把汇编文件缩小，只做最必要的步骤（不利于debug），并且会把无用的function （比如这个function所做的就是 return 一个 constant value ）忽略，直接储存 constant
	3. 当一个 function 用到 另一个 function 时汇编会用 call 命令以使用另一个function
	4. 每一个 function 有独特的 function signature 给 linker用
7. Linker 的工作过程是什么
	1. 在 compile 之后才发生
	2. 主要目的是找到所有的 symbol and function 并把它们 link在一起
	3. 因为每一个cpp compile而成的obj file彼此无法互相联系，要靠 linker 才能实现 include，即使没有 include，linker 还是需要 define entry point (main function)
	4. Compile button 只做 compile，不 link。Build project 才会既 compile 又 link
	5. 可以轻易看出 compile error 以及 linking error，所有 exe file 都需要 entry point (main function)
	6. Lnk error 2019 -> unresolved external symbol (function name/ return type/ parameter should match)
	7. 如果一个 function a 被 declare 但从未被 call 过，那哪怕 declaration 和源 function 不 match 也不会报错。而如果 function a 被declare 被用在 function b 里而 function b 从未被 call 过，那function a 还是会 有linking error
	8. Keyword static: This function is only declared for the current translation unit (it is internal, not visible to other files)
	9. Other possible linker error: duplicate function name (even function in header file)
	10. Keyword inline: put the function body with parameter into where it is called directly.
8. Variables in C++
	1. keyword: unsigned, an integer does not have sign bit
	2. char: 1byte; short: 2 bytes; int: 4 bytes; long: usually 4 bytes;
	3. compiler will treat the value differently based on the data type 
		eg: if you have char a = 65, it would print out 'A'; short a = 'A', it would print out 65  
	4. Core difference between different data types is the bytes allocated for each unit.
	5. float & double -> if f is appended, it is a float. Otherwise it is a double
	6. Though bool only takes one 'bit' to represent 0 or 1. We still need one 'byte' to store it because we cannot manipulate one 'bit' in memory.
	7. sizeof (type) -> check the size of certain type
9. Functions in C++
	1. Basic
10. Header in C++
	1. Usually used to do the declaration that some function exists (for cross file function reference)
	2. #pragma once -> only allow you to put the header file in the same file once, the duplicate parts would be ignored to prevent duplicate error
	3. If you define same function in two different header file A and B while A and B are both included in one function, you will still get duplicate error
	4. <> and "" in include statement: 
		i. "" -> relative path, you could use something like "../ Log.h", or use as <>
		ii. <> -> refer to the default include directory
	5. C++ std lib file does not have an extension; C std lib file has an extension
11. Debug C++ in visual studio
	1. Breakpoint: a point in the program where execution would pause and let you looks at the state in the memory.
	2. Looking in the memory
	3. Debug window -> orders/ locals/ watch
		i. Orders/ locals: show you local variables or something important
		ii. Watch: let you monitor the variable by yourself
	4. Memory view: show you all memories about this program
		i. & + variable name -> let you know where this variable locates
		ii. Memory cc -> a place holder for uninitialized stack memory (ony in debug mode?)
12. Condition and branch in C++
	1. In machine code level, branch is jumping to different part of memory. Avoid branching would optimize the program.
	2. BASIC
13. Loops in C++
	1. For loop: for (int i = 0; i < 5; i++)…
		i. int i = 0 -> variable declaration, only works once before the loop begins
		ii. i < 5 -> condition check everytime before each loop
		iii. i++ -> runs everytime after each loop (before the next loop)
	2. for (; ;) -> no condition, always true
	3. while loop is just a for loop with only the condition part
	4. do while loop:  do { …… } while (i < 5) -> the body of loop would be executed at least once no matter what.
14. Control flow in c++
	1. BASIC
15. Pointers in c++
	1. a pointer is an integer variable that stores memory address
	2. we can regard memory as a linear one dimensional line, every point (unit) is going to have a number and address (one byte of data), all our code do is reading and writing from/ to memory
	3. type does not matter for pointer, if we give a pointer a type, it just means we presume the type.
	4. void* -> just hold an address, does not care about type
		i. void* ptr = 0/NULL/nullptr;
			0 is an invalid memory, means the same as null. a pointer set to 0 means its invliad
	5. & before variable -> return the variable's memory address
	6. * before pointer -> dereference the pointer, go back to the value the pointer stores 
			Example:
			int var = 8
			int* ptr = &var // ptr is a variable, is a pointer, reference to var variable's memory address
			*ptr = 10           // ptr is a variable, is a pointer. *ptr is a reference to the value associated with the memory address pointer points to
	7. we don't know how big a pointer is (how many memories it points to), we can specify the size by claiming a char* (char is one byte) = new char[8] (ask for 8 bytes of memory)
	8. memset(ptr, value, bytes) -> fill the block of memory with the data with specified, we need delete[] to delete the allocated memory from memset()
	9. pointers are still variables and are also stored in memory, so we can get pointer to pointer
16. Reference in C++
	1. a reference is a way for us to reference a existing variable, they are not new variables/ does not occupy memory/ does not have storage
	2. difference between & before variable and & after type:
		i. & before variable: represent's the variable's memory address
		ii. &after type (its part of the type): reference, alias
	3. reference is more like a syntax sugar, everything could done by a reference could be done by a pointer. It would make our life more easier and make our code looks cleaner
17. Classes in C++
	1. C++ does not force to do oop
	2. Classes allow us to group variables together to become a type, and to add functionalities which are called methods.
	3. Classes does not provide new functionalities, they are essentially syntax sugar to orgnazie our code better
18. Classes vs struct in C++
	1. Technique difference: all elements in class by default is private / struct -> default is public
	2. structs exist in C++ in order to maintain compatibility with C.
	3. Usage difference:
		i. structs: structure that’s all about variables/ variable manipulation (like a n-dimensional vector)
		ii. class: may have more functionality, and more hierarchy (like inheritance
19. Write class in c++
	1. define different visibility variable/ functions in different area
20. (+21) Statics in C++
	1. Statics outside of a class: variable is going to be linked only internally to the translation unit
		i. Cant have two global variables with the same name, we could use the keyword 'extern' -> looking for the variable in external translation unit
		ii. Since variables are by default globally visiable, we should use static as much as we can if we don't want it to be global
	2. Statics inside a class/ struct: the variable is going to share memories with all the instances of the class 
		i. with variable: there is going to be only one variable with all instances of that class, so its like they don’t belongs to the certain class instance, but the whole class name space
		ii. with methods: can be called without a class instances, cannot refer to a class instance
			1) static methods CANNOT access non static variables because a static method does not have a class instance (every methods write inside a class actually regard a class instance as a parameter) 
22. local static in C++: statics in local scope
	1. life time: how long the variable stays in our memory
	2. scope: where we can access the variable
	3. local static: the variable would last over the entire program, however the scope is limited to the function
23. enums in C++
	1. enumerations, a way to give a name to a value.
	2. Value in enum would be auto assigned, and incremented by 1 if not assigned 
24. Constructor in C++
	1. A constructor is a speical type of method which runs everytime we instantiate an object (of a class)
	2. If we instantiate an object, we don’t initialize the memory of it, and it would refer to what is orginally stored inside
	3. constructor: name must match the class, can have optional parameter
	4. We can hide a constructor if we only want people to use some static method inside but not create a class instance in two ways:
		i. make the constructor method private
		ii. constructor = delete
25. Destructor in C++
	1. for uninitialized and clean memories that you have used or declared from constructor, or you would get a memory leak
	2. syntax: ~destructor
	3. object is going to destructed automatically once the function creates it is terminated
26. Inheritance in C++
	1. hierarchy of classes which relate to each other, avoid code duplication
	2. all non private section of a mother class is accessible by child class
	3. the size of the class equal all variables it stores + all variable its mother class stores
27. Virtual Functions in C++
	1. allow us to override methods in subclasses
	2. keyword virtual: mark the method in mother class, so that a v table would be created and map all overriding methods in all child class
	3. keyword override: mark the overrided method in child class, works the same as virtual
28. Interface in C++
	1. there is a specific type of virtual function, pure virtual function 
	2. pure function allows us to define a function in base class that does not have any implementation, and force subclasses to implement that function. 
	3. interface is a class of only pure virtual function, acting as a template. Since no implemented method, we cannot instantiate an interface class
	4. syntax: virtual function() = 0   <- = 0 make a function pure virtual function 
29. Visibility in C++
	1. no effects on program's performance, purely helps you organize code
	2. three types:
		i. private: only* this class can access the variables; friend keyword -> exception 
		ii. protected: this class and all subclasses could access the variables
		iii. public: anyone could access it
30. Arrays in C++
	1. array is a collection of variables (usually for same type)
	2. array is actually a pointer type
	3. access unexist index -> memory violation error only in debug mode
	4. array stores data contiguously in memory
	5. pointer arithmetic:
	6. create arrays on heap
	7. size of array
		hard to find the actual size, can use this trick, but not on heap based array
		maintain the size by yourself, size shall be a known static const
31. strings in C++
	1. string is an array of charaters (letters/ numbers/ symbols -> text)
	2. char = 1 byte
	3. const char* string
		i. const: we need const here because we don’t want people change the value of string, it should be immutable and have fixed amount of allocated memory
		ii. char*: it does not mean its heap allocated, we don’t need to delete (only use delete when you use new)
		iii. null termniation character -> 00 in memory, '\0' in list, indicates end of string
		iv. single quote -> char; double quote -> string
	4. C++ string -> std::String
		i. it has a basic string class -> std::string
		ii. it is a const char array
		iii. has a whole bunch of useful methods (strlen/ strcpy)
		iv. string concatenation:
	5. pass string to function
32. String literals in C++
	1. anything between double quote, it is a const char array
	2. some other types
	3. string literal namespace
	4. String literals are always stores in read-only memories 
		even we modify the string, we create a new variable		
33. CONST in C++
	1. more like a "promise" that something will not change
	2. CONST's multiple usage relate to pointer:
		i. before *: you CANNOT change the content (value) of the pointer; you CAN change the pointer's memory address
		ii. after *: opposite, you CANNOT change the pointer's memory address; you CAN change the content (value) of the pointer
	3. CONST with classes and methods
		i. CONST after method name (right side), in a class: it is not going to change any member/ variables in class. Make sense with a better method
		ii. if the function in a class is not going to modify the member in class, mark it as const.
		iii. mutable keyword: even we mark a method as const so it should not change any variable in the class, we can still modify the variables by give variable a mutable keyword.
34. Mutable in C++
	1. in the context of const: same as 33/3/iii
	2. in the context of lambda: leave for later
35. Member initializer lists in C++
	1. a way to initialize class member function in the constructor
	2. if using member initializer, must initialize them in order
	3. why? : 
		i. code style, compact to read
		ii. functional difference: the members in the class would be constructed twice (1. when you declare it in the member region 2. when you give it a value in actual constructor) 
36. Ternary operators in C++
	1. syntax sugar for if statement:
37. How to create/ instantiate obbjects in C++
	1.  how do we instantiate an object: stack vs heap
		i. stack: lifetime controled by the scope, use it whenever you can
		ii. heap: lifetime forever, until manual terminate, performance worse, manually free the memory (delete)
38. The new keyword in C++
	1. main purpose of new is to allocate memory on the heap specifically based on the type and give us a pointer to that memory
	2. With classes: not only allocates memory, but also call constructor.
	3. must use delete with new, delete also calls the destructor
	4. new[] is a different function: delete with []
	5. new(specify memory address), placement new
39. Implicit Conversion and the explicit keyword in C++
	1. C++ allows you to implicitly construct an object by assigning the object to its constructor's parameter
	2. implicit keyword prevent you from doing it
40. Operators and operator overloading in C++
	1. there are a lot of operators, essentially operators are just functions
	2. we can define our own operator by overloading
	3. << operator: you could overload it from std::ostream to create your own print function
41. "This" keyword in C++
	1. "this" is a pointer to the current object instance that the method belongs to
	2. "this" is only accessible through a member function (a function belongs to a class)
42. Object lifetime in C++ (stack/ scope lifetimes)
	1. stack based object get destroyed when we get out of the scope
	2. Common mistake: create object in function, in stack base and expect it to appear out of the scope.
	3. a lot of usage relate to scope: scoped class/ scoped pointer/ scoped lock
		i. scoped pointer: a class that is a wrapper over a pointer which upon construction heap allocated the pointer, upon destruction delete the pointer.
43. smart pointers in C++
	1. smart pointer is like a wrapper around a real raw pointer: it will heap allocate for you and free the memory for you automatically depends on which smart pointer you use
		i. unique pointer: cannot have two unique pointer because memory would be freed when one of them dies and the memory get freed.
		ii. shared pointer: reference counting, keep track how many references you have to your pointer. Once reference count = 0, the pointer gets deleted. Shared pointer would assign a block of memory to store reference count
		iii. weak pointer: works like a shared pointer
	2. Try to use smart pointer all the time since they automated the memory management, prevent you from accidenly leaking memory cuz forgetting to call delete
44. Copying and copy constructor in C++
	1. try to avoid unnecessary copy as it takes time
	2. copy by value, normally " = " is always copy by value;  a = 2; b = a; b = 3 -> b wont affect a; 
	3. sometimes you do copy by pointer (you got two pointer points to same memory address), both pointer are affected if the memory address they both pointed to are affected. We want to avoid this.
	4. deep copy: copy the entire object (all fields) which would avoid the copy by pointer.
45. Arrow in C++
	1. Arrow would dereference the pointer and let you call method/ variable
	2. overload arrow: you can define your own arrow when in scoped pointer
46. Dynamic Arrays in C++
	1. the standard vector class -> standard template library: the data type container contains is for you to decide.
	2. std::namespace vector -> essentially a dynamic array list, like a set does not enforce any unique element, not a math vector. It does not have a size.
	3. it will extend the memory size once the old is full and move everything to the new memory place, so the performance may not be very good
	4. dynamic array still consumes memory continuously, so save the object rather than pointer would be technically more efficient.
47. Optimizing the usage of std::vector in C++
	1. Main optimizing strategy: avoid copying objects (vectors)
	2. since the vertex is defined in main function stack frame, it needs to be copied to the actual vertices memory block
	3. the size of dynamic array is limited three times so is moved and copied three times
48. Using libraries in C++ (static linking)
	1. cherno's idea: put everything in the repository, don’t leave it for user to sync with library for C++.
	2. GLFW linking
		i. download binary: 32bit vs 64bit -> depends on your application target
		ii. project -> properties -> C/C++ -> general -> Additional Include Directories -> add relative path $(SolutionDir)Foldername\...
		iii. include the header file
		iv. Property -> Linker -> General -> Additional Dependencies -> glfw3.lib; Linker -> General -> Additional Library Directories
	3. Static linking: the library get put into the executable (inside .exe file). Technically faster. dll.lib -> for static linking, read everything from dll file
	4. Dynamic linking: link to the runtime, dll files are going to be used
49. Using dynamic libraries in C++
	1. linking that happen at runtime, link another external binary file at runtime, the library is loaded when you launch the executable. you can dynamic link in two ways:
		i. "50/50" way: the executable is aware of the dynamic library and list it as a requirement, but its still a module that loads at runtime
		ii. "complete dynamically": executable has nothing to do with the library, inside the executable you can write codes with loads dynamic libraries
	2. GLFW.linking
		i. glfw3dll.lib ->  a series of pointers of the gldw3.dll file so that we don’t have to recreate the location and everything at runtime. the two files are compiled at the same time.
		ii. property -> linker -> input -> additional dependencies: add glfw3dll.lib
		iii. When exe missing dll file, easiest way is to put dll file at the same location as the exe
51. How to Deal with Multiple Return Values in C++
	1. in C++ traditionally function could only return one type.
	2. create a struct with the return structure you want
	3. Put the output as input parameter and modify the parameter
	4. return a vector or an array or a tuple (from utility)
52. template in C++
	1. what is a template: the compiler writing codes for you based on your given rules. Like a blue print
	2. work like a java generic, but not only type can be generic, int could also be generic as the code shows.
	3. if you don’t call the template, it does not really exist. When template with different type is called, it works like it copied itself multiple times with different paramter type methods.
53. stack vs heap memory in c++
	1. stack: memory area usually with pre-defined size
	2. heap: can grow when program goes on
	3. physical location of both are in our ram, not cpu 
	4. how they allocate the memory are completely different
		i. stack: all we do is to move the stack pointer the type size amount of bytes. And the memory address stack pointer points to is the memory address of the varaible. So literally stack things on top of each other. When the memory in stack is freed, the stack pointer just points back where is used to be. it is really fast.
		ii. heap: store variable in different memory address
	5. What does new keyword do?
		Call function malloc: call os platform specific function which allocate memory for you on the heap. Program keeps free list: keeps track which block of memory are free, where they are and when asked for dynamic memory using, it will go to free list to find a block which is at least the size we need  and book it and return the pointer back
	6. Allocate memory on stack is only one cpu instruction, pretty fast. Allocate memory on heap is a whole thing with a lot of background operation going on, which is quiet expensive
		Always try to allocate memory on the stack whenever possible. Unless you need the object's lifetime or loading fairly large object
54. Macros in C++
	1. Using preprocessor to macrofy certain operation,pure text replacing, can go with parameter.
	2. macro could contain some logic (if else)
55. auto keyword in C++
	1. let c++ automatically choose which type to use, so no longer need to worry too much about type. "kind of " turn cpp as a weak type language?
	2. pros and cons about auto, when should we use it?
		i. if your variable is a return value of a function, you don’t have to change variable type when you change the function return type by using auto
			```C++
			std::string  becomes char* GetName() {}
			auto name = GetName() // use auto here, dont need to change type
			```
		ii. however, in this case you lose the api avaiable to std::string like size(), so maybe don’t use auto in this case for readibility and error-proof
		iii. you may consider to use auto if the type is really long
56. static arrays in C++
	1. constant size and type once created: std::array<int, 5> data;
	2. why and when should you use?
		i. when you for loop you don’t need to pass is the size as parameter
		ii. std:array has some api like sort to help you
		iii. when you create std vector class, it creates underlie data storage on the heap
		iv. the size of static array is not a variable, more like a template argument, so doesn’t consume memory
57. function pointer in c++
	1. function are just cpu instruction, they are still somewhere in the memory as binary and we can assign a function to a variable
	2. void (* variable_name)() -> actual type of of the function, better to use with auto or make an alias

