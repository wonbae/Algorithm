#include<bits/stdc++.h>
using namespace std;

int main() {

    int n1, n2, idx=0, p=0, s1, s2, ans[10001];
    char c1[10001], c2[10001];
	scanf("%s%s", c1, c2);
	s1 = strlen(c1); s2 = strlen(c2);

	while (s1||s2||p) {
		if (s1)	n1 = c1[(s1--) - 1]-'0';
		if (s2)	n2 = c2[(s2--) - 1]-'0'; 
		ans[idx++] = (n1 + n2 + p) % 10;
		p = n1 + n2 + p > 9 ? 1 : 0;
		n1 = n2 = 0;
	}
	for (int i = idx-1; i >= 0; i--)printf("%d", ans[i]);
	return 0;
}