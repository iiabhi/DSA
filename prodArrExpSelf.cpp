#include <iostream>
using namespace std;

//Product of array except self.
//approach 1, multiple all elements and then at ith position divide with ith value.
vector<int> prodArr(vector<int> nums){
    int prod = 1;
    int n=nums.size();
    vector<int> res(n,1);
    for(int val:nums){
        prod *= val;
    }
    for(int i=0; i<n; i++){
        res[i] = prod/nums[i];
    }
    return res;
}

//But, RULE: can't use div operator
//Brute Force: TC: O(n^2)
vector<int> prodArrBrute(vector<int> nums){
    
    int n=nums.size();
    vector<int> res(n,1);
    for(int i=0; i<n; i++){
        int prod = 1;
        for(int j=0; j<n; j++){
            if(i!=j){
                prod *= nums[j];
            }
        }
        res[i] = prod;

    }
    return res;
}

//Optimal Approach 
//find pre-product and post- product and then multiply it
vector<int> prodArrOpt(vector<int> nums){
    int n=nums.size();
    vector<int> preProd(n,1);
    for(int i =1; i<n; i++){
        preProd[i] = preProd[i-1]*nums[i-1];
    }
    vector<int> postProd(n,1);
    for(int i =n-2; i>=0; i--){
        postProd[i] = postProd[i+1]*nums[i+1];
    }
    vector<int> res(n,1);
    for(int i =0; i<n; i++){
        res[i] = preProd[i]*postProd[i];
    }
    return res;
}
//But it takes two extra array space, we need SC: o(1)
vector<int> prodArrOptimal(vector<int> nums){
    int n=nums.size();
    vector<int> res(n,1);
    for(int i =1; i<n; i++){
        res[i] = res[i-1]*nums[i-1];
    }
    int suffix = 1;
    for(int i =n-2; i>=0; i--){
        suffix *= nums[i+1];
        res[i] = suffix*res[i];
    }
    return res;
}
//SC: O(1)

int main()
{
    vector<int> vec = {1,2,3,4};
    vector<int> ans = prodArr(vec);
    for(int val: ans ){
        cout<<val<<" ";
    }
    cout<<endl;

    vector<int> answer = prodArrBrute(vec);
    for(int val: answer ){
        cout<<val<<" ";
    }
    cout<<endl;

    vector<int> result = prodArrOpt(vec);
    for(int val: result ){
        cout<<val<<" ";
    }
    cout<<endl;

    vector<int> finalresult = prodArrOptimal(vec);
    for(int val: finalresult ){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}