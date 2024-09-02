# Chapter 3: Lists, Stacks and Queues

## 3.1 Abstract Data Types (ADTs)
 An ADT is a set of objects together with a set of operations.

## 3.2 The List ADT （表）
For a list of form $A_0,A_1,...,A_{N-1}$, we say that size = N. N = 0 means empty list.

For any list (except empty list), **$A_i$ succeeds/follows (后继) $A_{i-1}$**, and that **$A_{i-1}$ precedes (前驱) $A_i$**. (n. predecessor)

* First element: $A_0$. 
* Last element: $A_{N-1}$. 
* Position: $i$
.
### 3.2.1 Simple Array Implementation of Lists
printList: Linear

findKth: constant

**insert/remove:**
* worst-case: **at 0: O(N)**
* best-case: **at high end: O(1)**

## 3.2.2 Simple Linked List (单链表)
The linked list consists of a series of nodes, which are **not necessarily adjacent (相邻的) in memory**. Each node contains the **element** and a **next link**. The last cell's next link points to **nullptr**.

* printList()/find(x): Start at 1st node and traverse the list by following the next links. **Linear-time (might greater than an array)**.
* findKth(i): Traversing down the list. **O(i) time**.(However, the bound is pessimistic cuz frequently the calls to it are sorted order, such as findKth(2),findKth(3),findKth(4) can all be executed in one scan).
* remove(): Change the next pointer.
* insert(): Obtain a new node by **new** and executing two next pointer maneuvers (US ver. of "manoeuver").

## 3.3 STL vector and list
Containers.

For all STL containers:
```c++
int size() const;// returns the number of elements in the container
void clear();// removes all elements
bool empty() const;// returns true if container is empty
```

For both vector and list:
```c++
void push_back(const Object & x);// adds x to the end
void pop_back();// removes the object at the end
const Object & back() const;// returns the object at the end
const Object & front() const;// returns the object at the front
//For 3nd and 4th, a mutator that returns a ref is also provided
```

For list only:(vector does not allow efficient changes at the front)
```c++
void push_front(const Object & x);
void pop_front();
```

For vector only:(two allow indexing, and two allow view & change the internal capacity)
```c++
Object & operator[](int idx);// returns the obj at idx with NO bounds-checking (also provides an accessor that returns a constant ref)
Object $ at(int idx);// returns the obj at idx with bounds-checking (also provdes an accessor that returns a constant ref)
int capacity() const;// returns the internal capacity of the vector
void reserve(int newCapacity);// sets the new capacity. It can be used to avoid expansion of the vector
```

### 3.3.1 Iterators
In STL, a pos is represented by a nested type, **iterator**.

`STLtype<type>::iterator`

#### Getting an Iterator
```c++
iterator begin();// returns the iterator representing the first item
iterator end();// returns the iterator representing the endmarker AFTER the last item
```

#### Iterator Methods
```c++
itr++; ++itr;// advances the itr to the next location. 
*itr;// returns a ref to the obj stored at the location of "itr"
itr1 == itr2;// returns true if itr1 and itr2 refer to the same location
itr1 != itr2;
```

So the method to traverse a vector is:
```c++
vector<obj>::iterator itr = v.begin();
while(itr != v.end())
    cout << *itr++ << endl;
```

#### Container Operations That Require Iterators
```c++
iterator insert(iterator pos, const Object & x);
iterator erase(iterator pos);
iterator erase(iterator start, iterator end);
```

Example: List
```c++
template <typename T>
void removeEveryOtherItem(T & lst)
{
    auto itr = lst.begin();
    while (itr != lst.end())
    {
        itr = lst.erase(itr);
        if(itr!= lst.end())
            ++itr;
    }
}
```

### 3.3.3 const_iterators
The comiler will force you to use a **const_iterator** to traverse a constant collection.
```c++
iterator begin();
const_iterator begin() const;
iterator end();
const_iterator end() const;
```

When begin is invoked on a const container, it'll return a **const_iterator**.

Example: (begin(c) is C++11 feature)
```c++
template <typename C>
void print(const C & c, ostream &out = cout)
{
    if(c.empty()) out << "(empty)";
    else
    {
        auto itr = begin(c); //itr will be deduced to a const_iterator
        out << "[" << *itr++;
        while(itr != end(c)) out << ", " << *itr++;
        out << " ]" << endl;
    }
}
```

## 3.4 Implementation of vector
移动构造函数是一个特殊的构造函数，它能够从一个右值引用创建新的对象，而无需进行深拷贝。
```c++
Vector v1(10);        // 调用默认构造函数
Vector v2 = v1;       // 调用拷贝构造函数
Vector v3 = std::move(v1); // 调用移动构造函数
```
其中，std::move 是一个标准库函数，用于将一个对象显式地转换为右值引用，从而启用移动语义。移动语义允许资源从一个对象“移动”到另一个对象，而不是复制它们，这在处理大对象或资源密集型对象时可以显著提高性能。

一个简易的vector类实现如下：
```c++
#include <algorithm>
#include <vector>

template <typename Object>
class Vector
{
public:
    //explicit防止隐式转换
    //默认构造函数
    explicit Vector(int initSize = 0) : theSize{initSize}, theCapacity{initSize + SPARE_CAPACITY}
    {
        objects = new Object[theCapacity];
    }

    //拷贝构造函数
    Vector(const Vector & rhs) : theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{nullptr}
    {
        objects = new Object[theCapacity];
        for (int k = 0; k < theSize; ++k)
            objects[k] = rhs.objects[k];
    }

    Vector & operator=(const Vector & rhs)
    {
        Vector copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    ~Vector()
    {
        delete[] objects;
    }

    //移动构造函数
    Vector(Vector && rhs) : theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{rhs.objects}
    {
        rhs.objects = nullptr;
        rhs.theSize = 0;
        rhs.theCapacity = 0;
    }

    //移动赋值运算符
    Vector & operator=(Vector && rhs)
    {
        std::swap(theSize, rhs.theSize);
        std::swap(theCapacity, rhs.theCapacity);
        std::swap(objects, rhs.objects);

        return *this;
    }

    //改变大小
    void resize(int newSize)
    {
        if (newSize > theCapacity)
            reserve(newSize * 2);
        theSize = newSize;
    }
    //改变容量
    void reserve(int newCapacity)
    {
        if (newCapacity < theSize)
            return;

        Object *newArray = new Object[newCapacity];
        for (int k = 0; k < theSize; ++k)
            newArray[k] = std::move(objects[k]);
    
        theCapacity = newCapacity;
        std::swap(objects,newArray);
        delete[] newArray;
    }

    //重载[]运算符
    Object & operator[](int index)
    {
        return objects[index];
    }

    //常量重载[]运算符
    const Object & operator[](int index) const
    {
        return objects[index];
    }

    bool empty() const
    {
        return size() == 0;
    }

    int size() const
    {
        return theSize;
    }

    int capacity() const
    {
        return theCapacity;
    }

    //+1的原因是当theCapacity为0时，能够使newCapacity为1
    void push_back(const Object & x)
    {
        if (theSize == theCapacity)
            reserve(2 * theCapacity + 1);
        objects[theSize++] = x;
    }

    void push_back(Object && x)
    {
        if (theSize == theCapacity)
            reserve(2 * theCapacity + 1);
        objects[theSize++] = std::move(x);
    }

    void pop_back()
    {
        if (theSize > 0) {
            objects[theSize - 1].~Object(); // 调用最后一个元素的析构函数
            --theSize;
        }
    }

    const Object & back() const
    {
        return objects[theSize - 1];
    }

    typedef Object * iterator;
    typedef const Object * const_iterator;

    iterator begin()
    {
        return &objects[0];
    }

    const_iterator begin() const
    {
        return &objects[0];
    }

    iterator end()
    {
        return &objects[size()];
    }

    const_iterator end() const
    {
        return &objects[size()];
    }

    static const int SPARE_CAPACITY = 16;

private:
    int theSize;
    int theCapacity;
    Object * objects;
};
```

## 3.5 Implementation of list
一个简单的双向链表的实现：
```c++
#include <iostream>
template <typename T>
class List
{
private://定义节点结构体
    struct Node
    {
        T data;
        Node* prev;
        Node* next;

        Node (const T & d = T{}, Node* p = nullptr, Node* n = nullptr)
            : data{d},prev{p},next{n}{}

        Node (T && d, Node* p = nullptr, Node* n = nullptr)
            : data{std::move(d)},prev{p},next{n}{}
    };

public://定义迭代器
    class const_iterator
    {
    public:
        const_iterator(): current{nullptr}
        {};

        // 重载解引用
        const T& operator*() const
        {
            return retrieve();
        }

        // 重载前置递增
        const_iterator& operator++()
        {
            current = current->next;
            return *this;
        }

        // 重载后置递增
        const_iterator operator++(int)
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const const_iterator & rhs) const
        {
            return current == rhs.current;
        }

        bool operator!=(const const_iterator & rhs) const
        {
            return !(*this == rhs);
        }

    protected:
        Node* current;
        const List<T> *theList;// 保存List对象的地址
        
        const_iterator(const List<T> & lst, Node* p): theList{&lst},current{p}
        {}// 保护构造函数，只能被List类的成员函数调用

        void assertIsValid() const
        {
            if(theList == nullptr || current == nullptr || current == theList->head)
                throw std::invalid_argument{"Iterator is invalid"};
        }

        T& retrieve() const
        {
            return current->data;
        }

        const_iterator(Node* p): current{p}
        {};

        friend class List<T>;
    };

    class iterator: public const_iterator
    {
    public:
        iterator()
        {};

        T& operator*()
        {
            return const_iterator::retrieve();
        }

        const T& operator*() const
        {
            return const_iterator::operator*();
        }

        iterator& operator++()
        {
            this->current = this->current->next;
            return *this;
        }

        iterator operator++(int)
        {
            iterator old = *this;
            ++(*this);
            return old;
        }

    protected:
        iterator(Node* p): const_iterator{p}
        {};

        friend class List<T>;
    };

//定义List类的成员函数
public:
    List()
    { init();}

    ~List()
    {
        clear();
        delete head;
        delete tail;
    }

    List(const List& rhs)
    {
        init();
        for(auto & x : rhs)
            push_back(x);
    }

    List& operator=(const List & rhs)
    {
        List copy = rhs;
        std::swap(*this,copy);
        return *this;
    }

    List(List&& rhs)
        : theSize{rhs.theSize},head{rhs.head},tail{rhs.tail}
    {
        rhs.theSize = 0;
        rhs.head = nullptr;
        rhs.tail = nullptr;
    }

    List& operator=(List && rhs)
    {
        std::swap(theSize,rhs.theSize);
        std::swap(head,rhs.head);
        std::swap(tail,rhs.tail);

        return *this;
    }

    iterator begin( )
    { return { head->next }; }
    
    const_iterator begin( ) const
    { return { head->next }; }
    
    iterator end( )
    { return { tail }; }
    
    const_iterator end( ) const
    { return { tail }; }

    int size() const
    { return theSize; }

    bool empty() const
    { return size() == 0; }

    void clear()
    {
        while(!empty())
            pop_front();
    }

    T& front()
    { return *begin(); }

    const T& front() const
    { return *begin(); }

    T& back()
    { return *--end(); }

    const T& back() const
    { return *--end(); }

    void push_front(const T & x)
    { insert(begin(),x); }

    void push_front(T && x)
    { insert(begin(),std::move(x)); }

    void push_back(const T & x)
    { insert(end(),x); }

    void push_back(T && x)
    { insert(end(),std::move(x)); }

    void pop_front()
    { erase(begin()); }

    void pop_back()
    { erase(--end()); }

    //在迭代器指向的元素之前插入元素
    iterator insert(iterator itr,const T & x)
    {
        Node* p = itr.current;
        theSize++;
        return { p->prev = p->prev->next = new Node{x,p->prev,p} };
    }

    iterator insert(iterator itr,T && x)
    {
        Node* p = itr.current;
        theSize++;
        return { p->prev = p->prev->next = new Node{std::move(x),p->prev,p} };
    }

    //删除迭代器指向的元素
    iterator erase(iterator itr)
    {
        Node* p = itr.current;
        iterator retVal{p->next};
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        theSize--;

        return retVal;
    }

    //删除区间[from,to)的元素
    iterator erase(iterator from,iterator to)
    {
        for(iterator itr = from;itr != to;)
            itr = erase(itr);

        return to;
    }
private:
    int theSize;
    Node * head;
    Node * tail;
    
    void init()
    {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }
};
```

## 3.6 The Stack ADT

### 3.6.1 Stack Model
Fundamental operations: 
* push (equivalent to insert)
* pop (deletes the most recently inserted element)

Stack model: Only the top element is accessible.
 ![Stack](https://tse1-mm.cn.bing.net/th/id/OIP-C.PoJpa5-ZfQQfl0QryBDGvwHaFj?rs=1&pid=ImgDetMain)

### 3.6.2 Implementation of Stacks
1. Using simple linked list 
   * push: by inserting at the front of the list.
   * pop: by deleting the element at the front.
   * top: returning the value of element at the front.

2. Using array (vector)
Array is probably the more popularr solution.
   * push: by push_back().
     * increment `topOfStack` then set `arr[topOfStack] = x`. 
   * pop: by pop_back().
     * set the return value to `arr[topOfStack]` then decrement `topOfStack`.
   * top: by back().

For an empty stack, `topOfStack` is -1. (init)

```
出栈时返回栈顶的值，可以方便使用被移除的元素。
```

### 3.6.3 Application of Stack

#### Balancing Symbols
Compiler check your programs for syntax errors.

For example, [()] is valid, but [(]) is invalid.

1. Make an empty stack. Read characters until EOF.
2. If char is an opening symbol, push it onto the stack.
3. If it is a closing symbol & the stack is empty, report an error. Otherwise, pop the stack. 
4. If the symbol popped isn't the corresponding opening symbol, report an error.
5. At EOF, if the stack isn't empty, report an error.

#### Postfix Expressions
Postfix notation / reverse Polish notation

Normal: $4.99 * 1.06 + 5.99 + 6.99 * 1.06$
Postfix: $4.99 1.06 * 5.99 + 6.99 1.06 * +$

Example: 6 5 2 3 + 8 * + 3 + * is evaluated as follows:
```
The first four numbers are placed.
3 <-top
2
5
6
```

```
'+' is read, so 3 and 2 are popped, and the sum 5 is pushed.
5
5
6
```