#include <iostream>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map; //store index of recent element.

        for(int i=0; i<n; i++){
            if((map.find(nums[i])!=map.end()) && ((i-map[nums[i]])<=k)){
                cout<<i-map[nums[i]]<<" "<<map[nums[i]]<<endl;
                cout<<"here"<<endl;
                return true;
            }
            if(map.find(nums[i]) == map.end()){
                map[nums[i]] = i;
            }
           
        }
       

        return false;
    }
int main()
{
    vector<int> nums = {1,2,3,1,2,3};
    int k = 2;
    cout<<containsNearbyDuplicate(nums, k)<<endl;
    return 0;
}