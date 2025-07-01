#include <iostream>
using namespace std;
int sumArr(int arr[], int size){
    int sum = 0;
    for(int i=0; i<size; i++){
        sum = sum + arr[i];
    }
    return sum;
}

int prodArr(int arr[], int size){
    int prod = 1;
    for(int i=0; i<size; i++){
        prod = prod * arr[i];
    }
    return prod;
}
//Time complexity : O(n)
int main()
{
    int arr[5] = {1,2,3,4,5};
    cout<<"Sum of Array : "<<sumArr(arr,5)<<endl;
    cout<<"Product of Array : "<<prodArr(arr,5)<<endl;

    return 0;
}