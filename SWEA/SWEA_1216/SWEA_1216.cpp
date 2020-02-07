#include<iostream>
#include<cstring>
using namespace std;
#define MAX 100

int answer = 1;
char Map[MAX][MAX];

void initialize(){
    answer = 1; // 최소가 'A'와 같은 문자 하나니깐 1로 초기화
    memset(Map, 0, sizeof(Map));

}

void input(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            cin>>Map[i][j];
        }
    }
}

void col_check(int i, int j, int pal_len){   //가로
    int end = j + pal_len - 1;
    int start = j;
    bool flag = false;

    while(start < end){
        if(Map[i][start] == Map[i][end]){
            end--;
            start++;
            flag = true;
        }else{
            flag = false;
            break;
        }
    }
    
    if(flag){
        if(answer < pal_len) answer = pal_len;
    }
}

void row_check(int i, int j, int pal_len){  //세로
    int end = i + pal_len - 1;
    int start = i;
    bool flag = false;

    while(start < end){
        if(Map[start][j] == Map[end][j]){
            end--;
            start++;
            flag = true;
        }else{
            flag = false;
            break;
        }
    }
    
    if(flag){
        if(answer < pal_len) answer = pal_len;
    }
}

void solution(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            for(int palindrome_size = 2; palindrome_size < MAX/2; palindrome_size++){
                if((j + palindrome_size) <= MAX){
                    col_check(i,j,palindrome_size);
                }
                if((i + palindrome_size) <= MAX){
                    row_check(i,j,palindrome_size);
                }
            }
        }
    }
}

void solve(){
    int T;
    while(1){
        cin>>T;

        initialize();
        input();
        solution();

        cout<<"#"<<T<<" "<<answer<<"\n";

        if(T == 10) break;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("Input.txt","r",stdin);
    solve();

    return 0;
}