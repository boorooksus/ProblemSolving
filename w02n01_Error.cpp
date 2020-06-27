#include <iostream>
using namespace std;

int m, n, x_len;
string x;
string cordword[26];


int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> m >> n;
		for (int i = 0; i < m; i++) {
			cin >> cordword[i];
		}
		cin >> x_len >> x;

		string ans = "";
		for (int i = 0; i < x_len; i += n) {
			int cnt[26];
			fill_n(cnt, 26, 0);
			int min_cnt = 128;
			char min_char = 0;

			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					if (cordword[k][j] != x[i + j]) {
						cnt[k]++;
					}
				}
			}

			for (int j = 0; j < m; j++) {
				if (cnt[j] < min_cnt) {
					min_cnt = cnt[j];
					min_char = j + 65;
				}
			}

			ans += min_char;
		}

		cout << ans << "\n";

	}

}