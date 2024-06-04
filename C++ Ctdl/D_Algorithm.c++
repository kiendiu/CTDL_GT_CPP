#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
//cmp de so sanh 
bool cmp(int a, int b){
    return abs(a)<abs(b);
}
int main(){
    //min nhiều số phải dùng ngoặc nhọn
    cout<<min(10, 20)<<'\n';
    cout<<min({10, 3, 4, 56})<<endl;
    //min trong một mảng : trả về vị trí giá trị nhỏ nhất 
    //nếu muốn trả về giá trị thêm con trỏ * vào đầu min 
    int a[5] = {1, 2, 3, 4, 5};
    cout<< *min_element(a, a+5);
    //tính tổng giá trị của mảng và vector 
    cout<<accumulate(a, a+5, 0)<<endl;
    //sort: sắp xếp lại các phần tử theo thứ tự tăng dần 
    sort(a, a+5);
    sort(a, a+5, greater<int>());//nhỏ hơn
    stable_sort(a, a+5, cmp);
    //hàm tìm kiếm
    auto it = find(a, a+5, 3);
    if(it == a+5){
        cout<<"not found";
    }else cout<<"found";
    //binary_search: dungf khi mang da xap sep( boolean )
    if(binary_search(a, a+5, 2) == true){
        cout<<"found";
    }
    //memset gan gia tri cho cac phan tu cua mang bang 0 hoac 1
    //memset chi dung mang ko dung vector
    memset(a, 0, sizeof(a));
    fill(a, a+5, 10);
    //trộn hai mảng tang dần vào 
    vector<int> b = {1, 2, 3, 4};
    vector<int> c = {1, 2, 5, 10};
    vector<int> res(8);
    merge(b.begin(), b.end(), begin(c), end(c), res.begin());
    //ham dao nguoc
    reverse(a, a+5);
    string s;
    cin>>s;
    reverse(begin(s), end(s));
    //thao tác của tập hợp set
    /*
    set_union: hop hai mang
    set_intersection:giao hai mang
    set_diference: co cua mang dau khong co cua mang sau
    set_symmetric_diference: khong lay nhung cai tring nhau
    bên trong giống nhau
    */
   int d[] = {1, 4, 5, 6};
    vector<int> u(11);
    set_union(a, a+5, d, d+4, u.begin());
    video tiep theo la 20
}