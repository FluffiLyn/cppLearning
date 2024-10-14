## 4.1 Prelim
树是n（n>=0）个结点的有限集。当n = 0时，称为空树。在任意一棵非空树中应满足：
1. 且仅有一个特定的称为根的结点。
2. 当n>1时，其余节点可分为m（m>0）个互不相交的有限集T1,T2,…,Tm，其中每个集合本身又是一棵树，并且称为根的子树。

显然，树的定义是**递归**的，即在树的定义中又用到了自身，树是一种递归的数据结构。树作为一种逻辑结构，同时也是一种分层结构，具有以下两个特点：

1. 树的**根结点**没有**前驱**，除根结点外的所有结点有且只有一个前驱。
2. 树中所有结点可以有零个或多个后继。

因此n个结点的树中有n-1条边。

其他：
* 没有子节点的节点叫做**叶子节点（leaf）**
* 具有相同父节点的多个节点互为**兄弟节点（siblings）**。祖父、孙子节点的定义类似。

* **路径(path)**：从节点$n_1$到$n_k$的路径是节点$n_1,n_2,...,n_k$的序列。
* **边长（length）**：该路径上的边的条数。
* **深度（depth）**：从**根**到$n_i$的**唯一路径**的边长。根的深度为0.
* **高度（height）**：从$n_i$到一片树叶的最长路径的长。树叶的高度为0.

* 如果存在$n_1$到$n_2$的一条路径，那么$n_1$是$n_2$的**祖先**（ancestor），而后者是前者的**后裔（descendant）**。如果$n_1 \neq n_2$，那么是真祖先、真后裔（proper ancestor/proper descendant）。

### 4.1.1 Implementation of Trees
由于每个节点的儿子节点可能变化很大且不可预知，因此直接建立各子节点的链接是不可行的。

以下为“孩子-兄弟表示法”（Child-Sibling Representation），可将所有的树以二叉树的形式表现,从而为所有的树使用二叉树的操作。每个节点的所有儿子放在树节点的链表中。
```c++
struct TreeNode
{
    Object data;
    TreeNode *firstChild;//左指针指向自己的第一个孩子
    TreeNode *nextSibling;//右指针指向与自己相邻的兄弟
};
```
![孩子兄弟表示法](https://img2020.cnblogs.com/blog/1662740/202104/1662740-20210402212730970-481741869.png)

### 4.1.2 树的遍历
树的常用应用就是操作系统中的文件目录结构。

#### 深度优先遍历

##### 前序遍历 （preorder tree walk）
* 先访问根节点，然后访问左子树，最后是右子树
![前序遍历](https://www.runoob.com/wp-content/uploads/2020/09/traverse-02.png)

```c++
void preOrder(TreeNode *node) 
{
    //首先判空
    if (node == nullptr) 
    {
        return;
    }
    // 访问当前节点的数据
    cout << node->data << " ";
    // 递归访问左子树
    preOrder(node->left);
    // 递归访问右子树
    preOrder(node->right);
}
```

##### 中序遍历（inorder tree walk）
* 先递归访问左子树，再访问自身，最后递归访问右子树
![中序遍历](https://www.runoob.com/wp-content/uploads/2020/09/traverse-01.png)

```c++
void inOrder(TreeNode *node) 
{
    if (node == nullptr) 
    {
        return;
    }
    // 递归访问左子树
    inOrder(node->left);
    // 访问当前节点的数据
    cout << node->data << " ";
    // 递归访问右子树
    inOrder(node->right);
}
```

##### 后序遍历
* 先递归访问左、右子树，再访问自身节点。
![后序遍历](https://www.runoob.com/wp-content/uploads/2020/09/traverse-03.png)

```c++
void inOrder(TreeNode *node) 
{
    if (node == nullptr) 
    {
        return;
    }
    // 递归访问左子树
    inOrder(node->left);
    // 递归访问右子树
    inOrder(node->right);
    // 访问当前节点的数据
    cout << node->data << " ";
}
```

## 4.2 Binary Trees 二叉树
定义：二叉树是n(n>=0)个结点的有限集合，该集合或为空集（称为空二叉树），或由一个根结点和两棵互不相交的、分别称为根结点的左子树和右子树组成。

性质：
1. 在二叉树的第$i$层上最多有$2^{i-1}$个节点
2. 二叉树中如果深度为k，那么最多有$2^k-1$个节点
3. $n_0 = n_2 1$，其中$n_0$是度为0的节点数，$n_2$是度为2的节点数。

### 4.2.1 各种二叉树

#### 斜树
定义：所有节点只有左子树或右子树的二叉树称为斜树。斜树分为左斜树和右斜树。

![斜树](https://pic3.zhimg.com/v2-070d6c38620f184c39bfa6f63335c378_r.jpg)

#### 满二叉树
定义：**所有分支节点都有左子树和右子树**，并且**所有叶子都在同一层上**的二叉树称为满二叉树。

特点：
1. 叶子只能出现在最下一层，出现在其他层就不可能达成平衡。
2. 非叶子节点的度一定是2。
3. 在同样深度的二叉树中，满二叉树的节点个数最多，叶子数最多。

![满二叉树](https://pic4.zhimg.com/v2-73700a3984cdb1543f036e04b9c5f7c9_r.jpg)

#### 完全二叉树
定义：对一棵具有n个结点的二叉树按层序编号，如果编号为i(1<=i<=n)的结点与同样深度的**满二叉树**中编号为i的结点在二叉树中位置完全相同，则这棵二叉树称为完全二叉树。

通俗地说，完全二叉树的特点是：
1. 除了最后一层，其他层的节点数都是满的。
2. 最后一层的节点都从左到右依次排列，中间没有空缺。

其他特点：
1. 叶子节点只能出现在最下两层。
2. 最下层的叶子一定集中在左部连续位置。
3. 倒数第二层，若有叶子节点，一定都在右部连续位置。这意味着在倒数第二层的叶子结点出现在树的右侧，并且是连续的。
4.  如果一个结点的度为1（只有一个子节点），那么该结点只能有左子节点，即没有右子树。
5.  同样节点数的二叉树，完全二叉树的深度最小。
6. 与满二叉树的关系：
   * 满二叉树$\Rightarrow$完全二叉树
   * 完全二叉树$\nRightarrow$满二叉树

### 4.2.2 Binary Search Tree 二叉搜索树
概念：二叉搜索树（Binary Search Tree，简写BST）的任何一个节点的**左子树**上的点，都必须**小于**当前节点。任何一个节点的**右子树**上的点，都必须**大于**当前节点。所有的子树也必须满足上面两个条件。

二叉搜索树上的基本操作所花费的时间与这棵树的高度成正比。对于一个有 n 个结点的二叉搜索树中，这些操作的最优时间复杂度为 O(\log n)，最坏为 O(n)。随机构造这样一棵二叉搜索树的期望高度为 O(\log n)。

```c++
//Binary search tree class skeleton
template <typename Comparable>
class BinarySearchTree
{
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree &rhs);
    BinarySearchTree(BinarySearchTree &&rhs);
    ~BinarySearchTree();

    const Comparable &findMin() const;
    const Comparable &findMax() const;
    bool contains(const Comparable &x) const;
    bool isEmpty() const;
    void printTree(std::ostream &out = std::cout) const;

    void makeEmpty();
    void insert(const Comparable &x);
    void insert(Comparable &&x);
    void remove(const Comparable &x);

    BinarySearchTree &operator=(const BinarySearchTree &rhs);
    BinarySearchTree &operator=(BinarySearchTree &&rhs);

private:
    struct BinaryNode
    {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const Comparable &theElement, BinaryNode *lt, BinaryNode *rt)
            : element{theElement}, left{lt}, right{rt} {}
        BinaryNode(Comparable &&theElement, BinaryNode *lt, BinaryNode *rt)
            : element{std::move(theElement)}, left{lt}, right{rt} {}
    };

    BinaryNode *root;

    void insert(const Comparable &x, BinaryNode *&t);
    void insert(Comparable &&x, BinaryNode *&t);
    void remove(const Comparable &x, BinaryNode *&t);
    BinaryNode *findMin(BinaryNode *t) const;
    BinaryNode *findMax(BinaryNode *t) const;
    bool contains(const Comparable &x, BinaryNode *t) const;
    void makeEmpty(BinaryNode *&t);
    void printTree(BinaryNode *t, std::ostream &out) const;
    BinaryNode *clone(BinaryNode *t) const;
};
```

#### contains
```c++
bool contains(const Comparable &x, BinaryNode *t) const
{
    if (t == nullptr)
        return false;
    else if (x < t->element)
        return contains(x, t->left);
    else if (t->element < x)
        return contains(x, t->right);
    else
        return true; // Match
}
```
如果树为空，返回false；如果x小于当前节点的值，递归查找左子树；如果x大于当前节点的值，递归查找右子树；如果相等，返回true。

#### findMin 和 findMax
To perform a findMin, start at the root and go left until you reach a node that does not have a left child. This node is the minimum node in the tree. The findMax operation is similar, but you go right instead.

```c++
//递归实现
BinaryNode * findMin(BinaryNode* t) const
{
    if (t == nullptr)
        return nullptr;
    return t->left == nullptr ? t : findMin(t->left);
}
```
```c++
//迭代实现
BinaryNode * findMin(BinaryNode* t) const
{
    if (t != nullptr)
        while (t->left != nullptr)
            t = t->left;
    return t;
}
```

#### insert
```c++
// x is the item to insert.
// t is the node that roots the subtree.
void insert(const Comparable &x, BinaryNode *&t)
{
    if (t == nullptr)
        t = new BinaryNode{x, nullptr, nullptr};
    else if (x < t->element)
        insert(x, t->left);
    else if (t->element < x)
        insert(x, t->right);
    else
        return; // Duplicate; do nothing
}
```

右值引用版本：
```c++
void insert(Comparable &&x, BinaryNode *&t)
{
    if (t == nullptr)
        t = new BinaryNode{std::move(x), nullptr, nullptr};
    else if (x < t->element)
        insert(std::move(x), t->left);
    else if (t->element < x)
        insert(std::move(x), t->right);
    else
        return; // Duplicate; do nothing
}
```
当我们不再需要x时，可以用右值引用将其值移动到新节点中，而不是复制。

#### remove
许多数据结构最困难的操作是删除。删除一个节点可能会导致树的结构发生变化，因此需要小心处理。
1. 如果节点是树叶，可以直接删除。
2. 如果节点有一个子节点，可以用子节点替换该节点。
![删除节点](pics/屏幕截图%202024-09-23%20164440.png)

3. 如果节点有两个子节点：（一般策略：）
    * 找到右子树的最左子节点（也即右子树 中序遍历 的第一个节点）
    * 将它的值与要删除的节点的值交换
    * 删除右子树的最左子节点，相当于删除了我们要删除的节点


为什么要找右子树的最左子节点？
1. 保持二叉搜索树的性质
    * 用这个节点的值替换要删除节点的值，可以确保替换后的树仍然满足二叉搜索树的性质。因为这个节点是右子树的最小值，所以它的值大于左子树的所有节点，小于右子树的所有节点。
2. 简化删除操作
    * 右子树的最左子节点没有左子节点（否则它就不是最左子节点），这使得删除这个节点变得简单。
    * 删除这个节点只需要调整它的父节点的指针，而不需要处理复杂的子树重组。

```c++
// x is the item to remove.
// t is the node that roots the subtree.
void remove(const Comparable &x, BinaryNode *&t)
{
    // 判空
    if (t == nullptr)
        return;
    // 递归查找 
    if (x < t->element)
        remove(x, t->left);
    else if (t->element < x)
        remove(x, t->right);
    // 两个子节点的情况
    else if (t->left != nullptr && t->right != nullptr)
    {
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);
    }
    // 处理有一个或零个子节点的情况
    else
    {
        BinaryNode *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
    }
}
```

#### Destructor and Copy Constructor
Destructor
```c++
~BinarySearchTree()
{
    makeEmpty();
}
void makeEmpty(BinaryNode *&t)
{
    if (t != nullptr)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}
```

Copy Constructor
```c++
BinarySearchTree(const BinarySearchTree &rhs): root{nullptr}
{
    root = clone(rhs.root);
}
BinaryNode *clone(BinaryNode *t) const
{
    if (t == nullptr)
        return nullptr;
    else
        return new BinaryNode{t->element, clone(t->left), clone(t->right)};
}
```

#### 时间复杂度分析
二叉树预期的时间复杂度是$O(logN)$。

* 令D(N)为具有N个节点的某棵树的**内部路径长**（所有节点的深度之和），D(1)=0。一颗N节点树是由一颗**i个节点左子树**和一颗**(N-i-1)个节点右子树**以及深度0处的一个根节点组成的，其中$0\leq i < N$。

* 左子树和右子树的**所有节点**在原树中的深度都比它们在子树中的深度**多1**。因此，
  * 左子树的每个节点的深度增加1，总共增加(i)次。
  * 右子树的每个节点的深度增加1，总共增加(N-i-1)次。

* 左子树的内部路径长为D(i)，加上每个节点深度增加的(i)次，**总共为(D(i)+i)**。
* 右子树的内部路径长为D(N-i-1)，加上每个节点深度增加的(N-i-1)次，**总共为(D(N-i-1)+(N-i-1))**。

因此，我们有递推关系：$D(N)=(D(i)+i)+(D(N-i-1)+(N-i-1))$

化简得$D(N) = D(i) + D(N-i-1)+N-1$

如果所有子树是等概率的（对二叉查找树是成立的，但二叉树不一定），那么我们可以得到：
D(i)和D(N-i-1)的平均值都是$\displaystyle\frac{1}{N}\sum_{j=0}^{N-1}D(j)$，因此：

* $D(N)=2\displaystyle\frac{1}{N}\sum_{j=0}^{N-1}D(j)+N-1$（在第七章会求解）

得到$D(N)=O(NlogN)$

#### 二叉搜索树的平衡
然而，二叉搜索树的相关操作平均运行时间不一定一直是O(logN)。原因在于**删除操作**。之前所写的删除算法会导致左子树比右子树更深，这是因为我们总是选择右子树的最小节点来替换要删除的节点。这样会导致树的高度增加，从而使得查找操作的时间复杂度增加。最终，二叉搜索树可能会退化为链表，时间复杂度变为O(N)。

如果交替插入和删除$\Theta(N^2)$次，那么树期望的深度是$\sqrt\Theta(N)$。

平衡的方法：
1. 用一些算法实现平衡查找树，如AVL树。
2. 放弃平衡，使用自调整类的数据结构，如伸展树（splay tree）。

## 4.3 AVL树
AVL（Adelson-Velsky and Landis）树是一种自平衡二叉搜索树。在AVL树中，任何节点的左右子树的**高度最多相差1**。空树的高度定义为**-1**。如果在插入或删除节点后，树的高度差超过1，那么需要通过旋转操作来重新平衡树。

![AVL树](pics/屏幕截图%202024-09-27%20165350.png)

在高度为h的AVL树中，最少的节点数是$S(h)=S(h-1)+S(h-2)+1,(h\geq 2)$，并且$S(0)=1,S(1)=2$。也即：左子树（每个节点都只有一个左子树）节点+右子树（每个节点都只有一个右子树）节点+ 根节点。

当插入一个节点后，可能会导致AVL树失去平衡。为了重新平衡树，我们需要通过**旋转**操作来调整树的结构。不平衡的情况有四种：
1. 左子树的左子树插入（LL）
2. 左子树的右子树插入（LR）
3. 右子树的左子树插入（RL）
4. 右子树的右子树插入（RR）

1,4的情况是插入发生在“外边”的情况，用单旋转；

2,3的情况是插入发生在“内部”的情况，用双旋转。

### 4.3.1 单旋转


### 4.3.2 双旋转


### 4.3.3 AVL树代码实现
AVL树节点
```c++
struct AvlNode
{
    Comparable element;
    AvlNode* left;
    AVlNode* right;
    int height;

    AvlNode(const Comparable& ele, AvlNode* lt, AvlNode* rt, int h = 0): element{ele}, left{lt}, right{rt},height{h}{}

    AvlNode(const Comparable& ele, AvlNode* lt, AvlNode* rt, int h = 0): element{std::move(ele)}, left{lt}, right{rt},height{h}{}
}
```

获取高度
```c++
int height(AvlNode *t) const
{
    return t == nullptr ? -1 : t->height;
}
```

插入与平衡
```c++
// x is the item to insert
void insert(const Comparable& x, AvlNode*& t)
{
    if (t == nullptr)
        t = new AvlNode{x,nullptr,nullptr};
    else if (x < t->element)
        insert(x, t->left)
    else if (x > t->element)
        insert(x, t->right)

    balance(t);
}

void balance(AvlNode*& t)
{
    if(t == nullptr)
        return;

    // ALLOWED_IMBALANCE = 1
    if(height(t->left) - height(t->right) > ALLOWED_IMBALANCE)
    {
        // 左子树比右子树高，需要右旋或者双旋处理
        if (height(t->left->left) >= height(t->left->right))
            // LL型不平衡：直接对节点进行右旋转
            rotateWithLeftChild(t);
        else
            // LR型不平衡：先对左子节点左旋，再对当前节点右旋
            doubleWithLeftChild(t);
    }
    else if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE)
    {
        // 右子树比左子树高，需要左旋或者双旋处理
        if (height(t->right->right) >= height(t->right->left))
            // RR型不平衡：直接对节点进行左旋转
            rotateWithRightChild(t);
        else
            // RL型不平衡：先对右子节点右旋，再对当前节点左旋
            doubleWithRightChild(t);
    }

    // 更新节点的高度信息
    t->height = max(height(t->left),height(t->right)) + 1;
}
```

单旋转-左旋转
```c++

void rotateWithLeftChild(AvlNode*& k2)
{
    AvlNode* k1 = k2->left;//
    k2->left = k1->right;//
    k1->right = k2;//
    k2->height = max(height(k2->left),height(k2->right)) + 1;
    k1->height = max(height(k1->left),k2->height) + 1;
    k2 = k1;
}
```