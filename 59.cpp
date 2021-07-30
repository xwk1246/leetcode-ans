#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    int offset = 0;
    int num = 1;
    vector<vector<int>> output(n, vector<int>(n, 0));
    while (offset / 2 < n) {
        for (int i = 0; i < n - 2 * offset - 1; i++) {
            output[offset][offset + i] = num++;
        }
        for (int i = 0; i < n - 2 * offset - 1; i++) {
            output[offset + i][n - 1 - offset] = num++;
        }
        for (int i = 0; i < n - 2 * offset - 1; i++) {
            output[n - 1 - offset][n - 1 - offset - i] = num++;
        }
        for (int i = 0; i < n - 2 * offset - 1; i++) {
            output[n - 1 - offset - i][offset] = num++;
        }
        offset++;
    }
    if (n % 2 == 1)output[n / 2][n / 2] = num;
    return output;
}

int main() {
    generateMatrix(5);
    return 0;
}