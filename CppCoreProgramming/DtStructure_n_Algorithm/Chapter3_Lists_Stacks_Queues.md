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

# 3.2.2 Simple Linked List (单链表)
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