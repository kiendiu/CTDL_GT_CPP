/*
        QUEUE 
    push: đẩy vào cuối hàng
    pop: xóa phần tử khỏi đầu hàng đợi
    emtpy: check hàm rỗng
    size: kích thước hàng đợi
    front: lấy ra phần tử ở đầu hàng đợi
    ham stoll(): chuyen doi xau sang so
    bai chuyen tu so nay sang so khac thong qua cac thao tac thi dung queue ko dung de quy
*/
#include<iostream>
#include<queue>
using namespace std;
using ll = long long;
vector<ll> res;
ll ant[101];
void init3(){
    //boi so nho nhat cua mot so do 0 va 9
    queue<string> q;
    q.push("9");
    res.push_back(9);
    while(1){//1 la true
        string top = q.front();
        q.pop();
        if(top.length() == 11) break;
        res.push_back(stoll(top + "0"));
        res.push_back(stoll(top + "9"));
        q.push(top+"0");
        q.push(top+"9");
    }
    int cnt = 0;
    for(int i=1; i<=100; i++){
        for(ll x : res){
            if(x%i == 0){
                ant[i] = x;
                ++cnt;
                break;
            }
        }
    }
    cout<<cnt<<endl;//tim xem ham reverse()
}
/*string res[100001];
void init(){
    queue<string> q;
    q.push("1");
    int cnt = 1;
    res[1] = "1";
    while(cnt <= 10111){
        cnt;
        string top = q.front();
        ++cnt;
        res[cnt] = top + "0";
        ++cnt;
        res[cnt] = top + "1";
    }
}
vector<string> re;
void init2(){
    queue<string> q;
    q.push("1");
    re.push_back("1");
    while(re.size() < 10000){
        string top = q.front();
        q.pop();
        re.push_back(top + "0");
        re.push_back(top + "1");
        q.push(top+"0");
        q.push(top+"1");
    }
}*/
int main(){
    init3();
    for(int i=1; i<= 100; i++){
        cout<<i<<" "<<ant[i]<<endl;
    }
    /*init2();
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        for(int i=0; i<n; i++){
            cout<<re[i]<<" ";
        }
        cout<<endl;
    }*/
}