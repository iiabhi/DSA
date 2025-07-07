#include <iostream>
using namespace std;
bool isValid(vector<int> nums, int n,int m, int x){
    int painter = 1;
    int board = 0;
    for(int val:nums){
        if(board+ val <= x) board += val;
        else{
            painter++;
            board = val;
        }
    }
    return painter>m? false:true;
}
int painterPartition(vector<int> nums, int n,int m){
    int ans = -1;
    int st =INT_MIN;
    int sum = 0;
    for(int val:nums){
        sum+=val;
        st = max(val,st);
    } 
    int end = sum;
    while(st<=end){
        int mid = st + (end-st)/2;
        if(isValid(nums, n, m, mid)){
            end = mid-1;
            ans = mid;
        } 
        else st = mid+1;
    }
    return ans;
}
int main()
{
    vector<int> vec = {40,30,10,20};
    int n=4, m= 2;
    int minTime = painterPartition(vec,n,m);
    cout<<minTime<<endl;
    return 0;
}