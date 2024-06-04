#include<bits/stdc++.h>
#include<map>
#include<vector>
#include<unordered_map>//khong sap xep theo thu tu
using namespace std;
int main(){
    map<int,int> mp;
    //them value khi co key
    mp[1] = 2;
    //them 1 cap
    mp.insert({2,3});
    //duyet cac phan tu dung
    for(auto x:mp){
        cout<<x.first<<" "<<x.second<<'\n';
    }
    //duyet bang interator
    for(map<int,int>::iterator it=mp.begin(); it!= mp.end(); it++){
        cout<<(*it).first<<" "<<(*it).second<<'\n';
    }
    //tim key trong map co ton tai
    cout<<mp.count(1)<<endl;//tim thay tra ve 1 con khong la ve 0
    //find se tra ve mp.end neu khong tim thay
    if(mp.find(2) == mp.end()){
        cout<<"not found";
    }
    //xoa cap ra kho imap
    mp.erase(1);
    //xoa ky tu trung nhau
    string s;
    cin>>s;
    map<char,int> st;
    for(int i=0; i<s.length();i++){
        st[s[i]]++;
    }
    for(auto x:st){
        cout<<x.first;
    }
    return 0;
}