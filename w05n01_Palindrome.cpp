#include <iostream>
#include <string>
using namespace std;

string word;

string palindrome() {
	int sp = 0;
	int ep = word.length() - 1;

	while (sp < ep) {
		if (word[sp] >= 'a' && word[sp] <= 'z') {
			word[sp] -= 'a' - 65;
		}
		else if (word[sp] < 'A' || word[sp] > 'Z') {
			sp++;
			continue;
		}

		if (word[ep] >= 'a' && word[ep] <= 'z') {
			word[ep] -= 'a' - 65;
		}
		else if (word[ep] < 'A' || word[ep] > 'Z') {
			ep--;
			continue;
		}

		if (word[sp] != word[ep]) {
			return "No";
		}

		sp++;
		ep--;
	}

	return "Yes";
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> word;
		cout << palindrome() << "\n";
	}
}