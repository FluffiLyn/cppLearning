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
| ios::ate | 初始位置：文件尾 |
| ios::app | 追加方式写文件 |
| ios::trunc | 如果文件存在，先删除，再创建 |
| ios::binary | 二进制方式 |

注：文件打开方式可以用"|"操作符来配合使用。

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


