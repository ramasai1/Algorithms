//For numbers from 2 to a certain integer limit. 
//Does not include 1 as it is not prime. 

#include <iostream>
#include <cmath>
using namespace std;

void sieve_of_erastothenes(int limit)
{
    bool prime [limit];
    memset (prime, true, sizeof(prime));

    for (int i = 2; i < sqrt(limit); i++)
    {
        if (prime[i] == true)
        {
            for (int j = i*i; j < limit; j += i)
                prime[j] = false;
        }
    }

    for (int p=2; p<=limit; p++)
        if (prime[p])
            cout << p << " ";
}
