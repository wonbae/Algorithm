#include<iostream>
#include<vector>
using namespace std;

int button[10];

int abs(int a){
    if(a < 0) return (-1)*a;
    return a;
}

bool check(int ch){
    if(ch == 0){
        if(button[ch]) return false;
        return true;
    }

    while(ch){
        if(button[ch%10]) return false;
        ch/=10;
    }
    return true;
}

int getDigit(int ch){
    int cnt = 0;
    if(ch == 0) return 1;
    while(ch){
        ch/=10;
        cnt++;
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int n, m, ans = 2147000000;
    cin>>n>>m;

    for(int i = 0; i < m; i++){
        int a;
        cin>>a;
        button[a] = 1;
    }

    for(int i = 0; i < 1000000; i++){
        int channel = i;
        if(check(channel)){
            int digit = getDigit(channel);

            ans = min(ans, digit + abs(n - channel));
        }
    }
    ans = min(ans, abs(n-100));
    cout<<ans<<"\n";
    return 0;
}