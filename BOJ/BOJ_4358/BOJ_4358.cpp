#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string, int> mp;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    string str;
    int cnt = 0;

    while(!cin.eof()){
        getline(cin, str);
        if(str == "") break;
        mp[str]++;
        cnt++;
    }
    cout<<fixed;
    cout.precision(4);
    map<string, int>::iterator iter;
    for(iter = mp.begin(); iter != mp.end(); iter++){
        cout<<(*iter).first <<" " << ((double)(*iter).second / cnt) * 100 << "\n";
    }

    return 0;
}