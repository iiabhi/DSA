#include <iostream>
using namespace std;

int countHillValley(vector<int>& nums) {
        int hill = 0, valley =0;

         
        int n = nums.size();
        if(n<=2){
            return 0;
        }else{
            int i = 1;
            int j = 1;
            while(i>=1 && i<n-1 && j>=1 && j<n-1){
                while(j<n-1 && nums[j]==nums[j+1]){
                    j++;   
                }
                if(j==n-1){
                        break;
                    }
                
                if(nums[i-1]< nums[i] && nums[j+1] < nums[j]){
                    hill++;
                }else if(nums[i-1]> nums[i] && nums[j+1] > nums[j]){
                    valley++;
                    cout<<"vall here"<<endl;
                }

                j++;
                i=j;
            }
        }
        return hill+valley;
    }

int main()
{
    vector<int> vec = {3,2,3,3};
    cout<<countHillValley(vec)<<endl;
    return 0;
}