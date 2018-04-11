#include<iostream>
#include"stack"
#include"queue"
using namespace std;
class Tree
{
public:
    char data;
    struct Tree *l,*r;
};
class Bitree
{
private:
    Tree *root;
    void pre(Tree *t);
    void in(Tree *t);
    void post(Tree *t);
    Tree *Bitree::create(string &s,int &pos);
public:
    Bitree()
    {
        root=NULL;
    }
   // Tree *Bitree::searchB(char k,Tree *t);//���ֶ���������
    void createB(string s);//����������
    void preB();//ǰ�����
    void inB();//�������
    void postB();//�������
    void postB1();//�ǵݹ�
    void leve();//�����
};
Tree *Bitree::create(string &s,int &pos)
{
    ++pos;
    Tree *t;
    if(pos>=s.size())
        return NULL;
    else if(s[pos]=='#')//�Ծ���Ϊ��־����Ϊ#��Ϊ��
        t=NULL;
    else {
        t=new Tree;
        t->data=s[pos];
        t->l=create(s,pos);
        t->r=create(s,pos);
    }
    return t;
}
void Bitree::createB(string s)
{
    int pos=-1;
    root=create(s,pos);
}
void Bitree::preB()
{
    pre(root);
    cout<<endl;
}
void Bitree::pre(Tree *t)
{
    if(t!=NULL)
    {
        cout<<t->data<<' ';
        pre(t->l);
        pre(t->r);
    }
}
void Bitree::inB()
{
    in(root);
    cout<<endl;
}
void Bitree::in(Tree *t)
{
    if(t!=NULL)
    {
        in(t->l);
        cout<<t->data<<' ';
        in(t->r);
    }
}
void Bitree::postB()
{
    post(root);
    cout<<endl;
}
void Bitree::post(Tree *t)
{
    if(t!=NULL)
    {
        post(t->l);
        post(t->r);
        cout<<t->data<<' ';
    }
}
void Bitree::postB1()
{
    Tree *p,*rr;
    p=root;
    rr=NULL;
    stack<Tree*>sqstack;
    while(p!=NULL||!sqstack.empty())
    {
        if(p)
        {
            sqstack.push(p);
            p=p->l;
        }
        else
        {
            p=sqstack.top();
            if(p->r!=NULL&&p->r!=rr)
            {
                p=p->r;
                sqstack.push(p);
                p=p->l;
            }
            else
            {
                p=sqstack.top();
                sqstack.pop();
                cout<<p->data<<' ';
                rr=p;
                p=NULL;
            }
        }
    }
    cout<<endl;
}
void Bitree::leve()
{
    if(root==NULL)
        return;
    queue<Tree*>q;
    q.push(root);
    while(!q.empty())
    {
        Tree *t;
        t=q.front();
        q.pop();
        cout<<t->data<<' ';
        if(t->l!=NULL)
            q.push(t->l);
            if(t->r!=NULL)
            q.push(t->r);

    }
    cout<<endl;
}
/*Tree *Bitree::searchB(char k,Tree *t)
{
    Tree *q=root;
    while(q)
    {
        t=q;
        if(q->data==k)
            return t;
        else if(q->data>k)
            q=q->l;
        else
            q=q->r;
    }
    return NULL;
}*/

int main()
{
    Bitree a;
    string s;
    char k;
    Tree *t;
    s="ABD##E#F##C##";
    a.createB(s);
    cout<<"ǰ�����"<<endl;
    a.preB();
     cout<<"�������"<<endl;
    a.inB();
     cout<<"�������"<<endl;
    a.postB();
    cout<<"�ǵݹ�"<<endl;
    a.postB1();
    cout<<"�����"<<endl;
    a.leve();
   /* cout<<"����"<<endl;
    cin>>k;
    a.searchB(k,t);*/
   return 0;
}

