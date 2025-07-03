#include <iostream>
using namespace std;

//To find exponentiation but without inbuilt func.
//First approach.
//example : 7^4 = 7*7*7*7 (run a loop 4(n) times (n being the power)).
int exp(int base, int power){
    int res = 1;
    for(int i=0; i<power; i++){
        res *= base;
    }
    return res;
}

//but an AMaZIMG Approach (if you are reading this, follow me on twitter XD)
//lets say what if break down the power(n) in terms of sum of powers of two:
// lets say n= 9, n = 1+8 (2^0 + 2^4)
//and to find 3^9(9 being power: what if we multiple ; 3^1 * 3^8 
//this we only need to have : a, a^2, a^4, a^8, ...., a^i (n being the power , then 1+2+4+...+i = n )
//TC: O(logn)
//Implementation:
int powAmaze(int base, int power){
    int binaryForm = power;
    int ans = 1;
    while(binaryForm>0){
        if(binaryForm%2 == 1){
            ans *= base;
        }
        base *= base;
        binaryForm /= 2;
    }
    return ans;
}
int main()
{
    cout<<"Result: "<<exp(7,4)<<endl;
    cout<<"Result: "<<powAmaze(8,4)<<endl;
    cout<<"Result: "<<exp(9,5)<<endl;
    cout<<"Result: "<<powAmaze(76,2)<<endl;
    cout<<"Result: "<<powAmaze(6,3)<<endl;
    cout<<"Result: "<<powAmaze(13,4)<<endl;
    return 0;
}