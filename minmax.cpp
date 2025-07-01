#include <iostream>
using namespace std;

int minm(int arr[],int size){
    int minimun = INT_MAX;
    for(int i=0; i<size; i++){
        minimun = min(arr[i],minimun);
    }
    return minimun;
}

int maxm(int arr[], int size){
// int maxm(int arr[]){
    //  if you write line 14 instead of 15:
    // int size = sizeof(arr)/sizeof(int); //This is a common mistake people do to find size of array if not passed with parameter.
    //Reason : Array decays into pointer (int* arr (pointer) you are basically passing apointer)
    // you can't get the size of original array inside the function.
    // Correct way is to pass the size seperately.
    int maximum = INT_MIN;
    for(int i=0; i<size; i++){
        maximum = max(arr[i],maximum);
    }
    return maximum;
}

int minIndex(int arr[], int size){
    int minimun = INT_MAX;
    int index = 0;
    for(int i=0; i<size; i++){
        if(minimun > arr[i]){
            index = i;
        }
        minimun = min(arr[i],minimun);
    }
    return index;
}

int maxIndex(int arr[], int size){
    int maximum = INT_MIN;
    int index = 0;
    for(int i=0; i<size; i++){
        if(maximum < arr[i]){
            index = i;
        }
        maximum = max(arr[i],maximum);
    }
    return index;
}

int main()
{
    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;

    int arr[n];
    cout<<"Enter the values of array:"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Minimum of array is:"<<minm(arr,n)<<endl;
    cout<<"Maximum of array is:"<<maxm(arr,n)<<endl;

    cout<<"Minimum element of array Index is:"<<minIndex(arr,n)<<endl;
    cout<<"Maximum element of array index is:"<<maxIndex(arr,n)<<endl;
    return 0;
}