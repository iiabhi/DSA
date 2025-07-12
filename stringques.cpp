#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

//ek character se differ wala code likho!.substring ka

int main() {
    // Input handling
    string s, t;
    cin >> s >> t;

    // Call the user logic function and print the output
    // int result = sub(s, t);
    // cout << result << endl;
    unordered_map<string, int> myMap = {
        {"I", 1},
        {"V", 5},
        {"X", 10},
        {"L", 50},
        {"C", 100},
        {"D", 500},
        {"M", 1000}
    };
    s= "XXVII";
    int sum = 0;
    for(int j=s.size()-1; j>0; j--){
            sum += myMap[string(1, s[j])];
        }

    cout<<sum<<endl;
    return 0;
}