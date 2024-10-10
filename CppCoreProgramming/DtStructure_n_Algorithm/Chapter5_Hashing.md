## Chapter5 Hashing
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

#### 5.2.1 分离链接法（Separate Chaining）
将哈希表的每个位置的所有元素都保存到一个链表。若空间充足，可以直接使用std::list，反之则应自己实现单链表。

```c++