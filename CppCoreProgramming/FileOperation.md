# 文件操作
程序运行时产生的数据属于临时数据，程序一旦运行结束，所有数据都会被释放。

然而，我们可以通过**文件**将数据持久化——有请`#include <fstream>`。

文件类型分为两种：
1. 文本文件——以文本的**ASCII码**形式存储在计算机中
2. 二进制文件——以文本的**二进制形式**存储在计算机中。用户一般不能直接读懂他它们

操作文件的三大类：
1. ofstream：写
2. ifstream：读
3. fstream：读写

## 1. 文本文件

### 1.1 写文件
步骤如下：
1. `#include <fstream>`
2. 创建流对象`ofstream ofs;`
3. 打开文件`ofs.open("文件路径",打开方式);`
4. 写入数据`ofs << "写入的数据";`
5. 关闭文件`ofs.close();`

文件打开方式：
| 打开方式 | 描述 | 
| --- | --- |
| ios::in | 为读文件而打开文件 |       
| ios::out | 为写文件而打开文件 |
| ios::ate | 初始位置：文件尾。只在打开时才将写指针置于文件末尾。在文件操作过程中，可以通过seekp等操作移动指针位置。|
| ios::app | 追加方式写文件——每次写操作前会把写指针置于文件尾 |
| ios::trunc | 如果文件存在，先删除，再创建 |
| ios::binary | 二进制方式 |

注：
1. 文件打开方式可以用"|"操作符来配合使用。
2. ios::app不能和ios::in相配合,但可以和ios::out配合，打开输入流；
3. ios::ate可以和ios::in配合，此时定位到文件尾，如果是同ios::out配合，那么将清空原文件；

如：用二进制方式写文件`ios::binary | ios::out`

例：
```c++
#include <iostream>
#include <fstream>
using namespace std;

void test01()
{
    ofstream ofs;
    
    //注：写路径时用"/"或"\\"，这是由于转义字符"\"的原因，两个"\"才会被认作一个"\"
    ofs.open("test.txt", ios::out);
    
    //endl也可以用于文件中换行
    ofs << "姓名：张三" << endl;
    ofs << "性别：男" << endl;
    ofs << "年龄：18" << endl;

    ofs.close();
}

int main()
{
    test01();
    return 0;
}
```

### 1.2 读文件
利用上一节的test.txt
```c++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void test01()
{
    ifstream ifs;
    ifs.open("test.txt", ios::in);

    //判断文件是否打开成功
    if(!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    //读数据

    // 第一种
    // char buf[1024] = {0};
    // while(ifs >> buf)
    // {
    //     cout << buf << endl;
    // }

    // ifs.close();

    // 第二种
    // char buf[1024] = {0};
    // while (ifs.getline(buf,sizeof(buf)))//一个字符占一个字节
    // {
    //     cout << buf << endl;
    // }

    // 第三种
    string buf;
    while (getline(ifs, buf))
    {
        cout << buf << endl;
    }

}

int main()
{
    test01();
    return 0;
}
```

### 1.3 读文件的相关函数
| 函数 | 描述 | 参数 |
| --- | --- | --- |
| `open()` | 打开文件 | `const char* filename`, `ios_base::openmode mode` |
| `close()` | 关闭文件 | 无 |
| `is_open()` | 检查文件是否已经成功打开 | 无 |
| `good()` | 检查文件流是否处于一个有效状态 | 无 |
| `bad()` | 检查文件流是否处于一个错误状态 | 无 |
| `operator>>` | 从文件流中读取数据 | `int`, `char`, `string` 等不同类型的数据 |
| `tellg()` | 返回当前读指针的位置 | 无 |
| `seekg()` | 设置读指针位置 | `streamoff off`, `ios_base::seekdir way` |
| `tellp()` | 返回当前写指针的位置 | |
| `seekp()` | 设置写指针位置 | |
| `peek()` | 查看下一个字符，但不提取它 | 无 |
| `ignore()` | 忽略一定数量的字符 | `streamsize n = 1`, `int_type delim = Traits::eof()` |

#### 输入流：seekg(),tellg()
seekg（）是对输入文件定位，它有两个参数：第一个参数是偏移量，第二个参数是基地址。

对于第一个参数，可以是正负数值，正的表示向后偏移，负的表示向前偏移。而第二个参数可以是：
* ios::beg：表示输入流的开始位置(begin)
* ios::cur：表示输入流的当前位置(current)
* ios::end：表示输入流的结束位置(end)

要获取文件长度，可以用 seekg 函数将文件读指针定位到文件尾部，再用 tellg 函数获取文件读指针的位置，此位置即为文件长度。

### 1.4 随机存取文件
随机存取指的是**直接移动文件的位置指针，在指定位置读写数据**，而非真的随机。

假设我们有这样一个类：
```c++
Class CustomClass
{
    int num;
    char ch[16];
};
```
#### 创建.dat文件，写入字节数据
使用reinterpret_cast<const char *>(&)将指针转化为字符指针，以输出其他类型的对象，否则write()无法运行。
```c++
outfile.write(reinterpret_cast<const char*>(&CustomClass));
```

#### 以二进制模式打开用于输出的文件
```c++
ofstream outfile("filename.dat",ios::out|ios::binary);
```

#### 向文件中随机写入数据
```c++

outfile.seekp()
```