#include<bits/stdc++.h>
using namespace std;
class sinhVien{
	char mssv[20];
	string hoten;
	int diemdanh;
	float ck, bt, th, ktgk, ktck;
	float diemqt(){
		return(0.3*ck + 0.3*bt + 0.4*th); 
	}
	float diemkt(){
		return(0.3*ktgk + 0.7*ktck); 
	}
	float diemhp;
    public:
    sinhVien(){

    }
    float diemHP(){
       diemhp = 0.3*diemqt() + 0.7*diemkt();
       return diemhp;
    }
    void nhapSV(){
        cout<<"nhap ten sinh vien: "; 
        cin.ignore();
        getline(cin, hoten);
        cout<<" +mssv: "; fflush(stdin); gets(mssv);
        cout<<"-Nhap diem "<<hoten<<" - "<<mssv<<" : "<<endl;
	 	cout<<" +buoi diem danh: "; 
	 	cin>>diemdanh;
	 	cout<<" +diem chuyen can: ";
	 	cin>>ck;
	 	cout<<" +diem bai tap: ";
	 	cin>>bt;
	 	cout<<" +diem thuc hanh: ";
	 	cin>>th;
	 	cout<<" +diem giua ky: ";
	 	cin>>ktgk;
	 	cout<<" +diem cuoi ky: ";
	 	cin>>ktck;
    }
    void xuatSV(){
        cout << left
             << "|" << setw(20) <<hoten
             << "|" << setw(8) <<mssv
             << "|" << setw(8) <<diemqt()
             << "|" << setw(8) <<diemkt()
             << "|" << setw(8) <<diemHP()<< endl;
    }
};
class lop{
    sinhVien ds[20];
    char tenlop[20];
    int n;
    public:
    lop(){

    }
    void ttlop(){
        cout<<"ten lop: "; fflush(stdin); gets(tenlop);
        cout<<"nhap si so lop; "; cin>>n;
    }
    void nhaplop(){
        for(int i=0; i<n; i++){
            ds[i].nhapSV();
        }
    }
    void xuatlop(){
        cout << "Lop: "   <<tenlop <<endl;
        cout << "Si so: " << n << endl;
        cout << left
         << "|" << setw(20) << "Ho ten"
         << "|" << setw(8) << "MSSV"
         << "|" << setw(8) << "DQT"
         << "|" << setw(8) << "DKT"
         << "|" << setw(8) << "DHP" << endl;
        for(int i=0; i<n; i++){
            ds[i].xuatSV();
        }
    }
    void sapxep(){
	int max;
	for(int i = 0; i<n; i++){
		max = i;
		for(int j = i+1; j<=n+1; j++ ){
			if(ds[j].diemHP() > ds[max].diemHP())
			{
				max = j;
			}
			swap(ds[max], ds[i]);
		}
	}
}
};
int main(){
    lop a;
    a.ttlop();
    a.nhaplop();
    a.xuatlop();
    a.sapxep();
    a.xuatlop();
    return 0;
}