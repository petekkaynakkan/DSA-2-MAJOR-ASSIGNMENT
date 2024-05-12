

/* PETEK KAYNAKKAN 211504030 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isFeasible(vector<int>& A, int n, int m, int mid) {
    int students = 1;
    int pagesRead = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] > mid) {
            return false;
        }
        if (pagesRead + A[i] > mid) {
            students++;
            pagesRead = A[i];
            if (students > m) {
                return false;
            }
        }
        else {
            pagesRead += A[i];
        }
    }

    return true;
}

int findPages(int N, int M, vector<int>& A) {
    if (N < M) {
        return -1;
    }

    int low = *max_element(A.begin(), A.end());
    int high = 0;
    for (int i = 0; i < N; i++) {
        high += A[i];
    }
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isFeasible(A, N, M, mid)) {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    
    int N1 = 4;
    int M1 = 2;
    vector<int> A1 = { 12, 34, 67, 90 };
    cout << "Minimum total number of pages: " << findPages(N1, M1, A1) << endl;

 
    int N2 = 3;
    int M2 = 2;
    vector<int> A2 = { 15, 17, 20 };
    cout << "Minimum total number of pages: " << findPages(N2, M2, A2) << endl;

    return 0;
}
