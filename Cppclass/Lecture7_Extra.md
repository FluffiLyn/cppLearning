# 01. Typedef
* 在编程中使用typedef目的一般有两个，一个是给变量提供一个易记且意义明确的新名字（类型有新别名，方便变量的定义），另一个是简化一些比较复杂的类型声明。

Example:
```c++
//New name
typedef unsigned int size_t;

//Simplifiy the complex declaration
//int *(*a[5])(int, char*);
typedef int *(*pFun)(int, char*);
pFun a[5];

//Simplify double(*)() (*e)[9];
typedef pFuny (*pFunParamy)[9];
pFunParamy e;


//type (*)(....)函数指针
//type (*)[]数组指针
```

# 02 Multi-include  
