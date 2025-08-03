#include <iostream>
using namespace std;
//TC: O(n)
void merge(vector<int> &arr, int st, int mid, int end){ 
    vector<int> temp;
    int i = st;
    int j = mid+1;
    
    while(i<=mid && j<=end){
        if(arr[i]>arr[j]){
            temp.push_back(arr[j]);
            j++;
        }else{
            temp.push_back(arr[i]);
            i++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }

    for(int i=0; i<temp.size(); i++){
        arr[i+st] = temp[i];
    }



}

void mergeSort(vector<int> &arr, int st, int end){
    if(st<end){
    int mid = st + (end - st)/2;
    mergeSort(arr, st, mid);
    mergeSort(arr, mid+1, end);

    merge(arr, st, mid, end);
    }
    

}


int main()
{
    vector<int> vec = {4,2,7,7,9,5,1,2};

    mergeSort(vec, 0, vec.size()-1);
    for(auto x: vec){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}