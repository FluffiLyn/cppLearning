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
<mark>(1) Nonconstant pointer to nonconstant data</mark>
* ***Highest*** amount of access
* Data can be modified through the dereferenced pointer
* Pointer can be modified to point to other data
* Its declaration does not include const qualifier

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