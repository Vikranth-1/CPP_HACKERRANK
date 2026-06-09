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
    
    // Read n integers into the vector
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    // First query: erase element at a specific position
    int position;
    cin >> position;
    // Note: Input uses 1-based indexing, but vector uses 0-based indexing
    v.erase(v.begin() + (position - 1));
    
    // Second query: erase a range of elements [a, b)
    int a, b;
    cin >> a >> b;
    // Note: Input uses 1-based indexing, so convert to 0-based
    // Erase from index (a-1) to index (b-1) (b is exclusive in the second argument)
    v.erase(v.begin() + (a - 1), v.begin() + (b - 1));
    
    // Print the size of the vector
    cout << v.size() << endl;
    
    // Print all elements in the vector
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    
    return 0;
}
