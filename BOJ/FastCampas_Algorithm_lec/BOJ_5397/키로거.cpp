#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	string pwd;
	cin >> tc;
	while (tc--) {
		cin >> pwd;
		stack<char> lst;
		stack<char> rst;

		int len = pwd.length();
		for (int i = 0; i < len; i++) {
			if (pwd[i] == '-') {
				if (!lst.empty()) {
					lst.pop();
				}
			}
			else if (pwd[i] == '<') {
				if (!lst.empty()) {
					char tmp = lst.top();
					lst.pop();
					rst.push(tmp);
				}
			}
			else if (pwd[i] == '>') {
				if (!rst.empty()) {
					char tmp = rst.top();
					rst.pop();
					lst.push(tmp);
				}
			}
			else {
				lst.push(pwd[i]);
			}
		}
		string str = "";
		string str2 = "";
		while (!lst.empty()) {
			char a = lst.top();
			str += a;
			lst.pop();
		}
		while (!rst.empty()) {
			char a = rst.top();
			str2 += a;
			rst.pop();
		}
		reverse(str.begin(), str.end());
		cout << str + str2 << "\n";
	}
	return 0;
}