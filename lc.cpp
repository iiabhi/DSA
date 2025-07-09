#include <iostream>
using namespace std;
vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> neg(nums.size(),0);
        int idxCnt =0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0){
                neg[idxCnt] = nums[i];
                idxCnt++;
            }
        }
        vector<int> pos(nums.size(),0);
        int idxP =0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>=0){
                pos[idxP] = nums[i];
                idxP++;
            }
        }
        int cnt =0;
        for(int i= 1; i<nums.size(); i += 2){
            nums[i] = neg[cnt];
            cnt++;
        }
        int count =0;
        for(int i= 0; i<nums.size(); i += 2){
            nums[i] = pos[count];
            count++;
        }

        return nums;
}

vector<int> rearrangeArray1(vector<int>& nums){
    vector<int> res(nums.size(),INT_MIN);
    int idxPos = 0;
    int idxNeg = 1;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]>=0){
            res[idxPos] = nums[i];
            idxPos += 2;
        }else{
            res[idxNeg] = nums[i];
            idxNeg += 2;
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {3,1,-2,-5,2,-4};
    vector<int> res = rearrangeArray1(arr);
    for(int val:res) cout<<val<<" ";
    return 0;
}