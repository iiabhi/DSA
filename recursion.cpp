#include <iostream>
using namespace std;

//print
void print(int num){
    if(num==1){
        cout<<1<<endl;
        return;
    }
    cout<<num<<" ";
    return print(num-1);
}
//sum N
int sum(int x){
    if(x==1){
        return 1;
    }
    return x+sum(x-1);

}

//factorial
int fact(int n){
    if(n==0){
        return 1;
    }
    return n*fact(n-1);
}

//id array is sorted
 bool isSorted(vector<int> arr, int n){
    if(n==0 || n==1){
        return true;
    }
    return arr[n-1]>arr[n-2] && isSorted(arr, n-1);

 }

 //binary search.  TC: O(logN)
 int binarySearch(vector<int> arr, int target, int st, int end){
    if(st>end){
        return -1;
    } 
    int mid = st + (end-st)/2;

     if(arr[mid]==target) return mid;
     else if(arr[mid]>target){
        return binarySearch(arr, target, st, mid-1);
     }else{
        return binarySearch(arr, target, mid+1, end);
     }
 }

 //Print all the subsets or subsequence
 void printSubset(vector<int> &arr, vector<int> &ans, int i){
    if(i==arr.size()){
        //print subsets
        for(auto val: ans){
            cout<<val<<" ";
        }
        cout<<endl;
        return ;
    }

    //inclusion
    ans.push_back(arr[i]);
    printSubset(arr, ans, i+1);

    ans.pop_back();

    //exclude
    printSubset(arr,ans,i+1);

 }

int main()
{
    print(5);

    cout<<sum(5)<<endl;

    cout<<fact(5)<<endl;

    vector<int> arr = {1,2,3,4,5,9};
    cout<<isSorted(arr, arr.size())<<endl;

    cout<<binarySearch(arr, 0, 0, arr.size()-1)<<endl;

    vector<int> ans;
    printSubset(arr, ans, 0);
    return 0;
}