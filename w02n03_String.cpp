#include <iostream>
#include <string>
#define MAX 100000
using namespace std;

string s, r;
int cnt[58];

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> s >> r;

		for (int i = 0; r[i] != '\0'; i++) {
			cnt[r[i] - 65]--;
		}

		int sp = 0, ep = 0;
		int ans = MAX;
		for (int i = 0; i < s.length(); i++) {
			cnt[s[i] - 65]++;
			
			int isPos = 1;
			for (int j = 0; j < 58; j++) {
				if (cnt[j] < 0) {
					isPos = 0;
					break;
				}
			}
			if (isPos == 1) {
				for (int j = sp; j <= i; j++) {
					int isPos = 1;
					for (int k = 0; k < 58; k++) {
						if (cnt[k] < 0) {
							isPos = 0;
							break;
						}
					}
					if (isPos == 1) {
						if (i - sp + 1 < ans) {
							ans = i - sp + 1;
						}
						cnt[s[sp] - 65]--;
						sp++;
					}
					else {
						break;
					}
				}
			}
		}

		if (ans == MAX) {
			ans = 0;
		}
		cout << ans << "\n";

		fill_n(cnt, 58, 0);
	}
}