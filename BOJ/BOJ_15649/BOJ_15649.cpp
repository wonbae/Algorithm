#include <cstdio>
int get[8];
int n, m;

void dfs(int start, int pick) {
	if (pick == m) {
		for (int i = 0; i < m; ++i) printf("%d ", get[i]);
		printf("\n");
		return;
	}
	for (int i = start; i <= n; ++i) {
		get[pick] = i;
		dfs(i + 1, pick + 1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	dfs(1, 0);
}

// #include <bits/stdc++.h>    //이문제 솔직히 이해못함..
// using namespace std;

// int n,m;
// bool visit[9];
// vector<int> v;

// void DFS(int idx, int cnt){
//     if(cnt == m){
//         for(int i = 0; i < v.size(); i++){
//             cout<<v.at(i)<<" ";
//         }
//         cout<<"\n";
//         return;
//     }

//     for(int i = idx; i < n; i++){
//         if(!visit[i]){
//             if(visit[i] == true) continue;
//             visit[i] = true;
//             v.push_back(i + 1);
//             DFS(i, cnt + 1);
//             v.pop_back();
//             visit[i] = false;
//         }
//     }

// }

// int main(){
//     ios_base::sync_with_stdio(false); 
//     cin.tie(NULL); cout.tie(NULL);

//     cin>>n>>m;

//     DFS(0, 0);

//     return 0;
// }