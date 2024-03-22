# 01 **new** and **delete**
## 1. Dynamic memory management
* Enables programmers to allocate and deallocate memory for any built-in or user-defined type
* Performed by operators *new* and *delete*

## 2. Operator **new**
* Allocates storage of the proper size for an object at execution time
* Calls a constructor to initialize the object
* Returns a pointer of the type specified to the right of **new**
* Can be used to dynamically allocate any fundamental type or any class type

## 3. Free store
* Sometimes it is called the **heap**
* Region of memory assigned to each program for storing objects created at execution time

## 4. Operator delete
* Destroys a dynamically allocated object
* Calls the destructor for the object
* Deallocates (releases) memory from the free store
* The memory can then be reused

Example:
```c++
int *p1 = new int;
char *p2 = new char;
int *p4 = new int[4];
//......
delete p1;
delete p2;
delete p3;
```

## 5. Initializing an object allocated by **new**
Example:
```c++
#include <iostream>
using namespace std;
int main()
{
    int *p = NULL;
    p = new int(89);
    //This object "89" has no name
    //which can be only accessed by pointer

    if (p == NULL)
    {
        cout << "allocation faliure\n";
        return 0;
    }
    cout << *p;
    delete p;
    return 0;
}
```
## **new** operator can be used to allocate arrays dynamically
```c++
int *gradesArray = new int[10];
//Dynamically allocate a 10-element int array 
```

## delete a dynamically allocated array
```c++
delete [] gradesArray;
```
* If the pointer points to an array of objects:
    * First calls the destructor for every object in the array
    * Then deallocates the memory
* If the statement didn't include [] and gradesArray pointed to an array of objects: 
    * Only the ***first*** object in the array would have a destruction call.

Example:
```c++
#include <iostream>
using namespace std;
int main()
{
    int *p = NULL, *t;
    int i;
    p = new int[10];
    
    if (p == NULL)
    {
        cout << "allocation failure";
        return 1;
    }

    for (i = 0; i < 10; i++>)
        p[i] = 100 + i;
    cout << endl;

    for (t = p; t < p + 10; t++)
    {
        cout << *t << " ";
    }
    cout << endl;
    delete [] p;

    return 0;
}
```

<mark>Warning: Do remember ***DELETE*** when the new object is no longer used! 