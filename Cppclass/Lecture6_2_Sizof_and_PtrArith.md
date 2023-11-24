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
* Pointer can be assigned to another pointer if both are of the same type
* If not, ***cast operator*** must be used
* ***Exception***: Pointer to void (void *)
    * Generic pointer, represents any type
    * **NO** casting needed to convert pointer to void *, but is needed to convert void * to ***any other type***
    * void pointers ***cannot*** be dereferenced

## 3. Pointer comparison
* Use equality and relational operators
* Compare ***addresses*** stored in pointers
    * Comparisons are meaningless unless pointers point to members of the same ***array***
* Commonly used to determine whether pointer is ***Null pointer***

# 03 Arrays and Pointers

## 1. Arrays and pointers are closely related
* ***Array name*** is equivalent to a ***constant pointer***
* Pointers can do array subscripting operations

## 2. Accessing array elements with pointers
```c++
int b[5];
int *bPtr;
bPtr = b;
```
* Element b[n] can be accessed by *(bPtr + n)
    * This is called pointer/offset notation
* &b[3] is the same as (bPtr + 3)
* b[3] is the same as *(b + 3)
* Pointers can be subscripted
    * bPtr[3] is the same as b[3]

## 3. Accessing array elements with pointers
```c++
int a[10];
```

* a + i is equivalent to & a[i]
* a[i] is equivalent to *(a + i)

Example: 
```c++
#include <iostream>
using namespace std;

int main()
{
    int b[] = {10, 20, 30, 40};
    int *bPtr = b;

    cout << "Array b printed with:\n\nArray subscript notation: " << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << "b[]" << i << "] = " << b[i] << '\n';
    }

    cout << "\nPointer/offset notation where the pointer is the array name\n";

    for (int offset1 = 0; offset1 < 4; offset1++)
        cout << "*(b + " << offset1 << ") = " << *(b + offset1) << endl;

    return 0;
}
```

Output:
```
*(b + 0) = 10
*(b + 1) = 20
*(b + 2) = 30
*(b + 3) = 40
```