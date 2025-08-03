#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> res(nums1.size(), 0);
        if(nums2.size() == 0 || nums1.size() == 0) return res;
        if(nums2.size() == 1 && nums1.size() == 1){
            res[0] = -1;
            return res;
        }

        int n = nums2.size();
        stack<int> stk;
        unordered_map<int, int> great(n);
        stk.push(nums2[n-1]);
        great[nums2[n-1]] = -1;

        for(int i=n-2; i>=0; i--){
            while(stk.top() <= nums2[i]){
                stk.pop();
            }
            if(stk.empty()){
                great[nums2[i]] = -1;
            }else{
                great[nums2[i]] = stk.top();
            }
            stk.push(nums2[i]);
            
        }

        

        for(int i=0; i<nums1.size(); i++){
            res[i] = great[nums1[i]];
        }
        return res;
    }
int main()
{
    unordered_map<int, int> map = {
        {1,2},
        {2,8}
    };
    auto it = map.find(1);

    vector<int> vec = {4,1,2};
    vector<int> vec2 = {1,3,4,2};

    vector<int> res = nextGreaterElement(vec, vec2);
    for(auto x: res){
        cout<<x<<endl;
    }
 

    return 0;
}