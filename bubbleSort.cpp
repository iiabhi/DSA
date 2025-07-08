#include <iostream>
#include <vector>
using namespace std;

void swap(int &x, int &y){ //pass by refrence (as alias)
    int temp = x;
    x = y;
    y = temp;
}
void bubbleSorrt(vector<int> &vec){
    int n = vec.size();
    for(int i=0; i<n-1; i++){
        bool isSwap = false;
        for(int j=0; j<n-i-1; j++){
            if(vec[j]>vec[j+1]){
                swap(vec[j],vec[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap) return; //array is already is sorted
    }
}


//Time complexity: O(N^2)

void printArray(vector<int> vec){
    for(int val:vec) cout<<val<<" ";
    cout<<endl;
}
int main()
{
    vector<int> vec = {1,2,4,3,5};
    printArray(vec);
    swap(vec[2], vec[3]);
    printArray(vec);

    vector<int> arr = {9,7,8,1,2,3};
    printArray(arr);
    bubbleSorrt(arr);
    printArray(arr);
    return 0;
}