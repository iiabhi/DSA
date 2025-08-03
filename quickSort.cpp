#include <iostream>
using namespace std;

int partition(vector<int> &arr,int st, int end){
    int pivot = arr[end];
    int idx = st-1;
    for(int j=st; j<end; j++){
        if(arr[j]<= pivot){   //pivot = arr[end]
            ++idx;
            swap(arr[j], arr[idx]);
        }
    }
    idx++;
    swap(arr[idx], arr[end]);
    return idx;
}


void quickSort(vector<int> &arr,int st, int end){
    if(st<end){
        int pivot = partition(arr, st, end);
        quickSort(arr, st, pivot-1);
        quickSort(arr, pivot+1, end);
    } 
}

int main()
{
    vector<int> vec = {4,1,7,8,2,3,9};
    quickSort(vec, 0, vec.size()-1);
    for(auto x: vec){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}