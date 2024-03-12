# 排序

## 一、比较类排序

### 1. 选择排序（Selection Sort）
基本思想：每一趟从待排序的数据元素中选出最小（或最大）的一个元素，**顺序**放在待排序的数列的**最前**，直至全部元素排完。

代码：
```c++
#include <iostream>
using namespace std;

const int MAXN = 10001;

int main()
{
    int n,key;
    float temp, a[MAXN];
    
    cin >> n;
    //输入要排序的元素
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    //i控制当前序列中最小值存放的数据位置
    for (int i = 0; i < n; i++)
    {
        key = i;
        //在当前无序区a[i, ... , n]中选择最小的元素a[key]
        for (int j = i + 1;j < n; j++)
        {
            if (a[j] < a[key])
            {
                key = j;
            }

            //交换
            if (key != i)
            {
                temp = a[i]; a[i] = a[key]; a[key] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
```

### 2. 冒泡排序（Bubble Sort）
代码：
```c++
#include <iostream>
using namespace std;

const int MAXN = 10001;

int main()
{
    int n;
    bool flag;
    float temp, a[MAXN];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    //进行n-1轮冒泡
    for (int i = n - 1; i >= 1; i--)
    {   
        flag = true;
        //每轮进行i次比较
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
            flag = false;
        }
        if(flag) break;
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
```

### 3. 插入排序 （Insertion Sort）
基本思想：通过构建有序序列，对于未排序数据，在已排序序列中**从后向前**扫描，找到相应位置并插入。类似打牌时摸牌并将其从大到小排列。每次摸到一张牌后，根据其点数插入到确切位置。

复杂度分析：

* 平均时间复杂度：O(N^2)
* 最差时间复杂度：O(N^2)
* 空间复杂度：O(1)
* 排序方式：In-place
* 稳定性：稳定

代码：
```c++
#include <iostream>
using namespace std;

const int MAXN = 10001;

void insertSort(int a[], int len)
{
    for (int i = 1; i < len; i++)
    {
        //取出第二个元素
        //默认第一个元素是已排序的子列
        int temp = a[i];
        int j = i - 1;

        //如果a[j]比temp值大，则后移一位
        //如果小，则说明temp应插入a[j]后一位
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

int main()
{
    int n, a[MAXN];

    cin >> n;
    for (int i = 0; i< n; i++)
    {
        cin >> a[i];
    }

    insertSort(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
```
动图演示：

![动图演示](https://pic3.zhimg.com/v2-91b76e8e4dab9b0cad9a017d7dd431e2_b.webp "插入排序动图演示")

### 4. 快速排序（Quick Sort）
快速排序是对冒泡排序的一种改进。

基本思想：通过一趟排序将待排记录分割成独立的两部分，其中一部分的关键字均比另一部分记录的关键字小，则可分别对这两部分记录继续进行排序，以达到整个序列有序。（分治思想）

步骤：
* 从数列中挑出一个元素，称为 “基准”（pivot）

* 重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作。
* 运用递归，把小于基准值元素的子数列和大于基准值元素的子数列排序。
* 递归到最底部时，数列的大小是零或一，也就是已经排序好了。这个算法一定会结束，因为在每次的迭代中，它至少会把一个元素摆到它最后的位置去。

复杂度分析：
* 平均时间复杂度：O(NlogN)
* 最佳时间复杂度：O(NlogN)
* 最差时间复杂度：O(N^2)
* 空间复杂度：根据实现方式的不同而不同

代码：
```c++
#include <iostream>
using namespace std;

const int N = 10000;

void quickSort(int arr[], int start, int end)
{
    //基本情况
    if (start >= end) return;
    
    //以第0个元素为基准值base
    int base = arr[start];
    int left = start, right = end;
    while (left < right)
    {
        //从右向左找，若比base大，right--
        while (arr[right] >= base && left < right) right--;
        //若比base小，则替换left所在位置的数字
        arr[left] = arr[right];

        //以下同理
        while (arr[left] <= base && left < right) left++;
        arr[right] = arr[left];
        
        //此时left=right，我们用base来替换此位置的数字
        arr[left] = base;
    }

    //排列比base小的数字的数组
    quickSort(arr, start, left - 1);
    
    //排列比base大的数字的数组
    quickSort(arr, left + 1, end);
} 

int main()
{
    int n, a[N];
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    } 

    return 0;
}
```

动图演示：

![动图演示](https://pic1.zhimg.com/v2-3e7852bb7dcd18c6b45947f5939d0cd8_b.webp "快速排序动图演示")

### 5. 归并排序 （Merge Sort）
基本思想：运用分治思想，将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。

步骤：
* 将n个元素分成个含n/2个元素的子序列。
* 用合并排序法对两个子序列递归的排序。
* 合并两个已排序的子序列已得到排序结果。

代码：
```c++
#include <iostream>
using namespace std;

const int N = 100010;

// Merge函数用于合并两个有序子数组

void Merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex)
{
    // 初始化三个“指针”，i是左半部分起始，j是右半部分起始，k是临时数组的当前插入位置
    int i = startIndex, j=midIndex+1, k = startIndex;

    // 当左右两个子数组的指针都没有达到各自末尾时
    while(i <= midIndex && j <= endIndex) 
    {
        // 右半部分当前元素小于左半部分当前元素，则将右半部分当前元素放入临时数组并移动指针
        if(sourceArr[i] > sourceArr[j])
            tempArr[k++] = sourceArr[j++];
        // 否则将左半部分当前元素放入临时数组并移动指针
        else
            tempArr[k++] = sourceArr[i++];
    }

    // 将剩余的元素依次插入临时数组
    while(i <= midIndex)
        tempArr[k++] = sourceArr[i++];
    while(j <= endIndex)
        tempArr[k++] = sourceArr[j++];

    // 将临时数组的有序元素复制回原数组
    for(i=startIndex; i<=endIndex; i++)
        sourceArr[i] = tempArr[i];
}
 
//内部使用递归
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex) 
{
    int midIndex;
    if(startIndex < endIndex) 
    {
        midIndex = startIndex + (endIndex-startIndex) / 2;//避免溢出int
        // 分
        MergeSort(sourceArr, tempArr, startIndex, midIndex);
        MergeSort(sourceArr, tempArr, midIndex+1, endIndex);
        // 治
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}


int main()
{
    int n, a[N] = {0}, temp[N] = {0};
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    MergeSort(a, temp, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    } 

    return 0;
}


```
分而治之的图解：

![分而治之](https://img-blog.csdnimg.cn/20200209191150963.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2p1c3RpZGxl,size_16,color_FFFFFF,t_70 "分治图解")

动图演示：
![动图演示](https://img-blog.csdnimg.cn/20200209185525881.gif "动图演示")

参考：https://blog.csdn.net/justidle/article/details/104203958
## 二、非比较类排序

### 1. 桶排序（Bucket Sort）
基本思想：若待排序的值**值域较大，但分布较均匀**，可设计有限个有序桶，待排序的值装入对应的桶（也可以装入若干个值），桶号就是待排序的值，顺序输出各桶的值，得到有序的序列。

步骤：
* 设置一个定量的数组当作空桶子。

* 寻访序列，并且把元素一个一个放到对应的桶子去。
* 对每个不是空的桶子进行排序。
* 从不是空的桶子里把元素再放回原来的序列中。

复杂度分析：
* 平均时间复杂度：O(n + n^2/k + k)（将值域平均分成 n 块 + 排序 + 重新合并元素）
* 最佳时间复杂度：O(n + k)（所有元素均匀分配到每一个桶中）
* 最差时间复杂度：O(n ^ 2)（所有元素被分配到同一个桶中）
* 空间复杂度：O(n * k)
* 稳定性：稳定

代码：
```c++
#include <iostream>
#include <vector>//由于桶的大小不确定，故用vector
using namespace std;

const int N = 10000;

//需要用其他排序为每个桶内元素排序
//插入排序是个不错的选择，对于小规模数据集效果很好
void insertSort(vector<int>& A)
{
    for (int i = 1; i < A.size(); i++)
    {
        int temp = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > temp)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
}

int findMax(int a[], int n)
{
    if (n == 0)
        return 0;

    int maxValue = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > maxValue)
            maxValue = a[i];
    }
    return maxValue;
}
void bucketSort(int a[], int n)
{
    // 找出数组中的最大值以确定桶的数量
    int max_Value = findMax(a, n);
    // 假设我们以10为单位划分桶（可根据实际情况调整）
    // +1是保证max_Value小于10时也可以多分配一个桶来容纳所有可能的元素
    int bucket_count = max_Value / 10 + 1; 
    int bucket_size = bucket_count / n + 1;

    // 创建二维向量
    vector<vector<int>> bucket(bucket_count);

    // 初始化每个桶为空
    for (int i = 0; i < bucket_count; i++)
        bucket[i].clear();

    // 利用整数除法，确定a[i]放入哪个桶中
    for (int i = 0; i < n; i++)
        bucket[a[i] / bucket_size].push_back(a[i]);

    // 对每个非空桶进行排序
    for (int i = 0; i < bucket.size(); i++) 
    {
        if (!bucket[i].empty())
        {
            insertSort(bucket[i]);
        }
    }

    // 将桶内元素合并回原始数组
    int index = 0;
    for (int i = 0; i < bucket.size(); i++)
    {
        for (int j = 0; j < bucket[i].size(); j++) 
            a[index++] = bucket[i][j];
    }

}

int main()
{
    int n, a[N];
    cout << "Enter the number of elements: ";
    cin >> n;
    
    //生成随机数据
    cout << "Random data: ";
    for (int i = 0; i < n; i++) 
    {
        a[i] = rand() % 114514;
        cout << a[i] << " ";
    }
    cout << endl;

    bucketSort(a, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) 
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
```

### 2. 计数排序（Counting Sort）
基本思想：将输入的数据值转化为键存储在额外开辟的数组空间中。计数排序要求输入的数据必须是**有确定范围**的整数。

步骤：
1. 找出待排序的数组中最大和最小的元素；
2. 统计数组中每个值为i的元素出现的次数，存入数组bucket的第i项；
3. 对所有的计数累加（从bucket中的第一个元素开始，每一项和前一项相加）；
4. 反向填充目标数组：将每个元素i放在新数组的第bucket(i)项，每放一个元素就将bucket(i)减去1。

代码：
```c++
#include <iostream>
using namespace std;

void countingSort(int arr[],int max_Value, int min_Value, int n, int length)
{
    int count[length] = {0};
    int result[n] = {0};

    // 统计每个元素出现的次数
    for (int i = 0; i < n; i++)
    {
        count[arr[i] - min_Value]++;
    }

    // 累计计数，计算每个元素排序后在数组中的位置
    // 即将每个元素的 计数值 加上前一个元素的计数值，确保相同元素的相对顺序不变。

    for (int j = 0; j < length - 1; j++)
    {
        count[j + 1] += count[j];
    }
    
    // 根据累计计数数组将元素放置到正确的位置
    for (int k = n - 1; k >= 0; k--)
    {
        int index = count[arr[k] - min_Value] - 1;
        result[index] = arr[k];
        count[arr[k] - min_Value]--;
    }

    
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
}

int main()
{
    int n, max_Value, min_Value;
    cin >> n;

    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // 获取最大和最小值。数组长度就是最大减去最小再加一（防止max=min）
    max_Value = arr[0];
    min_Value = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max_Value)
        {
            max_Value = arr[i];
        }
        if (arr[i] < min_Value)
        {
            min_Value = arr[i];
        }
    }

    int length = max_Value - min_Value + 1;

    countingSort(arr, max_Value, min_Value, n, length);
}

    

```
注：
* count[] 数组在累计计数后存储的是每个值（基于 min_Value 的偏移）应当放置的***下一个元素***的位置。例如，如果 count[i] 的值是5，则表示从数组开始到这个位置，共有5个不大于 i + min_Value 的元素。

* 当我们想要将 arr[k] 放入结果数组时，我们需要找到它之前有多少个比它小或相等的元素。由于 count[] 存储的是***“下一个”***位置，所以我们需要访问的是当前位置之前的累计计数值，即 count[arr[k] - min_Value] - 1。

### 3. 基数排序
基本思想：将整数按位数切割成不同的数字，然后按每个位数分别比较。基数排序的方式可以由键值的最右边开始，也可以由键值的最左边开始。

步骤：
* 将所有待比较数值（正整数）统一为同样的数位长度，数位较短的数前面补零。
* 从最低位开始，依次进行一次排序。
* 这样从最低位排序一直到最高位排序完成以后, 数列就变成一个有序序列。

代码：
```c++

```

参考：https://zhuanlan.zhihu.com/p/126116878

# 附：
![排序总览](https://img-blog.csdnimg.cn/2021032110220898.png?"排序总览")
