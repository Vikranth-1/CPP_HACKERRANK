#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    
    vector<int> arr(n);
    
    // Read the sorted array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int q;
    cin >> q;
    
    // Process each query using manual binary search
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        
        // Binary search to find lower bound
        int left = 0, right = n - 1;
        int pos = n; // Initialize to n (end of array)
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= x) {
                pos = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        // Check if found
        if (pos < n && arr[pos] == x) {
            cout << "Yes " << pos + 1 << endl;
        } else {
            cout << "No " << pos + 1 << endl;
        }
    }
    
    return 0;
}
