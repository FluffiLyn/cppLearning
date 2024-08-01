# Data Structures and Algorithms
This is my note.

# Chapter 2: Algorithm Analysis

## 2.1 Mathematical Background

### Four Defenitions
Following are notations for calculating **relative rates of growth（相对增长率）**.

$T(N) =$
* $O(f(N)):\space\le$ 
* $\Omega(g(N)):\space\ge$
* $\Theta(h(N)):\space=$
* $o(p(N)):\space<$

When T(N) = O(f(N)), f(N) is the **upper bound** of T(N).

Also, T(N) is the **lower bound** of f(N).

---
### Three Important Rules
1. If $T_1(N) = O(f(N))$ and $T_2(N) = O(g(N))$, then:
    * $T_1(N) + T_2(N) = O(f(N)+g(N))$
    * $T_1(N) * T_2(N) = O(f(N)*g(N))$

2. If T(N) is a polynomial of degree k, then $T(N) = \Theta(N^k)$

    Some typical growth rates:
    
    |Function | Name |
    | --- | --- |
    |$c$|constant|
    |$logN$|Logarithmic|
    |$log^2N$|Log-squared|
    |$N$|Linear|
    |$NlogN$||
    |$N^2$|Quadratic|
    |$N^3$|Cubic|
    |2^N|Exponential|

3. For any constant k, $log^kN = O(N)$, which tells you that log grow very slowly.

Note that:
1. Do not add any constant or low-order terms inside Big-Oh.

2. We can calculate the relative rates of growth by calculating $\lim\limits_{x\rightarrow\infty}\frac{f(N)}{g(N)}$

## 2.3 What to analyze
Generally, the quantity required is the **worst-case** time.

## 2.4 Running-Time Calculation (!!!)

### 2.4.2 General Rules
1. **FOR Loops**: At most the running time of the **statements inside** times the number of iterations.

2. **Nested Loops**: (Analyze these **inside out**) the running time of the statement multiplied by the **product of the sizes of all loops**.

```C++
//Example
for (i; i< n; i++)
    for (j; j< n; j++)
        ++k;
```
$T(N) = O(N^2)$

3. **Consecutive Statements (顺序语句)**: The **maximum** is the one that counts.
```C++
//example
for(sth)
    doSth
for(sth)
    doSth;
    for(sth)
        doSth
```
$O(N)$ work followed by $O(N^2)$, so $T(N)=O(N^2)$

4. **IF/ELSE**: Never more than the running time of the **test** plus the **larger** of the running times of S1 and S2.

("test" means statements in if())

```c++
//example
if (condition)//count
    S1;//count S1
else
    S2;//otherwise, count S2
```

### 2.4.4 Logarithms in the running time
General rule: An algorithm is $O(logN)$ if it takes constant time  $(O(1))$ to cut the problem size by a fraction (usually $\frac{1}{2}$).

Examples:
#### 1. Binary search (二分查找): Given an integer $X$ and integers $A_0,A_1,...,A_{n-1}$, which are presorted and already in memory, find i such that $A_i = X$, or return -1 if X is not in the input.

```c++
template <typename Comparable>
int binarySearch(const vector<Comparable> &a, const Comparable &x)
{
    int low = 0, high = a.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] < x)
            low = mid + 1;
        else if (a[mid] > x)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}
```
* Binary search supports the **contains** operation in $O(logN)$ time, but all other operations require $O(N)$ time.


#### 2. Euclid's algorithm (欧几里得算法)
* gcd: The greatest common divisor
```c++
long long gcd(long long m, long long n)
{
    while(n != 0)
    {
        long long rem = m % n;
        m = n;
        n = rem;
    }
    return m
}
```
* $T(N) = 2logN = O(logN)$
---
**Theorem 2.1:** If $M > N$, then $M mod N < M/2$.

Proof: If $N \leq M/2$, then since the remainder is smaller than N, the theorem holds.
If $N > M/2$, then N goes into M once with a remainder $M  - N < M/2$, proving it.


#### 3. Exponentiation
Main idea: 
* Base case: $N \leq 1$
* If N is even, then $X^N = X^{N/2} \cdot X^{N/2}$
* If N is odd, then $X^N = X^{(N-1)/2} \cdot X^{(N-1)/2} \cdot X$

Time: $T(N) = 2logN = O(logN)$, because at most two multiplications are required to **halve the problem** if N is odd.

```c++
long long pow(long long x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (n % 2 == 0)
        return pow(x * x, n / 2);
    else
        return pow(x * x, n / 2) * x;
}
```

**Wrong return statements:**
```c++
return pow(pow(x,2), n/2);
return pow(pow(x,n/2),2);
return pow(x,n/2) * pow(x, n/2);
```