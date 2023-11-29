# 01 Using Const with Pointers
## 1. **const** qualifier

* **const** indicates that the value of variable should not be modified
* This is used when function does not need to change the variable's value

## 2. Principle of least privilege 最小特权原则
* This principle award function enough access to accomplish task but ***no more***
* Example:
  * A function that prints the elements of an array
    * Array contents are not changed -- should be const
    * Array length is not changed -- should be const

## 3. Four ways to pass pointer to function
### (1) Nonconstant pointer to nonconstant data
* ***Highest*** amount of access
* Data can be modified through the dereferenced pointer
* Pointer can be modified to point to other data
* Its declaration does not include const qualifier

Example:
```c++
#include <iostream>
#include <cctype>
using namespace std;

void convertToUppercase(char *);

int main()
{
    char phrase[] = "characters and $32.98";

    cout << "The phrase before conversion is: " << phrase;
    convertToUppercase(phrase);
    cout << "\nAfter: " << phrase << endl;
    return 0;
}

void convertToUppercase(char *sPtr)
{
    while (*sPtr != '\0')
    {
        if (islower(*sPtr))
        {
            *sPtr = toupper(*sPtr);
        }
        sPtr++;
    }
}
```

### (2) Nonconstant pointer to constant data
* Pointer can be modified to point to any appropriate data item
* Data ***cannot*** be modified through this pointer
* This provides the performance of "pass-by-reference" and
 the protection of pass-by-value

 Example:
 ```c++
 #include <iostream>
using namespace std;

int main()
{
  const char phrase[] = "Print characters of a" << endl;
}
void f(const char *sPtr)
{
  for (; *sPtr != '\0'; sPtr++)
  {
    cout << *sPtr;
  }
}
 ```

### (3) Constant pointer to nonconstant data
* Always points to the ***same memory location***
  * Can only access other elements using **subscript notation**
* Data can be modified through pointer
* Can be used by a function to receive an array argument 
* ***Must be initialized*** when declared

Example:
```c++
//Warning: This program is buggy.
#include <iostream>

int main()
{
  int x, y;
  int * const ptr = &x;
  *ptr = 7;//This is valid
  ptr = &y;//This is invalid
  return 0;
}
```

### (4) Constant pointer to constant data
* Least amount of access
* Always points to the same location
* Data cannot be modified using this pointer

Example: Do we really need an example?

## 4. Case: Selection Sort (Using Pass-by-reference)
```c++
#include <iostream>
#include <iomanip>
using namespace std;

void selectionSort(int * const, const int);
void swap1(int * const, int * const);

int main()
{
  const int arraySize = 10;
  int a[arraySize] = {2,6,8,4,10,12,89,68,45,37};

  cout << "Data items in original order\n";
  for (int i = 0; i < arraySize; i++)
  {
    cout << setw(4) << a[i];
  }

  selectionSort(a, arraySize);

  cout << "\nAfter sorting:\n";
  for (int j = 0; j < arraySize; j++)
  {
    cout << setw(4) << a[j];
  }
  return 0;
}

void selectionSort(int * const array, const int size)
{
  int smallest;//index of smallest element
  for (int i = 0; i < size - 1; i++)//loop over size - 1 elements
  {    
    smallest = i;
    for (int index = i + 1; index < size; index++)
    {
      if (array[index] < array[smallest])
      {
        smallest = index;
      }
      swap1(&array[i], &array[smallest]);
    }
  }
}

void swap1(int * const element1Ptr, int * const element2Ptr)
{
  int temp = *element1Ptr;
  *element1Ptr = *element2Ptr;
  *element2Ptr = temp;
}
```

# 02 Function Pointers

## 1. Pointer to functions
* Contain addresses of funcitons
  * Function name is starting address of code that defines function

## 2. Function pointers can be:
* Passed to functions
* Returned from functions
* Stored in arrays
* Assigned to other function pointers

## 3. Calling function by using pointers
Example:
```c++
#include <iostream>
using namespace std;
void swap(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int a = 5;
    int b = 10;

    cout << "before：a = " << a << ", b = " << b << endl;
    swap(&a, &b);
    cout << "after：a = " << a << ", b = " << b << endl;

    return 0;
}
``` 

## 4. Arrays of pointers to functions
Example: Menu-driven systems
* Pointers to each function stored in array of pointers to functions
  * All function must have same return type and parameter type
* Menu choice determines subscript into array of function pointers

Example:
```c++
#include <iostream>
using namespace std;
void function0(int);
void function1(int);
void function2(int);

int main()
{
  //Create an array initialized with names of 3 functions
  void (*f[3])(int) = {function0, function1, function2};
  int choice;

  cout << "Enter a number between 0 and 2 (3 to end): ";
  cin >> choice;
  
  while ((choice >= 0) && (choice < 3))
  {
    (*f[choice])(choice);

    cout << "Enter a number between 0 and 2 (3 to end): ";
    cin >> choice;
  }

  cout << "Program execution completed." << endl;
  return 0;
}

void function0(int a)
{
  cout << "You entered " << a << " so function 0 was called.\n\n"; 
}
void function1(int a)
{
  cout << "You entered " << a << " so function 1 was called.\n\n"; 
}
void function2(int a)
{
  cout << "You entered " << a << " so function 2 was called.\n\n"; 
}
```