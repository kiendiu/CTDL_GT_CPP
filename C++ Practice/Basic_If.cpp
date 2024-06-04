#include<iostream>
using namespace std;
int main(){
    // int a, b, c, d;//tim so be thu hai
    // cin>>a>>b>>c>>d;
    // int min;
    // int second;
    // if(a>b){
    //     min = b; 
    //     second = a;
    // }else {
    //     min = a;
    //     second = b;
    // }
    // if(min>c){
    //     second = min;
    //     min = c;
    // }
    // if(min>d){
    //     second = min;
    //     min = d;
    // }
    // cout<<"so be thu hai la: "<<second<<endl;
    // char ckytu;//doi chu hoa thanh chu thuong va nguoc lai dung bang ascci
    // cin>>ckytu;
    // if(ckytu >'a' && ckytu<'z'){
    //     ckytu-=32;
    // }else if(ckytu>'A' && ckytu<'Z'){
    //     ckytu+=32;
    // }
    // cout<<"ky tu chuyen doi la: "<<ckytu<<endl;
    float sokm;
    float sotien=1;
    cout<<"nhap so km: ";
    cin>>sokm;
    if(sokm <= 1){
        sotien=sokm*15000;
    }
    system("pause");
    return 0; 
}