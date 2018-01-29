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
	
