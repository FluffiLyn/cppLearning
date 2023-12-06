# 01 Struct 结构体
* **struct** is a complex ***data type*** declaration that defines a physically grouped list of variables to be placed under one name in a block of memory,
* allowing different variables to be accessed via a single pointer, or the ***struct declared name*** which returns the sanme address

## 1. struct Declaration
```c++
struct employee
{
    char name[10];
    long code;
    double salary;
    char address[50];
    char phone[20];
};
//DON'T forget the last semicolon
```

### Member of struct can be another defined struct
```c++
struct date
{
    int month;
    int day;
    int year;
};

struct employee
{
    char name[10];
    date birthday;
    //etc.
};
```

## 2. struct Initialization
```c++
struct employee
{
    char name[10];
    long code;
    double salary;
    char address[50];
    char phone[11];
};

employee worker = {"Trump", 1145141919810, 11451.4, "White House", "1234567890"};//By value
employee *Emp = &worker;//By reference
```

# 02 Visit struct Variable

## 1. Two ways

### By struct variable name

```c++
employee _001;
_001.name = "Tom";
```

### By struct pointer

```c++
employee _002;
employee * pp = &_002;

strcpy(pp -> name, "Kutto Yaki");
pp -> id = 123456789;
cout << (*pp).name << '\t' << (*pp).id;
```

## 2. Assignment
* The ***same type*** of the struct variables can be assigned as a whole.

```c++
_001 = _002;
```

# 03 struct Array

## Array elements' type is struct
```c++
struct S_type{int a; double x;};
S_type S_arr[10];
```
Each of the array element contains two members\
* S_arr[0].a
* S_arr[0].x

