#include<iostream>
using namespace std;
class xianxing
{
public:
    virtual void Input(int)=0;
    virtual void Output()=0;
};
class shunxu:virtual public xianxing
{
public:
    virtual void Input(int)=0;
    virtual void Output()=0;
};
class lianshi:virtual public xianxing
{
public:
    typedef struct sqstack
    {
        int data;
        struct sqstack *next;
    }*sq;
    sq a;
    void Chushi();
};
void lianshi::Chushi()
{
    a=(sq)malloc(sizeof(sqstack));
    if(a==NULL)
    {
        exit(0);
    }
    a->next=NULL;
}
class zhan:virtual public lianshi
{
public:
    void Input(int);
    void Output();

};
void zhan::Input(int e)
{
    sq p;
    p=(sq)malloc(sizeof(sqstack));
    p->data=e;
    while(p->data!=0)
    {
        p->next=a->next;
        a->next=p;
        p=p->next;
        p=(sq)malloc(sizeof(sqstack));
        cin>>p->data;
    }
}
void zhan::Output()
{
   sq p;
   p=a->next;
   while(p!=NULL)
   {
       cout<<p->data<<" ";
       p=p->next;
   }
   cout<<endl;
}
class duilie:virtual public lianshi
{
public:
    void Input(int);
    void Output();
} ;
void duilie::Input(int e)
{
    sq p,q;
    p=((sq)malloc(sizeof(sqstack)));
    a->next=p;
    p->data=e;
    while(p->data!=0)
    {
        q=((sq)malloc(sizeof(sqstack)));
        p->next=q;
        p=q;
        cin>>p->data;
        p->next=NULL;
    }
}
void duilie::Output()
{
    sq q;
    q=a->next;
    while(q->next!=NULL)
    {
        cout<<q->data<<" ";
        q=q->next;
    }
}
int main()
{
    int e;
    zhan f;
    duilie d;
    lianshi *a=&f;
    a->Chushi();
    cout<<"Õ»£º";
    cin>>e;
    a->Input(e);
    a->Output();
    a=&d;
    a->Chushi();
    cout<<"¶ÓÁÐ";
    cin>>e;
    a->Input(e);
    a->Output();
    return 0;
}
