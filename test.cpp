#include <iostream>
using namespace std;
int main()
{
    string vec = {"ab", "ba"};
    string x = "ab";

    vector<pair<int, int>> arr = {{1,2}, {3,4}};
    cout<<arr[0].second<<endl;

    int freq[26] = {0};
    string s = "abhi";
    for(int i=0; i<s.length(); i++){
        (freq[((int)s[i]) - 97])++;
    }
    for(int i=0; i<26; i++){
        cout<<freq[i]<<" ";
    }


    return 0;
}