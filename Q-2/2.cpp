
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

bool sortByProfit(const Job& a, const Job& b) {
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n) {
    sort(arr, arr + n, sortByProfit);

    vector<bool> slot(n, false);
    vector<int> result;

    int countJobs = 0, maxProfit = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; --j) {
            if (!slot[j]) {
                slot[j] = true;
                countJobs++;
                maxProfit += arr[i].profit;
                break;
            }
        }
    }

    result.push_back(countJobs);
    result.push_back(maxProfit);
    return result;
}

int main() {
    Job jobs[] = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };
    int n = sizeof(jobs) / sizeof(jobs[0]);
    vector<int> result = JobScheduling(jobs, n);
    cout << "Number of jobs done: " << result[0] << endl;
    cout << "Maximum profit: " << result[1] << endl;
    return 0;
}
