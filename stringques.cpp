#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

//ek character se differ wala code likho!.substring ka
int sub(string s, string t){
    int result = 0;
    int n = s.length();
    int m = t.length();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int diff = 0;
            for(int k=0; i+k<n && j+k < m; k++){
                if(s[i+k] != s[j+k]){
                    diff++;
                }
                if (diff > 1) break;
                if (diff == 1) result++;
            }
            
        }
    }
    
    return result;
}

int main() {
    // Input handling
    string s, t;
    cin >> s >> t;

    // Call the user logic function and print the output
    int result = sub(s, t);
    cout << result << endl;
   
    return 0;
}