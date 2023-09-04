#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


vector<int> findDivisors(int num){
    vector<int> divisors;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            divisors.push_back(i);
            if(num / i != i)
                divisors.push_back(num / i);
        }
    }
    return divisors;
}


int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> numbers(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    
    int difference = numbers[1] - numbers[0];
    
    for (int j = 2; j < n; j++) {
        difference = gcd(difference, numbers[j] - numbers[j - 1]);
    }

    vector<int> divisors = findDivisors(difference);

    sort(divisors.begin(), divisors.end());


    for (int i = 1; i < divisors.size(); i++) {
        cout<<divisors[i]<<" ";
    }

    return 0;
}
