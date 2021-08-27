#include<iostream>
using namespace std;



bool check(int *a, int *b){
    int atmp = 0, btmp = 0, cnt = 0;
    
    for(int i = 0; i < 26; i++){
        atmp += a[i];
        btmp += b[i];
        cnt += abs(a[i] - b[i]);
    }

    if(cnt <= 2 && abs(atmp - btmp) <= 1){
        return true;
    }else return false;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int arr[26]={0,};
    int n, ans = 0;
    cin>>n;
    string first;
    cin>>first;

    for(int i = 0; i < first.size(); i++){
        arr[first[i]-'A']++;
    }

    string str;
    for(int i = 1; i < n; i++){
        cin>>str;
        int arr2[26] = {0,};
        for(int j = 0; j < str.size(); j++){
            arr2[str[j] - 'A']++;
        }
        if(check(arr, arr2)){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}