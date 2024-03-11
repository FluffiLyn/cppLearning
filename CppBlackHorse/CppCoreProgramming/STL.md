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