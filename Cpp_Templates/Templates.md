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
Return type depends on the order of call arguments parameters. If you defined a function max(T a, T b) and call it as max(66.66, 42), it will return double 66.66. If you call it as max(42, 66.66), it will return int 66.

Following are ways to solve these.

### 1.3.1 Template Parameters for Return Types
```c++
template<typename T1, typename T2, typename RT>
RT max(T1 a, T2 b);
//...
::max<int,double,double>(4, 7.2)//OK, but tedious
```
We can simplify this by specifying only the return type:
```c++
::max<double>(4,7.2)//Return type is double, T1 and T2 are deduced
```

### 1.3.2 Deducing the Return Type
Since C++14, we can use "auto" to deduce the return type.
```c++
template<typename T1, typename T2>
auto max(T1 a, T2 b)
{
    return b < a ? a : b;
}
```
Before C++14, we should also use "decltype" to deduce the return type.
```c++
template<typename T1, typename T2>
auto max(T1 a, T2 b) -> decltype(b < a ? a : b)
{
    return b < a ? a : b;
}
```
Here, the resulting type is determined by the yield of ?: . Note that 
`auto max (T1 a, T2 b) -> decltype(b < a ? a : b)` is a declaration.


However, sometimes the return type is a reference type. For this reason you should use return the type **decayed from T**.
```c++
#include <type_traits>
template<typename T1, typename T2>
auto max(T1 a, T2 b) -> typename std::decay<decltype(b < a ? a : b)>::type
{
    return b < a ? a : b;
}
```
`std::decay<>` is defined in std in `<type_traits>`

Note that an initialization of type `auto` always decays.
```c++
int i = 42;
int const& ir = i;//ir refers to i
auto a = ir;//a is declared as new object of type int
```

<details> <summary>什么是std::decay<>?</summary>
std::decay是C++标准库中提供的一个类型萃取工具，其功能是将给定的类型T“衰减”（decay）成一个更基础的类型，具体来说，它执行如下操作：

1. 数组到指针的转换： 如果T是数组类型（如T[]或T[N]），std::decay将其转换为指向数组元素类型的指针（如T*）。

2. 函数到指针的转换： 若T是函数类型（如void(int)），std::decay将其转换为指向该函数类型的指针（如void (*)(int)）。

3. 去除引用： 如果T是引用类型（如T&或T&&），std::decay将其转换为对应的非引用类型（即去掉&或&&，得到T）。

4. 去除cv-qualifiers（const/volatile限定符）： std::decay还会移除T上的const、volatile以及const volatile限定符，无论这些限定符出现在何处（顶层或底层）。

5. 从左值到右值的转换： 虽然不直接体现在std::decay的名称中，但它也模拟了编译器在函数参数按值传递时对左值的隐式转换，即将左值对象转换为对应的右值临时对象。这意味着即使T原本是某种用户自定义类型（如std::string）的左值引用，std::decay也会将其视为该类型的一个普通（非引用）副本。
</details>

<details><summary>What is std::decay<>?</summary>
std::decay is a type manipulation tool provided in the C++ Standard Library that "decays" a given type T into a more fundamental form by performing the following operations:

1. Array-to-pointer conversion: If T is an array type (e.g., T[] or T[N]), std::decay converts it to a pointer to the array's element type (e.g., T*).

2. Function-to-pointer conversion: If T is a function type (e.g., void(int)), std::decay converts it to a pointer to that function type (e.g., void (*)(int)).

3. Reference removal: If T is a reference type (e.g., T& or T&&), std::decay converts it to the corresponding non-reference type (i.e., removes the & or &&, resulting in T).

4. Removal of cv-qualifiers (const/volatile qualifiers): std::decay also removes any const, volatile, or const volatile qualifiers from T, regardless of where they appear (top-level or nested).

5. Conversion from lvalue to rvalue: Although not directly implied by its name, std::decay also simulates the implicit conversion of lvalue objects to corresponding rvalue temporary objects that occurs when function arguments are passed by value. This means that even if T is originally a reference to some user-defined type (like std::string), std::decay treats it as a plain (non-reference) instance of that type.
</details>

### 1.3.3 Return Type as Common Type