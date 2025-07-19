#include <iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main()
{
    string x = "abhsihek";
    for(auto val:x){
        cout<<val<<" ";
    }
    vector<string> res;
    unordered_map<char, string> map = {
        {'2', "abc"},
        {'3', "def"}
    };
    string digits = "23";
    string str = map[digits[0]];
    cout<<str<<endl;
    for(int i=0; i<str.length(); i++){
        res.push_back(str.substr(i,1));
    }

    cout<<res[0]<<res[1]<<res[2]<<endl;
    res.push_back(str);
    cout<<str[0]+str[1];
    return 0;
}