# 01 sizeof Operators
## 1. sizeof()
* Returns size of operand in ***bytes***
* For **arrays**, sizeof() returns
        
        (size of 1 element) * ( number of elements)
    * size of every int element is 4
    * short 2
    * etc. 

* This operator can be used with 
  * Variable names
  * Type names
  * Constant values
* This operator is performed at compiler-time
* Parentheses (括号) are only required if the operand is a type name
Example:
```c++
#include <iostream>
using namespace std;

size_t getSize(double *);

int main()
{
    double array[20];
    cout << "The number of bytes in the array is " << sizeof(array);//output 160
    cout << "\nThe number of bytes returned by getSize is " << getSize(array) << endl;//output 20
    return 0;
}

size_t getSize(double *ptr)
{
    return sizeof(ptr);
}
```

# 02 Pointer Expressions and Pointer Arithmetic

## 1. Pointer arithmetic
* Increment/Decrement pointer (++/--)
* Add/Subtract an integer tp/from a pointer (+ or += / - or -=)
* Pointer may be subtracted from each other
* Pointer arithmetic is meaningless ***unless*** performed on a pointer to an ***array***

Example: Add
```c++
arr[114514]
vPtr = &v[0];//vPtr points to the first element v[0] (Assume that the location is 3000)
vPtr += 2;// vPtr points to v[2]; Sets vPtr to 3008 = 3000 + 4 * 2
```

## 2. Pointer assignment