
/* PETEK KAYNAKKAN 211504030 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int first;
    int second;
};

bool sortBySecond(const Pair& a, const Pair& b) {
    return a.second < b.second;
}

int maxChainLen(struct Pair arr[], int n) {
    sort(arr, arr + n, sortBySecond);

    int maxLength = 1;
    int prevEnd = arr[0].second;

    for (int i = 1; i < n; ++i) {
        if (arr[i].first > prevEnd) {
            maxLength++;
            prevEnd = arr[i].second;
        }
    }

    return maxLength;
}

int main() {
    Pair pairs[] = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    int n = sizeof(pairs) / sizeof(pairs[0]);
    cout << "Length of the longest chain: " << maxChainLen(pairs, n) << endl;
    return 0;
}
