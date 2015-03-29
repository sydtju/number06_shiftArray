#include<stdio.h>
#include<stdlib.h>
//最大公约数
int gcd(const int length,int offset){
	int offset_temp=0;
	int length_temp=0;
	if (0>=length||0==offset) return 0;
	length_temp=length;
	offset_temp=offset>0?offset:length-offset%length;
	while(length_temp%offset_temp){
		int temp=0;
		temp=offset_temp;
		offset_temp=length_temp%offset_temp;
		length_temp=temp;
	}
	return offset_temp;
}
//最小临时空间  数组移位
int shiftarray(int dat[],const int length,const int offset){
	int i=0,j=0,k=0;
	int last=0;
	if (NULL==dat||length<=0||0==offset){
		return 0;
	}
	j=offset>0?offset:length+offset%length;//统一采用向右移动的方式
	for(i=0;i<gcd(length,offset);i++){
		int temp=dat[i];
		k=i;
		do{
			dat[k]=dat[(k+j)%length];
			last=k;
			k=(k+j)%length;
		}while(i!=k);
		dat[last]=temp;
	}
	return 0;
}
//打印函数
int display(const int dat[],const int length){
	int i=0;
	if(length<=0||NULL==dat) return 0;
	for(;i<length;i++){
		fprintf(stdout,"%d  ",dat[i]);	
	}
		fprintf(stdout,"\n");
		return 0;
}
//测试
int main(int argc,char**argv){
	int dat[10]={0,1,2,3,4,5,6,7,8,9};
	int offset=5;
	display(dat,10);
	shiftarray(dat,10,0);
	display(dat,10);
	shiftarray(dat,10,-2);
	display(dat,10);
	shiftarray(dat,10,2);
	display(dat,10);
	getchar();
	return 0;
}
