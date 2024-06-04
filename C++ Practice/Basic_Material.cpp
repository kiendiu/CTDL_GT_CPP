#include<iostream>
#include<iomanip> 

using namespace std;

#define MAX 100

int main(){
    float SoThuTu[MAX], SoLuong[MAX],TienVatLieu[MAX], Tong=0, max,a,b,TG ;
    string TenVatLieu[MAX],luachon, TG2;
    float DonGia[MAX];
    for (int i=0; i<MAX; i++){
        cout << i+1;
        cout << " . nhap ten vat lieu : ";
        getline(cin,TenVatLieu[i]);
        cout << "\nnhap don gia > 0  : ";
        do{cin >> DonGia[i];}   while(DonGia[i]<=0);
        cout << "\nnhap so luong vat lieu > 0 : ";
        do{cin >> SoLuong[i];}  while(SoLuong[i]<=0);
        cout << "\nban co muon nhap tiep khong(y/n) : ";
        cin >> luachon;
        b=i;
        cin.ignore();
        if(luachon=="n")  break;
    }
    for(int i=0; i <= b ; i++){
        TienVatLieu[i]=DonGia[i]*SoLuong[i];
        Tong += TienVatLieu[i];
    }
    system("cls");
    max = TienVatLieu[0];
    for (int i = 0; i <= b; i++){
        if (max < TienVatLieu[i])  { max = TienVatLieu[i];}
    }

    cout << "STT  |Ten Vat Lieu        |Don Gia  |So Luong |Tien Vat Lieu " <<endl;
    for (int i = 0; i <= b; i++){
        cout << setw(1) << i+1;
        cout << setw(24) << TenVatLieu[i];
        cout << setw(10) << DonGia[i];
        cout << setw(10) << SoLuong[i];
        cout << setw(10) << TienVatLieu[i];
        cout << endl;
    }

    for (int i = 0; i < b ; i++) {
        for (int j = i + 1; j <= b; j++) {
        if (TienVatLieu[i] < TienVatLieu[j])
        {
                TG = TienVatLieu[i];
                TienVatLieu[i] = TienVatLieu[j];
                TienVatLieu[j] = TG;

                TG = DonGia[i];
                DonGia[i] = DonGia[j];
                DonGia[j] = TG;

                TG2 = TenVatLieu[i];
                TenVatLieu[i] = TenVatLieu[j];
                TenVatLieu[j] = TG2;

                TG = SoLuong[i];
                SoLuong[i] = SoLuong[j];
                SoLuong[j] = TG;
        }}}
    cout << "\n\n\n Sap xep \n\n\n";
    cout << "STT  |Ten Vat Lieu        |Don Gia  |So Luong |Tien Vat Lieu " <<endl;
    for (int i = 0; i <= b; i++){
        cout << setw(1) << i+1;
        cout << setw(24) << TenVatLieu[i];
        cout << setw(10) << DonGia[i];
        cout << setw(10) << SoLuong[i];
        cout << setw(10) << TienVatLieu[i];
        cout << endl;
    }

    cout << "\nVat tu ton nhieu tien nhat la : ";
    for (int i = 0; i <= b; i++){
        if (TienVatLieu[i]==max) {cout << TenVatLieu[i] << " ";}
    }
    cout << "\nVat tu do da ton : "<< max;
    cout << "\nTong so tien cua ca cong trinh la : "<< Tong;

    return 0;
}
