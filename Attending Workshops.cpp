#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Workshop {
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops {
    int n;
    Workshop* workshops;
};

Available_Workshops* initialize(int start_time[], int duration[], int n) {
    Available_Workshops* available = new Available_Workshops;
    available->n = n;
    available->workshops = new Workshop[n];
    
    for (int i = 0; i < n; i++) {
        available->workshops[i].start_time = start_time[i];
        available->workshops[i].duration = duration[i];
        available->workshops[i].end_time = start_time[i] + duration[i];
    }
    
    return available;
}

bool compareWorkshops(const Workshop& a, const Workshop& b) {
    return a.end_time < b.end_time;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
    sort(ptr->workshops, ptr->workshops + ptr->n, compareWorkshops);
    
    int count = 1;
    int last_end = ptr->workshops[0].end_time;
    
    for (int i = 1; i < ptr->n; i++) {
        if (ptr->workshops[i].start_time >= last_end) {
            count++;
            last_end = ptr->workshops[i].end_time;
        }
    }
    
    return count;
}

int main() {   
    int n;
    cin >> n;
    
    int* start_time = new int[n];
    int* duration = new int[n];
    
    for (int i = 0; i < n; i++) {
        cin >> start_time[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> duration[i];
    }
    
    Available_Workshops* ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    
    delete[] start_time;
    delete[] duration;
    delete[] ptr->workshops;
    delete ptr;
    
    return 0;
}
