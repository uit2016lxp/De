#include <stdio.h>
#include <stdlib.h>
#define m 100

struct ptree//定义二叉树结点类型
{
    int w;               //定义结点权值
    struct ptree *lchild;//定义左子结点指针
    struct ptree *rchild;//定义右子结点指针
};

struct pforest//定义链表结点类型
{
    struct pforest *link;
    struct ptree *root;
};

int WPL=0;
struct ptree *hafm();
void travel();
struct pforest *inforest(struct pforest *f,struct ptree *t);

void travel(struct ptree *head,int n)
{
//遍历
    struct ptree *p;
    p=head;
    if(p!=NULL)
    {
         if((p->lchild)==NULL && (p->rchild)==NULL) //如果是叶子结点
        {
              printf("%d ",p->w);
              printf("the hops of the node is: %d\n",n);
              WPL=WPL+n*(p->w);    //计算权值
        }
        travel(p->lchild,n+1);
        travel(p->rchild,n+1);
    }
}
struct ptree *hafm(int n, int w[m])
{
    struct pforest *p1,*p2,*f;
    struct ptree *ti,*t,*t1,*t2;
    int i;
    f=(pforest *)malloc(sizeof(pforest));
    f->link=NULL;
    for(i=1;i<=n;i++)          //产生n棵只有根结点的二叉树
    {
        ti=(ptree*)malloc(sizeof(ptree));//开辟新的结点空间
        ti->w=w[i];               //给结点赋权值
        ti->lchild=NULL;
        ti->rchild=NULL;
        f=inforest(f, ti);
       //按权值从小到大的顺序将结点从上到下地挂在一颗树上
    }
    while(((f->link)->link)!=NULL)//至少有二棵二叉树
    {
        p1=f->link;
        p2=p1->link;
        f->link=p2->link;           //取出前两棵树
        t1=p1->root;
        t2=p2->root;
        free(p1);
        free(p2);
        t=(ptree *)malloc(sizeof(ptree));
        t->w = (t1->w)+(t2->w);         //权相加
        t->lchild=t1;
        t->rchild=t2;             //产生新二叉树
        f=inforest(f,t);
    }
    p1=f->link;
    t=p1->root;
    free(f);
    return(t);
    }

pforest *inforest(struct pforest *f,struct ptree *t)
{
    struct pforest *p, *q, *r;
    struct ptree *ti;
    r=(pforest *)malloc(sizeof(pforest)); //开辟新的结点空间
    r->root=t;
    q=f;
    p=f->link;
    while (p!=NULL)
 {
   ti=p->root;
   if(t->w > ti->w)//如果t的权值大于ti的权值
     {
         q=p;
        p=p->link;
    }
   else
      p=NULL;
  }
    r->link=q->link;
    q->link=r;
    return(f);
    }

void InPut(int &n,int w[m])
{
    printf("节点数\n"); //结点数
    scanf("%d",&n);      //输入结点数
    printf ("节点权值\n"); //每个结点的权值
    for(int i=1;i<=n;i++)
    scanf("%d",&w[i]);  //输入每个结点权值
}

int main( )
{
    struct ptree *head;
    int n,w[m];
    InPut(n,w);
    head=hafm(n,w);
    travel(head,0);
    printf("The length of the best path is WPL=%d", WPL);//输出最佳路径权值之和
    return 0;
}
