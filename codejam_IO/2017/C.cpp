#include<bits/stdc++.h>
using namespace std;

int D,N;

void dealm(int n,int m){
	int i;
	if(n>0)
		printf("/");
	else
		printf("O");
	for(i=0;i<m;i++)
		printf("/");
	for(i=m;i<13;i++)
		printf("O");
	if(n>1)
		printf("/");
	else
		printf("O");
	printf("\n");
}
void solve(void){
	int i;
	int k,l,m,n;
	k=N/41;
	l=N%41;
	m=l/3;
	n=l%3;
	int k1=k;
	while(k){
		if(k>0){
			printf("OOOOOOOOOOOOOOO\n");
			printf("///////////////\n");
			k--;
		}
		else
			break;
		if(k>0){
			printf("IIIIIIIIIIIIIII\n");
			printf("///////////////\n");
			k--;
		}
		else
			break;
	}
	if(k1%2==0){
		printf("OOOOOOOOOOOOOOO\n");
		if(l>0){
			dealm(n,m);
			printf("IIIIIIIIIIIIIII\n");
		}
	}
	else{
		printf("IIIIIIIIIIIIIII\n");
		if(l>0){
			dealm(n,m);
			printf("OOOOOOOOOOOOOOO\n");
		}
	}
}

int main(void){
	int T,Case=1;
	scanf("%d",&T);
	while(T-->0){
		printf("Case #%d:\n",Case++);
		scanf("%d%d",&D,&N);
		solve();
	}
	return 0;
}