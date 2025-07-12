#include <iostream>
#include<unordered_map>
#include<string>
using namespace std;

int romanToInt(string s) {
        
        unordered_map<string, int> myMap = {
            {"I", 1},
            {"V", 5},
            {"X", 10},
            {"L", 50},
            {"C", 100},
            {"D", 500},
            {"M", 1000}
        };
        int n = s.size();
        int sum =0;
        int i=n-2;
        int j= n-1;

        while(i>=0 || j>=0){
            sum += myMap[string(1, s[j])];
            if(i>=0){
                if((s[j] == 'V' && s[i] == 'I') || (s[j] == 'X' && s[i] == 'I')){
                sum -= 1;
                j -= 2;
                i -= 2;
                continue;
            }else if((s[j] == 'L' && s[i] == 'X') || (s[j] == 'C' && s[i] == 'X')){
                sum -= 10;
                j -= 2;
                i -= 2;
                continue;
            }else if((s[j] == 'D' && s[i] == 'C') || (s[j] == 'M' && s[i] == 'C')){
                sum -= 100;
                j -= 2;
                i -= 2;
                continue;
            }
            }
            

            i--;
            j--;

        }
        return sum;
    }
int main()
{
    string s = "LVIII";
    int res = romanToInt(s);
    cout<<res<<endl;
    return 0;
}