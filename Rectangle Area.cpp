#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Rectangle {
protected:
    int width;
    int height;
    
public:
    void display() {
        cout << width << " " << height << endl;
    }
};

class RectangleArea : public Rectangle {
public:
    void read_input() {
        cin >> width >> height;
    }
    
    void display() {
        int area = width * height;
        cout << area << endl;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    RectangleArea rect_area;
    rect_area.read_input();
    rect_area.Rectangle::display();  // Call base class display method
    rect_area.display();              // Call derived class display method
    
    return 0;
}
