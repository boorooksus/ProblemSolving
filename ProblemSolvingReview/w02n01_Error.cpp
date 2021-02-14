#include <iostream>
using namespace std;

int T, m, n, len;
string codeword[26];
string word;
int hamming[26];

void errCorr(int start) {
	char letter;
	int min_hamming = 128;
	fill_n(hamming, 26, 0);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (word[start + j] != codeword[i][j]) {
				hamming[i]++;
			}
		}
		
		if (hamming[i] < min_hamming) {
			min_hamming = hamming[i];
			letter = i + 65;
		}
	}

	cout << letter;

}

int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> m >> n;
		for (int i = 0; i < m; i++) {
			cin >> codeword[i];
		}
		cin >> len >> word;

		for (int i = 0; i < len; i += n) {
			errCorr(i);
		}
		cout << "\n";
	}
}