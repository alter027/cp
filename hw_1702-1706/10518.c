#include<stdio.h>
int s[25],n,base;
int fac(unsigned long long int num);
int find(int div);
int fac_before(int i);
int main(void){
	int i,ncase;
	unsigned long long int num;
	scanf("%d",&ncase);
	while(ncase-->0){
		scanf("%d",&n);
		scanf("%llu",&num);
		for(i=0;i<25;i++)
			s[i]=0;
		printf("(");
		fac(num-1);
		printf(")\n");
	}
	return 0;
}
int fac(unsigned long long int num){
	int i=1,div;
	unsigned long long int cmp=1;
	while(i<=20){
		cmp=cmp*i;
		if(num<=cmp){
			base=fac_before(i);
			break;
		}
		i++;
	}
	if(i==21){
		i--;
		base=fac_before(i);
	}
	while(i>0){
		if(i!=n){
			div=num/cmp;
			find(div+1);
			num=num-cmp*(div);
		}
		else if(i==n)
			base=1;
		cmp=cmp/(i--);
	}
	for(i=0;s[i]!=0;i++);
	printf("%d",base+i);
	return 0;
}
int find(int div){
	int i=0,count=0;
	while(count<div){
		if(s[i]==0)
			count++;
		i++;
	}
	i--;
	s[i]=1;
	printf("%d,",base+i);
}
int fac_before(int i){
		int j;
		for(j=1;j<=n-i-1;j++){
			printf("%d,",j);
	}
	return n-i;
}
