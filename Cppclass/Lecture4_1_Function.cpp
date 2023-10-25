/*
//1、生词
facilitate   v.促进             coercion    n.强制，胁迫
heirarchical adj.分层的
invoke       v.调用，激发
parameter    n.形参
argument     n.实参
invoke       v.调用 (=call) 


//2、函数创建

dataType functionName (Parameters)
{
    xxx;
    return xxx; | or no return
}


//3、函数调用

functionName(Arguments);

//(1)arguments和parameters要一一对应

//(2)Argument Coercion
        Forcing arguments to the appropriate types specified by the corresponding parameters.
        (For Example, calling a funcion with an int argument, even though the function prototype specifies a double argument)

//(3)C++ Promotion Rules
        a)Indicate how to convert between types without losing data.
        b)Promotion also occurs when the type of a function argument does not match the specified parameter type.
        c)Promotion is as if the argument value were being assigned directly to the parameter variable

//(4)Apply (3) to expressions containing values of two or more data:
        a)Such expressions are also referred to as mixed type expressions
        b)
        c)

//(5)Converting a value to a lower fundamental type:
        a)Will likely result in the loss of data or incorrect values.
        b)can only be performed explicitly.
        c)If by assigning the value to a variable of lower type, some compilers may issue a warning.
        d)U can use a cast operator

        static_cast<type>(data);


//4、Function Prototype(or Declaration) 函数声明


//5、Function Signature 函数签名
//C++ 官方定义中，签名就是函数的参数部分，不包括函数的返回类型。但习惯上一般把函数返回类型和参数都作为签名的部分。
  例如函数声明中 std::size_t func(int num);，func 函数签名为 std::size_t 和 int。



*/ 

