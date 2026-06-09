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
    
    vector<int> v(n);
    
    // Read n integers directly into the vector
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    // Sort the vector
    sort(v.begin(), v.end());
    
    // Print the sorted integers using range-based for loop
    for (int num : v) {
        cout << num << " ";
    }
    
    return 0;
}
