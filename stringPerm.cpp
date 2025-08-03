#include <iostream>
using namespace std;
void getPer(string &s, int idx, vector<string> &res){
    //base case
    if(idx == s.length()){
        res.push_back(s);
        return;
    }

    for(int i = idx; i<s.length(); i++){
        swap(s[i], s[idx]);
        getPer(s, idx+1, res);

        swap(s[i], s[idx]); //backtrack
    }
}

int main()
{
    string s = "abc";
    int idx =0;
    vector<string> res;
    getPer(s,idx,res);
    for(auto x: res){
        cout<<x<<endl;
    }
    


    return 0;
}