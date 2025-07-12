#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 1;
        int end = n-1;
        if(nums[0]==target || nums[0]>target) return 0;
        if(nums[n-1]==target) return n-1;
        if(nums[n-1]<target) return n;
        while(st<=end){
            int mid = st + (end - st)/2;
            if(nums[mid] == target || nums[mid]>target && nums[mid-1]<target) return mid; 
            else if(nums[mid]>target){
                end = mid-1;
            }else if (nums[mid]<target){
                st = mid+1;
            }
        }
        return -1;

    }
int main()
{
    vector<int> vec = {1,3};
    int target = 3;
    int res = searchInsert(vec, target);
    cout<<res<<endl;
    return 0;
}