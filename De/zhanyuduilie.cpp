#include<iostream>
using namespace std;
class xianxing//���������
{
public:
    void Input(int);//����
    void Output();//���
};
class shunxu:virtual public xianxing//˳�����
{
public:
    void Input();
    void Output();
private:
    int s[3];
};
class lianshi:virtual public xianxing
{
public:
     void Input();
     void Output();
} ;
class zhan:virtual public lianshi
{
public:
    void chushi();//ջ�ĳ�ʼ��
    void Input(int);//��ջ
    void Output();//��ջ
private:
    typedef struct sqstack
    {
        int data;
        struct sqstack *next;
    }*sq;
    sq a;
};
void zhan::chushi()
{
    a=((sq)malloc(sizeof(sqstack)));
    if(a==NULL)
       {
           exit(0);
       }
       a->next=NULL;
}
void zhan::Input(int e)
{
    sq p=(sq)malloc(sizeof(sqstack));
    p->data=e;
    p->next=a->next;
    a->next=p;
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
    void chushi();
    void Input(int);
    void Output();
private:
    typedef struct duil
    {
        int data;
        duil *next;
    }*dui;
    dui a;
};
void duilie::chushi()
{
    a=((dui)malloc(sizeof(duil)));
    if(a==NULL)
    {
        exit(0);
    }
    a->next=NULL;
}
void duilie::Input(int e)
{
    dui p,q;
    p=((dui)malloc(sizeof(duil)));
    a->next=p;
    p->data=e;
    while(p->data!=0)
    {
        q=((dui)malloc(sizeof(duil)));
        p->next=q;
        p=q;
        cin>>p->data;
        p->next=NULL;
    }
}
void duilie::Output()
{
    dui q;
    q=a->next;
    while(q->next!=NULL)
    {
        cout<<q->data<<" ";
        q=q->next;
    }
}
int main()
{
    int x;
    zhan a;
    cout<<"ջ"<<endl;
    a.chushi();
    a.Input(1);
    a.Input(3);
    a.Input(5);
    a.Output();
    cout<<"����,����0����ѭ��"<<endl;
    duilie y;
    cin>>x;
    y.chushi();
    y.Input(x);
    y.Output();
    return 0;
}

