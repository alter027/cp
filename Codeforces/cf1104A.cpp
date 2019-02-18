#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n;
	scanf("%d",&n);
	for(int i=9;i>=1;i--){
		if(n%i==0){
			printf("%d\n",n/i);
			while(n){
				printf("%d ",i);
				n-=i;
			}
			break;
		}
	}
	return 0;
} 
