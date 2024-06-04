//Truyền hàm vào hàm dưới dạng đối số 
#include<iostream>
#include<functional>
using namespace std;
//dùng hàm tăng và giảm làm ví dụ 
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
//thuat toan selectionsort
void selectionsortAsc(int *arr, int n){
    int i, j, min_idx;
    for(int i=0; i<n-1; i++){
        min_idx = i;;
        for(j=i+1; j<n; j++){
            if(arr[min_idx] > arr[j]){
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}
void selectionsortDes(int *arr, int n){
    int i, j, min_idx;
    for(int i=0; i<n-1; i++){
        min_idx = i;;
        for(j=i+1; j<n; j++){
            if(arr[min_idx] < arr[j]){
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}
void printArr(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
bool asc(int a, int b){
    return a>b;
}
bool des(int a, int b){
    return a<b;
}
void selectionsort(int *arr, int n, bool (*comparisonfcn)(int , int)){
    int i, j, find_idx;
    for(int i=0; i<n-1; i++){
        find_idx = i;
        for(j=i+1; j<n; j++){
            if(comparisonfcn(arr[find_idx], arr[j])){
                find_idx = j;
            }
        }
        swap(arr[find_idx], arr[i]);
    }
}
int funca();
double funcb(int );
int main(){
    //sizeof(arr) la kich thuoc cua mang: so phan tu * 4 byte;
    //sezeof(int) la kich thuoc cua kieu du lieu
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(int);
    selectionsort(arr, n, asc);
    function<int()> fncPtA = funca;
    function<double(int )> fncPtB = funcb;
    //auto co the nhan dang con tro ham
    //auto ptrwap = swap;//cac tham so va kieu tra ve bi an
    //xac dinh kdl tai thoi diem bien dich nene khong duoc su dung cho tham so ham
}