#include <bits/stdc++.h>

using namespace std;

int solve(int n, int c, vector<long long> &weight){
    if(weight.size() == 0) return 0;
    if(weight.size() == 1){
        if(weight[0]>c) return 1;
        else return 0;
    }
    sort(weight.begin(), weight.end());

    int coin = 0;
        
    while(weight.size()!=0){
        int idx = -1;
        for(int i=0; i<weight.size(); i++){
            if(weight[i]>c){
                break;
            }
            idx++;
        }
        
        if(idx==-1){
            coin = weight.size();
            break;
        }
        
        weight.erase(weight.begin()+idx);
        
        for(int j=0;j<weight.size(); j++){
            if(weight[j] < c){
                weight[j] *= 2;
            }
        }
    }
    return coin;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int c;
        int n;
        cin>>n>>c;
        vector<long long> weight(n);
        for(int i=0; i<n; i++){
            cin>>weight[i];
        }
        
        int result = solve(n, c, weight);
        cout<<result<<endl;
        
    }
    return 0;
}
