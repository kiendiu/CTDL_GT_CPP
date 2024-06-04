#include<bits/stdc++.h>
using namespace std;
void xuat(int *a[], int n, int m){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<setw(5)<<a[i][j];
		}cout<<endl;
	}
}
int main(){
    int *a[100];
    int m, n;
    int s = 0;
    cout<<"nhap cot: "; cin>>n;
    cout<<"nhap hang: "; cin>>m;
    for(int i=0; i<n; i++){
        a[i] = new int[m];
        for(int j =0; j<m; j++){
             cout<<"nhap a[i][j] = ";
             cin>>a[i][j];
        }
    }
    xuat(a, n, m);
    int **b = new int*[n];
    for(int j=0; j<m; j++){
        b[j] = new int[m];
        for(int i=0; i<m; i++){
            b[i][j] == a[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j =0; j<m; j++){
            if(a[i][j] %2 == 0)
            a[i][j]= b[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            s+=b[i][j];
        }
    }
    for(int i=0; i<n; i++){
        delete b[i];
        delete b;
    }
    for(int i=0; i<n; i++){
        delete a[i];
    }
} 
