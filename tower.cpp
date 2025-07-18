#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

string solve(vector<int> vec, int n, int k){
    int curr = vec[--k];
    sort(vec.begin(), vec.end());
    int global_max = vec[n-1];

    int currentIdx = 0;
    for(int i=n-1; i>=0; i--){
        if(vec[i] == curr){
            currentIdx = i;
            break;
        }
    }
    int level = 1;
    int check = 0;
    for(int j=currentIdx; j<n-1; j++){

        check = vec[currentIdx]-level + 1;
        if((vec[currentIdx+1] - vec[currentIdx]) > check){
            return "NO";
        }
        level = level + (vec[currentIdx+1] - vec[currentIdx]);
        currentIdx++;
    }
   if(vec[currentIdx] == global_max){
    return "YES";
   }else{
    return "NO";
   }

}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> vec(n);
        for(int i=0; i<n; i++){
            cin>>vec[i];
        }
        cout<<solve(vec, n , k)<<endl;

    }
    return 0;
}