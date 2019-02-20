#include<iostream>
#include<string>
using namespace std;

string Short_str;
string Full_str;
int num;

void search(int pos) {
    int index = Full_str.find(Short_str, pos);
    // cout<<"t : "<<index<<endl;
    
    if (index != string::npos)
    {
        num++;
        search(index + Short_str.size());
    }
}

int main(void) {
    int tc;
    for (int t = 1; t <= 10; t++) {
        num = 0;
        cin >> tc>>Short_str>>Full_str;
        search(0);
        cout << "#" << t << ' ' << num << endl;
    }
}
