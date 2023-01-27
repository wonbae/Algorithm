#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define INF 2147483648
typedef std::pair<int, int> pii;

using namespace std;

int n, num, cnt;
vector<pii> tmp;
vector<int> v;
stack<int> st;

int main(){
    fastio;
    cin>>n;
    v.resize(n,0);

    for(int i = 0; i < n; i++){
        cin>>num;
        
        auto it = lower_bound(v.begin(), v.begin()+cnt, num);
        int idx = (int)(lower_bound(v.begin(), v.begin()+cnt, num) - v.begin());
        if(*it == 0){
            cnt++;
        }
        *it = num;
    
        tmp.push_back({idx, num});
    }

    cout<<cnt<<"\n";

    for(int i = tmp.size()-1; i >= 0; i--){
        if(tmp[i].first == cnt-1){
            st.push(tmp[i].second);
            cnt--;
        }
    }
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}


// #include <cstdio>
// #include <algorithm>
// #include <stack> 
// using namespace std; 
// int n, lis[1000004], len, num;
// pair<int, int> ans[1000004];
// stack<int> stk; 
// int main() {
// 	scanf("%d", &n);
// 	for (int i = 0; i < n; i++){
//         scanf("%d", &num);
//         auto lowerPos = lower_bound(lis, lis + len, num);
//         int _pos = (int)(lower_bound(lis, lis + len, num) - lis);
//         if(*lowerPos == 0) len++;
//         *lowerPos = num;  
//         ans[i].first = _pos;
//         ans[i].second = num; 
//         printf("%d , %d\n",_pos, num);
//     }
// 	printf("%d\n", len);
//     for(int i = 0; i < n; i++)printf("%d %d\n", ans[i].first, ans[i].second);
//     for(int i = n - 1; i >= 0; i--){
//         if(ans[i].first == len - 1){
//             stk.push(ans[i].second); len--;
//         }
//     }
//     while(stk.size()){
//         printf("%d ", stk.top());stk.pop();
//     } 
// 	return 0;
// }
