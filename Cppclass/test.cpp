#include <iostream>
using namespace std;
void function0(int);
void function1(int);
void function2(int);

int main()
{
  //Create an array initialized with names of 3 functions
  void (*f[3])(int) = {function0, function1, function2};
  int choice;

  cout << "Enter a number between 0 and 2 (3 to end): ";
  cin >> choice;
  
  while ((choice >= 0) && (choice < 3))
  {
    (*f[choice])(choice);

    cout << "Enter a number between 0 and 2 (3 to end): ";
    cin >> choice;
  }

  cout << "Program execution completed." << endl;
  return 0;
}

void function0(int a)
{
  cout << "You entered " << a << " so function 0 was called.\n\n"; 
}
void function1(int a)
{
  cout << "You entered " << a << " so function 1 was called.\n\n"; 
}
void function2(int a)
{
  cout << "You entered " << a << " so function 2 was called.\n\n"; 
}