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


