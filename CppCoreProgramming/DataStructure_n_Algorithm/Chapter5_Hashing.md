## Chapter 5: Hashing
哈希表（hash table），也称散列表，是一种数据结构，用于存储键值对（key-value pair）。

* 哈希函数：每个键被映射到0~TableSize-1的一个整数，这个整数称为哈希值（hash value），这个映射称为哈希函数（hash function）。

* 哈希表的核心思想：通过哈希函数将键映射到特定的索引位置。


哈希表的性质：
* 哈希表中的键值对是无序的。（相比于树）
* 任何操作的时间复杂度是O(1)

冲突（collision）：两个键映射到同一个位置。

### 5.1 哈希函数的选择
#### 5.1.1 直接寻址表（Direct Address Table）
直接寻址表使用数组实现，非常快速。

直接寻址表的使用条件：
* 键是在集合U中的**整数**，U={0,1,2,...,m-1}
* m是一个较小的数。
* 任意两个键的值**不相同**。

以下是简单实现（无检查）
```c++
class DirectAddressTable
{
private:
    int* table;
    int size;

public:
    DirectAddressTable(int m) : size(m) 
    {
        table = new int[m];
        for (int i = 0; i < m; ++i) 
        {
            table[i] = -1; // Initialize table with -1 indicating empty slots
        }
    }

    ~DirectAddressTable() 
    {
        delete[] table;
    }

    void insert(int key, int value) 
    {
        table[key] = value;
    }

    void remove(int key) 
    {
        table[key] = -1; // Mark slot as empty
    }

    int search(int key) 
    {
        return table[key];
    }
};

//对外接口
void Insert(DirectAddressTable& table, int key, int value) 
{
    table.insert(key, value);
}
int Find(DirectAddressTable& table, int key) 
{
    return table.search(key);
}
```
缺点：
* 如果U很大，且大部分键没有被使用，那么直接寻址表会浪费大量的空间。此时应当缩小键的范围。
* 
#### 5.1.2 处理字符串键
通常，键是字符串。

方法一：将字符串中的每个字符转换为ASCII码，然后求和。（设所有的关键字最长为8个字符）
* 缺点：由于ASCII码的范围是0~127，所以哈希值的范围是0~1016，这样会导致冲突。

方法二：如下：假设Key至少有3个字符。
```c++
int hash(const string& key, int tableSize)
{
    return (key[0] + 27*key[1] + 729*key[2]) % tableSize;
}
其中27表示英文字母表的字母外加一个空格的总数，729表示27^2。
```
* 缺点：3个字符有17,576种可能组合，但实际上三个字母的组合仅有2851，会造成极大的浪费。

方法三：取模运算
```
s = n mod m，m是表的大小，且为素数
```

方法四：Horner法则

方法n...
#### 总结
哈希函数的选择取决于键的性质。如果关键字特别长，那么散列函数计算的时间会很长。我们应该选择部分字符作为关键字，例如，前三个字（符合某种规律）。

### 5.2 冲突解决：两个键映射到同一个位置
我们必须保证映射是一对一的，解决冲突。比如世界上有很多人的生日是同一天，但是我们只有365个位置来存储生日。

#### 5.2.1 使用链表：分离链接法（Separate Chaining）
将哈希表的每个位置的所有元素都保存到一个链表。若空间充足，可以直接使用std::list，反之则应自己实现单链表。

假设键是前10个完全平方数，设hash(x)=x mod 10，那么哈希表如下：

![哈希表](./pics/屏幕截图%202024-10-12%20145114.png)

分离链接哈希表的类型声明：
```c++
template <typename HashedObj>
class HashTable
{
public:
    explicit HashTable(int size = 101);
    
    bool contains(const HashedObj& x) const;

    void makeEmpty();

    bool insert(const HashedObj& x);
    bool insert(HashedObj&& x);
    bool remove(const HashedObj& x);

private:
    vector<list<HashedObj>> theLists;
    int currentSize;

    void rehash();
    size_t myhash(const HashedObj& x) const;
};
```

具体实现：
* search：使用哈希函数找到位置，然后在链表中查找。

* insert：先检查是否已经存在（如果允许重复，则通常要留一个额外的字段，匹配事件时字段+1），否则将新元素插入到链表的头部（方便，且新插入的元素可能不久又被访问）。


```c++
void makeEmpty()
{
    for (auto& thisList : theLists)
    {
        thisList.clear();
    }
}

bool contains(const HashedObj& x) const
{
    auto& whichList = theLists[myhash(x)];
    return find(begin(whichList), end(whichList), x) != end(whichList);
}

bool remove(const HashedObj& x)
{
    auto& whichList = theLists[myhash(x)];
    auto itr = find(begin(whichList), end(whichList), x);

    if (itr == end(whichList))
    {
        return false;
    }

    whichList.erase(itr);
    --currentSize;
    return true;
}

bool insert(const HashedObj& x)
{
    auto& whichList = theLists[myhash(x)];
    if (find(begin(whichList), end(whichList), x) != end(whichList))
    {
        return false;
    }

    whichList.push_back(x);

    if (++currentSize > theLists.size())
    {
        rehash();
    }

    return true;
}
```
注：rehash()函数在5.5节中讨论。

#### 5.2.2 不使用链表：开放寻址法（Open Addressing）
链表的缺点：给新单元分配地址需要时间，会减慢算法。

定义哈希表的装填因子（load factor）$\lambda = \frac{n}{m}$，其中n是表中元素的个数，m是表的大小。链表的平均长度是$\lambda$。

另一种不用链表解决冲突的方法是，当发生冲突时，我们检查下一个位置，直到找到一个空位置。设$h_i(x)=(hash(x)+f(i)) mod TableSize，且f(0)=0$，这个f(i)称为探测序列（probing sequence），这样构成的表称为探测哈希表（probing hash table）。

一般的探测哈希表$\lambda$低于0.5。

对于f(i)的查找，有以下几种方法：
##### 线性探测法
$f(i)=i$，即：
* 从冲突处按照1的步长逐个查找下一个位置，直到找到空位置。

缺点：容易产生一次聚集（primary clustering），即连续的位置被占用，导致查找时间增加。

##### 二次探测法
流行的选择是$f(i)=i^2$，即：
* 从冲突处按照$i^2$的步长查找下一个位置，直到找到空位置。

缺陷：一旦表被填满超过一半，就不能保证能找到空位置。会产生二次聚集。

补救方法：平方消解函数$f(i)=f(i-1)+2i-1$。它将下一个要尝试的位置与上一个位置的差值加上2i-1。如果新的定位越界，可以减去TableSize将其拉回数组范围内

##### 双重哈希法
**double hashing考试常考。**

双重哈希法的思想是发生冲突时对键做第二个哈希函数。

一般形式：$hash(x)=(hash_1(x)+i*hash_2(x)) mod(TableSize)$

对于这样的函数，如果发生冲突，i会进行递增，然后重复计算哈希值。

常用的第二个哈希函数是：$hash_2(x)=R-(x mod R)$，其中R是小于TableSize的素数。

* 优点：不会产生聚集。
* 缺点：计算时间较长。

### 5.3 再哈希（Rehashing）