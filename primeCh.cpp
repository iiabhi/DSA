#include <iostream>
using namespace std;

bool primeCheck(int num)
{
    bool isPrime = true;
    if (num == 0 || num == 1)
    {
        isPrime = false;
        return isPrime;
    }else if(num ==2){
        return isPrime;
    }
    else
    {
        for (int i = 2; i * i < num; i++)
        {
            if (num % i == 0)
            {
                isPrime = false;
                return isPrime;
            }
        }
        return isPrime;
    }
}

int main()
{
    int number;
    cout<<"Enter the number to check:"<<endl;
    cin>>number;
    bool val = primeCheck(number);
    if(val){
        cout<<"Prime number"<<endl;
    }else{
        cout<<"Not a prime no."<<endl;
    }

    return 0;
}