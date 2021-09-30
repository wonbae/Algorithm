#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int n,m;
    cin>>n;
    vector<int> crain(n);
    for(int i = 0; i < n; i++)
        cin>>crain[i];
    cin>>m;
    vector<int> boxes(m);
    for(int i = 0; i < m; i++)
        cin>>boxes[i];

    sort(crain.begin(), crain.end(), cmp);
    sort(boxes.begin(), boxes.end(), cmp);

    if(crain[0] < boxes[0]){
        cout<<-1;
        return 0;
    }
    
    vector<int> pos(n,0);
    vector<bool> check(m,false);
    int cnt = 0, ans = 0;

    while(1){
        if(cnt == boxes.size())
            break;
        for(int i = 0; i < n; i++){
            while(pos[i] < boxes.size()){
                if(!check[pos[i]] && crain[i] >= boxes[pos[i]]){
                    check[pos[i]] = true;
                    pos[i]++;
                    cnt++;
                    break;
                }
                pos[i]++;
            }
        }
        ans++;
    }

    cout<<ans;

    return 0;
}