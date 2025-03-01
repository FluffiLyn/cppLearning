## Chapter 9 Graphs

### 9.1 图的定义与术语
一个图**G(V,E)**由**顶点（vertex）**和**边（edge）**组成，其中V是顶点的集合，E是边的集合。一条边就是(v,w)，其中v,w∈V。如果边是有序对，则图是**有向图（directed graph）**，否则是无向图。如果图中的边有权（weight）或者值（cost），则称为加权图。

顶点也称为节点（node）。边也称为弧（arc）。有向图可简写为digraph。

**路径（path）**是图中的顶点序列w1,w2,...,wn，其中每个顶点都通过边连接到下一个顶点。

路径的**长度（length of path）**是路径上边的数量，等于N-1。

**简单路径**：路径中的顶点不重复出现，但第一个和最后一个顶点可以相同。

**环**：如果路径的第一个顶点和最后一个顶点相同，则称为**环（cycle）**。
* 对于无向图，路径u,v,u不是环，因为(u,v)和(v,u)是同一条边。
* 对于有向图，路径u,v,u是环,因为(u,v)和(v,u)是不同的边。

**deg(v)**：与顶点相连的边的数量。
* 一个环贡献2度。

**相邻顶点（adjacent vertices）**：如果两个顶点之间有边，则称这两个顶点是相邻的。
* 对于有向图中的路径（u，v），u is adjacent **to** v，v is adjacent **from** u。

in-degree：指向顶点的边的数量。

out-degree：从顶点出发的边的数量。

**DAG（Directed Acyclic Graph）**：有向无环图。

**连通图（connected graph）**：无向图中，任意两个顶点都有路径相连的图。

**强连通图（strongly connected graph）**：有向图中，任意两个顶点都有路径相连的图。

**弱连通图（weakly connected graph）**：不是强连通的、去掉边的方向能得到连通图的图。

***握手定理（handshaking theorem）***：
$$2|E|=\sum_{v\in V}deg(v)$$

* 推论1：所有顶点的度数之和是偶数
* 推论2：奇数度数的顶点的数量是偶数

### 9.2 图的应用
选课系统中，顶点是课程，边是先修课程。

链表、树都可以泛化为图。

在状态机中，顶点是状态，边是状态转移。

### 9.3 图的表示
图有两种表示方法：邻接矩阵和邻接表。

#### 1、邻接矩阵（adjacency matrix）
映射为 $M(v,w)=\begin{cases}1 & \text{if } (v,w)\in E\\0 & \text{otherwise}\end{cases}$

（1）无向图的邻接矩阵是**对称的**，因为(v,w)和(w,v)是同一条边。

![无向图的邻接矩阵](pics/屏幕截图%202024-11-07%20094436.png)

（2）有向图的邻接矩阵是**非对称的**。

![有向图的邻接矩阵](pics/屏幕截图%202024-11-07%20100535.png)

性质：
* 空间复杂度：$O(V^2)$
* 对于稀疏的图，邻接矩阵的空间浪费很大。


#### 2、邻接表（adjacency list）
邻接表是标准的表示方法，每个顶点都有一个邻接表，其中包含与该顶点**相邻**的顶点列表。

(1)无向图的邻接表：

![无向图的邻接表](pics/屏幕截图%202024-11-07%20101751.png)

(2)有向图的邻接表：

![有向图的邻接表](pics/屏幕截图%202024-11-07%20101818.png)

性质：
* 空间复杂度：
  * 无向图的邻接表：$O(a|V|+2b|E|)$
  * 有向图的邻接表：$O(a|V|+b|E|)$
  * 简写为$O(|V|+|E|)$

### 9.4 拓扑排序（topological sort）
拓补排序是将所有顶点按照先后顺序排列。（有向无环图）

（有环图中的环的入度均不为0，无法进行拓扑排序）

步骤：
1. 每次选择一个**入度为0**的顶点，然后**删除**这个**点**和它的**出边**。

性质：
* 拓扑排序不唯一。（有多个入度为0的顶点时）
* 时间复杂度：$O(|V|+|E|)$
  
作用：
* 可以用拓补排序来检测有向图中是否有环。

例如：
![拓补排序](pics/屏幕截图%202024-11-11%20151350.png)

src: [图-拓扑排序](https://www.bilibili.com/video/BV1XV411X7T7/?share_source=copy_web&vd_source=06b1f610d231aea4a5a27eaa894aa2d5)

#### 实现
**关键思想**：使用一个存储所有入度为0的顶点的**队列**。
* 首先，对每个顶点计算入度。
* 然后，将所有入度为0的顶点加入初始为空的队列中。
* 当队列不为空时，从队列中删除一个顶点v，并将邻接v的所有顶点的入度减1。
* 只要一个顶点的入度降为0，就将其加入队列。此时，拓补排序就是顶点出队的顺序。

这是一种DFS的思想。

伪代码实现：
```c++
//topoNum是顶点的拓补编号
void Graph::topoSort()
{
    Queue<Vertex> q;
    int counter = 0;
    
    q.makeEmpty();
    foreach Vertex v
    {
        if (v.indegree == 0)
            q.enqueue(v);
    }

    while (!q.isEmpty())
    {
        Vertex v = q.dequeue();
        v.topoNum = ++counter;
        foreach Vertex w adjacent to v
        {
            if (--w.indegree == 0)
                q.enqueue(w);
        }
    }

    //若不是所有的顶点都被处理过，则图中有环
    if (counter != NUM_VERTICES)
        throw "Graph has a cycle";
}
```

### 9.5 最短路径问题
问题描述：给定一个图G(V,E)和一个起始顶点s，找到从s到所有其他顶点的最短路径。

变体：
- 单源->多源
- 无权->有权
- 无环->有环
- 正权->正、负权

#### 解法一：广度优先搜索（BFS）
适用：无权图；有环/无环。

基本思想：从起始顶点s开始，一层一层往外访问，规定起点是第0层，即第0层的距离为0，第N层的顶点距起点的距离为N。最少边的路径就是最短路径。

性质：
* 时间复杂度：$O(|V|+|E|)$

伪代码实现：
```c++
/*
 * dist 是 distance
 * path 是 起始顶点s 到 调用者v 的路径上的前一个顶点 
 */
void Graph::unweighted(Vertex s)
{
    Queue<Vertex> q;

    for each Vertex v
    {
        v.dist = INFINITY;// =Unmarked
    }

    while (!q.isEmpty())
    {
        Vertex v = q.dequeue();
        foreach Vertex w adjacent to v
        {
            if (w.dist == INFINITY)
            {
                w.dist = v.dist + 1;
                w.path = v;
                q.enqueue(w);
            }
        }
    }
}
```

例：
![BFS](pics/屏幕截图%202024-11-11%20165153.png)
![How it works](pics/屏幕截图%202024-11-11%20165319.png)

#### 解法二：Dijkstra算法（必考！）
适用：有权图（正权）；有环/无环。

基本思想：
1. 定义s为初始的顶点。将`权重值`看作是`边长`，定义`顶点v的距离`为`从s到v的距离`。将s的距离初始化为0，其他顶点的最短距离初始化为无穷大。

2. 定义S是已经确定了最短路径的顶点的集合，将S初始化为空集。

3. 每次从未标记的节点中选择距出发点最近的顶点v，标记v并将v加入S。

4. 计算刚加入S的顶点v的邻接顶点w的最短距离（不包含标记的顶点），若（
v的距离+（v,w）的边长）小于w的距离，则更新w的距离。

这是一种贪心算法。

性质：
* 时间复杂度：$O((n+m)logn)$
  * n是顶点数，m是边数
  * 初始化数据结构：$O(n+m)$
  * 每次选取最小距离的顶点：$O(nlogn)$
  * 更新距离：$O(mlogn)$
  * 更新前驱指针：$O(m)$

例：

![Dijkstra](pics/屏幕截图%202024-11-11%20174617.png)

解法：

![Dijkstra解法](pics/屏幕截图%202024-11-11%20174822.png)


### 9.6 图的搜索
图的搜索有两种：深度优先搜索（DFS）和广度优先搜索（BFS）。

#### DFS
1、基本思想
- 先从一条路径的起始顶点开始，一直走到不能走为止
- 然后回溯，走另一条没走过的路径

- 使用栈来实现
- 允许简单的递归实现

2、伪代码实现：

简单版（无法遍历非连通图）
```c++
void Graph::dfs(Vertex v)
{
    v.visited = true;// 标记为已访问
    // 遍历邻接顶点可以按标号从小到大进行
    foreach Vertex w adjacent to v
    {
        if (!w.visited)
            dfs(w);
    }
}
```

3、复杂度分析
- 时间复杂度：$O(|V|+|E|)$
- 空间复杂度：$O(|V|)$
#### BFS 
1、简单介绍
- 使用队列存储顶点
- 所有在相同特定距离上的顶点都被访问后，才访问下一层的顶点

2、伪代码实现：
```c++
void Graph::bfs(Vertex v)
{
    Queue<Vertex> q;

    v.visited = true;
    q.enqueue(v);

    while (!q.isEmpty())
    {   // 从队列中取出一个顶点
        Vertex v = q.dequeue();
        // 遍历所有邻接顶点
        foreach Vertex w adjacent to v
        {
            if (!w.visited)
            {
                w.visited = true;
                q.enqueue(w);
            }
        }
    }
}
```

3、复杂度分析

### 9.7 最小生成树（Minimum Spanning Tree）
众所周知如果一个无向连通图不包含回路，那么它就是一棵树。而**最小生成树**是一个连通加权图的生成树，它的所有边的权值之和最小。

构造最小生成树的策略是：
- 从一个顶点开始，添加一个最小权值且不会形成回路的边
- 重复|V|-1次，直到所有顶点都被加入生成树

下面介绍两种最小生成树算法：Prim算法和Kruskal算法。
#### Prim算法（加点法）
这是一种贪心算法。

1、基本思想：
- 选择一个顶点v作为起始顶点，将其加入生成树。
- 然后选择一个距离任何已标记的顶点 **最近（边权值最小）** 的顶点u，将u加入生成树。
- 重复上述步骤，直到所有顶点都被加入生成树。

2、伪代码实现：
```c++
void Graph::prim(Vertex v)
{
    v.marked = true;
    v.cost = 0;
    v.path = null;

    while (not all vertices are marked)
    {
        Vertex v = unmarked node u with minimum cost;
        v.marked = true;
        foreach unmarked Vertex w adjacent to v
        {
           if (cost(v,w) < w.cost)
            {
                w.cost = cost(v,w);
                w.path = v;// 或者理解为w.prev = v，连接w和v
            }
        }
    }
}
```

3、复杂度分析
- 时间复杂度：$O((n+m)logn)$
  - m=|E|, n=|V|

4、适用范围：稠密图

#### Kruskal算法（加边法）
这是一种贪心算法。

1、基本思想：
- 将所有边按照权值从小到大排序
- 从权值最小的边开始，如果这个边不会形成回路，就将这个边加入生成树
- 重复上述步骤，直到所有顶点都被加入生成树

2、伪代码实现：
```c++
void Graph::kruskal()
{
    // 初始化森林，每棵树都是一个单独的节点
    Forest F = new Forest(V);

    // 将所有边按照权值排序
    PriorityQueue<Edge> Q;
    foreach Edge e in graph
    {
        Q.insert(e)
    }

    while(F.size() < |V| - 1)
    {
        // 删除最小边并获取
        Edge e = Q.deleteMin();

        // 如果形成环则丢弃
        if (e.u == e.v) continue;

        // 否则接受该边并进行并集操作
        F.union(e.u, e.v);
    }
}
```

3、复杂度分析
- 时间复杂度：$O(mlogm)=O(mlogn)$
  - m=|E|, n=|V|

4、适用范围：稀疏图