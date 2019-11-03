#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// bool desc(int a, int b){
//     return a>b;
// }
string solution(string s) {
   sort(s.rbegin(), s.rend());
    
    // sort(s.begin(), s.end(), greater<char>());
 
    return s;
}
