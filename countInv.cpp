#include <iostream>
#include<vector>
using namespace std;

int merge(vector<int> &arr, int st, int mid, int end){
    int cntInv = 0;
    vector<int> temp;
    int i=st;
    int j = mid+1;

    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[j]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
            cntInv += (mid-i+1);
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
    for(int idx =0; idx<temp.size(); idx++){
        arr[st+idx] = temp[idx];
    }
    return cntInv;
}



int mergeSort(vector<int> &arr, int st, int end){
    if(st<end){
        int mid = st + (end-st)/2;

        int leftInvCnt = mergeSort(arr, st, mid);
        int rightInvCnt = mergeSort(arr, mid+1, end);

        int cntInv = merge(arr, st, mid, end);

        return leftInvCnt+rightInvCnt+cntInv;
    }
    return 0; //invalid count
}
int main()
{
    vector<int> vec = {5,3,7,9,1,2};

    int ans = mergeSort(vec, 0, vec.size()-1);
    cout<<"Count inversion: "<<ans<<endl;
    return 0;
}