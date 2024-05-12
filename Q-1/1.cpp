
/* PETEK KAYNAKKAN 211504030 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting {
    int start;
    int end;
    int index;
};

bool sortByEnd(const Meeting& a, const Meeting& b) {
    return a.end < b.end;
}

int maxMeetings(int start[], int end[], int n) {
    vector<Meeting> meetings(n);
    for (int i = 0; i < n; ++i) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
        meetings[i].index = i;
    }

    sort(meetings.begin(), meetings.end(), sortByEnd);

    int count = 1;
    int prevEnd = meetings[0].end;
    for (int i = 1; i < n; ++i) {
        if (meetings[i].start > prevEnd) {
            count++;
            prevEnd = meetings[i].end;
        }
    }
    return count;
}

int main() {
    int start[] = { 1, 3, 0, 5, 8, 5 };
    int end[] = { 2, 4, 6, 7, 9, 9 };
    int n = sizeof(start) / sizeof(start[0]);
    cout << "Maximum number of meetings: " << maxMeetings(start, end, n) << endl;
    return 0;
}
