* Character constant
  * Integer value represented as character in single quotes.
  * Example: 'z' is integer value of z (122 in ASCII)
* String
  * Series of characters treated as **SINGLE** unit 
  * Can include letters, digits, special characters, ...
  * String literal (string constants)
    * Enclosed in double quotes
    * Example: " To C or not to C, that's a question. "
  * Array of characters, **ends with null character '\0'**

# 1. String Assignment
* Character array
```c++
char color[] = {'b', 'l', 'u', 'e', '\0'};
```

* String constant
```c++
char color[] = "blue";//This creates 5 element char array. (cuz this includes '\0')
```

# 2. Outputting String
Example:
```c++
//Warning: this program is buggy
#include <iostream>
using namespace std;
int main()
{
    char ca[5] = {'a', 'b', 'c' , 'd', 'e'};
    for (int i = 0; i < 5; i++)
    {
        cout << ca[i];
    }
    cout << endl;
    cout << ca << endl;

    return 0;
}
```
Output:
```
abcde
abcde烫烫烫蘠
```
Reasons:
* This char array doesn't include '\0'. Therefore, cout will not stop reading this array, till out of bound.

(Remark: acutally, cout << ca; is accessing the address of this array. However, it is useless to merely get the address of a char array. So the compiler will regard this command as outputting the contents.)

# 3. Reading strings

1. Assign input to character array word[20]

```c++
cin >> word;
``` 
* Reads characters until whitespace or EOF(结束符)
1. String could exceed array size
```c++
cin >> set2(20) >> word;
```
* Reads only up to 19 characters (space reversed for '\0')

## cin.getline
* Read line of text
```c++
cin.getline(array, size, delimiter);
```
* Copies input into specified array until either:
  * One less than **size** is reached
  * **delimiter** character is input

Example:
```c++
char sentence[80];
cin.getline(sentence, 80, '\n');
```

# 4. Output strings
EZ