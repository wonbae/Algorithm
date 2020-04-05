#include<bits/stdc++.h>
using namespace std;
#define MINF -987654321

int solution(string answer_sheet, vector<string> sheets) {
    int answer = 0;
    int r_len = sheets.size();  //제출한 답안지 갯수
    int c_len = sheets[0].size();   //선택한 한개의 답안지의 정답 길이
    int tmp[201][101] = {0,};
    // cout<<r_len<<" "<<c_len<<"\n";

    int idx = 0;
    for(int c = 0; c < c_len; c++){
        for(int r = 0; r < r_len; r++){
            if(answer_sheet[idx] == sheets[r][c]){
                continue;
            }else{
                tmp[r][c] = int(sheets[r][c] - 48);
            }
        }idx++;
    }

    // cout<<"\n==== tmp ====\n";
    // for(int r = 0; r < r_len; r++){
    //     for(int c = 0; c < c_len; c++){
    //         cout<<tmp[r][c]<<" ";   
    //     }cout<<"\n";
    // }

    int maxSL = MINF, maxSWA = MINF;
    for(int r = 0; r < r_len - 1; r++){
        int sWrongAns;
        int seqLen;
        for(int nr = r + 1; nr < r_len; nr++){
            sWrongAns = 0;
            seqLen = 0;
            for(int c = 0; c < c_len; c++){
                if(tmp[r][c] == 0 || tmp[nr][c] == 0){
                    seqLen = 0;
                    continue;
                } 

                // cout<<"("<<r<<", "<<c<<")"<< " - "<<"("<<nr<<", "<<c<<") \n";

                if(tmp[r][c] == tmp[nr][c]){
                    ++seqLen;
                    ++sWrongAns;
                    maxSL = max(maxSL, seqLen);
                }else{
                    maxSL = max(maxSL, seqLen);
                    seqLen = 0;
                    continue;
                }
            }
            maxSWA = max(maxSWA, sWrongAns);
        }
        
    }

    // cout<<"의심문항 : "<<maxSWA<<", \n"<<"가장긴 문항 : "<<maxSL<<"\n";
    answer = int(maxSWA + pow(maxSL, 2));
    // cout<<"Answer : "<<answer<<"\n\n";

    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0;
    string ash = "4132315142";
    vector<string> sh;
    sh.push_back("3241523133");
    sh.push_back("4121314445");
    sh.push_back("3243523133");
    sh.push_back("4433325251");
    sh.push_back("2412313253");

    string ash2 = "53241";
    vector<string> sh2;
    sh2.push_back("53241");
    sh2.push_back("42133");
    sh2.push_back("53241");
    sh2.push_back("14354");

    string ash3 = "24551";
    vector<string> sh3;
    sh3.push_back("24553");
    sh3.push_back("24553");
    sh3.push_back("24553");
    sh3.push_back("24553");

    // ++++++++++ Extra Exemple +++++++++++++++

    string ash4 = "123454321";
    vector<string> sh4;
    sh4.push_back("123451234");
    sh4.push_back("543211234");
    sh4.push_back("543212345");
    sh4.push_back("543213345");

    string ash5 = "543213543124";   //5 4 3 2 1 3 5 4 3 1 2 4
    vector<string> sh5;
    sh5.push_back("542313254341");  
    sh5.push_back("123454321344");  //1 2 0 4 5 4 /3 2 1 3 4 0
    sh5.push_back("123454213232");  //1 2 0 4 5 4 /2 1 0 2 3 2
    sh5.push_back("543213543144");

    string ash6 = "12345";
    vector<string> sh6;
    sh6.push_back("12345");
    sh6.push_back("54221"); //
    sh6.push_back("54221"); //
    sh6.push_back("14341");

    // ++++++++++ Extra Exemple +++++++++++++++
    
    ans = solution(ash, sh);
    cout<<ans<<"\n";

    ans = solution(ash2, sh2);
    cout<<ans<<"\n";

    ans = solution(ash3, sh3);
    cout<<ans<<"\n";

    // ++++++++++ Extra Exemple +++++++++++++++
    ans = solution(ash4, sh4);
    cout<<ans<<"\n";

    ans = solution(ash5, sh5);
    cout<<ans<<"\n";
    
    ans = solution(ash6, sh6);
    cout<<ans<<"\n";
    // ++++++++++ Extra Exemple +++++++++++++++

    return 0;
}