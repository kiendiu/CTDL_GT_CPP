#include<bits/stdc++.h>
using namespace std;
class hanghoa{
    string ten;
    string ma;
    float dongia;
    int soluong;
    public:
    hanghoa(){
        dongia = 0;
        soluong = 0;
    }
    hanghoa(string ten, string ma, float dongia, int soluong){
        this->ten = ten;
        this->ma = ma;
        this->dongia = dongia;
        this->soluong = soluong;
    }
    void inthongtin(){
        cout<<ten<<":"<<dongia*soluong;
    }
    float giatri(){
        return soluong*dongia;
    }
};
class hoadon{
    string sohoadon;
    int ngay;
    hanghoa ds[100];
    int soluong;
    public:
    hoadon();
    hoadon(string sohoadon){
        this->sohoadon=sohoadon;
    }
    void nhaphang(){
        cout<<"nhap so luong mat hang: ";
        cin>>soluong;
        float dongia;
        for(int i=0; i<soluong; i++){
            string ten, ma;
            int sl;
            cout<<"ten hang: ";
            cin>>ten;
            cout<<"ma hang: ";
            cin>>ma;
            cout<<"don gia: ";
            cin>>dongia;
            cout<<"soluong: ";
            cin>>sl;
            hanghoa h(ten, ma, dongia, sl);//Note
            ds[i]= h;
        }
    }
    void indanhsach(){
        for(int i=0; i<soluong; i++){
            ds[i].inthongtin();
        }
    }
    float tinhtong(){
        float s = 0;
        for(int i=0; i<soluong; i++){
            s+=ds[i].giatri();
        }
        return s;
    }
};
int main(){
    hoadon hd;
    hd.nhaphang();
    hd.indanhsach();
    cout<<hd.tinhtong();
    return 0;
}