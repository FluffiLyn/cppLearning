#include <iostream>
using namespace std;
/*To obtain all prime numbers within the natural number n, the multiples of all prime numbers that 
are not greater than sqrt (n) must be removed, and the remaining ones are prime numbers.*/
//This is sieve of Eratosthenes.

void findPrime(int x) 
{
    bool isPrime[x + 1]; //to sign the number
    fill_n(isPrime, x + 1, true); //Initiallize every element in every array, assuming that
                                  //they are all prime numbers.
    for (int n = 2; n * n <= x; n++) 
    {
        if (isPrime[n]) 
        {
            for (int i = n * n; i <= x; i += n) 
            {
                isPrime[i] = false; //Sign the multiples of n as non-primes.
            }
        }
    }

    cout << "2到" << x << "之间的所有质数有：" << endl;
    for (int n = 2; n <= x; n++) 
    {
        if (isPrime[n]) 
        {
            cout << n << " ";
        }
    }
    cout << endl;
}

int main() {
    findPrime(10000);
    return 0;
}
