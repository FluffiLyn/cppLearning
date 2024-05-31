# 一、iostream概述
## state bits（状态码）
任何流对象都有状态码。它们是ios_base的元素。可以认为，它们是一组3个二进制位的常量。比如eofbit=001，failbit=010，badbit=100，goodbit=000。每个元素都是**一位**，1（置位），0（清除）。
* eofbit: 当cin操作到达文件末尾时，它将置位eofbit
* failbit: 非致命的输入/输出错误，可挽回
* badbit: 致命的输入/输出错误，使程序终止
* goodbit: 正常。实际上goodbit取决于前三个bit

它们不一定是互斥的，可能同时发生。
## 流状态函数
每次使用cin和cout，程序会根据结果设置状态码。这涉及一些函数：
* eof()：判断存储状态的变量中eofbit那个二进制位是否=1（不论其他位的值）
* fail ()：判断 存储状态的变量中failbit 那个二进制位是否=1（不论其他位的值）
* bad ()： 判断 存储状态的变量badbit 那个二进制位是否=1（不论其他位的值）
* good ()： 判断 存储状态的变量eofbit failbit、 badbit的二进制位是否全部为0
* setstate(): 置位，开启三个状态（就是除goodbit之外）中的一个，要传入一个iostate值。（按位的或运算，实际上setstate()的定义中包含clear()）
* clear(): 复位，关闭，将传入的iostate值（二进制值）为0的位置在原条件变量中也设置为0.（按位的与运算）

## cout（标准输出流）
预定义的对象 cout 是 iostream 类的一个实例。cout 对象"连接"到标准输出设备，通常是显示屏。

### 输出字符串指针的地址
```c++
char * word = "Hello";
cout << static_cast<void*>(word);
```
### cout.put()函数
直接输出一个字符。
```c++
cout.put(char);
cout.put('A').put('B');
```

## cin（标准输入流）
输入一串字符串，按下回车(\r)，回车会被转换成换行符(\n)，并与字符串一起存入缓冲区。（字符数+1）

注意：遇到空格、回车等会结束获取输入的字符串，后面的字符串会留在输入流中，在下一次输入字符串时开始获取。在使用cin相关的输入时，如有必要，记得清空缓冲区。

### 输入方式

#### 1. >>输入

#### 2. cin.get()函数
用于输入字符和字符数组。有四种重载模式。
```c++
int cin.get();//无参，用于舍弃输入流中紧挨的一个字符
istream& cin.get(char& var);//输入单个字符
istream& get ( char* s, streamsize n );//输入字符数组（预设时要比实际输入长度大1）
istream& get ( char* s,  streamsize  n, char delim )
```

#### 3.cin.getline()函数
用于输入一整行字符数组，包括空格之类的制表符，可以以指定的结束符结束（如'\0'）。这些是>>做不到的。
```c++
istream& getline(char* s, streamsize count); //默认以换行符结束
istream& getline(char* s, streamsize count, char delim);
```
#### 4.getline()函数
这个函数是在string.h里声明的全局函数，接收string类型。相比cin.getline()，string的getline()可以接收回车，并且结尾没有'\0'。

### cin.ignore(),putback(),peek()
(1)cin.ignore()
```c++
istream& ignore();//无参时清空1个字符，遇到EOF停止
istream& ignore(streamsize n = 1, int delim = EOF);
```
它表示从输入流 cin 中提取字符，提取的字符被忽略，不被使用。而每抛弃一个字符，它都要进行计数和比较字符：如果计数值达到 n 或者被抛弃的字符是 delim ，则cin.ignore() 函数执行终止。

它可以清空回车结束的输入缓冲区的内容，消除上一次输入对下一次输入的影响。

（2）cin.putback()

将从流中提取的最后一个字符char放回流中，使得下一个读到的字符是char，其余保持不变。例如：
```c++
#include <iostream>
using namespace std;
int main () 
{
    char c;
    int n;
    char str[256];
    cout << "Enter a word: ";
    cin >> c;
    cin.putback (c);
    cin >> str;
    cout << " You have entered word " << str << endl;
    return 0;
}
```

(3)cin.peek()

返回指针指向的当前字符。并不会删除字符或者移动指针。如果访问的字符是文件结束符EOF，则返回EOF(-1)。

例：输入一串数字（包括空格），当键入回车时计算出输入数字的和。
```c++
#include<iostream>
using namespace std;

int main()
{
    int a;
    int sum;
      
    while(cin>>a)
    {
        sum+=a;
        while(cin.peek()==' ')//观测到当前字符为空格的话
        {
            cin.get();　　　　//从流中提取当前的空格
        }        
        if(cin.peek()=='\n')　　//观测到当前字符为换行符的话直接终止
        break;
    }
    
    cout<<"结果是："<<sum<<endl;
    return 0;
} 
```
### 非格式化IO：cin.read(),cout.write(),cin.gcount()
非格式化的输入输出用于处理二进制数据。

(1)cin.read()
```c++
istream& read(char* buffer, streamsize num);
```
从流中或者文件中按字节读取数据。例如：
```c++
char buf[] = "HAPPY BIRTHDAY";
cout.write(buf,10);
```
输出：
```
HAPPY BIRT //空格也算一个字节
```

(2)cin.gcount()
```c++
streamsize gcount();
```
用于获取上一次读操作获取的字符数，与cin.write()配合使用。

(3)cout.write()
```c++
ostream& write(const char* buffer, streamsize num);
```
用于将一个字符数组的数据写入输出流，可以精确控制。

## cerr（标准错误流）
cerr 对象是非缓冲的，且每个流插入到 cerr 都会立即输出。

## clog（标准日志流）
clog 对象附属到标准输出设备，通常也是显示屏，但是 clog 对象是缓冲的。这意味着每个流插入到 clog 都会先存储在缓冲区，直到缓冲填满或者缓冲区刷新时才会输出。

clog 通常用于记录目的。对于非关键事件日志记录，效率更为重要，因此clog 优于 cerr。缓冲输出不适用于严重错误。在系统崩溃的情况下，可能会出现输出仍在缓冲区中并且没有写入磁盘并且无法检索错误消息的情况。我们不能在系统崩溃的情况下丢失错误数据，因此即使速度较慢，我们也会继续将严重错误写入磁盘。

# 二、io manipulator