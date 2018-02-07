#include<bits/stdc++.h>
using namespace std;

int ans;
int A,B,a,b,Y;
void init(void){
	scanf("%d%d%d%d%d",&A,&B,&a,&b,&Y);
 }
void solve(){
	int tmp;
	int gre,acr,bou;
	while(Y--){
		gre=min(A,B);
		gre*=2;gre/=100;
		acr=(gre*a)/100;
		bou=(gre*b)/100;
		gre-=(acr+bou);
		A-=A/100;A+=acr+gre/2;
		B-=B/100;B+=bou+gre-gre/2;
	}
 }
int main(void){
	int T,Case=1;
	int a,b;
	scanf("%d",&T);
	while(T-->0){
		init();
		solve();
		printf("Case #%d: %d %d\n",Case++,A,B);
	}
	return 0;
}