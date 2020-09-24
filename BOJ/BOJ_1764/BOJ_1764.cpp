#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string a[500001], b[500001], c[500001];
    int N, M, idx = 0, aidx = 0, bidx = 0;
    cin>>N>>M;
    
    for(int i = 0; i < N; i++){
        cin>>a[i];
    }
    for(int i = 0; i < M; i++){
        cin>>b[i];
    }

    sort(a, a + N);
    sort(b, b + M);

    


    return 0;
}