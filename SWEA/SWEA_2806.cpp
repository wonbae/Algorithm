#include<iostream>
using namespace std;

#define SIZE 10

int board[SIZE];
int N;
int answer = 0;

int NQueen(int pos){
    bool isPossible;

    if(pos == N){
        answer++;
        return 0;
    }

    for(int i = 0; i < N; i++){
        isPossible = true;
        for(int j = 0; j < pos; j++){
            if(i == board[j] || i == board[j] + (pos - j) || i == board[j] - (pos - j)){
                isPossible = false;
                break;
            }
        }
        if(isPossible){
            board[pos] = i;
            NQueen(pos + 1);
        }
    }
    return 0;
}

int main(){
    int T;
    cin>>T;

    for(int tc = 1; tc <= T; tc++){
        answer = 0;

        cin>>N;

        NQueen(0);
        
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }

    return 0;
}