#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(string a, string b){
    //return a.length()>b.length();sap xep theo thu tu chieu dai cua chuoi giam dan
    //neu cos cung do dai thi la thu tu co thu tu nho hon se in truoc
    if(a.length() != b.length()){
        return a.length()>b.length();
    }return a<b;
}
int main(){
    int n; cin>>n;
    int a[10];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a, a+n);
    sort(a, a+n, greater());
    for(int i=0; i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}