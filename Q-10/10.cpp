
/* PETEK KAYNAKKAN 211504030 */

#include <iostream>
#include <vector>
#include <climits> 

using namespace std;

int kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
    int n = arr1.size();
    int m = arr2.size();

    
    if (n > m) {
        return kthElement(arr2, arr1, k);
    }

    
    int low = max(0, k - m);
    int high = min(k, n);

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = k - cut1;

       
        int leftMax1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int leftMax2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
        int rightMin1 = (cut1 == n) ? INT_MAX : arr1[cut1];
        int rightMin2 = (cut2 == m) ? INT_MAX : arr2[cut2];

      
        if (leftMax1 <= rightMin2 && leftMax2 <= rightMin1) {
            
            return max(leftMax1, leftMax2);
        }
        else if (leftMax1 > rightMin2) {
            
            high = cut1 - 1;
        }
        else {
            
            low = cut1 + 1;
        }
    }

    
    return -1;
}

int main() {
  
    vector<int> arr1 = { 2, 3, 6, 7, 9 };
    vector<int> arr2 = { 1, 4, 8, 10 };
    int k = 5;
    cout << kthElement(arr1, arr2, k) << endl;

    
    vector<int> arr3 = { 100, 112, 256, 349, 770 };
    vector<int> arr4 = { 72, 86, 113, 119, 265, 445, 892 };
    int k2 = 7;
    cout << kthElement(arr3, arr4, k2) << endl;

    return 0;
}
