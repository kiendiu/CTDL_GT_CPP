#include <bits/stdc++.h>

using namespace std;

int m, n;


typedef struct
{
    char madoi[5];
    int ketqua[30];
    float nangsuat;
} doikhoan;

typedef struct
{
    doikhoan ds[100];
    int sodoikhoan;
} bangtonghop;

void nhap_dulieu(bangtonghop *bang)
{
    ifstream file("test.txt");
    if (file.is_open())
    {
        file >> m >> n;
        bang->sodoikhoan = m;
        for (int i = 0; i < m; i++)
        {
            file >> bang->ds[i].madoi;
            for (int j = 0; j < n; j++)
            {
                file >> bang->ds[i].ketqua[j];
            }
        }
    }
}

void tinhnangsuat(doikhoan ds[], int sodoikhoan)
{
    for (int i = 0; i < sodoikhoan; i++)
    {
        float tong = 0;
        for (int j = 0; j < n; j++)
        {
            tong += ds[i].ketqua[j];
        }
        ds[i].nangsuat = tong / n;
    }
}

void in_file(doikhoan ds[], int sodoikhoan)
{
    // print madoi and nangsuat of each team
    ofstream file("test1.txt");
    if (file.is_open())
    {
        for (int i = 0; i < sodoikhoan; i++)
        {
            file << ds[i].madoi << " " << ds[i].nangsuat << endl;
        }
    }
}

void sort(doikhoan ds[], int sodoikhoan){
    for (int i = 0; i < sodoikhoan; i++)
    {
        for (int j = i + 1; j < sodoikhoan; j++)
        {
            if (ds[i].nangsuat < ds[j].nangsuat)
            {
                doikhoan temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

int main()
{
    bangtonghop bang;
    bangtonghop *bang1 = &bang;
    nhap_dulieu(bang1);
    tinhnangsuat(bang1->ds, bang1->sodoikhoan);
    sort(bang1->ds, bang1->sodoikhoan);
    in_file(bang1->ds, bang1->sodoikhoan);

    return 0;
}