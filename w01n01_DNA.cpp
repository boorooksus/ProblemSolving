#include <iostream>
using namespace std;

int m, n;
string dna[50];

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> m >> n;
		for (int i = 0; i < m; i++) {
			cin >> dna[i];
		}

		int hamming = 0;
		string repre = "";
		for (int i = 0; i < n; i++) {
			int base[26];
			char repre_base = 0;
			int max_cnt = 0;
			fill_n(base, 26, 0);
			for (int j = 0; j < m; j++) {
				base[dna[j][i] - 65]++;
				if (base[dna[j][i] - 65] > max_cnt) {
					max_cnt = base[dna[j][i] - 65];
					repre_base = dna[j][i];
				}
				else if (base[dna[j][i] - 65] == max_cnt && dna[j][i] < repre_base) {
					max_cnt = base[dna[j][i] - 65];
					repre_base = dna[j][i];
				}
			}
			repre += repre_base;
			for (int j = 0; j < 26; j++) {
				hamming += base[j];
			}
			hamming -= max_cnt;
		}

		cout << repre << "\n" << hamming << "\n";
	}
}