#include<stdio.h>
int main()
{
    int name[1000][20];
    int num[1000][20];
    int grade[1000];
    int na=0;
    int ca=0;
    int ni=0;
    int ci=0;
    int n,i;
    printf("请输入学生的人数");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("请输入第%d个学生的姓名，学号，成绩：",i+1);
        scanf("%s %s %d",name[i],num[i],&grade[i]);
        if(grade[i]>=na)
        {
            na=grade[i];
            ca=i;
        }
        if(grade[i]<=ni)
        {
            ni=grade[i];
            ci=i;
        }
    }
    printf("%s %s %d\n",name[ca],num[ca],grade[ca]);
    printf("%s %s  %d\n",name[ci],num[ci],grade[ci]);
    return 0;

}
