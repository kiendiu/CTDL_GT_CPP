#include<bits/stdc++.h>
using namespace std;
//khai bao: vector<kieu du lieu> tenvector
//size(): kich thuoc cua vector
int main(){
    vector<int> n;
    n.push_back(10);
    n.push_back(20);
    n.push_back(30);
    cout<<n.size()<<endl;//phan tu bat dau tu khong
    cout<<"phan tu dau tien: "<< n[0]<<endl;//
    cout<<"phan tu cuoi cung: "<< n[n.size()-1]<<endl;//n.back()
    //duyet thong qua chi so = index
    for(int i=0; i<n.size(); i++){
        cout<<n[i]<<endl;
    }
    //duyet qua x
    for(int x : n){
        cout<<x<<endl;
    }
    //duyet qua interator la con tro den mot phan tu cua vecto
    //n.begin() la phan tu dau tien 
    //n.end() la phan tu sau phan tu cuoi cung
    for(vector<int>::iterator it=n.begin(); it != n.end(); it++){
        cout<<*it<<endl;//dung toan tu tham chieu *
    }
    //duyet qua auto(duyet cham hon so voi index)
    for(auto it=n.begin(); it!=n.end(); it++){
        //auto co the thay cho string so 
        cout<<*it<<endl;
    }
    //tro den gia tri cua n[2] = *(n.begin()+2)
    int a;
    cin>>a;
    vector<int> v(a);//khai vao vt da co n phan tu
    //day gia tri vao vector
    for(int i=0; i<a; i++){
        int x; cin>>x;
        v.push_back(x);
    }
    //khoi tao vector co gia tri giong nhau 
    vector<int> b(a, 100);
    for(int i=0; i<a; i++){
        cout<<b[i]<<endl;
    }
    //tach cac tu trong sau
    string s ="lap trinh khong kho";
    stringstream ss(s);
    string tmp;
    vector<string> c;
    while(ss >> tmp){
        c.push_back(tmp);
    }
    for(string m:c){
        cout<<m<<endl;
    }
    return 0;
}