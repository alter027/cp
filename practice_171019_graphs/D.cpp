#include<bits/stdc++.h>
using namespace std;
int main(void){
	long long n,i,num[10]={0},k;
	scanf("%lld",&n);
	k=n;
	for(i=9;i>1;i--){
		while(n%i==0){
			num[i]++;
			n/=i;
		}
	}
	if(n>1)
		printf("-1\n");
	else if(k==1)
		printf("1\n");
	else{
		for(i=2;i<=9;i++){
			while(num[i]-->0)
				printf("%lld",i);
		}
		printf("\n");
	}
	return 0;
}