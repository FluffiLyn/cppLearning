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