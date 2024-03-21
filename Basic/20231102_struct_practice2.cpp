#include <iostream>
#include <string>
using namespace std;

struct hero
{
    string name;
    int age;
    string gender;
};

void bubbleSort(struct hero heroArray[], int len)
{
    for(int i = 0; i < len - 1; i++)
    {
        for(int j = 0; j < len - i - 1; j++)
        {
            if(heroArray[j].age > heroArray[j+1].age)
            {
                struct hero temp = heroArray[j];
                heroArray[j] = heroArray[j+1];
                heroArray[j+1] = temp;
            }
        }
    }
}

void printHero(struct hero heroArray[], int len)
{
    for(int i = 0; i < len; i++)
    {
        cout << "姓名：" << heroArray[i].name << " 年龄：" << heroArray[i].age << " 性别：" << heroArray[i].gender << endl;
    }
}

int main()
{
    struct hero heroArray[5] =
    {
        {"刘备",23,"男"},
        {"关羽",24,"男"},
        {"张飞",22,"男"},
        {"吕布",21,"男"},
        {"貂蝉",19,"女"}
    };

    int len = sizeof(heroArray) / sizeof(heroArray[0]);
    bubbleSort(heroArray, len);
    printHero(heroArray, len);

    return 0;
}