#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool Palindrome(string word) {
	stack<char> s;
	string convert;
	for (int i = 0; i < word.size(); i++) {
		if (word[i] > 64 && word[i] < 91) {
			convert += word[i];
			s.push(word[i]);
		}
		else if (word[i] > 96 && word[i] < 123) {
			convert += word[i] - 32;
			s.push(word[i] - 32);
		}
	}
	for (int i = 0; i < s.size(); i++) {
		if (s.top() != convert[i]) {
			return false;
		}
		else {
			s.pop();
		}
	}
	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string word;
		cin >> word;
		if (Palindrome(word)) cout << "Yes\n";
		else cout << "No\n";
	}
}