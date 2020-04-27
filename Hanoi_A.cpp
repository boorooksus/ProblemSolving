#include <iostream>
using namespace std;

int hanoi(int[], int);

int main() {
	std::ios::sync_with_stdio(false);
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0;
		cin >> n;
		int* stick = new int[n + 1];
		stick[0] == -1;
		for (int i = 1; i <= n; i++) {
			cin >> stick[i];
		}
		cout << hanoi(stick, n) << "\n";
	}
}

int hanoi(int stick[], int n) {
	int cur = n + 1;
	int cnt = 0;
	while (cur != 1) {
		for (int i = 1; i <= n; i++) {
			if (stick[i] == cur - 1) {
				cur--;
			}
		}
		cnt++;
	}

	return cnt;
}