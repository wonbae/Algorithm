#include<bits/stdc++.h>
using namespace std;

// long long sum(std::vector<int> &a);
// a: 합을 구해야 하는 정수 n개가 저장되어 있는 배열 (0 ≤ a[i] ≤ 1,000,000, 1 ≤ n ≤ 3,000,000)
// 리턴값: a에 포함되어 있는 정수 n개의 합

long long sum(vector<int> &a){
    long long sum = 0;
    for(int i = 0; i < a.size(); i++){
        sum += a[i];
    }

    return sum;
}
