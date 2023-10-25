# 1、生词

scope   n.域

# 2、Storage Classes 存储类

(1)Each identifier has several attributes: name, type, scope, linkage.

    •storage class
    •scope
	•linkage

(2)C++ provides five storage-class specifiers: auto, register, extern, mutable, static.

## •Automatic storage class

(1)Decalred with keywords "auto" and "register"

(2)Automatic variables

    •Created when program execution enters block in which they are defined.
    •Exist while the block is active.
    •Destroyed when program exits the block.

(3)Only local variables and parameters can be of automatic storage class.(local variables：函数内部定义的变量，称为局部变量)

`int max(int a, int b, int c) {     int t;     t=max(a,b);     return max(t,c); }`

## •Static storage class

(1)Declared with keywords "extern" and "static"

(2)Static-storage-class variables

    •Exist from the point at which the program begins execution
    •Initialized once when their Declarations are encountered
    •Last for the duration of program

(3)Static-storage-class functions
    The name of the function exists when the program begins execution, just as for all other functions

(4)However, even though the variables and the function names exist from the start of program execution,
    this does not mean that these identifiers can be used throughout the program

# 3、Scope Rules 作用域规则

 (1)Scope is a portion of the program where an identifier can be used

 (2)Four scopes for an identifier:
    •Function scope 函数作用域
    •File scope 文件作用域
    •Block scope 块级作用域
    •Function-prototype scope 函数原型作用域

## •File Scope

Example:

```c++
#include <iostream>

using namespace std;
int a=1, b=1;
void f1(int x)
{
    a = x * x; //a,b的作用域从这里开始
    b = a * x; //f1函数可以访问a,b
}
int c;
void f2( intx, inty)
{
    a = x > y ? x : y;//c的作用域从这里开始，初始值为0
    b = x < y ? x : y;//f2可以访问a,b,c
    c = x + y;
}
int main()//main函数可以访问a,b,c
{
    f1(4);
    cout << "Call function f1:\n";
    cout << "a=" << a << ",b=" << endl;
    f2(10,23);
    cout << "Call function f2:\n";
    cout << "a=" << a <<",b=" << b << ",c=" << c << endl;
}
```

## •Function Scope

(1)Labels (identifiers followed by a colon such as `start:`) are the only identifiers with function scope.

    •Can be used anywhere in the function in which they appear
	•Cannot be referenced outside the function body
	•Label are implementation details that functions hide from one another

Example:

```c++
void f1()
{
    label1:
    {
        cout << 1;
    }
  
    goto label1;//ok
    goto label2;//not ok
}
```

## •Block Scope

•在代码块内部声明的变量具有块作用域，它们只能在代码块内部访问。块作用域变量在代码块每次被执行时被创建，在代码块执行完后被销毁。

(1)Identifiers declared inside a block have block scope.

    •Block scope begins at the identifier's declaration
    •Block scope ends at the terminating right brace "}"
   	of the block in which the identifier is declared.

(2)Local variables and function parameters have block scope. The function body is their block.

(3)Any block can contain variable declarations.

(4)Identifiers in an outer block can be "hidden" when a nested block has a local identifier with the same name.

Example:

```c++
#include <iostream>
using namespace std;
int main()
{
int a = 1;//Outer a
{
int a = 1;//Inner a
a++;
cout << "inner a =" << a << endl;//output 2
}
cout << "outer a =" << a << endl;//output 1

return 0;
}
```

## •Function-prototype scope

•函数原型作用域是C++程序中最小的作用域。在函数原型声明时形式参数的作用范围就是函数原型作用域。

*•啥是function prototype？
    C++函数原型（function prototype）用于在函数定义之前声明函数的返回类型、函数名、参数类型和参数个数等信息。它通常位于函数所属的类或文件的头文件中，以便其他文件在使用该函数时可以正确地调用它。（其实就是个函数头）*

(1)Only identifiers used in the parameter list of a function prototype have f-p scope.

(2)Parameter names appearing in a function prototype are ignored by the compiler.

    •Identifiers used in a f~ p~ can be**reused** elsewhere in the program without ambiguity.
    •However, in a single prototype, a particular identifier can be used only once.

Example:

```c++
 double funPrototype(double x, double y);  
```

<font color=red face=宋体>我是红色字体</font> 