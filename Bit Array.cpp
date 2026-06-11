#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long N, S, P, Q;
    cin >> N >> S >> P >> Q;
    
    const long long MOD = 1LL << 31;
    
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    long long tortoise = S % MOD;
    long long hare = S % MOD;
    long long count = 1;
    
    // Find cycle using Floyd's algorithm
    do {
        if (count >= N) {
            cout << N << endl;
            return 0;
        }
        tortoise = (tortoise * P + Q) % MOD;
        hare = (hare * P + Q) % MOD;
        hare = (hare * P + Q) % MOD;
        count++;
    } while (tortoise != hare);
    
    // Find the first element of the cycle
    tortoise = S % MOD;
    long long mu = 0;
    while (tortoise != hare) {
        if (mu >= N) {
            cout << N << endl;
            return 0;
        }
        tortoise = (tortoise * P + Q) % MOD;
        hare = (hare * P + Q) % MOD;
        mu++;
    }
    
    // Find the length of the cycle
    long long lambda = 1;
    hare = (tortoise * P + Q) % MOD;
    while (tortoise != hare) {
        if (mu + lambda >= N) {
            cout << N << endl;
            return 0;
        }
        hare = (hare * P + Q) % MOD;
        lambda++;
    }
    
    long long result = min(N, mu + lambda);
    cout << result << endl;
    
    return 0;
}
