#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Student {
private:
    int scores[5];
    
public:
    void input() {
        for (int i = 0; i < 5; i++) {
            cin >> scores[i];
        }
    }
    
    int calculateTotalScore() {
        int total = 0;
        for (int i = 0; i < 5; i++) {
            total += scores[i];
        }
        return total;
    }
};

int main() {
    int n;
    cin >> n;
    
    Student* students = new Student[n];
    
    for (int i = 0; i < n; i++) {
        students[i].input();
    }
    
    int kristen_score = students[0].calculateTotalScore();
    int count = 0;
    
    for (int i = 1; i < n; i++) {
        if (students[i].calculateTotalScore() > kristen_score) {
            count++;
        }
    }
    
    cout << count << endl;
    
    delete[] students;
    
    return 0;
}
