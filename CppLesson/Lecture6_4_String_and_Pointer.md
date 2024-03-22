# 01 Pointer-based Strings

## 1. String assignment
* Variable of type char *: char *colorPtr = "blue";
  * creates pointer colorPtr to character b in string "blue"
  * "blue" is somewhere in memory 
## 2. Reading strings
* Assign input to character array word[20]:
```c++
cin >> word;
//This reads characters until whitespace or EOF
```
* Assign input to character pointer char *ptr:
```c++
cin >> ptr;
```
cout << ptr;

# 02 String-Handling Library

## 1. < cstring > or < string > provides functions to:
* Manipulate string data
* compare strings
* search strings for char and other strings
* Tokenize strings (separate strings into logical pieces)

## 2. New data type **size_t**
* size_t is defined to be an unsigned integral type

## 3. Copying strings
(1)
```c++
char *strcpy(char *s1, const char *s2)
```
* This copies second argument into first argument
* First argument must be large enough to store string and terminating null character.

***Notice: This function is banned by Visual Studio due to the unsafety.***
\
\
(2)
```c++
char *strncpy(char *s1, const char *s2, size_t n)
```
* This specifies number of characters to be copied from second argument into first argument, which does **not necessarily copy terminating null character**.

## 4. Concatenating strings 字符串连接
(1)
```c++
char *strcat(char *sq, const char *s2)
```
* This appends second argument to first one
  * First char of the second argument replaces '0' of the first argument
  * You must ensure the first argument is large enough to store concatenated result and '\0'

\
\
(2)
```c++
char *strncat(char *s1, char *s2, size_t n)
```
* Automatically appends terminating '\0' to result

## 5. Comparing strings
(1)
```c++
int strcmp(const char *s1, const char *s2)
```
* This compares character by character, and returns:
  * 0, if strings are equal
  * negative value, if *s1 > *s2
  * positive calue, if *s1 < *s2

(2)
```c++
int strncmp(const char *s1, const char *s2, size_t n)
```
* Compares up tot specified number of characters
  * Stops if it reaches '\0' in one of arguments

## 6. Tokenizing 字符串分割
* Breaking strings into tokens
  * Tokens usually are logical units such as words (separated by spaces)

Example:
* "This is my string" has 4 word tokens.(separated by spaces)

```c++
char *strTok(char *s1, const char *s2)

## Determining string lengths
```c++
size_t strlen(const char *s)
```

# 03 Arrays of Pointers to string

Arrays can contain pointers to store string array.

Example:
```c++
const char *nmsl[4] = {"Never", "Mind", "Slander", "Lies"};
```









