#include <iostream>
using namespace std;

void uniqueElements(int arr[], int size){
     for(int i=0; i<size; i++){
        int start = 0;
        int end = size -1;
        bool isUnique = true;
        int j =0;
        while(j < size){
            if(j!=i){
                if(arr[j] == arr[i]){
                    isUnique = false;
                    j++;
                    break;
                }
            }
            j++;
        }
        if(isUnique){
            cout<<arr[i]<<" ";
        }
        
     }
}

//O(n^2) [not the most optimized technique, can be done in O(n) with unordered_map (we'll learn later)]

int main()
{
    int arr[11] = {1,2,2,4,10,4,3,7,5,1,10};
    uniqueElements(arr, 11);
    cout<<endl;
    return 0;
}