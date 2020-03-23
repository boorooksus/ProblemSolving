#include <iostream>
using namespace std;

struct nucleotide {
	char cha;
	int cnt;
	bool repre;
};

void hamming();

int main() {
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		hamming();
	}

	return 0;
}

void hamming() {
	int m, n; //m : 종의 수 n : 유전자 길이
	cin >> m >> n;
	string* dna = new string[m];
	for (int i = 0; i < m; i++) {
		cin >> dna[i];
	}

	int sum = 0;
	//nucleotide * repre = new nucleotide[n];
	string repre_str;

	for (int i = 0; i < n; i++) {
		//각각의 염기 정보 담긴 구조체 생성
		nucleotide a = { 'A', 0, false };
		nucleotide t = { 'T', 0, false };
		nucleotide g = { 'G', 0, false };
		nucleotide c = { 'C', 0, false };
		char cha = '0';
		/*int a = 0;
		int c = 0;
		int g = 0;
		int t = 0;*/

		for (int j = 0; j < m; j++) {
			if (dna[j][i] == 'A') a.cnt++;
			else if (dna[j][i] == 'T') t.cnt++;
			else if (dna[j][i] == 'G') g.cnt++;
			else c.cnt++;
		}
		nucleotide repre = a;
		if (c.cnt > repre.cnt) {
			repre = c;
		}
		if (g.cnt > repre.cnt) {
			repre = g;
		}
		if (t.cnt > repre.cnt) {
			repre = t;
		}
		repre_str += repre.cha;
		sum += m - repre.cnt;
	}
	
	//대표 서열 출력
	/*for (int i = 0; i < n; i++) {
		cout << repre[i].cha;
	}*/

	cout << repre_str << "\n" << sum << "\n";

	return;
}