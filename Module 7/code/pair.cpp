#include<bits/stdc++.h>

using namespace std;

int main(){
    // roll, name, surname, certificate
    vector<pair<int,string>>v={{1,"x"},{2,"y"},{3,"z"}};
    for(int i=0;i<v.size();i++){
        cout<<v[i].roll<<" "<<v[i].name<<endl;
    }
}