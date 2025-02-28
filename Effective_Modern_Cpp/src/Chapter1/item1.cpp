template<typename T>
void f1(T& param);

void case1(){
    int x = 27;
    const int cx = x;
    const int& rx = x;

    // 将鼠标悬停在f1上，可以看到param的类型
    f1(x);   // T is int, param's type is int&
    f1(cx);  // T is const int, param's type is const int&
    f1(rx);  // T is const int, param's type is const int&
}

template<typename T>
void f1_const(const T& param);
void case1_const(){
    int x = 27;
    const int cx = x;
    const int& rx = x;

    f1_const(x);   // T is int, param's type is const int&
    f1_const(cx);  // T is int, param's type is const int&
    f1_const(rx);  // T is int, param's type is const int&
}

template<typename T>
void f1_pointer(T* param);
void case1_pointer(){
    int x = 27;
    const int* px = &x;

    f1_pointer(&x);//T is int，param's type is int*
    f1_pointer(px);//T is const int，param's type is const int*
}

template<typename T>
void f2(T&& param);
void case2(){
    int x = 27;
    const int cx = x;
    const int& rx = x;

    f2(x);//x是左值，所以T是int&，param类型也是int&

    f2(cx);//cx是左值，所以T是const int&，param类型也是const int&

    f2(rx);//rx是左值，所以T是const int&，param类型也是const int&

    f2(27);//27是右值，所以T是int，param类型就是int&&
}