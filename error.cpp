#include <iostream>
using namespace std;

string encording(int, int, string[], int, string);

int main() {
	std::ios::sync_with_stdio(false);
	int t; //t : test cases
	cin >> t;
	for (int i = 0; i < t; i++) {
		//m : number of alphabets
		//n : number of bits in cordword
		int m, n; 
		cin >> m >> n;
		//array that saves cordwords
		string* cordwords = new string[m];
		for (int j = 0; j < m; j++) {
			cin >> cordwords[j];
		}
		int o; // o : length of original cordword
		cin >> o;
		string original;
		cin >> original;
		cout << encording(m, n, cordwords, o, original) << "\n";


	}
}

string encording(int m, int n, string cordwords[], int o, string original) {
	string result = "";
	int* haming = new int[m];
	fill_n(haming, m, 0);
	int cur = 0;
	while (cur != o + 1) {
		if (cur % n == 0 && cur != 0) {
			//cout << haming[0] << haming[1] << "\n\n";
			int idx = 0;
			for (int i = 1; i < m; i++) {
				if (haming[i] < haming[idx]) {
					idx = i;
				}
			}
			result += idx + 65;
			fill_n(haming, m, 0);
		}

		for (int i = 0; i < m; i++) {
			if (original[cur] != cordwords[i][cur % n]) {
				haming[i]++;
			}
		}
		cur++;
	}
	return result;
}


//마지막에 아스키코드 통해서 배열 인덱스를 알파벳으로 변환시키자!