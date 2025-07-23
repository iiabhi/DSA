#include <iostream>
using namespace std;


    int removePair(string &s, char first, char second, int val) {
        string temp;
        int score = 0;

        for (char c : s) {
            if (!temp.empty() && temp.back() == first && c == second) {
                temp.pop_back();
                score += val;
            } else {
                temp.push_back(c);
            }
        }

        s = temp;  // update original string with leftovers
        return score;
    }

    int maximumGain(string s, int x, int y) {
        int total = 0;

        if (x > y) {
            total += removePair(s, 'a', 'b', x);  // remove "ab" first
            total += removePair(s, 'b', 'a', y);  // then "ba"
        } else {
            total += removePair(s, 'b', 'a', y);  // remove "ba" first
            total += removePair(s, 'a', 'b', x);  // then "ab"
        }

        return total;
    }

int main()
{
    string s = "cdbcbbaaabab";
    int x = maximumGain(s, 4, 5);
    cout<<x<<endl;
    return 0;
}