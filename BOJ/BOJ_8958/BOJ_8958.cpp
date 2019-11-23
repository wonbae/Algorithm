#include <bits/stdc++.h>
using namespace std;
// OOXXOXXOOO
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin>>n;

    string str[n];
    
    
    int sum = 0;

    for(int i = 0; i < n; i++){
        cin>>str[i];
    }

    for(int i = 0; i < n; i++){

        int add = 1;
        int len = str[i].length();
        int count[80] = {0,};
        int sum = 0;

        for(int j = 0; j < len; j++){
            if(str[i][j] == 'O'){
                count[j] = add;
                add++;
            }
            else if(str[i][j] == 'X'){
                add = 1;
                count[j] = 0;
            }
        }
        for(int k = 0; k < len; k++){
            sum += count[k];
        }
        cout<<sum<<"\n";
    }
    
    
    return 0;
}