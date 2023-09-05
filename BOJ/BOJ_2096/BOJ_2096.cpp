#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin>>n;

    vector<int> minNum(n), maxNum(n);

    int a, b, c;
    cin>>a>>b>>c;

    maxNum[0] = minNum[0] = a;
    maxNum[1] = minNum[1] = b;
    maxNum[2] = minNum[2] = c;

    int maxTmp0, maxTmp1;
    int minTmp0, minTmp1;

    for(int i = 1; i < n; i++){
        cin>>a>>b>>c;

        maxTmp0 = maxNum[0];
        maxTmp1 = maxNum[1];

        maxNum[0] = a + max(maxNum[0], maxNum[1]);
        maxNum[1] = b + max(maxTmp0, max(maxNum[1], maxNum[2]));
        maxNum[2] = c + max(maxTmp1, maxNum[2]);

        minTmp0 = minNum[0];
        minTmp1 = minNum[1];

        minNum[0] = a + min(minNum[0], minNum[1]);
        minNum[1] = b + min(minTmp0, min(minNum[1], minNum[2]));
        minNum[2] = c + min(minTmp1, minNum[2]); 
    }
  
    cout<<max(maxNum[0], max(maxNum[1], maxNum[2]))<<" ";
    cout<<min(minNum[0], min(minNum[1], minNum[2]))<<"\n";

    return 0;
}