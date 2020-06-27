#include <iostream>
using namespace std;

int n;
int disk[10002];

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		int cur = n, cnt = 0;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			if (disk[temp + 1] == 0) {
				disk[temp]++;
				cnt++;
			}
			else {
				disk[temp]++;
			}
		}
		cout << cnt << "\n";

		fill_n(disk, 10002, 0);
	}
}