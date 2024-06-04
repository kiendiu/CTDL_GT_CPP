#include<bits/stdc++.h>
#include<vector>
#include<set>
using namespace std;
int main(){
    // pair<int,int> v = make_pair(100,200);
    // pair<int,string> a = make_pair(100,"kien");
    // cout<<a.first<<" = "<<a.second<<endl;
    // tuple<char, string, int> b = {'k', 100, "kien"};
    // b = make_tuple('k',100,"java");
    multiset<int> ms;
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int &x : a){
        cin>>x;
    }
    for(int i=0; i<k; i++){
        ms.insert(a[i]);
    }
    for(int i=k; i<n; i++){
        cout<<*ms.rbegin()<<" ";
        ms.erase(ms.find(a[i-k]));
        ms.insert(a[i]);
    }
    cout<<*ms.rbegin();
    return 0;
}