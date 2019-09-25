#include <iostream>

using namespace std;


int main1() {
	
	int n;
	int length;
	int* a;
	int min = -1;
	int index;
	while (cin >> n) {
		length = n * 2;
		a = new int[length];
		for (int i = 0; i < length; i++) {
			if (i < length / 2) {
				a[i] = 1;
			}
			else {
				a[i] = 2;
			}
		}
		index = 0;
		for (int i = 2;min==-1; i++) {
			while (a[length - 1] != 1) {
				index =(index + i - 1) % length;;
				if (a[index] != 2) {
					break;
				}
				else {
					a[length-1] = 3;
					length--;
					if (index == length) {
						index = 0;
					}
				}
			}
			if (a[length - 1] == 1) { 
				min = i;
			}
			index = 0;
			length = n * 2;
			for (int i = 0; i < length; i++) {
				if (i < length / 2) {
					a[i] = 1;
				}
				else {
					a[i] = 2;
				}
			}
		}
		cout << min << endl;
		min = -1;
		delete a;
	}
	return 0;
}
