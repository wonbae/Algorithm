#include<bits/stdc++.h>
using namespace std;
#define SIZE 1001

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;

    cin>>n;
    cin.ignore(256, '\n');

    for(int i = 0; i < n; i++){
        string res;
        string str;

        getline(cin, str);

        for(int j = 0; j < str.length(); j++){
            if(str[j] == ' '){
                reverse(res.begin(), res.end());
                cout<<res<<" ";
                res.clear();
            }

            else{
                res += str[j];
            }

        }

        reverse(res.begin(), res.end());
        cout<<res<<"\n";
        
    }

}