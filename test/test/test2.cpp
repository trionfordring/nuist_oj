#include <iostream>

using namespace std;

int main41() {

	int n,ind,temp,last;
	int gap = 1;
	int len=0;
	bool ok = false;
	int* a;
	while (cin >> n) {
		ind = 0;
		last = n;
		for (temp = n; temp <= n * 2; temp++) {
			len += temp;

		}
		a = new int[len];
		for (int i = 0; i < n; i++) {
			for (temp = 0; temp < n; temp++) {
				a[ind] = 1;
				ind++;
			}
			for (temp = 0; temp < last; temp++) {
				a[ind] = 2;
				ind++;
			}
			last--;
		}
		for (gap = 2;; gap++) {
			ok = true;
			for (ind = 0; ind < len;ind+=gap) {
				if (a[ind] == 1) {
					ok = false;
					break;
				}
			}
			if (ok) {
				cout << gap + 1 << endl;
				return 0;
			}
		}
		delete a;
	}
	return 0;
}
