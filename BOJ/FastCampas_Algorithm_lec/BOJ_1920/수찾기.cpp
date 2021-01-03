#include<iostream>
#include<set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, a, b;
	set<int> s;
	cin >> n;
	while (n--) {
		cin >> a;
		s.insert(a);
	}
	cin >> m;
	while (m--) {
		cin >> b;
		if (s.find(b) != s.end()) {
			cout << "1" << "\n";
		}
		else cout << "0" << "\n";
	}
	return 0;
}