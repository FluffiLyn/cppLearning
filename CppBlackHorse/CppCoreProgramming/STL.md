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