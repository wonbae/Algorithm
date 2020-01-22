#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string str;
    int num[10] = {0,};
    int cnt = 0;

    cin>>str;

    int len = str.length();

    for(int i = 0; i < len; i++){
        if(str[i]- 48 == 6){    // 6일 때 뭐 9일때 뭐 이렇게 하기보단, 한곳에 몰아준다음 나누기 2 하는게 좋을듯 싶다
            num[9]++;
        }else{
            num[str[i] - 48]++;
        }
    }

    num[9] = (num[9] + 1) / 2;  // +1 해주는 이유는.. 음.. 99999 일때 3개가 되야되는데 2개가 되길래 증감 해줘서 나누기..

    int res = 0;
    for(int i = 0; i < 10; i++){
        res = max(res, num[i]);
    }

    cnt = res;

    cout<<cnt<<"\n";


    return 0;
}