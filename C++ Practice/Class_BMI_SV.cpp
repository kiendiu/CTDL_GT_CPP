#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>
using namespace std;
int n;
typedef struct{
    char maSV[6];
    float cao;
    float nang;
    float BMI;
    char the_trang[10];
    string hoten;
    char ngaysinh[10];
}sinhvien;
typedef struct{
    sinhvien ds[100];
    int so_sinh_vien;
}bangtonghop;
void nhap_bangtonghop(bangtonghop *bth){
    ifstream f("dulieu.txt");
    if(f.is_open()){
        f>>n;
        bth->so_sinh_vien = n;
        for(int i=0; i<n; i++){
            f>>bth->ds[i].maSV;
            f>>bth->ds[i].cao;
            f>>bth->ds[i].nang;
        }
    }
    ifstream g("sinhvien.txt");
    if(g.is_open()){
        g>>n;
        bth->so_sinh_vien = n;
        for(int i=0; i<n; i++){
            g>>bth->ds[i].maSV;
            g>>bth->ds[i].ngaysinh;
            getline(g, bth->ds[i].hoten);
        }
    }
}
void tinh_BMI(sinhvien ds[], int so_sinh_vien){
    for(int i=0; i<so_sinh_vien; i++){
        ds[i].BMI = ds[i].cao/ds[i].nang;
    }
    for(int i=0; i<so_sinh_vien; i++){
        if(ds[i].BMI < 18.5){
            char a[10] = "thieu can";
            strcpy(ds[i].the_trang, a);
        }
        else if(ds[i].BMI >=18.5 && ds[i].BMI < 25){
            char b[12]="binh thuong";
            strcpy(ds[i].the_trang, b);
        }
        else if(ds[i].BMI >= 25 && ds[i].BMI < 30){
            char d[9] = "thua can";
            strcpy(ds[i].the_trang, d);
        }
        else {
            char c[8] = "beo phi";
            strcpy(ds[i].the_trang, c);
        }
    }
}
void ghi_tep(sinhvien bh[], int so_sinh_vien){
    ofstream g("ketqua.txt");
    if(g.is_open()){
        g<<setw(5)<<"STT"<<setw(10)<<"MaSV"<<setw(30)<<"HO TEN"<<setw(20)<<"Ngay Sinh"<<setw(15)<<"BMI"<<setw(15)<<"Phan Loai"<<endl;
        for(int i=0; i<so_sinh_vien; i++){
            g<<setw(5)<<i+1<<setw(10)<<bh[i].maSV<<setw(30)<<bh[i].hoten<<setw(20)<<bh[i].ngaysinh<<setw(15)<<bh[i].BMI<<setw(15)<<bh[i].the_trang<<endl;
        }
    }
}
int main(){
    bangtonghop bth;
    nhap_bangtonghop(&bth);
    tinh_BMI(bth.ds, bth.so_sinh_vien);
    ghi_tep(bth.ds, bth.so_sinh_vien);
    return 0;
}