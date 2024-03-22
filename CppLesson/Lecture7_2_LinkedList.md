# 01 Linked List Introduction
【1】概念：链表是一种物理存储结构上非连续、非顺序的存储结构，数据元素的逻辑顺序是通过链表中的指针链接次序实现的。


【2】组成：由一系列节点（Node）通过指针连接而成，从一个头节点（Head）开始，头节点作为链表的入口点，它包含了对第一个节点的引用。最后一个节点的指针指向一个空值（NULL），表示链表的结束。


【3】存储：链表在内存中的存储方式则是随机存储（见缝插针），每一个节点分布在内存的不同位置，依靠指针关联起来。（只要有足够的内存空间，就能为链表分配内存）


【4】优缺点：相对于顺序储存（例如数组）：

优点：链表的插入操作更快（ O(1) ），无需预先分配内存空间

缺点：失去了随机读取的优点（需要从头节点开始依次遍历，直到找到目标节点。），内存消耗较大（每个节点都需要存储指向下一个节点的指针）。


```c++
struct node
{
    node * next;
    char name[20];
    double salary;
};
```
* If we add a pointer member in the node (节点), we can link all the nodes together.

* Then we define a struct pointer *head*, which points to the first node. We can get a linked list:
```c++
struct node
{
    node * next;
    char name[20];
    double salary;
} * head;
```
![图片](pics\Lecture7_2_01.jpg)

# 02 Create a Linked List
```c++
struct node
{
    int data;
    node * next;
} node * head;

node * CreateList()
{
    node * s, * p;
    s = new node;

    cin >> s -> data;
    head = NULL;

    while (s -> data != 0)
    {
        if (head == NULL)
            head = s;
        else
            p -> next = s;

        s = new node;
        cin >> s -> data;
    }
    p -> next = NULL;
    delete s;
    return (head);
}
```
这段代码是一个简单的链表创建函数。它使用了一个结构体 node 来表示链表节点，每个节点包含一个整数型数据 data 和一个指向下一个节点的指针 next。

首先，在全局范围内定义了一个 node* 类型的变量 head，用于指向链表的头节点。

然后，定义了一个名为 CreateList() 的函数，该函数返回一个指向链表头节点的指针。

在函数内部，首先声明了两个 node* 类型的变量 s 和 p，分别用于创建新的节点和遍历链表。

接下来，通过 new 运算符为 s 分配了一个新的节点，并从标准输入读取一个整数值，将其赋给节点的 data 成员。

然后，初始化 head 为 NULL，表示链表为空。

在接下来的循环中，如果 s->data 不等于 0，则执行以下操作：

如果 head 为 NULL，即链表为空，将 s 赋值给 head，表示当前节点为链表的头节点。
否则，将 s 赋值给 p->next，将当前节点连接到链表中。
然后，再次使用 new 运算符为 s 分配一个新的节点，并从标准输入读取下一个整数值。

循环结束后，将 p->next 设置为 NULL，表示链表的最后一个节点。

最后，释放 s 所指向的内存，返回 head，即链表的头节点的指针。

这段代码的作用是根据用户从标准输入中输入的整数值来创建一个链表，并返回链表的头节点的指针。用户通过输入 0 来结束链表的创建。

# 03 Insert a Node
## 1. Insert a node after *p
```c++
s -> next = p -> next;
p -> next = s;
```

## 2. Insert a node before *p
```c++
//Method 1: Find the *q which points to *p
s -> next = p;
q -> next = s;
```
```c++
//Method 2: 
//(1) Insert the node after *p
//(2) swap *p and the new node
s -> next = p -> next;
p -> next = s;

t = p -> data;
p -> data = s -> data;
s -> data = t;
```

# 04 Delete a node

## 1. Delete the first node
```c++
p = head;
head = head -> next;
delete p;
```

## 2. Delete node *p
```c++
//Find the *q which points to *p
q -> next = p -> next;
delete p;
```