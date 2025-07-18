// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

string solve(int n){
    if(n%4 == 0){
        return "Bob";
    }else{
        return "Alice";
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
        cout<<solve(n)<<endl;

    }
    

    return 0;
}
