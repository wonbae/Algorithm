#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int N,M,num;
    cin>>N>>M;
    vector<vector<int> > partialSum(N+1, vector<int>(N+1,0));

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin>>num;
            partialSum[i][j] = num + partialSum[i][j-1] + partialSum[i-1][j] - partialSum[i-1][j-1];
        }
    }

    int x1,y1,x2,y2;

    while(M--){
        cin>>x1>>y1>>x2>>y2;
        cout<<(partialSum[x2][y2] - partialSum[x1-1][y2] - partialSum[x2][y1-1] + partialSum[x1-1][y1-1])<<"\n";
    }
    return 0;
}