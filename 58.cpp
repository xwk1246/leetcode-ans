#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) {
    stringstream ss;
    ss << s;
    string last;
    string tmp;
    while (ss >> tmp) {
        last = tmp;
    }
    return last.length();
}
int main() {
    string in;
    cin >> in;
    cout << lengthOfLastWord(in);
}