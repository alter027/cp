#include<bits/stdc++.h>
using namespace std;

int ans;
int B[1003];

void solve(){
	int n;
	string s;
	cin>>n>>s;
	int i,j,t,tmp;
	for(i=0,t=0;i<n;i++){
		tmp=0;
		for(j=0;j<8;j++,t++){
			if(s[t]=='I')
				tmp=tmp*2+1;
			else if(s[t]=='O')
				tmp=tmp*2;
		}
		printf("%c",tmp);
	}
 }
int main(void){
	int T,Case=1;
	int a,b;
	scanf("%d",&T);
	while(T-->0){
		printf("Case #%d: ",Case++);
		solve();
		printf("\n");
	}
	return 0;
}