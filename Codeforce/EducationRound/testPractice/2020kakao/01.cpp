#include <string>
#include <vector>
using namespace std;

#define INF 1234567890

string s;
int N;

int Len(int n)
{
    int ret = 0;
    while(n)
    {
        ret++;
        n/=10;
    }
    return ret;
}

int solve(int n)
{
    int ret = 0, st = 1;
    for(int i=0; i<N; i+=n)
    {
        if (i+n+n>N || s.substr(i, n) != s.substr(i+n, n))
        {
            ret += min(n, N-i);
            if (st > 1) ret += Len(st);
            st = 1;
        }
        else st++;
    }
    return ret;
}

int solution(string S) {
    s=S;
    N=s.size();
    
    int res = INF;
    for(int i=1; i<=N; i++)
        res = min(res, solve(i));
    return res;
}
// [출처] 2020 카카오 블라인드 채용 KAKAO BLIND RECRUITMENT 후기|작성자 AM