#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> pii;

bool compare(const string & a, const string & b){
    if(a.length() != b.length()) return a.length() < b.length();
    else
        return a < b;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    string input = "";

    cin>>N;

    // // 1. Priority_Queue 사용시, iterator로 접근이 안되넹    28ms
    // priority_queue<pii, vector<pii>, greater<pii> > pq;
    // vector<string> strv;

    // for(int i = 0; i < N; i++){
    //     cin>>input;
    //     int len = input.length();
    //     pq.push(make_pair(len, input));
    // }
    
    // while(!pq.empty()){
    //     strv.push_back(pq.top().second);
    //     // cout<<pq.top().second<<"\n";
    //     pq.pop();
    // }

    // for(int i = 0; i < strv.size(); i++){
    //     if(i != 0){
    //         if(strv[i] == strv[i - 1]) continue;
    //     }
    //     cout<<strv[i]<<"\n";
        
    // }

    // 2. vector사용 20ms
    vector<string> v;
    string tmp = "";
    for(int i = 0; i < N; i++){
        cin>>tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), compare);

    cout<<v[0]<<"\n";
    for(int i = 1; i < v.size(); i++){
        if(v[i] == v[i - 1]) continue;
        cout<<v[i]<<"\n";
    }

    return 0;
}