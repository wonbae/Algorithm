// O(2^(m+n))
// 연습문제 5-6 정답은 없음. 겹치지 않아도 2차원 배열 필요. 

#include <iostream>
#include <string>
using namespace std;

void generate_interleavings(string& s1, string& s2, string& current, int i, int j) {
    if (i == s1.size() && j == s2.size()) {
        cout << current << endl;
        return;
    }

    if (i < s1.size()) {
        current.push_back(s1[i]);
        generate_interleavings(s1, s2, current, i + 1, j);
        current.pop_back();
    }

    if (j < s2.size()) {
        current.push_back(s2[j]);
        generate_interleavings(s1, s2, current, i, j + 1);
        current.pop_back();
    }
}

int main() {
    string string1 = "ab";
    string string2 = "xy";
    string current = "";

    generate_interleavings(string1, string2, current, 0, 0);

    return 0;
}
