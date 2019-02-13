#include<iostream>
using namespace std;

int maxf(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int T;
    int A, B, C;
    int result;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> A >> B >> C;

        result = maxf(C / A, C / B);
        cout << "#" << i + 1 << " " << result<<endl;
    }
    return 0;
}