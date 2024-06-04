#include <iostream>
#include <iomanip>

using namespace std;

struct SinhVien
{
    string sMSSV;
    string sHoTen;
    int iDiemDanh;
    double dDiemBT;
    double dDiemTH;
    double dDiemGK;
    double dDiemCK;
    double DiemQT()
    {
        return (iDiemDanh + dDiemBT + dDiemTH) / 3;
    }
    double DiemKT()
    {
        return (0.3 * dDiemGK + 0.4 * dDiemCK);
    }
    double DiemHP()
    {
        return (0.3 * DiemQT() + 0.7 * DiemKT());
    }
};
void Scan1(SinhVien sv[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap MSSV " << i + 1 << ": ";
        cin >> sv[i].sMSSV;
        cout << "Nhap ho ten sinh vien " << i + 1 << ": ";
        cin.ignore();
        getline(cin, sv[i].sHoTen);
    }
}
void Scan2(SinhVien sv[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin so sinh vien: " << sv[i].sHoTen << " MSSV: " << sv[i].sMSSV << endl;
        cout << "Nhap so buoi diem danh: ";
        cin >> sv[i].iDiemDanh;
        cout << "Nhap diem bai tap: ";
        cin >> sv[i].dDiemBT;
        cout << "Nhap diem thuc hanh: ";
        cin >> sv[i].dDiemTH;
        cout << "Nhap diem giua ky: ";
        cin >> sv[i].dDiemGK;
        cout << "Nhap diem cuoi ky: ";
        cin >> sv[i].dDiemCK;
        cout << "-------------------------" << endl;
    }
}
void Print(SinhVien sv[], int n, string sLop)
{
    cout << "Lop: " << sLop << endl;
    cout << "Si so: " << n << endl;
    cout << left << setw(5) << "STT"
         << "|" << setw(20) << "Ho ten"
         << "|" << setw(8) << "MSSV"
         << "|" << setw(8) << "DQT"
         << "|" << setw(8) << "DKT"
         << "|" << setw(8) << "DHP" << endl;
    cout << "----------------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << left << setw(5) << i + 1
             << "|" << setw(20) << sv[i].sHoTen
             << "|" << setw(8) << sv[i].sMSSV
             << "|" << setw(8) << sv[i].DiemQT()
             << "|" << setw(8) << sv[i].DiemKT()
             << "|" << setw(8) << sv[i].DiemHP() << endl;
    }
}
void swap(int &xp, int &yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}

void SapXep(SinhVien sv[], int n)
{
    int i, j, max_idx;
    for (i = 0; i < n - 1; i++)
    {
        max_idx = i;
        for (j = i + 1; j < n; j++)
            if (sv[j].DiemHP() > sv[max_idx].DiemHP())
            {
                max_idx = j;
            }
        swap(sv[max_idx], sv[i]);
    }
}
void loc(SinhVien sv[], int n){
    for(int i=0; i<n; i++){
        if(sv[i].DiemHP() >= 5.5){
            cout << left << setw(5) << i + 1
             << "|" << setw(20) << sv[i].sHoTen
             << "|" << setw(8) << sv[i].sMSSV
             << "|" << setw(8) << sv[i].DiemQT()
             << "|" << setw(8) << sv[i].DiemKT()
             << "|" << setw(8) << sv[i].DiemHP() << endl;
        }
    }
}
int main()
{
    SinhVien sinhVien[60];
    string sLop;
    int iSiSo;
    cout << "Nhap ten lop: ";
    cin >> sLop;
    cout << "Nhap si so lop: ";
    cin >> iSiSo;
    Scan1(sinhVien, iSiSo);
    cout << "---------------------------" << endl;
    Scan2(sinhVien, iSiSo);
    Print(sinhVien, iSiSo, sLop);
}
