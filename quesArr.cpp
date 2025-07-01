#include <iostream>
using namespace std;
void swaparr(int arr[], int size){
    int maxx = INT_MIN;
    int minn = INT_MAX;
    int indexMin;
    int indexMax;
    //O(n)
    for(int i=0; i<size; i++){
        if(arr[i]>maxx){
            maxx = arr[i];
            indexMax = i;
        }
        if(arr[i]<minn){
            minn = arr[i];
            indexMin = i;
        }
    }
    //swap
    int temp = arr[indexMin];
    arr[indexMin] = arr[indexMax];
    arr[indexMax] = temp;

}
int main()
{
    int arr[5] = {1,2,3,4,5};
    swaparr(arr, 5);

    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}