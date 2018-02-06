#include<bits/stdc++.h>
using namespace std;

map<int ,int>M;
map<int ,int>::iterator iter;
int P[202];
int N,ans;

void init(void){
	M.clear();
	int i;
	scanf("%d",&N);
	for(i=0;i<N*2;i++){
		scanf("%d",&P[i]);
		iter=M.find(P[i]);
		if(iter!= M.end())//do find A
		   M[P[i]]++;
		else//do not find A
		   M[P[i]]=1;
	}
 }
void solve(){
	int i=0,j=0;
	long long tmp;
	for(j=0;j<2*N;j++){
		if(M[P[j]]==0)
			continue;
		printf("%d ",P[j]);
		tmp=((long long)P[j]*4)/3;
		M[P[j]]--;M[tmp]--;i++;
	}
 }
int main(void){
	int T,Case=1;
	int a,b;
	scanf("%d",&T);
	while(T-->0){
		printf("Case #%d: ",Case++);
		init();
		solve();
		printf("\n");
	}
	return 0;
}