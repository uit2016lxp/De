 #include <stdio.h>
#include <stdlib.h>
struct Student
{
    int num;//���
    int d;//�·�
    int c;//�ŷ�
    int rank;//�ȼ�
    int sum;//�ܷ�
};
typedef struct Student *student;
int rank(student s,int H,int L)
{
    if(s->d<L||s->c<L)//Ӧ��ʧ��
        return 0;
    else if(s->d>=H&&s->c>=H)
        return 4;//һ����
    else if(s->d>=H)
        return 3;//�¾���ʧ��������
    else if(s->d>=s->c)
        return 2;//�ŵ�ȫ������ʤ�ţ�������
    else
        return 1;//ѹ�ߣ�������
}
int compare(const void *a,const void *b)//�����Ĳ������Ƚϴ�С�󷵻�
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
