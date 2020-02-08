#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000    //1e+7 10^7

bool isPrime[MAX+1];

// vector<long long> primes;

void eratos(){
    memset(isPrime, true, sizeof(isPrime));

    isPrime[0] = false;
    isPrime[1] = false;

    for(long long i = 2; i*i <= MAX; i++){
        if(isPrime[i]==true){
            for(long long j = (i*i); j <= MAX; j += i){
                isPrime[j] = false;
            }
            // primes.push_back(i);
        }
    }

    // sort(primes.begin(), primes.end());

}

void solution(){
    long long start, end;
    int N = 2;
    int answer = 0;

    cin>>start>>end;

    long long tmp = 0;
    for(long long i = 2; i <= MAX; i++){
        if(i*i > end){
            break;
        }
        
        if(isPrime[i]){
            N = 2;
            tmp = pow(i,N);
            while(tmp <= end){
                
                if(tmp >= start && tmp <= end){
                    answer++;
                }
                
                N++;
                tmp = pow(i,N);
                
                if(tmp % i != 0) break;
                

            }
        }
    }

    // long long tmp = 0;
    // for(int i = 0; i < primes.size(); i++){
    //     if(primes[i] * primes[i] > end) break;

    //     N = 2;

    //     while(tmp <= end){
    //         long long tmp = pow(primes.at(i),N);
    //         if(tmp >= start && tmp <= end){
    //             cout<<" ( "<<primes.at(i)<<", ^ "<<N<<" = "<<tmp<<" ), ";
    //             answer++;
    //         }else{
    //             break;
    //         }
    //         N++;
    //     }
        
    // }


    cout<<answer<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    eratos();

    solution();
    
    return 0;
}