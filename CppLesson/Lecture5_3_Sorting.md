# 1. Bubble Sort

* Compares each pair of adjacement（相邻的） items and swaps them if they are in the wrong order
* Pass through the list is repeated until no swaps are needed, which indicates that the list is sorted.

Example:
```c++
void bubbleSort( int a[], int size)
{
    int i, temp, work;
    for (int pass = 1; pass < size; pass++)
    {
        work = 1;
        for (i = 0; i < size - pass; i++)
        {
            if (a[i] > a[i+1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                work = 0;
            }
            if (work) break;//When no swap happens, break.
        }

    }
}
```

# 2. Selection Sort
* Finding the smallest (or largest, depending on sorting order) element in the unsorted datalist
* Swapping it with the leftmost unsorteed element (putting it in sorted order)
* Moving the datalist boundaries one element to the right
```c++
void selectionSort()
{
    int max, t;
    for (int i = 0; i < n-1; i++)
    {
        t = i;
        for (int j = i + 1; j < n; j++)//Finding the largest element
        {
            if (x[j] > x[t])//x[t]在左边，x[j]在右边
                t = j;//让t等于最大值的序号
            if (t != i)//Swap elements
                {
                    max = x[i];
                    x[i] = x[t];
                    x[t] = max;
                }
        }
    }
    return;
}
```

# 3. Insertion Sort 插入排序
* Simple but ***inefficient***
* First iteration（迭代）takes second element —— if it is less than the first element, swap it with first element.
* Second iteration looks at eht third element —— insert it into the corrrect position with respect to first two elements.\
...
* At the *i*th iteration of this algorithm, the first *i* element in the original array will be sorted.

Example:
```c++
void InsertionSort(int arr[], int len)
{
	for (int next = 1; next < len; next++)
	{
		int insert = arr[next]; //Store the value in the current element
		int moveItem = next;    //Initialize location to place element
		while (moveItem > 0 && arr[moveItem - 1] > insert)
		{
            //Shift element one slot to the right
			arr[moveItem] = arr[moveItem - 1];
			moveItem--;
		}
		arr[moveItem] = insert; //Place inserted element into the array
	}
}
```



