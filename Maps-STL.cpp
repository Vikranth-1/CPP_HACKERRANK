#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    cin >> q;
    
    map<string, int> marks;
    
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        
        if (type == 1) {
            string name;
            int score;
            cin >> name >> score;
            marks[name] += score;
        }
        else if (type == 2) {
            string name;
            cin >> name;
            marks.erase(name);
        }
        else if (type == 3) {
            string name;
            cin >> name;
            
            // count() returns 1 if key exists, 0 otherwise
            if (marks.count(name)) {
                cout << marks[name] << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
    
    return 0;
}
