#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
class xe{
    protected:
    string ten_nguoithue;
    float sogiothue;
    public:
    void nhap(){
        while(getchar() != '\n');
        cout<<"nhap ten nguoi thue: ";
        getline(cin, ten_nguoithue);
        cout<<"nhap so gio thue: "; 
        cin>>sogiothue;
    }
    void xuat(){
        cout<<"ho ten nguoi thue : "<<ten_nguoithue<<endl;
        cout<<" +so gio thue : "<<sogiothue<<endl;
    }
};
class xedap: public xe{
    private:
    public:
    float tien_thuexe(){
        return (10000 + 8000*(sogiothue - 1));
    }
};
class xemay: public xe{
    private: 
    int loaixe;
    string bienxe;
    public:
    void nhap(){
        xe::nhap();
        cout<<"nhap loai xe muon di (100 pk - 250 pk): "; 
        cin>>loaixe;
        while(getchar() != '\n');
        cout<<"nhap bien so xe: ";
        getline(cin, bienxe);
    }
    void xuat(){
        xe::xuat();
        cout<<" +loai xe: "<<loaixe<<endl;
        cout<<" +bien so xe: "<<bienxe<<endl;
    }
    float tien_thuexe(){
        float s = 0;
        if(loaixe == 100) s = 1500000;
        else if(loaixe == 250) s = 200000;
        return (s + 100000*(sogiothue - 1));
    }
    int Getter(){
        return loaixe;
    }
    void Setter(int LOAIXE){
        loaixe = LOAIXE;
    }
};
void xuat_all(xedap ds_xedap[], int n, xemay ds_xemay[], int m){
    int dem = 0;
    cout<<"=====DANH SACH THUE XE DAP====="<<endl;
    for(int i=0; i<n; i++){
        cout<<"thong tin xe dap "<<dem++<<": "<<endl;
        ds_xedap[i].xuat();
        cout<<" +tien thue: "<<(size_t)ds_xedap[i].tien_thuexe()<<endl;
    }
    cout<<"=====DANH SACH THUE XE MAY====="<<endl;
    for(int i=0; i<m; i++){
        cout<<"thong tin xe may "<<dem++<<": "<<endl;
        ds_xemay[i].xuat();
        cout<<" +tien thue: "<<(size_t)ds_xemay[i].tien_thuexe()<<endl;
    }
}
float tong_tienthue(xedap ds_xedap[], int n, xemay ds_xemay[], int m){
    float tong = 0;
    for(int i=0; i<n; i++){
        tong+=ds_xedap[i].tien_thuexe();
    }
    for(int i=0; i<m; i++){
        tong+=ds_xemay[i].tien_thuexe();
    }
    return (size_t)tong;
}
void menu_quanly(xedap ds_xedap[], int n, xemay ds_xemay[], int m){
    int luachon;
    while(true){
        cout<<"\n\t ======= QUAN LY XE ======="<<endl;
        cout<<"1. Nhap danh sach thue xe dap va xe may."<<endl;
        cout<<"2. Xuat tat ca thong tin thue xe."<<endl;
        cout<<"3. Tinh tong so tien cho thue xe."<<endl;
        cout<<"4. Xuat tat ca thong tin lien quan den thue xe dap."<<endl;
        cout<<"5. Tinh tong so tien cho thue xe loai 250 pk"<<endl;
        cout<<"0. ket thuc chuong trinh."<<endl;
        cout<<"=============END============="<<endl;
        cout<<"Nhap lua chon: ";
        cin>>luachon;
        if(luachon == 1){
            int chon;
            while(true){
                system("cls");
                cout<<"1. thue xe dap"<<endl;
                cout<<"2. thue xe may"<<endl;
                cout<<"0. ket thuc lua chon"<<endl;
                cout<<"Ban can thue xe gi: ";
                cin>>chon;
                if(chon == 1){
                    xedap x;
                    cout<<"Nhap thong tin thue xe dap: "<<endl;
                    x.nhap();
                    ds_xedap[n] = x;
                    n++;
                }else if(chon == 2){
                    xemay x;
                    cout<<"Nhap thong tin thue xe may: "<<endl;
                    x.nhap();
                    ds_xemay[m] = x;
                    m++;
                }else break;
            }
        }
        else if(luachon == 2){
            xuat_all(ds_xedap, n, ds_xemay, m);
            system("pause");
        }
        else if(luachon == 3){
            cout<<"Tong tien thue xe la: "<<tong_tienthue(ds_xedap, n, ds_xemay, m);
            system("pause");
        }
        else if(luachon == 4){
            cout<<"=====DANH SACH THUE XE DAP====="<<endl;
            for(int i=0; i<n; i++){
                cout<<"thong tin xe dap "<<i+1<<": "<<endl;
                ds_xedap[i].xuat();
                cout<<" +tien thue: "<<(size_t)ds_xedap[i].tien_thuexe()<<endl;
            }
            system("pause");
        }
        else if(luachon == 5){
            int dem = 0;
            cout<<"===DANH SACH THUE XE MAY LOAI 250 PK==="<<endl;
            for(int i=0; i<m; i++){
                if(ds_xemay[i].Getter() == 250){
                    cout<<"thong tin xe may "<<dem++<<": "<<endl;
                    ds_xemay[i].xuat();
                    cout<<" +tien thue: "<<(size_t)ds_xemay[i].tien_thuexe()<<endl;
                }
            }
            system("pause");
        }
        else {
            break;
        }
    }
}
int main(){
    xedap ds_xedap[100];
    int n=0;
    xemay ds_xemay[100];
    int m=0; 
    menu_quanly(ds_xedap, n, ds_xemay, m);
    system("pause");
    return 0;
}