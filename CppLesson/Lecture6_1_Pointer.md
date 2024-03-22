# 01. Introduction of Pointer
## 1. Pointers
* <font color=red> ***POWERFUL, BUT DIFFICULT TO MASTER***</font>
* Can be used to create and manipulate ***dynamic data structures***
* Have close relationship with arrays and strings

## 2. Pointer variables

* Contain memory addresses as values
  * Normally, variable contains specific value (***direct reference***)
  * Pointers contain address of variable that has specific value (***indirect reference***)
  
## 3. Pointer declarations & Initializaion
```c++
int *myPtr1, *myPtr2;
int *myPtr3 = 0, *myPtr4 = NULL;//0 or NULL points to nothing
```

## 4. Address operator (&) 取址符
* Return memory address of its operand

Example:
```c++
int y = 5;
int *yPtr;
yPtr = &y;
```
This means that variable yPtr "points to" y

## 5. * operator 解引用符
* Also called ***indirection operator*** or ***dereferencing operator***
* Returns synonym for the object its operand points to
* *yPtr returns value of y (cuz yPtr pooints to y)
* Dereferenced pointer is an Lvalue（左值）

## 6. * and & are inverses of each other

# 02. Passing Arguments to functions by reference with Pointers

## 1. Three ways to pass arguments to a function
* Pass-by-value
* Pass-by-reference with reference arguments
* Pass-by-reference with pointer arguments

A function can **return** only one value.

But a function can modify original values of arguments, thus more than one value "returned".

## 2. Pass-by-reference with pointer arguments
* Simulates pass-by-reference
  * Use pointers and indirection operator
* Pass address of argument using & operator
* **Arrays is not passed with &** because ***array name*** is already a <font color=red> ***pointer***</font>
* "*" operator is used as alias/nickname ofr variable inside of function

Example:
```c++
#include <iostream>
using namespace std;

int cubeByValue(int);//Prototype
void cubeByReference(int *);//Prototype

int main()
{
    int number = 5;

    cout << "The original value of number is: " << number << endl;

    number = cubeByValue(number);
    cout << "\n The New value of n is : " << number << endl;

    number = 5;

    cubeByReference(&number);
    cout << "\n The New value of n is : " << number << endl;
}

int cubeByValue(int n)
{
    return n * n * n;
}

void cubeByReference(int *nPtr)
{
    *nPtr = *nPtr * *nPtr * *nPtr;//No return but change "number"
}
```