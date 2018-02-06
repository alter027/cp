#include<bits/stdc++.h>
using namespace std;

int ans;
int d,k,n;

void init(void){
	scanf("%d%d%d",&d,&k,&n);
 }
int solve(int k,int n,int t){
	k+=n*t;
	while(k>d)
		k-=d;
	while(k<1)
		k+=d;
	return k;
 }
int main(void){
	int T,Case=1;
	int a,b;
	scanf("%d",&T);
	while(T-->0){
		printf("Case #%d: ",Case++);
		init();
		int t,tmp;
		t=(k%2)?1:-1;
		tmp=solve(k,n,t);
		printf("%d %d",solve(tmp+1,n,t),solve(tmp-1,n,t));
		printf("\n");
	}
	return 0;
}