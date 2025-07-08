#include <iostream>
using namespace std;

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}
void selectionSort(vector<int> &vec){
    int n = vec.size();
    for(int i=0; i<n-1; i++){
        int smallestidx = i; //assume smallest el at i
        for(int j=i+1; j<n; j++){
            if(vec[j]<vec[smallestidx]){
                smallestidx = j;
            }
        }
        swap(vec[i],vec[smallestidx]);
    }

}
//TC: O(n^2)

void printArray(vector<int> vec){
    for(int val:vec) cout<<val<<" ";
    cout<<endl;
}

int main()
{
    vector<int> arr = {9,7,8,1,2,3};
    printArray(arr);
    selectionSort(arr);
    printArray(arr);
    return 0;
}