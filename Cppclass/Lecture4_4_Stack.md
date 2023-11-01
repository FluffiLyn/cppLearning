# 1. 生词
stack 栈\
stack frame 栈帧\
pop 弹出\
qualifier 限定符，修饰符\
# 2. Function Call Stack 函数调用栈

&emsp;&emsp;*程序在运行期间，内存中有一块区域，用来实现程序的函数调用机制。这块区域是一块LIFO的数据结构区域，我们可以叫函数栈（调用栈）。每个未退出的函数都会在函数栈中拥有一块数据区，我们叫函数的栈帧。函数的调用栈帧中，保存了相应的函数的一些重要信息：函数中使用的局部变量，函数的参数，另外还有一些维护函数栈所需要的数据，比如EBP指针，函数的返回地址。*

(1) Sometime also called the program execution stack.

(2) Supports the function call/return mechanism.

    (a) Each time a function calls another function, a stack frame (also known as an activation record) is pushed onto the stack.
        
        • Maintains the return address that the called function needs to return to the calling function.

        • Contains automatic variables —— parameters and any local variables the function declares.

(3) If a function makes a call to another function:
        
    (a) Stack frame for the new function call is simply pushed onto the call stack.

    (b) Return address required by the newly called function to return to its caller is now located at the top of the stack.

(4) When the call function returns:
    
    (a) Stack frame for the function call is popped(弹出).

    (b) Control transfers to the return address in the popped stack frame.

# 3. Incline Function 内联函数
&emsp;&emsp;*用关键字inline修饰的函数就是内联函数。关键字在函数定义的时候要加上，而不是在函数声明时加上，因为系统会忽略掉函数声明时的incline关键字。*


(1) ***Reduce function call overhead*** —— especially for ***small*** funcitons.

(2) has a qualifier "incline" before a function's return type in the function definition, "advises" the compiler to generate a ***copy*** of the function's code in place (when appropriate) to avoid a function call.

(3) The compiler can ignore the incline qualifier and typically does so for ***all but the smallest functions***.

***To sum up, incline function can reduce the time and the use of stack when being called, especially when the incline function is small.***