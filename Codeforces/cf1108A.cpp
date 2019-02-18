#include<bits/stdc++.h>
using namespace std;
int main(void){
	int a,b,c,d,n;
	int x,y;
	scanf("%d",&n);
	while(n-->0){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a>c) y=c,x=a;
		else x=a,y=max(c,a+1);
		printf("%d %d\n",x,y);
	}
	return 0;
}
