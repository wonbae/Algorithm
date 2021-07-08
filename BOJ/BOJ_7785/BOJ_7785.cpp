#include<iostream>
#include<map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);

    int n;
    cin>>n;
    map<string, bool,greater<string> > mm;

    for(int i = 0; i < n; i++){
        string name;
        string status;
        cin>>name>>status;
        if(status=="enter"){
            mm[name]=true;
        }else{
            // map[name]=false;
            mm.erase(name);
        }
    }
    
    map<string,bool>::iterator iter;
    for(iter = mm.begin(); iter!=mm.end(); iter++){
        cout<<iter->first<<"\n";
    }

    return 0;
}