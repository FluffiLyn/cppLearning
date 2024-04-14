#include <iostream>
using namespace std;

int main()
{
    HugeInteger a("999999999998888877777766666"), b("4"),c("999999999998888877777766667"),
    d("99999999999");
    cout << "a = " ; a.output(); cout << ", b = " ; b.output();
    cout << ", c = "; c.output(); cout << ", d = "; d.output(); cout << endl;
    
    cout << "a + b = "; a.add(b);
    cout << "a - c = "; a.subtract(c); 
    cout << "a * b = "; a.multiply(b);
    cout << "a * c = "; a.multiply(c); 
    cout << "a / b = "; a.divide(b);
    cout << "a / d = "; a.divide(d);
    return 0;
}
