#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int n, m, num, ans = 0;
    cin>>n>>m;
    vector<int> vec(n);
    vector<int> rest;

    for(int i = 0; i < n; i++){
        cin>>vec[i];
    }
    
    sort(vec.begin(), vec.end());

    for(int i = 0; i < n; i++){
        num = vec[i];

        if(num == 10){
            ans++;
        }else if(num % 10 == 0){    //20 40 70
            int tmp = (m - ((num/10)-1));
            if(tmp >= 0){
                ans += (num/10);
                m -= ((num/10)-1);
            }else{
                if(m == ((num/10)-1)){
                    ans += m+1;
                    m -= m;
                }else{
                    ans += m;
                    m -= m;
                }
            }
        }else if(num > 10){     // 34 57 39
            rest.push_back(num);
        }
    }

    for(int i = 0; i < rest.size(); i++){
        num = rest[i];
        int tmp = (m - (num/10));
        if(tmp >= 0){
            ans += (num/10);
            m -= (num/10);
        }else{
            ans += m;
            m -= m;
        }
    }
    cout<<ans<<"\n";
    return 0;
}