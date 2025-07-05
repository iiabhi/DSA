#include <iostream>
using namespace std;

int single(vector<int> nums){
    int st =0;
    int end = nums.size()-1;
    if(nums.size() == 1) return nums[0]; //if size is 1 .
    while(st<=end){
        int mid = st + (end-st)/2;
        if(mid == 0 && nums[0]!=nums[1]) return nums[0];    //for edge and corner cases (to remove overflow)
        if(mid == end && nums[end]!=nums[end-1]) return nums[end];
        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
        if(mid%2==0){
            if(nums[mid-1]==nums[mid]) end = mid-1;
            else st = mid+1;
        }else{
            if(nums[mid-1]==nums[mid]) st = mid+1;
            else end = mid-1;
        }
    }
    return -1;
}
int main()
{
    vector<int> vec = {2,2,3,3,4,4,5};
    cout<<"SIngle element: "<<single(vec)<<endl;
    return 0;
}