#include<bits/stdc++.h>
using namespace std;

int ans;

void solve(){
	int i,n,arr[55]={0},input;
	scanf("%d",&n);
	for(i=0;i<n+1;i++)
		scanf("%d",&input);
	if(n%2)
		printf("1\n0.0\n");
	else
		printf("0\n");
 }
int main(void){
	int T,Case=1;
	int a,b;
	scanf("%d",&T);
	while(T-->0){
		printf("Case #%d: ",Case++);
		solve();
	}
	return 0;
 }