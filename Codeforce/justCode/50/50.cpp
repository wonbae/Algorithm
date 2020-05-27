#include<iostream>
#include<vector>
using namespace std;

int mmax(int a, int b){
    return a > b ? a : b;
}
int main(){
    freopen("input.txt", "r", stdin);
    int H, W, h, w, sum = 0, res = 0;
    cin>>H>>W;
    vector<vector<int> > farm(H, vector<int>(W, 0));

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin>>farm[i][j];
        }
    }
    cin>>h>>w;

    for(int i = 0; i < H - h; i++){
        for(int j = 0; j < W - w; j++){
            sum = 0;
            for(int r = i; r < h + i; r++){
                for(int c = j; c < w + j; c++){
                    sum += farm[r][c];
                }
            }
            res = mmax(sum, res);
        }
    }

    cout<<res<<"\n";

    return 0;
}