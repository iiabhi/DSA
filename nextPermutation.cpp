#include <iostream>
#include <vector>
using namespace std;
vector<int> nextPer(vector<int> &vec){
    int n= vec.size();
    int pivot = -1;
    //finding the pivot
    for(int i=n-2; i>=0; i--){
        if(vec[i]<vec[i+1]){
            pivot = i;
            break;
        } 
    }
    //edge case
    if(pivot == -1){ 
        int i=0;
        int j = n-1;
        while(i<=j){
            swap(vec[i], vec[j]);
            i++;
            j--;
        }
        return vec;
    }

    //swap pivot with RME greater than pivot
    for(int i = n-1; i>pivot; i--){
        if(vec[i]>vec[pivot]){
            swap(vec[i],vec[pivot]);
            break;
        }
    }
    //revrse the array from pivot+1 to n-1
    int low = pivot+1;
    int high = n-1;
    while(low<= high){
        swap(vec[low], vec[high]);
        low++;
        high--;
    }
    return vec;

}
int main()
{
    vector<int> vec = {1,4,5,3,2};
    vector<int> res = nextPer(vec);
    for(int val:res){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}