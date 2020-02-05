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

    
        answer = 0;

        cin>>N;

        NQueen(0);
        
        cout<<answer<<"\n";
    

    return 0;
}



// int n, col[16], dig1[30], dig2[30], ans;
// void go(int row) {
// 	if (row == n) {
// 		ans++;
// 		return;
// 	}

// 	for (int i = 0; i < n; i++) {
// 		if (col[i] + dig1[row + i] + dig2[n - 1 - (i - row)] == 0) {
// 			col[i] = dig1[row + i] = dig2[n - 1 - (i - row)] = 1;
// 			go(row + 1);
// 			col[i] = dig1[row + i] = dig2[n - 1 - (i - row)] = 0;
// 		}
// 	}
// }
// int main() {
// 	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// 	cin >> n;
// 	go(0);
// 	cout << ans;
// }