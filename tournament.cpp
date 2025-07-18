// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

string solve(vector<int> vec, int n, int j, int k){
    int num = vec[--j];
    int maxx = INT_MIN;
    for(int val:vec){
        maxx = max(maxx, val);
    }
    if(maxx==num){
        return "YES";
    }else{
        if(k==1){
            return "NO";
        }else{
            return "YES";
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    int n;
    while(t--){
        int n,j,k;
        cin>>n>>j>>k;

        vector<int> vec(n);
        for(int i=0; i<n; i++){
            cin>>vec[i];
        }
        cout<<solve(vec, n , j , k)<<endl;

    }
    

    return 0;
}
