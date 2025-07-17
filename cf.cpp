// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T;
//     cin >> T;
//     while(T--){
//         int n;
//         long long cur;
//         cin>>n>>cur;
//         vector<array<long long,3>> a(n);
//         for(int i = 0; i < n; i++){
//             cin>>a[i][0]>>a[i][1]>>a[i][2];
//         }
//         sort(a.begin(), a.end());
//         priority_queue<pair<long long,long long>> pq;
//         int idx = 0;
//         while(idx < n && a[idx][0] <= cur){
//             if(a[idx][1] >= cur){
//                 pq.emplace(a[idx][2], a[idx][1]);
//             } 
//             idx++;
//         }
//         while(!pq.empty()){
//             auto p = pq.top(); 
//             pq.pop();
//             long long x = p.first;
//             if(x <= cur){
//                 break;
//             } 
//             cur = x;
//             while(idx < n && a[idx][0] <= cur){
//                 if(a[idx][1] >= cur){
//                     pq.emplace(a[idx][2], a[idx][1]);
//                 } 
//                 idx++;
//             }
//         }
//         cout<<cur<<endl;
//     }
//     return 0;
// }
