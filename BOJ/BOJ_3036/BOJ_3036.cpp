#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    int n;

    while(b != 0){
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}


int main(){

    int t,n;
    vector<int> v;

    cin>>t;

    for(int i = 0; i < t; i++){
        cin>>n;
        v.push_back(n);
    }

    int denominator = v.front();

    for(int i = 1; i < v.size(); i++){
        int gcd_num = gcd(denominator,v[i]);
        cout<<denominator/gcd_num<<"/"<<v[i]/gcd_num<<"\n";
    }

    return 0;
}