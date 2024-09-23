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

### 4.2.2 二叉搜索树（Binary Search Tree）
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