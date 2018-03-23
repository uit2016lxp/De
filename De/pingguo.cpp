#include<iostream>
using namespace std;
void pingguo(int n)
{
    int i=0,j,h[20],d,t;
    if(n%2!=0)
        cout<<"-1"<<endl;
    else
    {
        for(d=0;d<17;d++)
            for(j=0;j<13;j++)
            {
                if(6*d+8*j==n)
                {
                    h[i]=j;
                    i++;
                }
            }
        for(j=0;j<i;j++)
        {
            if(h[0]<h[j])
        {
            h[0]=h[j];
        }
        }
    d=(n-h[0]*8)/6;
    t=d+h[0];
    printf("%d",t);
    }
}
int main()
{
    int n;
    cin>>n;
    pingguo(n);
    return 0;
}
