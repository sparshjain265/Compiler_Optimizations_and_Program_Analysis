#include<stdio.h>
void fun(int x){
printf("xx %d\n",x);
}
void fun1(int x){
printf("yy %d\n",x);
}
int  main(){
int a=110;
int b=220;
int c,c1,d,e;
c = a+b;
c1=b+a;
d=1500+a;
e=a+1500;
printf("Hello World c=%d,c1=%d,d=%d,e=%d\n",c,c1,d,e);
return 1;
}
