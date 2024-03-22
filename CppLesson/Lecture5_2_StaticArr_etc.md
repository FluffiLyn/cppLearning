# 1. Static local arrays

## 1.1 Static local arrays and automatic local arrays
A ***static local variable*** in a function
* exists forthe duration of the program
* is visible only in the **function body**

A ***static local array***
* exists for the duration of the program
* is initialliezed when its' declaration is first encountered. All elements are initiallized to **zero** if not explicitly initialized. (***This does not happen for automatic local arrays***)

# 2. Passing Arrays to Functions

## 2.1 To pass an array argument to a function
Specify array name without brackets
* Array declares: `int hourlyTemperatures[24];`
* Funtion call: `modifyArray(hourlyTemperatures, 24);`\
passes array `hourlyTemperatures` and its **size** to function `modifyArray`.

## 2.2 Functions that take arrays as arguments
* Function parameter list must specify array parameter\
Function prototype: `void modArray( int b[], int arraySize)`
* Array parameter may include the size of the array\
(Compiler will ignore it, though compiler only cares about the address of the first element)

## 2.3 ***Arrays*** are passed by reference （地址传递）

## 2.4 ***Array elements*** are passed by value （值传递）

## 2.5 Const array parameters
Prevent accidental modification of data.

Example:
```c++
void tryToModifyArr(const int b[])
{
    b[0] /=2;
}

int main()
{
    int a[] = {1,2,3}
    tryToModifyArr(a)//Will issue an error
    return 0;
}
```

# 3. Seraching Arrays

## 3.1 Arrays may store large amounts of data
May need to determine if certain key value is located in an array

## 3.2 Linear search
* Compares each element of an addry with a **search key**
* On average, program must compare the search key with **half** the elements of the array
* To determine that value is not in array, program must compare the search key to every element in the array
* This works well for **small** or **unsorted** arrays