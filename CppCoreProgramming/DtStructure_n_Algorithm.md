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

2. We can calculate the relative rates of growth by calculating $\lim\limits_{x\rightarrow\infin}\frac{f(N)}{g(N)}$

## 2.3 What to analyze
Generally, the quantity required is the **worst-case** time.

## 2.4 Running-Time Calculation (!!!)

### 2.4.2 General Rules
1. **FOR Loops**: At most the running time of the **statements inside** times the number of iterations.

2. **Nested Loops**: (Analyze these **inside out**) the running time of the statement multiplied by the **product of the sizes of all loops**

```C++
//Example
for (i; i< n; i++)
    for (j; j< n; j++)
        ++k;
```
$T(N) = O(N^2)$