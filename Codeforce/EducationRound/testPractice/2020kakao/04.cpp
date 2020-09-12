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

struct Node {
    int cnt;
    int go[26];
} trie[2][2020202];
int P = 10001;

void Update(int ty, string &s, int p, int n)
{
    trie[ty][n].cnt++;
    if (p == s.size()) return;
    int val = s[p]-'a';
    if (trie[ty][n].go[val] == 0)
        trie[ty][n].go[val] = P++;
    Update(ty, s, p+1, trie[ty][n].go[val]);
}

int Query(int ty, string &s, int p, int n)
{
    if (n == 0) return 0;
    if (s[p] == '?') return trie[ty][n].cnt;
    int val = s[p]-'a';
    return Query(ty, s, p+1, trie[ty][n].go[val]);
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> res;
    
    for(int i=0; i<words.size(); i++) // 접두사 트라이
        Update(0, words[i], 0, (int)words[i].size());
    for(int i=0; i<words.size(); i++) // 접미사 트라이
    {
        reverse(words[i].begin(), words[i].end());
        Update(1, words[i], 0, (int)words[i].size());
    }
    for(int i=0; i<queries.size(); i++)
    {
        int type = 0;
        if (queries[i][0] == '?') { type = 1; reverse(queries[i].begin(), queries[i].end()); }
        int cnt = Query(type, queries[i], 0, (int)queries[i].size());
        res.push_back(cnt);
    }
    return res;
}
// [출처] 2020 카카오 블라인드 채용 KAKAO BLIND RECRUITMENT 후기|작성자 AM