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

    //第一种
    // char buf[1024] = {0};
    // while(ifs >> buf)
    // {
    //     cout << buf << endl;
    // }

    // ifs.close();

    //第二种
    // char buf[1024] = {0};
    // while (ifs.getline(buf,sizeof(buf)))//一个字符占一个字节
    // {
    //     cout << buf << endl;
    // }

    //第三种
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