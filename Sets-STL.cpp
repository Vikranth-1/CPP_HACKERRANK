#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    cin >> q;
    
    set<int> s;
    
    for (int i = 0; i < q; i++) {
        int type, x;
        cin >> type >> x;
        
        if (type == 1) {
            // Add element to the set
            s.insert(x);
        }
        else if (type == 2) {
            // Delete element from the set (if present)
            s.erase(x);
        }
        else if (type == 3) {
            // Check if element is present
            set<int>::iterator it = s.find(x);
            if (it != s.end()) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    
    return 0;
}
