#include<stdio.h>
int main(void){
	int ncase;char t;
	scanf("%d%c",&ncase,&t);
	while(ncase-->0){
		int a;
		char c,n;
		scanf("%c%c%d%c",&c,&n,&a,&n);
		if(c>='a')
			a+='a'-c-1;	
		else
			a+=c-'A'+1;
		printf("%d\n",a);
	}
	return 0;
}
