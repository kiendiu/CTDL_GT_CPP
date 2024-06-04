#include<bits/stdc++.h>
using namespace std;
//nhap ma tran
void get(int a[10][10], int n, int m){
	for (int i=1;i<=n; i++){
		for (int j=1;j<=m; j++){
			cout<<"a["<<i<<"]["<<j<<"] = ";
			cin>>a[i][j];
		}
	}
}
//xuat ma tran
void print(int a[10][10], int n, int m){
	for (int i=1;i<=n; i++){
		for (int j=1;j<=m; j++){
			cout<<setw(5)<<a[i][j];
		}
		cout<<endl;
	}
}
//ham doi
void swap(int &x, int &y){
    int tg = x; 
    x = y; 
    y = tg;
}
//max tung hang luu vao mang b
void maxHang(int a[10][10], int b[], int n, int m){
	int k=1;
	for (int j=1;j<=m;j++){
		int max=a[j][1];
		for (int i=1;i<=n;i++){
			if (a[j][i]>max)
			max=a[j][i];
		}b[k] = max;
		k++;
	}
	for (int k=1; k<=m; k++){
		cout<<setw(5)<<b[k]; 
	}
	cout<<endl;
    for(int k=1; k<=m; k++){
        for(int j = k+1; j<=m; j++){
            if(b[k]>b[j]){
               swap(b[k], b[j]);
            }
        }
    }
	for (int k=1; k<=m; k++){
		cout<<setw(5)<<b[k]; 
	}
}
//xuat chi so cua min
void minAdress(int a[10][10], int n, int m){
	int min = a[1][1], p, q;	
	for(int i=1;i<=n; i++){
		for (int j=1;j<=m; j++){
			if (a[i][j]<min)	min = a[i][j];
		}
	}
	for (int i=1;i<=n; i++){
		for (int j=1;j<=m; j++){
			if (a[i][j]==min){
				p = i;
				q= j;
			cout<<min<<endl;
			cout<<"("<<p<<", "<<q<<")"<<endl;
			}
		}
	}
}
//xoa hang va cot chua max dau tien
void xoa(int a[10][10], int n, int m){
	int p,q;
	int max=a[1][1];
	for (int i=1;i<=n; i++){
		for (int j=1;j<=m; j++){
			if (a[i][j]>max)
				max = a[i][j];
		}
	}
	for (int i=1;i<=n; i++){
		for (int j=1;j<=m; j++){
			if (a[i][j]==max){
				p = i;
				q = j;
				break;
			}
		}
	}
	for (int i=p;i<n;i++){
		for (int j=1;j<=m;j++){
			a[i][j]=a[i+1][j];
		} 
	}n--;
	for (int i=q;i<m;i++){
		for (int j=1;j<=n;j++){
			a[j][i]=a[j][i+1];
		} 
	}m--;
	//xoa hang va cot muon
	for (int i=p;i<=n;i++){
		for (int j=q;j<=m;j++){
			a[i][j]=a[i+1][j+1];
		} 
	}n--;
	m--;
}
//ma tran tang dan
void tang(int a[10][10], int n, int m){
	//tang tung cot
	int k;
	for (int j=1;j<=m; j++){
		for (int i=1;i<=n; i++){
			for (k=i+1;k<=n;k++){
				if(a[i][j]<a[k][j]){
					swap(a[i][j], a[k][j]);
				}
			} 
		} 
	} //tung hang doi i va j o vong lap
	
}
//chen ma tran
void chen(int a[10][10], int n, int m){
	int d;
	cout<<"nhap hang muon chen :"<<endl;
	cout<<"d ="; cin>>d; 
    for(int i=n+1;i>=d;i--)
        for(int j=1;j<=m;j++)
            a[i][j]=a[i-1][j];
    n++;
    for(int j=1;j<=m;j++)
    {
        cout<<"phan tu cot "<<j<<" la: ";
        cin>>a[d][j];
    }
}
int main(){
	int a[30][30];
	int n, m;
}
