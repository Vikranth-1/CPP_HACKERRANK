#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

        // Format A: Hexadecimal representation of truncated A
        cout << hex << showbase << nouppercase << left;
        cout << (long long int)A << endl;
        
        // Format B: Sign, 2 decimal places, width 15, padded with underscores
        cout << dec << right << setw(15) << setfill('_') << showpos << fixed << setprecision(2);
        cout << B << endl;
        
        // Format C: Scientific notation with 9 decimal places, uppercase
        cout << scientific << uppercase << noshowpos << setprecision(9);
        cout << C << endl;
    
	}
	return 0;

}
