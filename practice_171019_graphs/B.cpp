#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n,x,date[1000000];
	scanf("%d %d",&n,&x);
	int d,s;
	int i,ans=0;
	for(i=1;i<1000000;i++){
		date[i]=0;
	}
	while(n-->0){
		scanf("%d %d",&d,&s);
		date[d+s]++;
	}
	for(i=1;i<1000000;i++){
		if(date[i]==x)
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}