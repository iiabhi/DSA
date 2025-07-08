#include <iostream>
using namespace std;

void insertionSort(vector<int> &vec){
    int n = vec.size();
    for(int i = 1; i<n; i++){
        int curr = vec[i];
        int prev = i-1;
        while(prev>=0 && vec[prev]>curr){
            vec[prev+1] = vec[prev];
            prev--;
        }
        vec[prev+1]=curr;
    }
}
//TC: O(N^2)

void printArray(vector<int> vec){
    for(int val:vec) cout<<val<<" ";
    cout<<endl;
}
int main()
{
    vector<int> arr = {9,7,8,1,2,3};
    printArray(arr);
    insertionSort(arr);
    printArray(arr);
    return 0;
}