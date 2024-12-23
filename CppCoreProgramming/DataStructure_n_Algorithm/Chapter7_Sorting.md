## Chapter 7: Sorting

### 7.1 算法概述
排序算法是计算机科学中最基本的算法之一，它的目的是将一组数据按照一定的顺序排列。排序算法的性能通常用时间复杂度和空间复杂度来衡量。

输入输出
* 输入：一个数组、一个比较函数
* 输出：一个排好序的数组

空间复杂度
* 是否复制？$O(n)$额外空间。
* 原地排序（不复制）？$O(1)$额外空间。
* 有的临时变量需要$O(\log n)$额外空间。
* 外存文件的排序：数据量太大，无法全部载入内存，需要外存文件排序。

时间复杂度
* 你至少需要最后一次比较来确定排序是否完成。i.e., at least $O(n)$。

稳定性
* 稳定性是相等的元素在排序后保持原有的相对顺序

### 7.2 冒泡排序（不推荐）
两两比较相邻记录的关键字，如果反序则交换，直到没有反序的记录为止。从1到n-1，经过 n-1 轮比较后，整个数组就会被排序。

性质：
* 时间复杂度：$O(n^2)$
  * 最坏情况是全部逆序，需要 $n(n-1)/2$次比较
* 稳定性：稳定

升序实现：
```cpp
//n是元素个数，从下标1开始排序
void BubbleSort(int A[], int n) 
{
    for (int i = 1; i <= n - 1; i++) 
    {
        for (int j = 1; j <= n - i; j++) 
        {
            if (A[j] > A[j + 1]) 
            {
                std::swap(A[j], A[j + 1]);
            }
        }
    }
}
```

### 7.3 插入排序（Insertion Sort）
插入排序是将待排列元素划分为已排序和未排序两部分，每次从未排序的元素中选择一个插入到已排序的元素中的正确位置。

步骤：
1. 划分时，默认第一个是有序的，然后从第二个元素开始，将其插入到前面的有序序列中。
2. 从p开始，向前比较，如果tmp小于前面的元素，则将前面的元素后移。

性质：
* 时间复杂度：$O(n^2)$
  * 最坏情况是全部逆序
* 适用于几乎有序的数组
* 稳定性：稳定

```c++
//以下标1开始排序
void insertSort(vector<Comparable>& v)
{
    for (int p = 1; p <= v.size() - 1; ++p)
    {
        Comparable tmp = std::move(v[p]);
        int j;
        //从p开始，向前比较，如果tmp小于前面的元素，则将前面的元素后移
        for (j = p; j > 0 && tmp < v[j - 1]; --j)
        {
            v[j] = v[j - 1];
        }
        v[j] = tmp;
    }
}
```

### 7.4 选择排序（Selection Sort）
选择排序的工作原理是每次找出第 i 小的元素（也就是 $A_{i..n}$ 中最小的元素），然后将这个元素与数组第 i 个位置上的元素交换。

性质：
* 时间复杂度：$O(n^2)$
* 稳定性：不稳定。
  * 比如 {5,3,5,2}，2 是最小值，会和第 1 个 5 进行交换，那第 1 个 5 就去了第 2 个 5 的后面，两个 5 的相对位置发生改变。

```c++
void selection_sort(int* a, int n) 
{
    for (int i = 1; i < n; ++i) 
    {
        int ith = i;
        for (int j = i + 1; j <= n; ++j) 
        {
            if (a[j] < a[ith]) 
            {
                ith = j;
            }
        }
        std::swap(a[i], a[ith]);
    }
}
```
### 总结：冒泡、插入、选择
|**排序算法**| 插入排序 | 冒泡排序 | 选择排序 |
|:---:|:---:|:---:|:---:|
|比较次数：|||
|最好情况|$O(n)$|$O(n^2)$|$O(n^2)$|
|平均情况|$O(n^2)$|$O(n^2)$|$O(n^2)$|
|最坏情况|$O(n^2)$|$O(n^2)$|$O(n^2)$|
|交换次数：|||
|最好情况|$0$|$0$|$0$|
|平均情况|$O(n^2)$|$O(n^2)$|$O(n)$|
|最坏情况|$O(n^2)$|$O(n^2)$|$O(n)$|

### 7.5 希尔排序（Shell Sort）
希尔排序也称为缩小增量排序法，是插入排序的一种改进版本。

步骤：对不相邻的记录进行比较和移动：
1. 将待排序序列分为若干子序列（每个子序列的元素在原始数组中间距相同）；
2. 对这些子序列进行插入排序；
3. 减小每个子序列中元素之间的间距，重复上述过程直至间距减少为 1。

性质：
* 时间复杂度：
  * 最优：$O(n^{1.3})$
  * 平均：取决于选区的间距序列。若间距序列为$H= \{ k=2^p\cdot 3^q\mid p,q\in \mathbb N,k\le n \}$（从大到小），则希尔排序算法的平均时间复杂度为 O(n\log^2 n)。
* 稳定性：不稳定

实现：本例间距序列为$n/2,n/4,n/8,...,1$。
```c++
void shellSort(int* a, int n) 
{
    // 初始间隔设为数组长度的一半
    for (int gap = n / 2; gap > 0; gap /= 2) 
    {
        // 从间隔位置开始，对每个间隔进行插入排序
        for (int i = gap; i < n; ++i) 
        {
            int tmp = a[i];
            int j = i;
            for (; j >= gap && a[j - gap] > tmp; j -= gap) 
            {
                a[j] = a[j - gap];
            }
            a[j] = tmp;
        }
    }
}
```
图示：
![希尔排序](https://pica.zhimg.com/80/v2-7ef755d2b04f11cb013acb47f10928cc_720w.webp)

### 7.6 堆排序（Heap Sort）
我们使用最大堆来进行升序排序，使用最小堆来进行降序排序。

步骤（以升序排序为例）：
1. 创建一个最大堆
   * 从最后一个**非叶子节点**（i = n / 2 - 1 ）开始循环，i--，直到根节点（i = 0），对每个节点进行下滤操作：
     * 获取左子节点的下标，然后比较左右子节点的大小，选择**较大的子节点**
     * 如果选中的子节点大于父节点，则交换父子节点的值，并令i指向子节点，继续下滤操作

2. DeleteMax() N次，将堆顶元素与最后一个未排序的元素交换，然后对堆顶进行下滤操作。
（记住不是存储在“堆栈”的“堆”中，而是存储在堆数组中）

性质：
* 时间复杂度:
  * 构建最大堆：$O(N)$
  * N次DeleteMax：$N*O(\log N)$
  * 总共：$O(N \log N)$
* 稳定性：不稳定
* 是否原地排序：是（仅需常数级别的额外空间）

实现：（int可以替换为任何Comparable类型）
```c++
//返回左孩子的下标
//内联的目的是减少函数调用的开销
inline int leftChild(int i)
{
    return 2 * i + 1;
}

//下滤
void percDown(vector<int>& a, int i, int n)
{
    int child;
    int tmp;

    //每执行一次循环，都会获取交换前的子节点的下标
    for (tmp = std::move(a[i]); leftChild(i) < n; i = child)
    {
        //获取左孩子的下标
        child = leftChild(i);
        //如果右子节点存在，且右子节点大于左子节点，则选择右子节点
        if (child != n - 1 && a[child] < a[child + 1])
        {
            ++child;
        }

        //如果tmp小于子节点，则将子节点上移
        if (tmp < a[child])
        {
            a[i] = std::move(a[child]);
        }
        else break;
    }
    a[i] = std::move(tmp);
}

void heapSort(vector<int>& a)
{
    //构建最大堆
    for (int i = a.size() / 2 - 1; i >= 0; --i)
    {
        percDown(a, i, a.size());
    }
    //删除最大值
    for (int j = a.size() - 1; j > 0; --j)
    {
        std::swap(a[0], a[j]);
        percDown(a, 0, j);
    }
}
```

### 7.7 归并排序（Merge Sort）
运用了 **分治（divide and conquer）** 思想。

步骤：
1. 将n个元素分成个含n/2个元素的子序列。
2. 用归并排序对两个子序列递归地排序。
3. 将子序列两两合并，重复这一步骤直到最后只剩下一个子序列，这个子序列就是排好序的序列。

性质：
* 时间复杂度：$O(N \log N)$
* 稳定性：稳定
* 是否原地排序：否（需要O(N)额外空间）
* 此排序的递归实现可以减少复制

递归实现（升序）：
```c++
//对外接口
void mergeSort(vector<int>& a)
{
    vector<int> tmpArray(a.size());
    mergeSort(a, tmpArray, 0, a.size() - 1);
}

//内部实现
void mergeSort(vector<int>& a, vector<int>& tmpArray, int left, int right)
{
    if (left < right)
    {
        int center = (left + right) / 2;
        mergeSort(a, tmpArray, left, center);
        mergeSort(a, tmpArray, center + 1, right);
        merge(a, tmpArray, left, center + 1, right);
    }
}

//归并
void merge(vector<int>& a, vector<int>& tmpArray, int leftPos, int rightPos, int rightEnd)
{
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    //主循环
    while (leftPos <= leftEnd && rightPos <= rightEnd)
    {
        //如果左边元素小于等于右边元素，则将左边元素拷贝到tmpArray中
        if (a[leftPos] <= a[rightPos])
        {
            tmpArray[tmpPos++] = a[leftPos++];
        }
        else
        {
            tmpArray[tmpPos++] = a[rightPos++];
        }
    }

    //将剩余元素拷贝到tmpArray中
    //后缀自增相当于当前表达式执行完后再自增
    while (leftPos <= leftEnd)
    {
        tmpArray[tmpPos++] = a[leftPos++];
    }
    while (rightPos <= rightEnd)
    {
        tmpArray[tmpPos++] = a[rightPos++];
    }

    //将tmpArray拷贝回a
    for (int i = 0; i < numElements; ++i, --rightEnd)
    {
        a[rightEnd] = tmpArray[rightEnd];
    }
}
```
注：对于模板类型需要调用std::move()。

### 7.8 快速排序（Quick Sort）
快速排序是一种分治、递归的排序算法，它将一个数组分成两个子数组，将两部分独立地排序。和归并排序的区别是，第一步并不是直接分成前后两个序列，而是在分的过程中要保证相对大小关系，即第一步要是要把数列分成两个部分，然后保证前一个子数列中的数都小于后一个子数列中的数。

步骤：
1. 如果数组中元素个数是0个或1个，则返回；
2. 选择一个**基准元素（pivot）**，将剩余的元素分割为两部分（要求保证相对大小关系）；
3. 递归到子序列中分别再次进行快速排序；
4. 不用合并，因为在划分的过程中已经排好序了。


细节：
* 第二步的选择基准元素的方法有很多，成为一种设计决策。

性质：
* 时间复杂度：
  * 平均：$O(N \log N)$
  * 最坏情况：$O(N^2)$
* 稳定性：不稳定
* 是否原地排序：是（但是递归调用要使用辅助的栈空间，大小为$O(logN)$）
* 适用于较大的数据集

#### 选择基准元素
错误做法1：选择第一个元素作为基准元素，如果数组是有序的，那么时间复杂度会退化为$O(N^2)$。

错误做法2：随机选择一个元素作为基准元素。随机数生成器的开销很大。

推荐做法：**三数中值分割法**（median-of-three partitioning）。
* 选择第一、中间、最后一个元素，取这三个元素的**中位数**作为基准元素。然后，对这三个元素进行排序，最小的放最左侧，次小的放中间，最大的放最右侧。
  * 例如：8,1,4,9,6,3,7,5,2,0，选择8,6,0，那么取6作为基准元素。

#### 分割策略（不包含重复元素）
书中给出的策略如下：
1. 利用三数中值分割法，选择基准元素pivot
2. 维护两个指针i和j，i从left往右，j从right-1往左
3. 当i在j的左边时：将i右移，找到一个大于pivot的元素，停止；将j左移，找到一个小于pivot的元素，停止。交换这两个元素。
4. 持续第3步，直到i和j彼此交错。
5. 将pivot与i指向的元素交换

至此，我们完成了一次分割。直到left - right**小于等于**某个阈值，我们就可以对子数组使用插入排序。

#### 代码实现
三数中值分割法：
```c++
const int& median3(vector<int>& a, int left, int right)
{
    int center = (left + right) / 2;
    if (a[center] < a[left])
    {
        std::swap(a[left], a[center]);
    }
    if (a[right] < a[left])
    {
        std::swap(a[left], a[right]);
    }
    if (a[right] < a[center])
    {
        std::swap(a[center], a[right]);
    }

    //将pivot放在right-1处
    std::swap(a[center], a[right - 1]);
    return a[right - 1];
}
```

主程序：
```c++
void quickSort(vector<int>& a, int left, int right)
{
    //假设阈值为10，当剩余元素<=10时，使用插入排序
    if (left + 10 <= right)
    {
        //分割
        int pivot = median3(a, left, right);
        int i = left, j = right - 1;
        for (;;)
        {
            //前缀自增使得i、j先增加再执行表达式
            while (a[++i] < pivot) {}
            while (a[--j] > pivot) {}
            
            if (i < j) 
            {
                std::swap(a[i], a[j]);
            }
            else break;
        }
        std::swap(a[i], a[right - 1]);//将pivot与i指向的元素交换
        quickSort(a, left, i - 1);
        quickSort(a, i + 1, right);
    }
    else
    {
        //插入排序处理小数组
        insertSort(a, left, right);
    }
}
```

对外接口：
```c++
void quickSort(vector<int>& a)
{
    quickSort(a, 0, a.size() - 1);
}
```

#### 对for循环的分析
对于上文的写法：
```c++ 
while (a[++i] < pivot) {}
while (a[--j] > pivot) {}
```
这种写法会先将i或j移动一次，然后再进行比较。

如果写成下面的形式：
```c++
while (a[i] < pivot) {++i;}
while (a[j] > pivot) {--j;}
```
当a[i]=a[j]=pivot时，第二种写法会无限循环。因此，第一种写法是正确的。


### 7.9 桶排序（Bucket Sort）
桶排序运用分治思想，将数组分到有限数量的桶里，然后对每个桶进行排序，最后将所有桶合并。这是一种哈希的思想。

步骤：
1. 设置一个定量的数组当作空桶。（桶的数量的设定是算法设计的关键之一）
2. 遍历待排序数组，并且把元素一个一个放到对应的桶中。
3. 对每个非空的桶进行排序。
4. 从非空的桶子里把元素再放回原来的序列中。

性质：
* 时间复杂度：$O(M+N)$（M是桶的数量，N是元素的数量）
* 稳定性：稳定
* 是否原地排序：否（使用了额外的数组）

实现：
```c++
void bucketSort(vector<int>& a, int n)
{
    if (n <= 0) return;

    // 找出数组中的最大值和最小值以确定桶的数量和范围
    int max_Value = *max_element(a.begin(), a.end()); // 找出最大值
    int min_Value = *min_element(a.begin(), a.end()); // 找出最小值

    // 计算桶的大小和数量
    int bucketSize = (max_Value - min_Value) / n + 1; // 桶的大小
    int bucketCount = (max_Value - min_Value) / bucketSize + 1; // 桶的个数

    // 创建桶
    vector<vector<int>> buckets(bucketCount);

    // 利用整数除法，确定 a[i] 放入哪个桶中
    // a[i] - min_Value 是为了保证桶的下标不会小于0
    for (int i = 0; i < n; i++) {
        int bucketIndex = (a[i] - min_Value) / bucketSize;
        buckets[bucketIndex].push_back(a[i]);
    }

    // 对每个非空桶进行排序
    for (int i = 0; i < buckets.size(); ++i) 
    {
        if (!buckets[i].empty())
        {
            std::sort(buckets[i].begin(), buckets[i].end());
        }
    }
    
    // 将各个桶中的元素合并
    int index = 0;
    for (int i = 0; i < buckets.size(); ++i)
    {
        for (int j = 0; j < buckets[i].size(); ++j) 
            a[index++] = buckets[i][j];
    }
}
```
其中，`max_element`和`min_element`在`<algorithm>`头文件中，返回的是迭代器。
### 7.10 基数排序（Radix Sort）
参考：[基数排序](https://zhuanlan.zhihu.com/p/126116878)

基数排序是一种非比较型整数排序算法，将整数按**位数**切割成不同的数字，然后按每个位数分别比较。其中基数指的是进制的基数，比如十进制的基数是10，二进制的基数是2。

根据排序的顺序，基数排序可以分为**LSD（Least Significant Digit）**（从最低位开始）和**MSD（Most Significant Digit）**（从最高位开始）。

步骤：（以LSD为例）
1. 将所有待比较数值（正整数）统一为同样的数位长度，数位较短的数前面补零。
2. 从最低位开始，按位依次进行一次排序。
3. 从最低位排序一直到最高位排序完成以后，数列就变成一个有序序列。

性质：
* 时间复杂度：$O(k(n+b))$（k是最大数的位数，n是元素个数，b是桶数）
  * 简化为$O(k*n)$
* 稳定性：稳定
* 是否原地排序：否（需要额外的空间）

实现：
```c++
void radixSort(vector<int>& a)
{
    //找出最大值
    int maxVal = *max_element(a.begin(), a.end());
    int maxDigit = 0;
    while (maxVal)
    {
        maxVal /= 10;
        ++maxDigit;
    }

    //创建桶
    vector<vector<int>> buckets(10);

    //按位数进行排序
    for (int i = 0, mod = 10, div = 1; i < maxDigit; ++i, mod *= 10, div *= 10)
    {
        for (int j = 0; j < a.size(); ++j)
        {
            int bucketIndex = (a[j] % mod) / div;
            buckets[bucketIndex].push_back(a[j]);
        }

        //将桶中的元素放回原数组
        int index = 0;
        for (int j = 0; j < buckets.size(); ++j)
        {
            for (int k = 0; k < buckets[j].size(); ++k)
            {
                a[index++] = buckets[j][k];
            }
        }

        buckets.clear();
    }
}
```

### 总结
|**排序算法**| 平均时间复杂度| 最好情况 | 最坏情况 | 空间复杂度 | 排序方式 | 稳定性 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|冒泡排序| $O(n^2)$ | $O(n)$ | $O(n^2)$ | $O(1)$ | In-place | 稳定 |
|插入排序| $O(n^2)$ | $O(n)$ | $O(n^2)$ | $O(1)$ | In-place | 稳定 |
|选择排序| $O(n^2)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | In-place | 不稳定 |
|希尔排序| $O(n^{1.3})$ | $O(n)$ | $O(n^2)$ | $O(1)$ | In-place | 不稳定 |
|堆排序| $O(n\log n)$ | $O(n\log n)$ | $O(n\log n)$ | $O(1)$ | In-place | 不稳定 |
|归并排序| $O(n\log n)$ | $O(n\log n)$ | $O(n\log n)$ | $O(n)$ | Out-place | 稳定 |
|快速排序| $O(n\log n)$ | $O(n\log n)$ | $O(n^2)$ | 最好 $O(\log n)$ 最坏 $O(n)$ | In-place | 不稳定 |
|桶排序| $O(n+k)$ | $O(n+k)$ | $O(n^2)$ | $O(n+k)$ | Out-place | 稳定 |
|基数排序| $O(k(n+b))$ | $O(k(n+b))$ | $O(k(n+b))$ | $O(n+b)$ | Out-place | 稳定 |
|计数排序| $O(n+k)$ | $O(n+k)$ | $O(n+k)$ | $O(k)$ | Out-place | 稳定 |

稳定：冒泡、插入、归并、桶、基数

不稳定：选择、希尔、堆、快速

### 7.11 决策树与下界证明
决策树是用于证明下界的抽象概念。决策树是一种二叉树：每个节点代表元素之间一组可能的排序。
* 根节点：最初始判定的属性，判定区域是全局的数据集；
* 内部节点：中间的判定属性，判定区域是符合某些特征的子数据集；
* 叶子节点：决策结果，位于决策树的最底层，每个叶子节点都是一个决策结果。

一个**比较**排序算法可以被视为一个决策树，每一个叶子节点对应一个排列（permutation）。证明一个排序算法的下界，就是证明决策树的高度。

性质：
1. 一个n个节点的决策树高度是$\Omega (\log n)$
  * 回顾：$\Omega(n)$ 表示 $T(N) \geq c  f(N)$，
2. 对n个元素排序的决策树有n!片叶子节点，那么只使用元素间比较的任何排序算法均需要$\Omega (\log n!)=\Omega(n\log n)$次比较。
   * 证明：$\log (n!)=\log (n(n-1)...(2)(1))\\=\log n+\log(n-1)+...+\log 2+\log 1\\\geq \frac{n}{2}\log \frac{n}{2}\\\geq \frac{n}{2}\log n - \frac{n}{2}log2\\=\Omega(n\log n)$

### 7.12 外部排序（External Sorting）
**期末几乎不考**

外部排序是指数据量太大，无法一次性载入内存，需要借助外存（硬盘）进行排序，不是一种排序算法，而是一种排序策略。

#### 文件处理的黄金准则
* 一次性读取尽可能多的数据，**减少I/O次数**

#### 一些概念
* 