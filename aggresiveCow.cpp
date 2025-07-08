#include <iostream>
using namespace std;

//O(N)
bool isPossible(vector<int> nums, int N, int C, int x){
    int cow = 1;
    int lastStall = nums[0];
    for(int i = 1; i<N; i++){
        if((nums[i]-lastStall)>=x){
            cow++;
            lastStall = nums[i];
        }
        if(cow == C) return true;
    }
    return false;
}

int getDistance(vector<int> &vec, int N, int C){
    sort(vec.begin(), vec.end()); //NlogN

    int maxVal = vec[N-1];
    int minVal = vec[0];
    
    int st = 1;
    int result = -1;
    int end = maxVal - minVal;
    while(st<=end){  //O(log(Range) * N)
        int mid = st + (end - st)/2;
        if(isPossible(vec,N,C,mid)){
            st = mid+1;
            result = mid;
        }else{
            end = mid-1;
        }
    }
    return result;
}

int main()
{
    vector<int> vec = {1,2,4,8,9};
    int n=5, c=3;
    int res = getDistance(vec,n,c);
    cout<<res<<endl;
    return 0;
}