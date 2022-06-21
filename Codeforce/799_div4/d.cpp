// #include<iostream>
// #include<vector>
// #include<deque>
// #include<math.h>

// using namespace std;

// int main(){
//     int t;
//     cin>>t;

//     while(t--){
//         string time, tmp, origin;
//         int minutes, hour=0, ans = 0;
//         cin>>time>>minutes;
//         if(minutes >= 60){
//             hour = minutes/60;
//             // cout<<"hour:"<<hour<<"\n";
//         }
//         origin=time;
//         time.erase(time.begin()+2);
//         // cout<<time<<"\n";

//         int a, b;
//         for(int i = 0; i < 2; i++){
//             if(i == 0){
//                 a = time[i]-'0';
//                 a*=10;
//             }else{
//                 a += time[i]-'0';
//             }
//         }
//         for(int i = 2; i < 4; i++){
//             if(i == 2){
//                 b = time[i]-'0';
//                 b *= 10;
//             }else{
//                 b += time[i]-'0';
//             }
//         }

//         // cout<<a<<","<<b<<"\n";
//         int breakPoint_h = 0;
//         int breakPoint_m = 0;

//         while(origin != tmp){

//             if(hour != 0){
//                 a+=hour;
//                 breakPoint_h+=hour;
//             }else{
//                 b+=minutes;
//                 breakPoint_m+=minutes;
//             }
            
//             if(breakPoint_h > 100 || breakPoint_m > 6000){
//                 break;
//             }
            

//             if(b >= 60){
//                 a+=1;
//                 a%=24;
//                 b%=60;
//             }
            
//             a%=24;
//             b%=60;

//             // cout<<"h:"<<a<<", "<<"m:"<<b<<"\n";

//             string tmpa=to_string(a), tmpb=to_string(b);
//             if(a < 10){
//                 tmpa = "0" + to_string(a);
//             }if(b < 10){
//                 tmpb = "0" + to_string(b);
//             }

//             tmp = tmpa + ":" + tmpb;
//             // cout<<tmp<<"\n";

//             bool flag=true;
//             for(int i = 0; i < tmp.length()/2; i++){
//                 if(tmp[i] != tmp[tmp.length()-i-1]){
//                     flag=false;
//                 }
//             }
//             if(flag){
//                 ans++;
//             }
//             // break;
//         }
//         cout<<ans<<"\n";
//         // cout<<breakPoint_h<<","<<breakPoint_m<<"\n";

//     }

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

int a[5] = {600, 60, 0, 10, 1};
int good[16] = {0, 70, 140, 210, 280, 350, 601, 671, 741, 811, 881, 951, 1202, 1272, 1342, 1412};

void solve() {
	string s;
	cin >> s;
	int x;
	cin >> x;
	int tot = 0;
	for (int i = 0; i < 5; i++) {
		tot += (int)(s[i] - '0') * a[i];
	}

    cout<<tot<<"\n";
    return ;
	set<int> t;
	for (int i = 0; i < 2022; i++) {
		t.insert(tot);
		tot += x;
		tot %= 1440;
	}
	int res = 0;
	// for (int i : t) {
	// 	for (int j = 0; j < 16; j++) {
	// 		if (good[j] == i) {res++;}
	// 	}
	// }
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}