#include<iostream>
#include<vector>
#include<string>

using namespace std;

string solve(string sentence, string keyword, vector<int> skip){
    cout<<"\n\n";
    string ans = "";

    int pos=0, keylen = keyword.length(), senLen = sentence.length();
    string str = "im stupid and dump";
    pos = 5;
    cout<<str<<"\n";
    str.insert(str.begin() + str.find_first_of('m', pos), 'X');
    cout<<str<<"\n";

    for(int i = 0; i < skip.size(); i++){
        char ch = keyword[i%keylen];
        string st;
        st+=ch;

        cout<<"key : "<<ch<<",  skip:"<<skip[i]<<"\n";

        
    }

    return ans;
}


int main(){
    string a = "i love coding";
    string b = "i love coding";
    string c = "abcd fghi";
    string d = "encrypt this sentence";

    string kw = "mask";
    string kw2 = "mode";
    string kw3 = "axyz";
    string kw4 = "something";

    vector<int> s, s2, s3, s4;
    s.push_back(0);
    s.push_back(0);
    s.push_back(3);
    s.push_back(2);
    s.push_back(3);
    s.push_back(4);
    s2.push_back(0);
    s2.push_back(10);
    s3.push_back(3);
    s3.push_back(9);
    s3.push_back(0);
    s3.push_back(1);
    s4.push_back(0);
    s4.push_back(1);
    s4.push_back(3);
    s4.push_back(2);
    s4.push_back(9);
    s4.push_back(2);
    s4.push_back(0);
    s4.push_back(3);
    s4.push_back(0);
    s4.push_back(2);
    s4.push_back(4);
    s4.push_back(1);
    s4.push_back(3);
    

        
    string res = solve(a, kw, s);
    // string res2 = solve(b, kw2, s2);
    // string res3= solve(c, kw3, s3);
    // string res4 = solve(d, kw4, s4);

    assert(res == "mai lsovke cmodinag");
    // assert(res2 == "mi loove coding");
    // assert(res3 == "aabcde fghixy");
    // assert(res4 == "seoncrmypett thishisng ssenteonmcee");
    
    return 0;
}