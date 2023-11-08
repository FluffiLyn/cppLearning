# 1. 生词

# 2. Recursion 递归
## Recursive function
*&emsp;&emsp;A function that call itself, either directly or indirectly (through another function).*

## Recursion 
(1) Base cases: the simplest case(s), which the function knows how to handle.

(2) For all other cases, the function typically divides the problem into two conceptual pieces

* A piece that the function knows **how to do**.

* A piece that it does not know how to do —— slightly **simpler or smaller version of the original problem**.

(3) Recursive call (also called the recursion step)

* The function calls a ***fresh copy*** of itself to work on the smaller problem.

* Can result in many more recursive calls, as the function keeps dividing each new problem into two conceptual pieces.

* This sequence of smaller and smaller problems must eventually converge on the base case. <font color=red>***Otherwise the recursion will continue forever***</font>.

### Example 1: Fibonacci series
```c++
#include <iostream>
using namespace std;

unsigned long fibonacci(unsigned long number)
{
    if((number == 0) || (number == 1))//base cases
        return number;
    else//recursion step
        return fibonacci(number - 1) + fibonacci(number - 2);
}

int main()
{
    for(int counter = 0; counter <= 10; counter++)
    {
        cout << "fibonacci(" << counter << ")=" <<      fibonacci(counter) << endl;
    }

    cout << "fibonacci(20)=" << fibonacci(20) << endl;
    cout << "fibonacci(30)=" << fibonacci(30) << endl;
    cout << "fibonacci(35)=" << fibonacci(35) << endl;

    return 0;
}
```
<font color=red>***Caution:***</font>

* Each level of recursion in function fibonacci has a ***doubling effect*** on the number of function calls.

    * i.e. the number of recursive calls that are required to calculate the nth Fibonacci number is on the order of 2n.
* The ***exponential complexity*** in this function can <font color=red>***HUMBLE***</font> ***the world's most powerful computers***, so <font color=red>***AVOID using similar programs that result in an exponential EXPOSION of calls!!!!!!!!!!!!!!!!!***</font>

## Recursion vs Iteration 递归 vs 迭代
(1) Negatives of recursion

* Overhead of repeated function calls can be expensive in both ***processor time and memory space***.

* Each recursive call causes another copy of the function (actually only the function's variables) to be created can consume considerable memory.

(2) Iteration

* Normally occurs within a function.

* Overhead of repeated function calls and extra emory assignment is ***omitted***.

* Any problem that can be solved recursively can ***also be solved iteratively***.

### Example 3: Towers of Hanoi
```c++
#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n, char x, char y, char z)
{
    if(n == 1)
        cout << x << "-->" << z << endl;
    else
    {
        hanoi(n - 1, x, z, y);
        cout << x << "-->" << z << endl;
        hanoi(n - 1, y, x, z);
    }
}

int main()
{
    int m;
    cout << "Input the number of diskes:" << endl;
    cin >> m;
    hanoi(m,'A','B','C');
    cout << "steps = 2^n - 1 = " << pow(2,m) - 1;
    
    return 0;
}
```