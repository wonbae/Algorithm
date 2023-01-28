#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    for(int j = 0; j < t; j++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;

        int n;
        cin>>n;
        
        int cnt = 0;

        for(int i = 0; i < n; i++){
            int cx,cy,r, dis;
            bool a, b;
            cin>>cx>>cy>>r;

            dis = (cx - x1) * (cx - x1) + (cy - y1) * (cy - y1);
            a = dis > (r * r) ? false : true;

            dis = (cx-x2) * (cx-x2) + (cy-y2) * (cy-y2);
            b = dis > (r * r) ? false : true;
            
            if(a!=b){
                cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}