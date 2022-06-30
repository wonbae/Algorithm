#include <bits/stdc++.h>
using namespace std; 
int n, m, j, l, r, num, ret;

int main () {
    ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin>>n>>m>>j;
	l = 1;  

	for(int i = 0; i < j; i++){
		r = l + m - 1; 
		cin >> num;
		if(num >= l && num <= r) continue;
		else{ 
			if(num < l){  
				ret += (l - num);
				l = num; 
			}else{
                ret += (num - r); 
				l += (num - r);
			}
		} 
	} 
	cout << ret << "\n"; 
	return 0;
}