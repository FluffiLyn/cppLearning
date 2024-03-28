# 1. STL介绍
C++ STL（标准模板库）是一套C++模板类，提供了通用的模板类和函数，可以实现多种流行和常用的算法和数据结构。

它的核心包括三个组件：
| 组件 | 描述 |
| --- | --- |
| 容器（Containers）|用来管理某一类对象的集合。如deque，list，vector，map等｜
| 算法（Algorithms）| 算法作用于容器，例如对容器内容执行初始化、排序、搜索和转换等操作。|
| 迭代器（Iterators）| 用于遍历对象集合的元素。这些元素可能是容器，也可能是容器的子集 |     

# 2.序列容器

## 2.1 vector
vector类似数组，包含一组地址连续的存储单元。它可以自动扩容。

总览：
```c++
#include <iostream>

vector<int> v;//定义存放整形数据的vector容器"v"
vector<float> v1;
v.capacity();//获取容量（申请的内存空间大小）
v.size();//获取大小（元素的个数）
v.max_size();//返回int的最大值
v.at(index);//类似数组的[]运算

v.push_back(elem);//在尾部插入元素
v.pop_back();//尾部删除
v.front();//获取头部元素的引用
v.back();//获取尾部元素的引用
v.begin();//返回向量头指针(迭代器)
v.end();//返回向量尾指针（迭代器）

v.insert(pos, elem);//在pos处插入元素
                    //pos由begin()和end()加上常数来给出
v.insert(pos,n,elem);//在pos处插入n个elem
v.erase(pos);//移除pos处的元素
v.erase(begin,end);//移除从start到end的元素
v.reverse(pos1,pos2);//将pos1到pos2的所有元素逆序存储

vector<int>::iterator it1 = v1.begin();//使用迭代器
```

### 2.1.1 构造函数
常见的构造函数有四种：
```c++
//1、默认构造，无参
vector<int> v1;
for (int i = 0; i < 10; ++i)
{
    v1.push_back(i);
}

//2、利用区间方式构造
//将另一个向量的一个区间"复制"进来
vector<int> v2(v1.begin(), v1.end());

//3、n个element方式构造
vector<int> v3(10,100);//10个100

//4、拷贝构造
vector<int> v4(v3);
```

### 2.2.2 赋值操作
```c++
//1、直接赋值
vector<int> v2;
v2 = v1;

//2、assign赋值
vector<int> v3;
v3.assign(v1.begin(), v1.end());

//3、n个element赋值
vector<int> v4;
```

### 2.2.3 插入和删除
插入可以用push_back()，也可以insert()。删除一般是pop_back()，也可以erase()。
```c++
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(10);
    for(int i : v) cout << i << " ";
    cout << endl;

    //输出第二个数据
    cout << *(v.begin()+1) << endl;
    //在第二个元素处添加200
    v.insert(v.begin() + 1,200);
    cout << *(v.begin()+ 2) << endl;

    //在第一个元素处向后添加两个100
    v.insert(v.begin(),2,100);
    for (int i : v) cout << i << " ";
    cout << endl;

    //清空所有的100元素（删除当前元素后，迭代器会自动指向后一个元素，此时不能++，否则会出错）
    for(vector<int>::iterator it = v.begin(); it != v.end();)
    {
        if (*it == 100)
            it = v.erase(it);//erase函数返回的是下一个元素的迭代器
        else 
            it++;
    }
    
    for (int i : v)
    {
        cout << i << " ";
    }

    return 0;
}
```

### 2.2.4 容量和大小
容量是capacity()，大小是size()。你可以用resize()来改变大小，但是要先用empty()来判断容器是否为空。

对于vector，它的capacity是预留的空间大小，不一定等于元素个数。当元素存储达到预留空间上限时，会触发扩容。具体扩容的量取决于不同触发扩容的方式。

而size就是元素的个数。
```c++
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;

    for (int i=0;i<10;i++)
    {
        v.push_back(i);
    }

    //输出所有内容
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;

    if(v.empty())
    {
        cout << "The vector is empty." << endl;
    }
    else
    {
        cout << "The capacity is: " << v.capacity() << endl;
        cout << "The size is: " << v.size() << endl;
    }

    return 0;
}
```
输出结果：
```
0 1 2 3 4 5 6 7 8 9 
The capacity is: 16
The size is: 10
```

在实际应用时，我们应该为vector预先设置容量，尽量避免多次触发扩容。

## 2.3 deque（双端队列）
可以对deque两端的数据进行操作。它没有capacity属性，因此它不需要扩容，也因此没有空间保留（reverse）功能。

```c++
#include <deque>
```

### 2.3.1 构造函数
与vector类似。
```c++
deque<int> d1;
for (int i = 0; i < 10; i++)
{
    d1.push_back(i);
}

deque<int> d2(d1);

deque<int> d3(size);

deque<int> d4(first, last);

deque<int> d5 = d4;

```
### 2.3.2 赋值操作
### 2.3.3 大小

### 2.3.4 插入和删除
插入操作    
```c++
deque<int> d;

d.push_back(10);
d.push_back(20);//尾部插入

d.push_front(100);//头部插入

d.pop_back();//尾部删除
d.pop_front();//头部删除
```

删除操作
```c++
deque<int> d;
d.push_back(10);
d.push_back(20);

d.push_front(100);
d.push_front(200);


deque<int>::iterator it = d.begin();
it++;
d.erase(it);
printDeque(d);//自定义输出
d.erase(d.begin(),d.end());

d.clear();
```

### 2.3.5 数据存取
此处主要是区别[]方式和at()函数的访问情况。

使用at()更加安全，具体会在后面的Array中提及。

```c++
#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int> d(6);

    for (int i = 0; i < 6; i++)
    {
        d.at(i) = 100 * (i + 1);
    }

    //通过[]访问
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
    
    //通过at()访问
    for (int i = 0; i < d.size(); i++)
    {
        cout << d.at(i) << " ";
    }

    return 0;
}
```

## 2.4 list(列表/双向循环列表)
```
#include <list>
```

## 2.5 forward_list（单向链表）

## 2.6 array（数组）
与普通数组不同，stl里的数组多了很多新方法，例如可以用at()来访问数组内容。

at()比[]访问更加安全，这是因为在访问越界时，at会抛出异常，但是 []会使程序崩溃。

# 3.关联式容器
关联式容器是指数据是键值对的格式。它们没有头尾，所以不会有pushback,pushfront之类的操作。
## 3.1 set/multiset（集合/多重集合）
对于集合容器，它在使用insert()插入之后会**自行排序**，默认是升序，但不可重复插入，就像数学上的集合。它们是简单关联容器，其参数类型只有一个，所以它的元素既是键值（key）又是实值（value）。
 
引用方法：`#include <set>`（set和multiset都是用这个）

在头文件中的定义：
```c++
template<typename _Key, typename _Compare = std::less<_Key>,
	typename _Alloc = std::allocator<_Key> >
class set
{
    //...
};
```
这里定义了一个**类模板**，包括三个参数类型：变量类型、排序方式和内存分配器。
排序方式可以用仿函数来修改。见cppLearning/CppCoreProgramming/ClassAndObject.md的仿函数一栏。

### 3.1.1 常用操作
构造和赋值、大小和交换、插入和删除等操作，均予上述容器类似。

### 3.1.2 查找和统计操作
可以用find()函数访问相应的元素，可以用count()函数去统计相关元素在容器中出现了几次。
使用方法如下：
```c++
iterator find(const key_type &key);
size_type count(const key_type &key);
```
示例：
```c++
#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s1;

    for (int i = 7; i >= 1; i--)
    {
        s1.insert(i);
    }

    for (int i : s1)
    {
        cout << i << " ";//输出仍为正序
    }

    cout << endl;
    //1、查找
    //end()返回指向集合尾部元素之后的位置的指针，表示寻找的元素不存在。
    //也就是说集合的末尾并不是最大的元素
    set<int>::iterator pos = s1.find(3);
    if (pos != s1.end())
    {
        cout << "找到" << *pos << "了" << endl;
    } 
    else 
    {
        cout << "没找到" << endl;
    }

    //2、统计
    //由于集合元素的互异性，即使多次添加同一个数据，使用count()统计的结果仍然是1。

    return 0;
}
```

### 3.1.3 set和multiset的区别
在 multiset 中，元素按照值的大小进行排序，并且**可以有重复的值**。这使得 multiset 成为一种非常适合需要存储重复元素并保持有序的情况下使用的数据结构

## 3.2 pair（对组）
pair用于存储一对值。这对值可以是不同类型的数据，例如两个整数、一个整数和一个字符串等。std::pair 提供了一个简单的方法来将两个值组合在一起，方便进行处理和传递。
### 3.2.1 构造函数
```c++
pair<int, double> p1;
pair<int, double> p2(1,2,4);
pair<int, double> p3(p2);
```

### 3.2.2 访问元素
由于pair只有一对值，我们可以用first和second来访问。
```c++
pair<int, double> p1;
p1.first = 1;
p1.second = 2.5;
cout << p1.first << " " << p1.second << endl;
```

### 3.2.3 赋值
(1)用make_pair
```c++
pair<int, double> p1;
p1 = make_pair(1,1.2);
```

(2)变量间赋值
```c++
pair<int, double> p1(1, 1.2);
pair<int, double> p2 = p1;
```

### 3.2.4 应用
对组可以放入queue（队列）中，配合广度优先搜索（BFS）来解题。

例如：用pair充当结构体保存坐标(x,y)。

## 3.3 map/multimap（映射/多重映射）
map的所有元素都是pair，同时拥有键值（key）和实值（value），所有元素都会根据键值来自动排序。
当对它的容器元素进行新增操作或者删除操作时，操作之前的所有迭代器在操作之后依旧有效。

### 3.3.1 头文件
`#include <map>`

在头文件中，map是这样定义的：
```c++
template<typename _Key, typename _Tp, typename _Cmp = std::less<_Key>>
  using map
= std::map<_Key, _Tp, _Cmp,
   polymorphic_allocator<pair<const _Key, _Tp>>>;
//C++17
```
这是一个模板声明，定义了三个模板参数 _Key、_Tp 和 _Cmp，其中 _Key 是键的类型，_Tp 是值的类型，_Cmp 是比较函数对象的类型，默认值为 std::less<_Key>, 也就是说，默认是升序排序。

using map = std::map<_Key, _Tp, _Cmp, polymorphic_allocator<pair<const _Key, _Tp>>>;：这里定义了一个别名模板 map，它实际上是 std::map 的一个实例化版本，使用了自定义的内存资源管理器 polymorphic_allocator 来进行内存分配。具体地：

_Key 和 _Tp 分别作为键和值的类型参数传递给 std::map。

_Cmp 作为比较函数对象的类型参数传递给 std::map。

polymorphic_allocator<pair<const _Key, _Tp>> 指定了使用内存资源管理器来分配键值对 (pair<const _Key, _Tp>) 的内存。

### 3.3.2 常用操作
（1）构造和赋值

对于map容器，要使用pair来进行insert。

```c++
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // 构造一个空的 map
    map<string, int> myMap;

    // 插入键值对
    myMap["Alice"] = 25;
    myMap["Bob"] = 30;
    myMap["Charlie"] = 27;

    // 使用 insert 函数插入键值对
    myMap.insert(make_pair("David", 35));

    // 输出 map 中的键值对
    for (pair<const string, int>& pair : myMap) {
        cout << pair.first << " is " << pair.second << " years old." << endl;
    }

    // 使用迭代器遍历 map
    map<string, int>::iterator it;
    for (it = myMap.begin(); it != myMap.end(); ++it) {
        cout << it->first << " is " << it->second << " years old." << endl;
    }

    // 赋值操作
    map<string, int> anotherMap;
    anotherMap = myMap;  // 使用赋值操作符将一个 map 赋值给另一个 map

    return 0;
}
```

（2）大小和交换
```c++
#include <iostream>
#include <map>
using namespace std;

int main() 
{
    map<string, int> myMap;

    // 向 map 中插入一些元素
    myMap["Alice"] = 25;
    myMap["Bob"] = 30;
    myMap["Charlie"] = 27;

    // 获取 map 的大小
    cout << "Map 的大小为：" << myMap.size() << endl;

    return 0;
}
```
输出结果：
```
Map 的大小为：3
```
这说明size获取的是map的键值对数量。

（3）查找和统计

在map中，find函数可通过键值来查找相应的实值，如myMap.find("Alice")返回25。对于map，count函数返回的值一定是0或1；
对于multimap则可能大于1。

### 3.3.3 插入和删除
插入的方式记住前三种即可。

```c++
#include <iostream>
#include <map>
using namespace std;

int main() 
{
    map<int, int> m1;
    
    //插入
    //1
    m1.insert(pair<int, int>(1,10));

    //2
    m1.insert(make_pair(2,20));

    //3
    m1.insert(map<int, int>::value_type(3,30));

    //4
    //不建议，如果该键已经存在，它会直接覆盖原有的值。这可能会导致意外的数据丢失，特别是在不确定键是否存在的情况下。
    m1[4] = 40;

    //当你用[]访问不存在的键时，它会新建一个键值对，实值的默认值是0，导致意外的元素插入。
    cout << m1[5];

    //删除
    //1、用begin()删除
    m1.erase(m1.begin());
    
    //2、根据键值删除
    m1.erase(2);

    return 0;
}
```
insert会返回一个 pair 类型的值，指示插入是否成功，从而可以根据返回值来判断是否已存在相同的键，增强安全性。

### 3.3.4 map和multimap的区别
与 std::map 相比，std::multimap 允许键值对的键重复，因此它可以存储多个具有相同键的值。

# 4.容器适配器
容器适配器是一个封装了序列容器的类模板，它在一般序列容器的基础上提供了一些不同的功能。之所以称作适配器类，是因为它可以通过适配容器现有的接口来提供不同的功能。

## 4.1 stack（堆栈）
stack的内部元素是先进后出FILO的，只有栈顶的元素top才可以被访问。

### 4.1.1 头文件
`#include <stack>`

### 4.1.2 内部结构
![图片](https://c.biancheng.net/uploads/allimg/180913/2-1P913101Q4T2.jpg)

### 4.1.3 常用操作
push()入栈，pop()出栈，empty()判空（非空则返回size()），top()获取栈顶（最后入栈）的元素。

## 4.2 queue（队列）
queue与stack相反，它是先进先出（FIFO）。

## 4.2.1 与双端队列的区别
1. queue可以访问两端，但是只能修改对头。而deque可以修改首尾。
2. queue只能从队尾入队，而deque可以从两端入队。

### 4.2.2 头文件
`#include <queue>`

### 4.2.3 内部结构
![queue](https://img-blog.csdnimg.cn/20190616140540198.png)

### 4.2.4 常用操作
略。

## 4.3 priority_queue（优先队列）
我们可以在优先队列中自定义数据的优先级，让优先级高的排在队列前面，优先出队。优先队列在queue头文件中。

### 4.3.1 定义
```c++
priority_queue<Type, Container, Functional>
//数据类型，容器类型，比较方式
```
其中，Functional是一个模板头文件，确定了优先队列的比较方式。`greater`是升序，`less`是降序。