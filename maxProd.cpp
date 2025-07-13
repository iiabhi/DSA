#include <iostream>
using namespace std;

int prod(vector<int> vec){
    int n= vec.size();
    vector<vector<int>> res;
    for(int i=0; i<n; i++){
        vector<int> sub;
        for(int j=i; j<n; j++){
            sub.push_back(vec[j]);
            res.push_back(sub);
            
        }   
    }
    int maxx = INT_MIN;
    for(auto x: res){
        int prod = 1;
        for(auto val: x){
            prod *= val;
        }
        maxx = max(prod, maxx);
    }
    return maxx;
}

int prodKadane(vector<int> vec){
    int maxx = INT_MIN;
    int n= vec.size();
    vector<vector<int>> res;
    for(int i=0; i<n; i++){
        int prod = 1;
        for(int j=i; j<n; j++){
            prod *= vec[j];
            maxx = max(prod, maxx);
        }   
    }
    
    
    return maxx;
}

int main()
{
    vector<int> vec = {-1,2,2,3,-2,4,-2,1};
    int result = prodKadane(vec);

    cout<<result;
    // for(auto x: result){
    //     for(auto val: x){
    //         cout<<val;
    //     }
    //     cout<<" ";
    // }
    // cout<<result<<endl;
    return 0;
}