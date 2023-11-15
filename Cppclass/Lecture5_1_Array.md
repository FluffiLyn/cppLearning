# 1. Array Introduction
(1) An array is a data structure containing related data items of same type.

(2) ~ is always remain the same size once created.

(3) Declaration: **datatype identifier[expression];**

```c++
int arr[5];
```
* ***Consecutive (连续的) group of memory locations***, all of which have the same type.

* "Datatype" is the data type of elements in array (any non-reference data type).

* "Expression" is the size (number of elements) of array which must be an integer greater than 0;

# 2. Using Arrays
## Visit elements in array
Arrayname[index];
```c++
int arr[10] = {1,2,3,4,5,6,7,8,9,10};

cout << arr[0];//output 1
```
***Do remember first element has index ZERO***

## Using a loop to initialize the array's elements

## Initializing an array in a declaration with an initializer list

## Specifying an array's size with a constant variable
read-only.

## Setting array elements of an array