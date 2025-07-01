#include <iostream>
using namespace std;

//Assuming both array has distinct elements.

//O(n^2)
void intersectionArr(int arr1[], int size1, int arr2[], int size2){
    for(int i=0; i<size1; i++){
        for(int j=0; j<size2; j++){
            if(arr1[i]==arr2[j]){
                cout<<arr1[i]<<" ";
            }
        }
    }
}

int main()
{
    int arr2[7] = {1,2,3,4,5,6,7};
    int arr1[6] = {1,5,90,4,66,77};

    intersectionArr(arr1, 7, arr2, 6);
    cout<<endl;
    return 0;
}