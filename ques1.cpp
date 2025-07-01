#include <iostream>
using namespace std;

//usingLoop
bool powerOfTwo(int num){
    int compNum = 1;
    bool powerTwo = false;
    for(int i=0; i<32; i++){
        if(compNum == num){
            powerTwo = true;
            return powerTwo;
        }
        compNum = compNum*2;

    }
    return powerTwo;
}

//using bitwise to find power of two, (brilliant trick!)
bool powerTwobitwise(int num){
    if(num>0){
        if(((num)&(num-1))==0){   //in num , there is only single bit as 1 (if power of two ) and n-1 will have all 1's following, bitwise and will give zero.
            return true;
        }else{
            return false;
        }
    }else{
        cout<<"Negative or Zero."<<endl;
        return -1;
    }
}

int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;

    bool res = powerOfTwo(n);
    if(res){
        cout<<"Power of Two Confirmed!"<<endl;
    }else{
        cout<<"Power of Two Rejected !"<<endl;
    }

    bool result = powerTwobitwise(n);
    if(result){
        cout<<"Power of Two Confirmed!"<<endl;
    }else{
        cout<<"Power of Two Rejected !"<<endl;
    }

    return 0;
}