# Multidimensional Arrays
## 1. Definition

* Represent tables of values with rows and columns
* Elements referenced with 2 subscripts ([x],[y])
* *<font color=red> ***Do not write a[x,y]***</font> This will be treated as a[y].

## 2. Multidimensional arrays with more than two dims.

## 3. Declaration & Initializing
```c++
int b[2][2];

int c[2][2] = {{1,2},{3,4},{1}};
//The third one is defined implicitly as {1,0} 
```

## 4. Manipulations

## 5. Parameters

* Size of first dims is not required
* Size of subsequent dims are required
```c++
void printArray(const int a[][3]);
``` 
