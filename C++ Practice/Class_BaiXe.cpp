#include<bits/stdc++.h>
using namespace std;
class BAIXE;
class PHUONGTIEN{
    protected:
    char MaPT[30];
    char loai[30];
    float Gia;
    char HangSX[30];
    public:
    void nhap();
    void xuat();
};
class xeMay: public PHUONGTIEN{
    char Maxe[30];
    char Tenxe[30];
    float Dungtich;
    char Bienso[30];
    public:
    void nhap();
    void xuat();
    friend void Sap(BAIXE a);
};
class BAIXE{
    char Mabx[30];
    char Tenbx[30];
    float Dientich;
    xeMay *x;
    int n;
    public:
    void nhap();
    void xuat();
    friend void Sua(BAIXE &a);
    friend void Sap(BAIXE a);
};
void PHUONGTIEN::nhap(){
    cout<<"ma pt: "; fflush(stdin); gets(MaPT);
    cout<<"loai: "; fflush(stdin); gets(loai);
    cout<<"gia: "; cin>>Gia;
    cout<<"hang sx: "; fflush(stdin); gets(HangSX);
}
void PHUONGTIEN::xuat(){
    cout<<setw(10)<<MaPT<<setw(15)<<loai<<setw(10)<<Gia<<setw(15)<<HangSX<<endl;
}
void xeMay::nhap(){
    PHUONGTIEN::nhap();
    cout<<"ma xe: "; fflush(stdin); gets(Maxe);
    cout<<"ten xe: "; fflush(stdin); gets(Tenxe);
    cout<<"dung tich: "; cin>>Dungtich;
    cout<<"bien so: "; fflush(stdin); gets(Bienso);                                         
}
void xeMay::xuat(){
    PHUONGTIEN::xuat();
    cout<<setw(10)<<Maxe<<setw(15)<<Tenxe<<setw(10)<<Dungtich<<setw(15)<<Bienso<<endl;
}
void BAIXE::nhap(){
    cout<<"ma bai xe: "; fflush(stdin); gets(Mabx);
    cout<<"ten bai xe: "; fflush(stdin); gets(Tenbx);
    cout<<"dien tich: "; cin>>Dientich;
    cout<<"nhap so xe may: "; cin>>n;
    x = new xeMay[n];
    for(int i=0; i<n; i++){
        cout<<"nhap xe may thu "<<i+1<<endl;
        x[i].nhap();
    }
}
void BAIXE::xuat(){
    cout<<"ma bx: "<<Mabx<<endl;
    cout<<"ten bx: "<<Tenbx<<endl;
    cout<<"dien tich: "<<Dientich<<endl;
    cout<<setw(10)<<"Ma PT"<<setw(15)<<"loai"<<setw(10)<<"Gia"<<setw(15)<<"Hang SX"<<endl;
    cout<<setw(10)<<"Ma xe"<<setw(15)<<"Ten xe"<<setw(10)<<"Dung tich"<<setw(15)<<"Bien so"<<endl;
    for(int i=0; i<n; i++){
        x[i].xuat();
    }
}
void Sua(BAIXE &a){
    strcpy(a.Tenbx, "MAI DICH");
}
void swap(float &a, float &b){
    int temp;
    a = temp;
    a = b; 
    b = temp;
}
void Sap(BAIXE a){
    for(int i=0; i<a.n; i++){
        for(int j=0; j<a.n; j++){
            if(a.x[i].Dungtich > a.x[j].Dungtich){
                swap(a.x[i], a.x[j]);
            }
        }
    }
}
int main(){
    BAIXE a;
    a.nhap();
    a.xuat();
}