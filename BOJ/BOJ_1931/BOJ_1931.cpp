#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.second < b.second) return true;
    else if(a.second > b.second) return false;
    if(a.first < b.first) return true;
    else return false;
}

int main(){
    int N, endtime = -2147000000, cnt = 0;
    cin>>N;
    vector<pair<int, int> > v;

    for(int i = 0; i < N; i++){
        int s, e;
        cin>>s>>e;
        v.push_back(make_pair(s,e));
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < v.size(); i++){
        if(v[i].first >= endtime){
            endtime = v[i].second;
            cnt++;
        }
    }

    cout<<cnt<<"\n";

    return 0;
}