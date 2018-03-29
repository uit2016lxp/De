 #include <stdio.h>
#include <stdlib.h>
struct Student
{
    int num;//编号
    int d;//德分
    int c;//才分
    int rank;//等级
    int sum;//总分
};
typedef struct Student *student;
int rank(student s,int H,int L)
{
    if(s->d<L||s->c<L)//应考失败
        return 0;
    else if(s->d>=H&&s->c>=H)
        return 4;//一类生
    else if(s->d>=H)
        return 3;//德尽才失，二类生
    else if(s->d>=s->c)
        return 2;//才德全亡，德胜才，三类生
    else
        return 1;//压线，第四类
}
int compare(const void *a,const void *b)//函数的参数，比较大小后返回
{
    student s1=*(student*)a;
    student s2=*(student*)b;
    if(s1->rank!=s2->rank)
        return s1->rank-s2->rank;
    else if(s1->sum!=s2->sum)
        return s1->sum-s2->sum;
    else if(s1->d!=s2->d)
        return s1->d-s2->d;
    else if(s1->num!=s2->num)
        return s2->num-s1->num;
    else
        return 0;
}

int main()
{
    int N, L, H, M = 0,i;
    student stu[100000];

    scanf("%d %d %d", &N, &L, &H);
    for( i = 0; i < N; i++)
    {
        student s = (student)malloc(sizeof(struct Student));
        scanf("%d %d %d", &s->num, &s->d, &s->c);
        s->sum = s->d + s->d;
        if((s->rank = rank(s, H, L)))
            stu[M++] = s;
        else
            free(s);
    }

    qsort(stu, M, sizeof(student), compare);

    printf("%d\n", M);
    for(i = M - 1; i >= 0; i--)
        printf("%d %d %d\n", stu[i]->num, stu[i]->d, stu[i]->c);

    for(i = 0; i < M; i++) free(stu[i]);
    return 0;
}
