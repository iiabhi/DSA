#include <iostream>
using namespace std;
int main()
{   vector<vector<string>> magic = {{"hello","hallo","leetcode"}};
    string searchWord = "leetcodd";
    int len = searchWord.size();cout<<len<<endl;
        // for(auto word: magic){
        //     for(auto it: word){
        //         cout<<"size "<<it.size()<<endl;
        //         if(it.size()!=len) break;
        //         int diff =0;
        //         for(int i=0; i<len; i++){
        //             if(it[i]!=searchWord[i]){
        //                 cout<<"her"<<endl;
        //                 diff++;
        //             }
        //             if(diff>1) break;
        //         }
        //         if(diff==1){
        //             cout<<true<<endl;
        //             break;
        //         } 
                
        //     }
        // }
        // cout<<"end"<<endl;

        // for(int i=0; i<10; i++){
        //     for(int j=0; j<4; j++){
        //         cout<<"in j"<<endl;
        //         if(j==3) break;
        //     }
        //     cout<<"here"<<endl;
        // }
        vector<string> words = {"hello","leetcode"};
        string order = "hlabcdefgijkmnopqrstuvwxyz";
        unordered_map<char, int> myMap;
        int idx = 0;

        int n = words.size();
        for(int i=0; i<order.length(); i++){
            myMap[order[i]] = idx;
            idx++;
        }
        for(auto it:myMap){
            cout<<it.first<<"->"<<it.second<<endl;
        }

        for(int i=0; i<n-1;i++){
            string s1 = words[i];
            string s2 = words[i+1];

            //edge case check: eg: abcd abc
            if(s1.size()>s2.size() && s1.substr(0, s2.size())==s2){
cout<<"hehe"<<endl; return 0;
            } 
            //
            int len = min(s1.size(), s2.size());
            for(int j=0; j<len; j++){
                if(s1[j]!=s2[j]){
                    cout<<s1[j]<<"and"<<s2[j]<<endl;
                    if(myMap[s1[j]] > myMap[s2[j]]){
                        cout<<myMap[s1[j]]<<"and"<<myMap[s2[j]]<<endl;
                        cout<<"here"<<endl;
                        return 0;
                    }else{
                        break;
                    }
                }
            }
        }
        cout<<"end pos"<<endl;
    return 0;
}