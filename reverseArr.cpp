#include <iostream>
using namespace std;

void revArr(int arr[], int size){
    int i=0;
    int j=size-1;
    while(i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}
//Time complexity O(n)

//You can use this but it will check unecessary values 
// for(int i=0, j=size-1; i<j; i++, j--){
    //     int temp = arr[i];
    //     arr[i] = arr[j];
    //     arr[j] = temp;
    // }
//NOTE: The original Array will get channged as array is passed by refrence.(pointer)
//I have use i j but try to use words like start, end for good progg. practice

int main()
{
    int arr[5] = {1,2,3,4,5};
    int arr1[6] = {1,2,3,4,5,6};

    revArr(arr, 5);
    revArr(arr1, 6);

    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<6; i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}