# Chapter 0 Introduction
本书的每一小节是**指导方针**而非语法规则；最关键的部分不是建议，而是建议背后的**原理**。

## 术语和惯例
书中提到的c++版本的对应关系如下：
|术语|解释|
|---|---|
|C++|所有版本|
|C++98|C++98和C++03|
|C++11	|C++11和C++14|
|C++14	|C++14|

### 左值和右值
移步到[这里](./prelim_cpp11_move.md)。

### 拷贝与副本
当使用另一个同类型的对象来初始化一个对象时，新的对象被称为是用来初始化的对象（译者注：initializing object，即源对象）的一个副本（copy），尽管这个副本是通过移动构造函数创建的。
* 为了区别拷贝这个“动作”与拷贝得到的“东西”，将copy按语境译为拷贝（动作）和副本（东西）。在之后的章节中可能会不加区别地全部翻译为“拷贝”。
### 惯用命名
`widget`指代用户定义的类型。

`rhs`（right-hand side）是移动操作和拷贝操作的形参名，当然也会在双目运算符的右侧出现。

`…`表示“这里有一些别的代码”。不是`c++11`可变参数模板的语法`...`。
```cpp
template<typename... Ts>                //这些是C++源代码的
void processVals(const Ts&... params)   //省略号
{
    …                                   //这里意思是“这有一些别的代码”
}
```

`ctor`表示构造函数，`dtor`表示析构函数。

### 其他术语
**异常安全**的函数是能提供基本的异常安全保证的函数，具体是保证调用者在异常抛出时，程序不变量保持完整（即没有数据结构毁坏），且没有资源泄漏。有强异常安全保证的函数确保调用者在异常产生时，程序保持在调用前的状态。

**函数对象**通常指支持`operator()`的类对象，可以简单地认为是**可调用对象（callable objects）**。

**闭包**是通过lambda表达式创建的**函数对象**。本书将两者统称为lambdas。类似地，本书不区分函数模板和模板函数、类模板和模板类。
* 模板函数是由函数模板创建的具体函数。
* 模板类是由类模板创建的具体类。

**声明（declarations）**引入名字和类型，并不给出比如存放在哪或者怎样实现等的细节：
```cpp
extern int x; //对象x的声明

class Widget; //类Widget的声明

bool isPrime(int x); //函数isPrime的声明

enum class Color; //限定作用域枚举Color的声明
```

**定义（definitions）**提供存储位置或者实现细节：
```cpp
int x;
class Widget{…};
bool isPrime(int x){…}
enum class Color
{Yellow,Red,Blue};
```
* 注：extern是一个存储类说明符，用于声明一个变量或函数在其他文件中定义。它告诉编译器该变量或函数的定义在另一个翻译单元中，并且链接器会在链接阶段找到它。

**废弃特性（deprecated features）**是指在新版本中不再推荐使用的特性，通常是因为有更好的替代方案。

**未定义行为（undefined behavior）**意味着运行时表现不可预测。例如在`std::vector`范围外用方括号解引用未初始化的迭代器。

**原始指针（raw pointers）**指传统指针，例如从`new`返回的指针。

**智能指针（smart pointers）**是一种类，它的行为类似于指针，但提供了额外的功能。通常重载了`operator->`和`operator*`，但`std::weak_ptr`除外。