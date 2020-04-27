#include <iostream>
using namespace std;

bool multiple(string a, int b) {
	int res = 0;
	for (int i = 0; a[i] != '\0'; i++) {
		res = (10 * res + (a[i] - 48)) % b;
	}
	if (res == 0) return true;
	else return false;
}

int main() {
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string a = "";
		int b = 0;
		cin >> a >> b;
		cout << multiple(a, b) << "\n";
	}
}