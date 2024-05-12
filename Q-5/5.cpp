
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

    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i].first > arr[j].second && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    Pair pairs[] = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    int n = sizeof(pairs) / sizeof(pairs[0]);
    cout << "Length of the longest chain: " << maxChainLen(pairs, n) << endl;
    return 0;
}
