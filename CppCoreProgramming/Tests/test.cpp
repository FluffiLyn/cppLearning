#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <chrono>

using namespace std;

// 逐个插入元素到堆中
void insertToHeap(vector<int>& arr) 
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int value : arr) {
        minHeap.push(value);
    }
}

// 线性时间建立堆
void buildHeap(vector<int>& arr) {
    make_heap(arr.begin(), arr.end(), greater<int>());
}

// 测试运行时间的函数
void testHeapPerformance(vector<int>& arr) 
{
    // 测试逐个插入法
    auto start = chrono::high_resolution_clock::now();
    insertToHeap(arr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "逐个插入法耗时: " << elapsed.count() << "秒" << endl;

    // 测试线性时间建立堆
    start = chrono::high_resolution_clock::now();
    buildHeap(arr);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "线性时间建立堆耗时: " << elapsed.count() << "秒" << endl;
}

int main() 
{
    int N;
    cout << "请输入元素个数 N: ";
    cin >> N;

    vector<int> sortedArray(N);
    vector<int> reversedArray(N);
    vector<int> randomArray(N);

    // 初始化已排序数组
    for (int i = 0; i < N; i++) {
        sortedArray[i] = i;
    }

    // 初始化反序数组
    for (int i = 0; i < N; i++) {
        reversedArray[i] = N - i - 1;
    }

    // 初始化随机数组
    for (int i = 0; i < N; i++) {
        randomArray[i] = rand() % 100; // 随机数范围 0-99
    }

    // 测试已排序数组
    cout << "已排序数组：" << endl;
    testHeapPerformance(sortedArray);

    // 测试反序数组
    cout << "反序数组：" << endl;
    testHeapPerformance(reversedArray);

    // 测试随机数组
    cout << "随机数组：" << endl;
    testHeapPerformance(randomArray);

    return 0;
}