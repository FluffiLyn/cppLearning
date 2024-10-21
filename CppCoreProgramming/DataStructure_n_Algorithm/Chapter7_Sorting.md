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
* 外存文件的排序：数据量太大sasd，无法全部载入内存，需要外存文件排序。

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
    for (int p = 1; p < v.size(); ++p)
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
  * 最优：$O(n)$
  * 平均：取决于选区的间距序列
* 稳定性：不稳定

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
图示：![希尔排序](https://pica.zhimg.com/80/v2-7ef755d2b04f11cb013acb47f10928cc_720w.webp)

### 7.6 堆排序（Heap Sort）
我们使用最大堆来进行升序排序，使用小顶堆来进行降序排序。

步骤（以最大堆为例）：
1. 创建一个最大堆
2. DeleteMax() N次，返回每个最大值并存储在数组末尾
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
    for (tmp = std::move(a[i]); leftChild(i) < n; i = child)
    {
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
```

### 7.7 归并排序（Merge Sort）
运用了**分治（divide and conquer）**思想。

步骤：
1. 将n个元素分成个含n/2个元素的子序列。
2. 用归并排序对两个子序列递归地排序。
3. 将子表两两合并，重复这一步骤直到最后只剩下一个子表，这个子表就是排好序的线性表。

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
快速排序是一种分治的排序算法，它将一个数组分成两个子数组，将两部分独立地排序。

步骤：
1. 选择一个基准元素，将数列划分为两部分（要求保证相对大小关系）；
2. 递归到两个子序列中分别进行快速排序；
3. 不用合并，因为在划分的过程中已经排好序了。

和归并排序的区别是，第一步并不是直接分成前后两个序列，而是在分的过程中要保证相对大小关系。具体来说，第一步要是要把数列分成两个部分，然后保证前一个子数列中的数都小于后一个子数列中的数。为了保证平均时间复杂度，一般是随机选择一个数 m 来当做两个子数列的分界。

性质：
* 时间复杂度：
  * 平均：$O(N \log N)$
  * 最坏情况：$O(N^2)$
* 稳定性：不稳定
* 是否原地排序：是