#include <iostream>
using namespace std;

void countingSort(int arr[],int max_Value, int min_Value, int n, int length)
{
    int * count = new int[length];
    count = {0};
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

    
