#include<stdio.h>
#include<stdlib.h>
//绝对值的最大公约数
int absgcd(int m,int n){
	int temp=0;
	m=m>0?m:-m;
	n=n>0?n:-n;
	while(m%n){
		temp=n;
		n=m%n;
		m=temp;
	}
	return n;
}
//移位函数
