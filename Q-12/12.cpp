
/* PETEK KAYNAKKAN 211504030 */

#include <iostream>
#include <vector>

using namespace std;

int numberSequence(int m, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    
    for (int j = 0; j <= m; j++) {
        dp[0][j] = 1;
    }

   
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i][j - 1];
            if (j >= 2 * dp[i - 1][j - 1]) {
                dp[i][j] += dp[i - 1][j - 1];
            }
        }
    }

    
    return dp[n][m];
}

int main() {
   
    int m1 = 10, n1 = 4;
    cout << "Number of possible special sequences: " << numberSequence(m1, n1) << endl;

    int m2 = 5, n2 = 2;
    cout << "Number of possible special sequences: " << numberSequence(m2, n2) << endl;

    return 0;
}
