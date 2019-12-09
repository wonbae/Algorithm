// #include<iostream>
// #include<vector>

// using namespace std;
// //C++11 version

// int main(){

//     int x, y;
//     vector<vector<int> > res(3, vector<int> (2,0));
//     vector<int> ans = {0,0};

//     for(int i = 0; i < 3; i++){
//         cin>>x>>y;

//         res[i][0] = x;
//         res[i][1] = y;
        
//     }
    

//     for(int i = 0; i < 3; i++){
//         ans[0] ^= res[i][0];
//         ans[1] ^= res[i][1];
//     }

//     return 0;
// }

#include<cstdio>
int x,y,n,m;
int main() {
	while(~scanf("%d %d", &x, &y))n^=x,m^=y;
	printf("%d %d", n, m);
	return 0;
}