#include<bits/stdc++.h>
using namespace std;

vector<int> primes;
string p = "";

void eratos(int max){
    vector<bool> isPrime(max + 1, true);
    
    for(int i = 2; i < max; i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j = i*2; j < max; j += i){
                if(isPrime[j]){
                    isPrime[j] = false;
                }
            }
        }
    }

    // cout<<"Eratos : ";
    // for(int i = 0; i < primes.size(); i++){
    //     cout<<primes[i]<<" ";
    // }cout<<endl;

}

bool DevidePrime(int single_prime){
    int tmp = 0;
    bool flag = false;
    int len = p.length();

    for(int i = 0; i < len; i++){
        tmp = (tmp * 10 + (p[i] - '0')) % single_prime;
    }

    if(tmp == 0){
        flag = true;
    }else{
        flag = false;
    }

    return flag;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int k;
    int res = 0;

    cin>>p>>k;

    eratos(k);

    for(int i = 0; i < primes.size(); i++){
        // cout<<primes[i]<<" "<<"\n";
        if(DevidePrime(primes[i])){
            res = primes[i];
            cout<<"BAD"<<" "<<res<<"\n";
            return 0;
        }    
    }   

    cout<<"GOOD"<<"\n";
    

    return 0;
}