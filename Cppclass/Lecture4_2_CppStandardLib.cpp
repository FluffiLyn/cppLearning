/*
//1、生词
//Pseudo Ramdom Numbers 伪随机数
//Enumeration           n.枚举


//2、c++ Standard Library c++标准库
//(1)<iostream>
//(2)<cmath>
//(3)<string>
//(4)<alrogithm>
//etc.


//3、Pseudo Ramdom Numbers

#include <stdlib.h>
int rand(void);               //生成随机数
void srand(unsigned int seed);//生成由种子决定的随机数

//要取得 [a,b) 的随机整数，使用 (rand() % (b-a))+ a;
//要取得 [a,b] 的随机整数，使用 (rand() % (b-a+1))+ a;
//要取得 (a,b] 的随机整数，使用 (rand() % (b-a))+ a + 1;


//4、Enumeration 枚举
//(1)Concept
        A set of integer constants represented by identifiers.
        
            a)The values of enumeration constants start at 0, unless specified otherwise, and increment by 1. 
            b)The identifiers in an enum must be unique, but separate enumeration constants can have the same int value
//(2)Define an enumeration

    enum Status { WIN, LOST, CONTIUNE, DRAW}
    Status gameStatus;//定义一个变量gameStatus，其类型为Status（这是由前面代码定义的枚举类型）
    

*/

