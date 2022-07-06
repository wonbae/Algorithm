#include<bits/stdc++.h>
using namespace std;

int tominute(string t){
    int res=0;
    res += (t[0]-'0') * 600;
    res += (t[1]-'0') * 60;
    res += (t[3]-'0') * 10;
    res += (t[4]-'0');
    return res;
}

string output(int a){
    string h = "00" + to_string(a/60);
    string m = "00" + to_string(a%60);
    return h.substr(h.size()-2,2) + ":" + m.substr(m.size()-2, 2);
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(NULL);
    int t;
    cin>>t;
    int team, a=0, b=0, minute, winer=0, pre=0;
    string time;
    while(t--){
        cin>>team>>time;

        minute = tominute(time);

        if(winer > 0) a += minute - pre;
        if(winer < 0) b += minute - pre;

        winer += team==1?1:-1;
        pre = minute;
    }
    if(winer > 0) a += 2880 - minute;
    if(winer < 0) b += 2880 - minute;

    cout<<output(a)<<"\n";
    cout<<output(b)<<"\n";


    return 0;
}