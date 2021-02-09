#include <iostream>
#include <string>
using namespace std;

string seq[50];
string ans;
int diff;
int m, n;

int main() {
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		ans = "";
		diff = 0;
		cin >> m >> n;

		for (int i = 0; i < m; i++) {
			cin >> seq[i];
		}

		for (int cur = 0; cur < n; cur++) {
			int cnt[26] = { 0, };

			for (int i = 0; i < m; i++) {
				cnt[seq[i][cur] - 65]++;
			}

			int temp = 0;
			char dna;
			for (int i = 0; i < 26; i++) {
				if (cnt[i] > temp) {
					dna = i + 65;
					temp = cnt[i];
				}
				diff += cnt[i];
			}

			seq[cur] += dna;
			diff -= temp;
		}
		cout << ans << "\n" << diff << "\n";
	}
}