#include <iostream>
#include <string>

using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int n,id,max,cid;
	string con[500];
	int nums[500];
	string z[500];
	int seq[500];
	while (cin >> n) {
		id = 1;
		for (int i = 0; i < n; i++) {
			cin >> id;
			cin >> con[id] >> nums[id] >> z[id];
			seq[i] = i+1;
			if (con[id][0] == 'C') {
				cid = id;
			}
		}
		for (int i = 0; i < n; i++) {
			max = i;
			for (int k = i+1; k < n; k++) {
				if (con[seq[k]][0]<con[seq[i]][0]) {
					swap(seq[k], seq[i]);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (seq[i] == cid)continue;
			cout << seq[i] << " " << con[seq[i]] << " " << nums[seq[i]] << " " << z[seq[i]] << endl;
		}
		cout << cid << " " << con[cid] << " " << nums[cid] << " " << z[cid] << endl;
	}
	return 0;
}