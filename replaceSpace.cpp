#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        int last = s.length() - 1;
        for (int i = 0; i < s.length();i++) {
            if (s[i] == ' ')count++;
        }
        s.resize(s.length() + 2 * count);
        int right = s.length() - 1;
        while (last >= 0) {
            if (s[last] == ' ') {
                s[right--] = '0';
                s[right--] = '2';
                s[right--] = '%';
                last--;
                continue;
            }
            s[right--] = s[last--];
        }
        return s;
    }
};

int main() {
    Solution S1;
    cout << S1.replaceSpace("We are happy.");
    return 0;
}