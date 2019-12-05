#include <bits/stdc++.h>
using namespace std;
#define limit 10000

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T,num;
    cin>>T;

    vector<bool> isPrime(limit + 1, true);
    vector<int> prime_num;
    vector<pair<int, int> > prime_set;

    for(int i = 2; i*i <= limit; i++){
        if(isPrime[i]){
            for(int j = 2 * i; j <= limit; j+=i){
                isPrime[j] = false;     //prime 아닌것들 false로 맨듬
            }
        }
    }

    for(int i = 2; i < limit; i++){
        if(isPrime[i]){
            prime_num.push_back(i);
        }
        
    }

    while(T > 0){
        // cout<<"\n+++++++++++++++++++++++++\n";
        cin>>num;
        int tmp = 0;

        for(int i = 0; i < prime_num.size(); i++){
            
            if(prime_num[i] < num){
                int p = num - prime_num[i];
                // cout<<"p : "<<p<<"\n";
                if(isPrime[p]){
                    int tmp = prime_num[i];
                    prime_set.push_back(make_pair(tmp, p));
                    // cout<<num<<" - "<<prime_num[i]<<" = "<<p<<"\n";
                }
            }
        }

        int min = 987654321;
        int res = 0, res2 = 0;

        for(int j = 0; j < prime_set.size(); j++){
            int a = prime_set[j].first;
            int b = prime_set[j].second;

            // cout<<"a : "<<a<<", b : "<<b<<"\n";

            if(abs(a-b) < min){
                min = abs(a-b);
                res = a;
                res2 = b;
            }
        }
        
        cout<<res<<" "<<res2<<"\n";

        prime_set.clear();
        
        T--;
    }



    return 0;
}