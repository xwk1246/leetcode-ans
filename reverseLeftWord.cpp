#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    Solution S1;
    cout << S1.reverseLeftWords("abcdefg", 2);
}