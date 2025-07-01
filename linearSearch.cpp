#include <iostream>
using namespace std;

//Time complexity O(n)
int linearSearch(int arr[], int size, int target){
    for(int i=0; i<size; i++){
        if(arr[i] == target){ //FOUND
            return i;
        }
    }
    return -1; //NOT FOUND
}
int main()
{
    int n;
    cout<<"Enter arr size:";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the value to find"<<endl;
    cin>>target;

    int res = linearSearch(arr, n, target);
    if(res>=0){
        cout<<"Required Index: "<<res<<endl;
    }else{
        cout<<"Target not found"<<endl;
    }
    

    return 0;
}