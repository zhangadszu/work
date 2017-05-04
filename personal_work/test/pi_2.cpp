#include<iostream>
#include <stdio.h>
using namespace std;
//用级数编程计算圆周率(C++)
int main(void)
{
    long b=1000,c=200,d=0,e,f,i=0,N;
    cout<<"请输入圆周率位数(不超过100000)\n",cin>>N,N=N*10/3+20;
    long *a=new long[N+1];
    while(i<N)a[i++]=c;
    for(;(N-=10)>0;printf("%03ld",d+=(c+=e/b)/b),d=c%b,c=e%b)
        for(e=0,i=N;--i;a[i]=(e+=a[i]*b)%(f=i*2+1),e=e/f*i);
    delete []a,cin.ignore(),cin.ignore();
    return 0;
}
