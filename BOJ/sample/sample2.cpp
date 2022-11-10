#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'solution' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY cost
 *  2. INTEGER x
 */
int MOD = 1e9+7;

int solution(vector<int> cost, int x) {
    int ans = -987654321;
    int _len = cost.size();
    vector<int> presum(cost.size());
    
    presum[0] = cost[0];
    for(int i = 1; i < _len; i++){
        presum[i] = cost[i] + presum[i-1];
    }
    
    // for(int i = 0; i < cost.size(); i++){
    //     cout<<presum[i]<<" ";
    // }
    
    int p=0,q=1;
    int tmp = 0;
    
    while(true){
        if(p==q) break;
        
        if(presum[q] <= x){
            for(int i = 0; i <= q; i++){
                tmp += (1<<i);
            }
            ans = max(ans, tmp%MOD);
            q++;
        }else{
            if((presum[q] - presum[p]) <= x){
                
            }else{
                if((presum[q] - presum[q-1] + presum[p]) <= x){
                    tmp += (1<<p) + (1<<q);
                }
            }
        }
    }
    
    
    return ans %= MOD;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string cost_count_temp;
    getline(cin, cost_count_temp);

    int cost_count = stoi(ltrim(rtrim(cost_count_temp)));

    vector<int> cost(cost_count);

    for (int i = 0; i < cost_count; i++) {
        string cost_item_temp;
        getline(cin, cost_item_temp);

        int cost_item = stoi(ltrim(rtrim(cost_item_temp)));

        cost[i] = cost_item;
    }

    string x_temp;
    getline(cin, x_temp);

    int x = stoi(ltrim(rtrim(x_temp)));

    int result = solution(cost, x);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
