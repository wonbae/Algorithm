#include <string>
#include <vector>
#include<algorithm>
using namespace std;

string f1(string);
string f2(string);

string f1(string s)
{
    if (s.empty()) return s;
    return f2(s);
}

string f2(string s)
{
    string u, v;
    int sum = 0, chk = 0;
    for(int i=0; i<s.size(); i++)
    {
        if (s[i] == '(') sum++;
        else sum--;
        if (sum < 0) chk = 1;
        if (sum == 0)
        {
            u = s.substr(0, i+1);
            v = s.substr(i+1, (int)s.size()-i-1);
            break;
        }
    }
    if (chk == 0) // 3
    {
        string ret = u + f1(v);
        return ret;
    }
    else // 4
    {
        string ret;
        ret += '(';
        ret += f1(v);
        ret += ')';
        string t = u.substr(1, (int)u.size()-2);
        for(int i=0; i<t.size(); i++)
        {
            if (t[i] == '(') t[i]=')';
            else t[i] = '(';
        }
        ret += t;
        return ret;
    }
    return "ERROR";
}

string solution(string s) {
    return f1(s);
}
// [출처] 2020 카카오 블라인드 채용 KAKAO BLIND RECRUITMENT 후기|작성자 AM