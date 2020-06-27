#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int m, n, res;
int num[8];

int isPos() {
	for (int mask = 0; mask < pow(2, n - 1); mask++) {
		int cpy[8];
		for (int i = 0; i < 8; i++) {
			cpy[i] = num[i];
		}
		for (int i = 0; i < n - 1 ; i++) {
			int cur = 1 << i;
			if (cur & mask) {
				// ===== 1 ==================================
				cpy[i + 1] *= cpy[i];
				cpy[i] = 0;
			}
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += cpy[i];
		}

		if (sum == res) return 1;
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> m >> n;
		while (m--) {
			for (int i = 0; i < n; i++) {
				cin >> num[i];
			}
			cin >> res;
			cout << isPos() << " ";
		}
		cout << "\n";
		fill_n(num, 8, 0);
	}
}

//num 배열 그대로 갖다 쓰면 틀림,, 복사해야함