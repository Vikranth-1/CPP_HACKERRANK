#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int intVal;
    long longVal;
    char charVal;
    float floatVal;
    double doubleVal;
    
    // Read input values
    scanf("%d %ld %c %f %lf", &intVal, &longVal, &charVal, &floatVal, &doubleVal);
    
    // Print each value on a new line
    printf("%d\n", intVal);
    printf("%ld\n", longVal);
    printf("%c\n", charVal);
    printf("%.3f\n", floatVal);
    printf("%.9lf\n", doubleVal);
    
    return 0;
}
