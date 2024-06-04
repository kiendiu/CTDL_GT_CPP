#include<bits/stdc++.h>
using namespace std;
//nhap mang
void get(int a[], int n){
	for(int i=1; i<=n; i++){
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
}
//in mang
void print(int a[], int n){
    for(int i=0; i<n; i++){
        cout<<setw(5)<<a[i];
    }
}
//so xuat hien nhieu nhat trong mang
void count(int a[], int b[], int n){
	int d = 1;
	for(int i=1; i<=n; i++){
		b[i] = {0};
		for(int j=i; j<=n; j++){
			if(a[i] == b[j]) b[i]+=1;
		}
	}
	for(int i=1; i<=n; i++){
		if(b[i] > d) d = b[i];
	}
	for(int i=1; i<=n; i++){
		if(b[i] == d )
		cout<<"so lan xuat hien: "<<b[i];
	}
}
//chen mang
void chen(int a[], int &n, int sochen, int x){
	for(int i=n; i>=x; i--){
        a[i] = a[i-1];
    }
    a[x] = sochen;
    n++;
}
//xoa mang
void xoa(int a[], int &n, int v){
    for(int i=v; i<n ;i++){
        a[i] = a[i+1];
    }//v la vi tri can xoa
    n--;
}
//doi vi tri
void swap(int &x, int &y){
    int tg = x; 
    x = y; 
    y = tg;
}
//mang giam dan
void giam(int a[], int n){
    for(int i=0; i<n; i++){
        for( int j = i+1; j<n; j++){
            if(a[i]<a[j]){
                swap(a[i], a[j]);
            }
        }
    }
}
//mang tang dan
void tang(int a[], int n){
    for(int i=0; i<n; i++){
        for( int j = i+1; j<n; j++){
            if(a[i]>a[j]){
                swap(a[i], a[j]);
            }
        }
    }
}
int main(){
	int n; 
    cout<<"nhap so phan tu: ";
    do{
        cin>>n;
    }while(n<0 && n>1000);
    int *a = new int[n];
    int *b = new int[n];
    get(a, n);
    print(a, n);
    count(a, b, n);
    int x, sochen;
    cout<<"nhap so can chen : ";
    cin>>sochen;
    cout<<"nhap vi tri can chen: "; cin>>x;
    chen(a, n, sochen, x);
    print(a, n);
    delete[] a, b;
    return 0;
}
