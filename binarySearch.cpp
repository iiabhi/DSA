#include <iostream>
#include<vector>
using namespace std;

//Recursive version
int binarySearch(vector<int> arr , int st, int end, int target){
    if(st<=end){
        int mid = st+((end-st)/2);
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid]>target){
            return binarySearch(arr,st,mid -1,target);
        }else{
            return binarySearch(arr,mid+1,end,target); 
        }
        
    }   
    return -1;
}

//Iterative version
int binarySearchIt(vector<int> arr , int st, int end, int target){
    while (st<=end){
        int mid = st+((end-st)/2);
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid]>target){
            end = mid-1;
        }else{
            st = mid+1;   
        }
    }   
    return -1;
}

int main()
{
    vector<int> vec = {1,2,4,5,7};
    int target = 2; //to find
    int n = vec.size();
    int idx = binarySearch(vec, 0, n-1, target);
    if(idx>=0){
        cout<<"Index at which element found: "<<idx<<endl;
    }else{
        cout<<"Element not found."<<endl;
    }

    
    
    return 0;
}