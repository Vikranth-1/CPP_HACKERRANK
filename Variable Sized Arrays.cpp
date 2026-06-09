#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q;
    cin >> n >> q;
    
    // Create an array of pointers to hold the arrays
    int** arr = new int*[n];
    
    // Read each array
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;  // Read the size of the i-th array
        
        // Allocate memory for the i-th array
        arr[i] = new int[k];
        
        // Read k integers into the i-th array
        for (int j = 0; j < k; j++) {
            cin >> arr[i][j];
        }
    }
    
    // Process each query
    for (int query = 0; query < q; query++) {
        int i, j;
        cin >> i >> j;  // i = array index, j = element index in that array
        cout << arr[i][j] << endl;
    }
    
    // Free allocated memory
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    return 0;
}
