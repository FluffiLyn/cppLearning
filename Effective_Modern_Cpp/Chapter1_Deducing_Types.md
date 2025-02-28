# Chapter 1 类型推导（Deducing Types）
这一章是每个C++程序员都应该掌握的知识。它解释了**模板类型推导**是如何工作的，**auto**是如何依赖类型推导的，以及**decltype**是如何按照它自己那套独特的规则工作的。它甚至解释了你该如何强制编译器使类型推导的结果可视，这能让你确认编译器的类型推导是否按照你期望的那样进行。

## Item1  理解模板类型推导
### 三个情景
考虑该函数模板：
```cpp
template<typename T>
void f(ParamType param);

f(expr);// 调用f时从expr中推导T和ParamType
```
类型推导会根据以下三种情况进行不同的推导：
- ParamType是一个指针或引用，但不是通用引用（关于通用引用请参见Item24。这里只需要知道它存在，而且不同于左值引用和右值引用）
- ParamType是一个通用引用
- ParamType既不是指针也不是引用

#### 情景1：ParamType是指针或引用，但不是通用引用
1. 如果expr是一个引用，则**忽略expr的引用**部分，然后expr的类型与ParamType进行**模式匹配**来决定T。

对象的常量性constness会被保留为T的一部分，因此是安全的。
```cpp
template<typename T>
void f(T& param);// ParamType是引用

//声明变量
int x = 27;// x是一个int
const int cx = x;// cx是一个const int
const int& rx = x;// rx是一个引用，绑定到x

f(x);// T是int，param的类型是int&
f(cx);// T是const int，param的类型是const int&
f(rx);// T是const int，param的类型是const int&
```
对于右值引用也是一样。


2. 如果T&改为const T&，则const不再被推导为T的一部分，而是被推导为ParamType的一部分。
```cpp
template<typename T>
void f(const T& param);         //param现在是reference-to-const

int x = 27;                     //如之前一样
const int cx = x;               //如之前一样
const int& rx = x;              //如之前一样

f(x);                           //T是int，param的类型是const int&
f(cx);                          //T是int，param的类型是const int&
f(rx);                          //T是int，param的类型是const int&
```

3. 如果param的类型是指针（或指向const的指针），情况也类似。
```cpp
template<typename T>
void f(T* param);               //param现在是指针

int x = 27;                     //同之前一样
const int* px = &x;             //px是指向作为const int的x的指针

f(&x);                          //T是int，param的类型是int*
f(px);                          //T是const int，param的类型是const int*
```

#### 情景2：ParamType是通用引用
通用引用是一种引用，它可以绑定到左值或右值。通用引用的声明方式是T&&。

1. 如果expr是左值，T和ParamType都会被推导为**左值引用**。
   * 这是唯一一种**T被推导为引用**的情况。即使ParamType是右值引用类型，推导的结果也是左值引用。
2. 如果expr是右值，就使用情景1的规则。

```cpp
template<typename T>
void f(T&& param);              //param现在是一个通用引用类型
        
int x=27;                       //如之前一样
const int cx=x;                 //如之前一样
const int& rx=cx;              //如之前一样

f(x);                           //x是左值，所以T是int&，
                                //param类型也是int&

f(cx);                          //cx是左值，所以T是const int&，
                                //param类型也是const int&

f(rx);                          //rx是左值，所以T是const int&，
                                //param类型也是const int&

f(27);                          //27是右值，所以T是int，
                                //param类型就是int&&
```

to be continued...