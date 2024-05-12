
/* PETEK KAYNAKKAN 211504030 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool sortByDeadline(const Job& a, const Job& b) {
    return a.deadline < b.deadline;
}

vector<int> JobScheduling(Job arr[], int n) {
    sort(arr, arr + n, sortByDeadline);

    
    int maxDeadline = 0;
    for (int i = 0; i < n; ++i) {
        maxDeadline = max(maxDeadline, arr[i].deadline);
    }

    
    vector<int> dp(maxDeadline + 1, 0);

    for (int i = 0; i < n; ++i) {
        
        for (int j = arr[i].deadline; j > 0; --j) {
            if (dp[j] == 0) {
                dp[j] = arr[i].profit;
                break;
            }
        }
    }

    
    int countJobs = 0, maxProfit = 0;
    for (int i = 1; i <= maxDeadline; ++i) {
        if (dp[i] != 0) {
            countJobs++;
            maxProfit += dp[i];
        }
    }

    return { countJobs, maxProfit };
}

int main() {
    Job jobs[] = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };
    int n = sizeof(jobs) / sizeof(jobs[0]);
    vector<int> result = JobScheduling(jobs, n);
    cout << "Number of jobs done: " << result[0] << endl;
    cout << "Maximum profit: " << result[1] << endl;
    return 0;
}
