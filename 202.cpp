#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isHappy(int n) {
    unordered_set<int>record;
    int tmp = n;
    int sum = 0;
    while (sum != 1) {
        sum = 0;
        while (tmp) {
            sum += (tmp % 10) * (tmp % 10);
            tmp /= 10;
        }
        tmp = sum;
        if (record.find(sum) != record.end())return false;
        record.insert(sum);
    }
    return true;
}

int main() {
    cout << isHappy(2);
    return 0;
}