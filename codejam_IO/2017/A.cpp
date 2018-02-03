#include<bits/stdc++.h>
using namespace std;

int ans;
int F,S;
int N[100][100],C[100],R[100];

void init(void){
	scanf("%d%d",&F,&S);
	int i,j;
	for(i=0;i<S;i++){
		C[i]=0;R[i]=0;
		for(j=0;j<S;j++)
			N[i][j]=0;
	}
	ans=0;
 }
void tri(int a,int b){
	if(N[a][b]==0){
		N[a][b]=1;
		C[a]++;
		R[b]++;
		if(C[a]>ans)
			ans=C[a];
		if(R[b]>ans)
			ans=R[b];
	}
}
int main(void){
	int T,Case=1;
	int a,b;
	scanf("%d",&T);
	while(T-->0){
		init();
		while(F-->0){
			scanf("%d%d",&a,&b);
			a--;b--;
			tri(a,b);
			tri(b,a);
		}
		printf("Case #%d: %d\n",Case++,ans);
	}
	return 0;
}
