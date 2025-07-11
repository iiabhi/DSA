#include <iostream>
using namespace std;

string check_sequence_termination(int n) {
    if(n>0 && ((n&(n-1)) == 0)){
        return "YES";
    }else{
        return "NO";
    }
}

int main() {
    int n;
    cin >> n;
    
    // Call user logic function and print the output
    string result = check_sequence_termination(n);
    cout << result << endl;
    
    return 0;
}