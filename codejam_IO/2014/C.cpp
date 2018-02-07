#include<bits/stdc++.h>
using namespace std;

int ans;
int n,k,d1,d2,t1,t2;
//d -> people on every desk
//t -> number for different kinds of desk
void init(void){
	scanf("%d%d",&n,&k);
	if(n%k){
		d1=n/k;d2=d1+1;
		t2=n%k;t1=k-t2;
	}
	else{
		d2=0;t2=0;
		d1=n/k;t1=k;
	}
 }
void solve(void){
	ans=func(n)/(pow(func(d1),t1)*func(t1)*pow(func(d2),t2)*func(t2));
	if(d1>2)
		ans*=pow(func(d1-1)/2,t1);
	if(d2>2)
		ans*=pow(func(d2-1)/2,t2);
 }
int main(void){
	int T,Case=1;
	int a,b;
	scanf("%d",&T);
	while(T-->0){
		init();
		printf("Case #%d: %d\n",Case++,ans);
	}
	return 0;
}