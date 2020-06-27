#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n, a, b, x;
int num[9];

int cal(int x, int y) {
	int res = 1;
	for (int i = 0; i < y; i++) {
		res *= x;
	}

	return res;
}

int runner() {
	// === 1 =================================
	sort(num, num + n);
	int cnt = 0;
	do {
		int res = 0;

		for (int i = 0; i < n; i++) {
			res += ((int(pow(x, i)) % 1013) * num[i]) % 1013;
		}
		// ==== 2 ================================
		res %= 1013;

		if (res >= a && res <= b) cnt++;

	} while (next_permutation(num, num + n));

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}
		cin >> a >> b >> x;

		cout << runner() << "\n";

		fill_n(num, 9, 0);
	}

}

// 1: permutation 쓰기 전에 정렬 하기
// 2: 마지막에 mod 1013 꼭 하기