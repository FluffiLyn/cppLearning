#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
 
class CStudent
{
    public:
        char szName[20];
        int age;
};

int main()
{
	CStudent s;
	cout << sizeof(s);
	return 0;
}