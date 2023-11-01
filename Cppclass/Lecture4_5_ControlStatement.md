# 1. 生词
overhead 开销

# 2. Argument Coercion 参数强制
*Forcing argument to the appropriate types specified by the corresponding parameters*

• C++ Promotion Rules

(1) Apply to expressions containing values of ***two or more data types***.

    (a) Such expressions are also referred to as mixed-type expressions.

    (b) Each value in the expression is promoted to the "highest" type in the expression, convert between types without losing data.

    (c) Temporary vertion of each value is created and used for the expression. Original values remain UNCHANGED.

(2) Promotion also occurs when the type of a function argument does not match the specified ***parameter type***.

(3) <font color=red>***Warning:***</font> Converting a value to a ***lower type***:

    (a) Will likely result in data loss or incorrect values.

    (b) Can only be performed EXPLICITLY by assigning the value to a variable of lower type (some compilers will issue a warning) or by using static_cast<type>(argument).

# 3. Reference and Reference Parameters 引用和引用变量
## Reference Parameter
    
*An alias for its corresponding argument in a function call, with "&" placed after the parameter type in the function prototype and function header.*

•Example
```c++
#include <iostream>
using std::cout;
using std::endl;

int squareByValue(int );//function prototype (VALUE PASS 值传递)
void squareByReference(int &);//function prototype (REFERENCE PASS 引用传递)

int main()
{
    int x = 2, z = 4;

    cout << "x = " << x << endl;
    cout << "Value returned by squareByValue: " << squareByValue(x) << endl;
    cout << "x = " << x << " after squareByValue" << endl;
    
    cout << "z = " << z << endl;
    cout << "Value returned by squareByReference: " << endl; 
    squareByReference(z);
    cout << "z = " << z << " after squareByReference" << endl;

    return 0;
}

int squareByValue(int num)
{
    return num*=num;
}

void squareByReference(int &num)
{
    num *= num;
}
```

## Pros & Cons of Pass-by-reference
(1) Pros: Good for performance. Because it can eliminate the pass-by-value overhead of copying large amount of data.

(2) Cons: Bad for security. Because the called function can corrupt the caller's data.

    To avoid this, use a constant reference parameter to simulate the appearance and security of pass-by-value and avoid the overhead of passing a copy of large object.
```c++
void squareByReference(const int &num)
```

## References

(1) Can also be used as aliases for other variables ***Within a function***.
    
&emsp;&emsp;• All operations supposedly performed on the alias (i.e., the reference) are actually performed on the ***original variable***.

&emsp;&emsp;• An alias is simply another name for the original variable.

&emsp;&emsp;• Must be initialized in their ***declarations***.

&emsp;&emsp;• Cannot be reassigned afterward.

## Returning a reference from a function

(1) Functions can return references to variables, which should only be used when the variable is ***static***. 

(2) Dangling reference(悬空引用):

&emsp;&emsp;(a) Dangling reference will return a reference to an automatic variable that no longer exists after the function ends.

&emsp;&emsp;(b)Therefore, returning a reference to an automatic variable in a called function is a <font color=red>***Logic Error***</font>.

# 3. Default Arguments 默认实参
&emsp;&emsp;*某些函数有这样一种形参， 在函数的很多次调用中它们都被赋予一个相同的值， 我们把这个反复出现的值称为函数的默认实参。*

(1) A default value to be passed to a parameter is used when the function call ***does not specify an argument*** for that parameter.

(2) Default agruments must be the ***rightmost arguments*** in a function's parameter list.

(3) D~ a~ should be specified with the ***first occurrence*** of the function name —— typically the function type.
    
&emsp;&emsp;• It's a <font color=red>***Compilation Error***</font> to specify default arguments in both a function's prototype and header.

* Example
```c++
#include <iostream>
using namespace std;

int boxVolume( int length, int width, int height)
{
    return length * width * height;
}

int main()
{
    //Default values for all dimentions.
    cout << "The default box volume is: " << boxVolume();

    //Specify length; width and height remain default.
    cout << "\n\nThe volume of a box with length 10,\n"
        << "width 1 and height 1 is: " << boxVolume(10);

    //Specify width and height; length remains default.
    cout << "\n\nThe volume of a box with length 10,\n"
        << "width 5 and height 1 is: " << boxVolume(10, 5);

    //Specify all arguments.
    cout << "\n\nThe volume of a box with length 10,\n"
        << "width 5 and height 2 is: " << boxVolume(10, 5, 2);

    return 0;
}
```
*Notice: Some compilers may issue an error that "too few arguments to function 'int boxVolume'.*

# 4. Unary Scope Resolution operator 作用域运算符(::)
&emsp;&emsp;*"::" is used to access a global variable when a local variable of the ***samename*** is in scope.This cannot be used to access a local variable of the same name in an ***outer block***.*

* Example
```c++
#include <iostream>
using std::cout;
using std::endl;

int number = 7;//Global variable named "number".

int main()
{
    double number = 10.5;//Local variable named number.

    cout << "Local double value of number = " << number
        << "\nGlobal int value of number = " << ::number << endl;

    return 0;
}
```
Output:
>Local double value of number = 10.5\
>Global int value of number = 7