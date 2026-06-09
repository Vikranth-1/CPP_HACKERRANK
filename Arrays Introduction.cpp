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
    
    vector<int> arr(n);  // Declare vector of size n
    
    // Read n integers into the vector
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Print the array in reverse order
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
