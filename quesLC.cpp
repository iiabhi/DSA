#include <iostream>
#include <algorithm>
#include<vector>
#include<string>

using namespace std;
bool isAlphaNum(string s){
        if(s.length()==0) return false;
        for(auto ch : s){
            if(!(((tolower(ch)) >='a' && (tolower(ch))<='z') || (ch == '_') || (ch>='0' && ch<='9'))){
                return false;
            }
        }
        return true;
    }

    bool inCategories(string b){
        if(b=="electronics" || b=="grocery" || b=="pharmacy" || b=="restaurant"){
            return true;
        }
        return false;
    }
    bool comparator(pair<string, string> p1, pair<string, string> p2){
        if(p1.first<p2.first) return true;
        if(p1.first>p2.first) return false;
        if(p1.second < p2.second) return true;
        else return false;
    }



    
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string, string>> vec;
        int n = code.size();
        for(int i=0; i<n; i++){
            if(!(isAlphaNum(code[i]))){
                continue;
            }
            if(!(inCategories(businessLine[i]))){
                continue;
            }
            if(!(isActive[i])){
                continue;
            }
            vec.emplace_back(businessLine[i],code[i]);
        }
        sort(vec.begin(), vec.end(), comparator);
        vector<string> result(vec.size());
        for(int i=0; i<vec.size(); i++){
            result[i] = vec[i].second;
        }
        return result;
    }
int main()
{
    vector<string> code = {"SAVE20","","PHARMA5","SAVE@20"};
    vector<string>businessLine = {"restaurant","grocery","pharmacy","restaurant"};
    vector<bool> isActive = {true,true,true,true};

    vector<string> res = validateCoupons(code,businessLine,isActive);
    for(auto x: res){
        cout<<x<<endl;
    }


    return 0;
}