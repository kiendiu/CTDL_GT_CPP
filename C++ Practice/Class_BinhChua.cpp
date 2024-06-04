#include<bits/stdc++.h>
using namespace std;
class binhchua{
    float dai, rong, cao;
    public: 
    binhchua();
    binhchua(float a, float b, float c);
    bool operator-(binhchua y);
    bool operator++();
    friend istream& operator>>(istream& x, binhchua &y);
    friend ostream& operator<<(ostream& x, binhchua y);
};
binhchua::binhchua(){
    dai=rong=cao=0;
}
binhchua::binhchua(float a, float b, float c){
    dai = a;
    rong = b;
    cao = c;
}
istream& operator>>(istream& x, binhchua&y){
    cout<<"Nhap chieu dai: "; x>>y.dai;
    cout<<"Nhap chieu rong: "; x>>y.rong;
    cout<<"Nhap chieu cao: "; x>>y.cao;
    return x;
}
ostream& operator<<(ostream&x, binhchua y){
    x<<"chieu dai la: "<<y.dai<<endl;
    x<<"chieu rong la: "<<y.rong<<endl;
    x<<"chieu cao la: "<<y.cao<<endl;
    return x;
}
bool binhchua::operator-(binhchua y){
    if(dai*rong*cao == y.dai*y.rong*y.cao)
        return true;
    return false;
}
bool binhchua::operator++(){
    if(dai == rong && dai == cao)
        return true;
    return false;
}
int main(){
    binhchua p, q;
    cout<<"Nhap thong tin binh chua p: \n"; cin>>p;
    cout<<"Nhap thong tin binh chua q: \n"; cin>>q;
    ofstream f("binhchua.txt", ios::app);
    if(p-q==true){
        cout<<"hai binh co the tich bang nhau"<<endl;
        f<<"hai binh co the tich bang nhau"<<endl;
    }else{
        cout<<"hai binh co the tich khong bang nhau"<<endl;
        f<<"hai binh co the tich khong bang nhau"<<endl;
    }
    if(++p==true){
        cout<<"binh chua p la hinh lap phuong"<<endl;
        f<<"binh chua p la hinh lap phuong"<<endl;
    }else{
        cout<<"binh chua p khong la hinh lap phuong"<<endl;
        f<<"binh chua p khong la hinh lap phuong"<<endl;
    }
    if(++q==true){
        cout<<"binh chua q la hinh lap phuong"<<endl;
        f<<"binh chua q la hinh lap phuong"<<endl;
    }else{
        cout<<"binh chua q khong la hinh lap phuong"<<endl;
        f<<"binh chua q khong la hinh lap phuong"<<endl;
    }
    return 0;
}