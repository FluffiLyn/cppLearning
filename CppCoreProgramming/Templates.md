This is FluffiLyn's learning note of "C++ Templates The Complete Guide 2nd Edition"

# Chapter1: Function Templates

## 1.1 A First Look at Function Templates
Function templates provide a functional behavior that can be called for different types.

### 1.1.1 Definition
Example:
```c++
template<typename T>
T max(T a, T b)
{
    return b < a ? a : b;
}
```

Also, you can use keyword `class` instead of `typename` to define a type parameter, which comes from the C++98 standard. These are no different. However, you cannot use `struct`.
```c++
// basics/max1.hpp
template<class T>
T max(T a, T b)
{
    return b < a ? a : b; 
}
```
This is actually not recommended because it can be misleading (not only class type can be substituted for T).

### 1.1.2 Usage
```c++
// basics/max1.cpp
#include "max1.hpp"
#include <iostream>
#include <string>

int main()
{
    int i = 42;
    std::cout << "max(7,i): " <<::max(7,i) << std::endl;

    double f1 = 3.4, f2 = -6.7;
    std::cout << "max(f1,f2): " << ::max(f1, f2) << std::endl;

    return 0;
}

```

Note that void is also valid template argument:
```c++
Template<typename T>
T foo(T*)
{}

void vp* = nullptr;
foo(vp);// OK, deduces void foo(void*)
```

### 1.1.3 Two-Phase Translation
In order to prevent instantiation (实例化) of an unsupported type of function template, the compiler will perform two-phase translation on the function template:

1. Without instantiation at *definition* time, the template code itself is checked for correctness ignoring the template parameters, including:
 - syntax errors
 - using unknown names
 - static assertions (静态断言) that don't depend on the template parameters, and so on.

2. At *instantiation* time, the template code is checked again to ensure that all code is valid. That is, all parts that depend on template parameters are double-checked.

Example:
```c++
template<typename T>
void foo(T t)
{
    undeclared();// first-phase compile-time error if undeclared() is unknown
    undeclared(t);// second-phase compile-time error if undeclared(t) is unknown
    static_assert(sizeof(int) > 10, "int too small");// always fails if sizeof(int) <= 10
    static_assert(sizeof(T) > 10, "T too small");// fails if instantiated for T with size <= 10
}
```
For further discussion, please read section 14.3.1 on page 249.


(What is static assertion?) [Click here!](https://www.geeksforgeeks.org/understanding-static_assert-c-11/)

## 1.2 Template Argument Deduction

### 1.2.1 Type Conversions During Type Deduction
Generally, the compiler will deduce the template argument we pass. However, automatic type conversions are limited to the following:
1. When "pass-by-reference", two arguments declared with the same template T must match exactly.

2. When "pass-by-value", only trivial (微小的) conversions that *decay* are supported. 
- const or volatile qualifiers are ignored.
- references convert to reference type.
- raw arrays or functions convert to the corresponding pointer type.

Example:
```c++
template<typename T>
T max(T a, T b);
//...
int const c = 42;
max(c, 42);// OK, T is deduced as int
max(c, c);//OK, T is deduced as int
int& ir = i;
max(i, ir);//OK, T is deduced as int
int arr[4];
foo(&i, arr);//OK, T is deduced as int*

max(4,7.2);//Error, T is deduced as double or int
std::string s;
foo(s,"hello");//Error, T is deduced as const char[6] or std::string
```

( What is volatile qualifier? )[Click here!](https://zhuanlan.zhihu.com/p/62060524)

Here are 3 ways to solve this problem:
1. Using static_cast<typeUwannause>(var).
```c++
max(static_cast<double>(4),7.2);//OK
```

2. Specify or qualify the template argument explicitly.
```c++
max<double>(4,7.2);//OK
```

3. Specify that the parameters may have different types.

### 1.2.2 Type Deduction for Default Arguments
For example:
```c++
template<typename T>
void f(T = "");

f(1);//OK, T is deduced as int, so that it calls f<int>(1)
f();//ERROR, cannot deduce T from ""
```

To prevent this, declare a default argument for the **template parameter**.

```c++
template<typename T = std::string>
void f(T = "");
f();//OK
```

## 1.3 Multiple Template Parameters