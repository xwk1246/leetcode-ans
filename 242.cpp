#include <iostream>

using namespace std;

bool isAnagram(string s, string t) {
    int record[26] = { 0 };
    for (auto i : s) {
        record[i - 'a'] ++;
    }
    for (auto i : t) {
        record[i - 'a'] --;
    }
    for (auto i : record) {
        if (i != 0)return false;
    }
    return true;
}

int main() {

}