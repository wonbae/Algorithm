#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> addVectors(const vector<int>& num1, const vector<int>& num2) {
    int carry = 0;
    vector<int> result;
    int i = num1.size() - 1, j = num2.size() - 1;
    
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) sum += num1[i--];
        if (j >= 0) sum += num2[j--];
        
        carry = sum / 10;
        result.push_back(sum % 10);
    }
    
    reverse(result.begin(), result.end());
    return result;
}

string fibonacci(int n) {
    if (n <= 0) return "0";
    if (n == 1) return "1";
    
    vector<vector<int>> fib(n + 1);
    fib[0] = {0};
    fib[1] = {1};
    
    for (int i = 2; i <= n; i++) {
        fib[i] = addVectors(fib[i - 1], fib[i - 2]);
    }
    
    string result;
    for (int digit : fib[n]) {
        result += to_string(digit);
    }
    
    return result;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    int n;
    
    cin >> n;
    
    string result = fibonacci(n);
    cout << result << "\n";
    
    return 0;
}
