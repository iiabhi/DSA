#include <iostream>
#include <vector>

using namespace std;
bool isValid(vector<int> arr, int n, int m,int x){
    int student = 1;
    int pages =0;
    for(int val: arr){
        if(val>x) return false;
        if(pages+val <= x) pages += val; 
        else{
            student++;
            pages = val;
        } 
    }
    return student>m? false:true;

}

int allocateBooks(vector<int> &arr, int n, int m){
    int ans = -1;
    int sum =0;
    for(int val: arr){
        sum += val;
    }
    int st = 0;
    int end = sum;
    while(st<=end){
        int mid = st + (end-st)/2;
        if(isValid(arr,n,m,mid)){ //left
            end = mid-1;
            ans = mid;
        }else{ //right
            st = mid+1;
        }
    }
    return ans;
}
int main()
{
    vector<int> vec = {2,1,5,3,4};
    int n = 4, m=3;
    int minPages = allocateBooks(vec,n,m);
    cout<<minPages<<endl;
    return 0;

}