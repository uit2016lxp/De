#include<stdio.h>
int main()
{
    int x,m,i,j,l;
    float s[3][100],t,w=0,u=0;
    printf("请输入需要的月饼种类：");
    scanf("%d",&x);
    printf("请输入需要的市场额度：");
    scanf("%d",&m);
    for(i=0;i<2;i++)
        for(j=0;j<x;j++)
            scanf("%f",&s[i][j]);
    for(i=0;i<x;i++)
        s[2][i]=s[1][i]/s[0][i];
    for(j=0;j<x-1;j++)
        for(i=0;i<x-1-j;i++)
            if(s[2][i]<s[2][i+1])
                for(l=2;l>=0;l--)
                {
                    t=s[l][i];
                    s[l][i]=s[l][i+1];
                    s[l][i+1]=t;
                }

    i=0;
    while(u<m)
	{
		w+=s[1][i];
		u+=s[0][i];
		i++;
	}
	w=w-(u-m)*s[2][i-1];
	printf("%.2f",w);
	return 0;
}
