#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;


int maxSum(vector<int>& nums) {
        int n = nums.size();
        int maxx = INT_MIN;
        for(int i=0; i<n; i++){
            maxx = max(maxx, nums[i]);
        }

        if(maxx<=0) return maxx;


        int idx =0;
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                nums[idx] = nums[i];
                idx++;
            }
        }
        //size = idx;
        int sum =0;
        unordered_set<int> set;
        for(int i=0; i<idx; i++){
            if(set.find(nums[i]) != set.end()){
                continue;
            }
            
            set.insert(nums[i]);
            sum+= nums[i];
        }
        return sum;

    }


int main() {
    
    // Sample input
    vector<int> nums = {-6,12,20,20,-14,10,-12};

    // Call function and print result
    cout << "Maximum unique subarray sum: " << maxSum(nums) << endl;
   

    return 0;
}
