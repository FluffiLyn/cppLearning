# 1. 生词

# 2. Function Overloading 函数重载
*&emsp;&emsp;在传统的C语言中，函数名必须是唯一的，程序中不允许出现同名的函数。在C++中是允许出现同名的函数，这种现象称为函数重载。函数重载的目的就是为了方便的使用函数名。*



# 3. Function Template 函数模板
*&emsp;&emsp;函数模板是由参数表示的一系列的函数。函数模板可以被不同的类型参数所调用，使用时和普通的函数功能一样，不同的是函数模板在定义的时候参数的**类型是未知的**。*

## Function Templates Definition
(1) Function template is a more compact and convenient form of overloading.
* Identical program logic and operations for each data type.

(2) ~ ~ is written by programmer ***once*** and essentially defines a whole famliy of overloaded functions.

\
Example:
```c++
template <typename T>
T Max(const T a, const T b)
{
    return a > b ? a : b;
}
```
## Function Template Specialization
```c++
template <typename T>
T max(T a, T b)
{
    //略
}

cout << max(3,5) << endl;
cout << max('a','b') << endl;
cout << max(0.4, 0.1) << endl;
```