#include <iostream>
using namespace std;

string makeFancyString(string s){
    int n = s.length();
        char prev = s[0];
        string ans = "";
        int count = 0;
        for(int i=0; i<n; i++){
            if(prev == s[i]){
                count++;
                if(count<3){
                    ans += s[i];
                }
            }else{
                ans += s[i];
                prev = s[i];
                count =1;
            }

        }
        return ans;
}

int main()
{
    string s = "aabcccc";

    cout<<makeFancyString(s)<<endl;
    return 0;
}