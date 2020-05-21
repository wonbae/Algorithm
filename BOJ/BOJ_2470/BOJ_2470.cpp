#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000001
bool compare(int a, int b){
    return abs(a) < abs(b);
}
int main(){
    // // 1. just sort using abs()
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL), cout.tie(NULL);
    // int N, a[100001], lt = 0, rt, mini = 2147000000, ans1 = 0, ans2 = 0;
    // cin>>N;
    // for(int i = 0; i < N; i++){
    //     cin>>a[i];
    // }

    // sort(a, a+N, compare);

    // for(int i = 0; i < N - 1; i++){
    //     if(abs(a[i] + a[i + 1]) < mini){
    //         mini = abs(a[i] + a[i + 1]);
    //         ans1 = a[i];
    //         ans2 = a[i + 1];
    //     }
    // }
    // if(ans1 < ans2){
    //     cout<<ans1<<" "<<ans2<<"\n";
    // }else{
    //     cout<<ans2<<" "<<ans1<<"\n";
    // }
    // return 0;


    //2. using two pointer
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
	int arr[MAXN] = {0};
	int ans[2], min = 2147000000, N;
    
    cin >> N;

	for (int i = 1; i <= N; i++){
		cin >> arr[i];
	}

	sort(arr + 1, arr + N + 1);

	int L = 1, R = N;

	while (L < R)	{
		int diff = arr[L] + arr[R];
		if (min > abs(diff)){
			min = abs(diff);
			ans[0] = L; ans[1] = R;
		}
		if (diff > 0) R--;
		else if (diff < 0)	L++;
		else break;
	}


	cout << arr[ans[0]] << " " << arr[ans[1]];
}