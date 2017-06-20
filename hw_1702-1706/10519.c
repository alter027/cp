#include<stdio.h>
int main(void){
	int check[16]={1,1,1,3,3,15,15,9,9,1,1,11,11,15,15,1};
	int tal[3]={11,9,3};
	unsigned long long int num,numi,ans,i,n;
	scanf("%d",&n);
	while(n-->0){
		ans=1;
		long long int level,item,count=0,dig;
		scanf("%lld",&num);
		ans=check[num%16];
		while(num>1){
			num=num/2;
			count=(count+num)%4;
			ans=ans*(check[num%16]); 
		}
		while(count-->0){
			ans=ans*2;
		}
		ans=ans%16;
		printf("%llX\n",ans);
	}
	return 0;
} 
