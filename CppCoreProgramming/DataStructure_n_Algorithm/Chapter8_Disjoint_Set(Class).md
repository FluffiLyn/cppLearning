## Chapter 8 Disjoint Set(Class)
### 8.1 概述
并查集（或称不相交集合）是一种数据结构，它的实现是森林（树的集合），
每棵树表示一个集合，树的根节点是集合的代表元素。

并查集用于处理不相交集合的合并与查询问题。

### 8.2 等价关系
关系R定义在集合S上，如果对于任意一个有序对(a,b)∈R，都有a∈S，b∈S，则称R是S上的一个关系。

如果R是S上的一个关系，且满足下列性质：
1. 自反性（Reflexive）：∀a∈S, aRa
2. 对称性（Symmetric）：aRb iff bRa
3. 传递性（Transitive）：aRb, bRc -> aRc

则称R是S上的等价关系，记作~。

### 8.3 等价类
设R是S上的一个等价关系。与S中的一个元素a**有关系**的所有元素的集合称为**a的等价类**。记作$[a]_R$。只考虑一个关系时，简写为$[a]$，a称为等价类的**代表元素**。

$[a]_R=\{x|(x,a)\in R\}$

等价类是并查集。

例如：考虑整数集Z，对mod3同余，可将Z划分为三个等价类：
* $[0]_R=\{x|x\equiv0(mod 3)\}$
* $[1]_R=\{x|x\equiv1(mod 3)\}$
* $[2]_R=\{x|x\equiv2(mod 3)\}$

### 8.4 动态等价性问题
问题：给定一个等价关系~，对任意的a,b∈S，判断是否满足a ~ b。

解决：使用并查集。基本操作：
- Find(a):返回代表元素所在的所有**等价类**
- Union(x,y):合并两个类

性质：该算法是动态的，且是联机的。

### 8.5 并查集数据结构分析与简单实现
#### 8.5.1 数据结构分析
我们用**数组up[]**来隐式表示**森林**，用树表示每一个集合，开始时每个集合只有一个元素，即树的根节点。

根节点的**索引**表示这个集合的**名字**。数组的每个成员**up[i]**代表元素i的父亲；如果i是根节点，则up[i]=-1。

现在有一个数组，初始状态如下：

![初始状态](pics/屏幕截图%202024-11-04%20152656.png)

它们内部的关系如下：

![内部关系](pics/屏幕截图%202024-11-04%20163339.png)

查找操作：find(a)返回a所在集合的根节点。例如：
* find(6)=7，find(2)=1

合并操作：union(x,y)将y所在树的根节点指向x。例如：
* union(1,7)

时间复杂度：
* find(a)：O(h)，h是树的高度
* union(x,y)：O(1)，因为只需要修改一个元素的值

#### 8.5.2 简单实现
1、定义类
```c++
class DisjSets
{
public:
    explicit DisjSets(int numElements);
    
    int find(int x) const;
    int find(int x);
    void unionSets(int root1, int root2);

private:
    vector<int> up;//up[i]表示i的父节点，如果i是根节点，则up[i]=-1
};
```

2、实现
```c++
//构造函数
DisjSets::DisjSets(int numElements) : s(numElements, -1) {} 

//简单不相交集合的查找
//建议迭代而非递归
int DisjSets::find(int x) const
{
    while (up[x] >= 0)
    {
        x = up[x];
    }
    return x;
}

//并集（不是最好的实现）
//不检查错误
void DisjSets::unionSets(int root2, int root1)
{
    up[root2] = root1;
}
```

### 8.6 进阶：并查集的优化实现
#### 8.6.1 加权合并（Weighted Union）
加权指的是将**节点的数量**作为合并的依据。
- 加权合并总是将**节点少**的树合并到**节点多**的树上

加权的原因是：假设每次都是将节点长的树合并到节点短的树上，那么树的高度会增加，最终影响查找的效率。

如图，黄色数字代表当前树的权重，也即节点数。
![加权合并](pics/屏幕截图%202024-11-04%20175338.png)

我们用一个数组weight[]来表示每个树的权重，初始时每个树的权重都是1。
![数组weight](pics/屏幕截图%202024-11-04%20180313.png)


性质：
- 时间复杂度： $O(log_2N)=O(h)$，h是树的高度

实现：
```c++
//新增weight数组
class DisjSets
{
    //...
private:
    vector<int> up;
    vector<int> weight;
};

void disjSets::unionSets(int r1, int r2)
{
    w1 = weight[r1];
    w2 = weight[r2];

    if (w1 < w2)
    {
        up[r1] = r2;
        weight[r2] = w1 + w2;
    }
    else
    {
        up[r2] = r1;
        weight[r1] = w1 + w2;
    }
}
```

#### 8.6.2 路径压缩（Path Compression）


### 8.7 示例：生成迷宫
问题：给定一组方格、起点和终点，通过移除边的方式生成一个从起点到终点的迷宫。要求：
* 不允许移除边界
* 不允许生成环
* 每个方格都可以到达

![问题](pics/屏幕截图%202024-11-04%20145717.png)

思路：设全部方格的不相交集合为S，其中每个方格都是一个集合。设边的集合为E，用(a,b)代表ab之间的边，一共有60条边。
   * $S = \set{\set{1},\set{2},...,\set{36}}$
   * $E = \set{(1,2),(1,7),...,}$
   * Maze = set of maze edges initially empty
伪代码实现：
```
while (there are more than one set in S)
{
    randomly select an edge (a,b) from E
    u = find(a), v = find(b);
    if (u != v)
    {
        union(u,v);
    }
    else
    {
        add (a,b) to Maze;
    }
}
```
