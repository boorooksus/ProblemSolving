#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

int cal(string postfix) {
	stack<int> s;
	for (int i = 0; postfix[i] != '\0'; i++) {
		if (postfix[i] > 47) s.push(postfix[i] - 48);
		else {
			int b = s.top();
			s.pop();
			int a = s.top();
			s.pop();
			int temp = 0;
			if (postfix[i] == '+') temp = a + b;
			else temp = a * b;
			s.push(temp);
		}
	}
	return s.top();
}

string in2Post(string infix, int n) {
	string postfix = "";
	stack<char> s;
	for (int i = 0; infix[i] != ' '; i++) {
		if (infix[i] > 47) postfix += infix[i];
		else if (s.empty()) {
			s.push(infix[i]);
		}
		else if (!s.empty() && infix[i] < s.top()){
			s.push(infix[i]);
		}
		else if (!s.empty() && infix[i] >= s.top()) {
			postfix += s.top();
			s.pop();
			s.push(infix[i]);
		}
	}
	while (!s.empty()) {
		postfix += s.top();
		s.pop();
	}
	return postfix;
}

bool isPossible(string infix, int res, int n) {
	int op_set = pow(2, n - 1);
	while (op_set--) {
		int mask = 1;
		for (int i = 0; i < n - 1; i++) {
			if (op_set & mask) {
				infix[2 * i + 1] = '*';
			}
			else {
				infix[2 * i + 1] = '+';
			}
			mask = mask << 1;
		}
		string postfix = in2Post(infix, n);
		if (cal(postfix) == res) return true;
	}
	return false;
}

int main() {
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int m, n;
		cin >> m >> n;
		for (int j = 0; j < m; j++) {
			string infix = "";
			int res = 0;
			for (int k = 0; k < n; k++) {
				char temp;
				cin >> temp;
				infix += temp;
				infix += " ";
			}
			cin >> res;
			cout << isPossible(infix, res, n) << " ";
		}
		cout << "\n";
	}
}