#include <iostream>
#include <cmath>

using namespace std;

/*===============bool isPrime(float nTest)=============
nTest: the number to be test
returns: true if the number is a prime number
         false if it is not
assumes the test case is either an integer or a decimal number
========================================================*/

bool isPrime(float nTest)
{
    if(int(nTest) != nTest || nTest < 2)//check to see whether nTest is a legal input or not
    {
        return false;
    }
    else
    {
        bool isPrime = true;
        int nTestInt = int(nTest);
        for (int i = 2; i <= sqrt(nTestInt); i++)//to test from 2 to sqrt(n) because of the symmetry of multiplying
        {
            if (nTestInt % i == 0)//there is a divisor
            {
                isPrime = 0;//if there is a divisor, set the flag to false
            }
        }
        if (isPrime)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}


int main()
{
    int testNum = 10;
    float testCase[testNum] = {-34, -94.67, 0, 0.3, 1, 1.4, 2, 45, 134.45, 73};
    for (int i = 0; i < testNum; i++)
    {
        cout << testCase[i] << ": " << isPrime(testCase[i]) << endl;
    }
    return 0;
}
