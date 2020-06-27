#include <iostream>
#include <string>
using namespace std;

string a;
int b;

int multi() {
	int res = 0;
	for (int i = 0; a[i] != '\0'; i++) {
		res = (res * 10 + int(a[i]) - 48) % b;
	}

	if (res == 0) return 1;
	else return 0;
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> a >> b;
		cout << multi() << "\n";
	}
}