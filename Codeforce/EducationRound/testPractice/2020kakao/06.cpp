#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;

#define INF 1234567890
#define ll long long

int N, W, D;
vector<int> v;

int solution(int n, vector<int> weak, vector<int> dist) {
    N=n; W=weak.size(); D=dist.size();
    for(int i=0; i<W; i++)
        weak.push_back(weak[i]+N);
    sort(dist.begin(), dist.end());
    
    int res = INF;
    v = dist;
    do
    {
        for(int i=0; i<W; i++)
        {
            int last = -INF, cnt = -1, success = 1;
            for(int j=i; j<i+W; j++)
            {
                if (last == -INF || weak[j]-last > v[cnt])
                {
                    last = weak[j];
                    cnt++;
                    if (cnt == v.size())
                    {
                        success = 0;
                        break;
                    }
                }
            }
            if (success) res = min(res, cnt + 1);
        }
    }
    while(next_permutation(v.begin(), v.end()));

    if (res == INF) return -1;
    return res;
}
// [출처] 2020 카카오 블라인드 채용 KAKAO BLIND RECRUITMENT 후기|작성자 AM