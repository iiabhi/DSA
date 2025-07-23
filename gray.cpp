#include <iostream>
using namespace std;

int grayToBinary(int n){
    return n^(n>>1);
}

vector<int> grayCode(int n) {
    int len = pow(2, n);
    vector<int> gray;

    for(int i=0; i<len; i++){
        int x = grayToBinary(i);
        gray.push_back(x);
    }
    return gray;
}

int main()
{
    int num = 5;
    vector<int> result = grayCode(5);
    for(auto x: result){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}