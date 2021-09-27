 #include<iostream>
 using namespace std;

 int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, ans = 0;
    int coin[] = {500, 100, 50, 10, 5, 1};
    cin>>n;
    n = 1000-n;

    for(int i = 0; i < 6; i++){
        ans += n/coin[i];
        n = n%coin[i];
    }
    cout<<ans<<"\n";

     return 0;
 }