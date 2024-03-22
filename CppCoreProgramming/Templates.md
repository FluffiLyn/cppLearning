This is FluffiLyn's learning note of "C++ Templates The Complete Guide 2nd Edition"

# Chapter1: Function Templates

## 1.1 A First Look at Function Templates
Function templates provide a functional behavior that can be called for different types.

### 1.1.1 Definition
Example:
```c++
template<typename T>
T max(T a, T b)
{
    return b < a ? a : b;
}
```

Also, you can use keyword `class` instead of `typename` to define a type parameter, which comes from the C++98 standard. These are no different. However, you cannot use `struct`.
```c++
// basics/max1.hpp
template<class T>
T max(T a, T b)
{
    return b < a ? a : b; 
}
```
This is actually not recommended because it can be misleading (not only class type can be substituted for T).

### 1.1.2 Usage
```c++
// basics/max1.cpp
#include "max1.hpp"
#include <iostream>
#include <string>

int main()
{
    int i = 42;
    std::cout << "max(7,i): " <<::max(7,i) << std::endl;

    double f1 = 3.4, f2 = -6.7;
    std::cout << "max(f1,f2): " << ::max(f1, f2) << std::endl;

    return 0;
}

```