#include <iostream>
using namespace std;
struct Node
{
    int du_lieu;
    Node *next;
};
struct List
{
    Node *head;
    Node *tail;
};
void khoitaoList(List &list)
{
    list.head = NULL;
    list.tail = NULL;
}
Node *khoitaoNode(int du_lieu)
{
    Node *node = new Node;
    node->du_lieu = du_lieu;
    node->next = NULL;
    return node;
}
void themHead(List &list, Node *p)
{
    if (list.head == NULL)
    {
        list.head = list.tail = p;
    }
    else
    {
        p->next = list.head;
        list.head = p;
    }
}
void themTail(List &list, Node *p)
{
    if (list.head == NULL)
    {
        list.head = list.tail = p;
    }
    else
    {
        list.tail->next = p;
        list.tail = p;
    }
}
void nhapList(List &list, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Du lieu node " << i + 1 << " : ";
        cin >> x;
        Node *p = khoitaoNode(x);
        themTail(list, p);
    }
}
void xuatList(List list)
{
    if (list.head != NULL)
    {
        Node *node = list.head;
        while (node != NULL)
        {
            cout << node->du_lieu << ' ';
            node = node->next;
        }
    }
}
Node *timNode(List list, int x)
{
    Node *node = list.head;
    while (node != NULL && node->du_lieu != x)
        node = node->next;
    if (node != NULL)
        return node;
    return NULL;
}
void xoaNode(List &list, int x)
{
    Node *p = list.head;
    if (p == NULL){
        cout << "Danh sách rỗng!!";
    }
    else{
        Node *pPre = NULL;
        while (p != NULL){
            if (p->du_lieu == x)
            {
                break;
            }
            pPre = p;
            p = p->next;
        }
        if (p == NULL){
            cout << "Không tìm thấy số cần xóa";
        }
        else{
            if (p == list.head){
                list.head = list.head->next;
                p->next = NULL;
                delete p;
                p = NULL;
            }
            else if (p->next == NULL){
                list.tail = pPre;
                pPre->next = NULL;
                delete p;
                p = NULL;
            }
            else{
                pPre->next = p->next;
                p->next = NULL;
                delete p;
                p = NULL;
            }
        }
    }
}
int main()
{
    List list;
    khoitaoList(list);
    int n;
    cout << "nhap so luong node: ";
    cin >> n;
    nhapList(list, n);
    xuatList(list); cout<<endl;
    int x;
    cout<<"nhap gia tri node can tim: "; cin>>x;
    timNode(list, x);
    int a;
    cout<<"nhap gia tri can xoa: "; cin>>a;
    xoaNode(list, a);
    xuatList(list);
    return 0;
}