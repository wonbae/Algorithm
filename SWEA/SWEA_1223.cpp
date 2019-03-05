#include <iostream>
#include <stack>
using namespace std;

int N; 
int main()
{
 
    for (int tc = 1; tc <= 10; ++tc)
    {
        cin >> N;
        int sum = 0;
        char c;
        stack <int> num;
        for (int j = 0; j < N; ++j)
        {
            cin >> c;
            if (c <= '9' && c >= '0') num.push(c - '0');
            if (c == '*')
            {
                cin >> c; 
                int tmp = num.top(); num.pop();
                num.push((c - '0') * tmp);
                j++;
            }
        }
        while (!num.empty())
        {
            sum += num.top(); num.pop();
        }
        cout << "#" << tc << " " << sum << "\n";
 
    }
    return 0;
}