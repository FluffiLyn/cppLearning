#include <iostream>
using namespace std;
/*To obtain all prime numbers within the natural number n, the multiples of all prime numbers that 
are not greater than sqrt (n) must be removed, and the remaining ones are prime numbers.*/

//This is sieve of Eratosthenes.

void findPrime(int x) 
{
    bool isPrime[x]; //to mark the number
    fill_n(isPrime, x, true); //Initiallize every element in every array, assuming that
                                  //they are all prime numbers.
    for (int n = 2; n * n <= x; n++) 
    {
        if (isPrime[n]) //If the smallest number is prime
        {
            for (int i = n * n; i <= x; i += n) 
            {
                isPrime[i] = false; //Mark the multiples of n as non-primes.
            }
        }
    }

    cout << "The prime numbers between 2 and " << x << "are: " << endl;
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
