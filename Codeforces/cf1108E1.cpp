#include<bits/stdc++.h>
using namespace std;
int n,m,a[302],c1[302],c2[302],b[302],ans,cnt=0,total;
void tri(int k){
	int tmp=0;
	for(int i=0;i<n;i++) b[i]=a[i];
	for(int i=0;i<m;i++){
		if(!(c1[i]<=k+1&&k+1<=c2[i])){
			for(int j=c1[i]-1;j<c2[i];j++) b[j]--;
			tmp++;
		}
	}
	int x=b[0],y=b[0];
	for(int i=0;i<n;i++) x=min(x,b[i]),y=max(y,b[i]);
	if(y-x>cnt) cnt=y-x,ans=k,total=tmp;
	return;
}
void final(int k){
	printf("%d\n%d\n",cnt,total);
	for(int i=0;i<n;i++) b[i]=a[i];
	for(int i=0;i<m;i++){
		if(!(c1[i]<=k+1&&k+1<=c2[i])) printf("%d ",i+1);
	}
	printf("\n");
	return;
}
int main(void){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<m;i++) scanf("%d%d",&c1[i],&c2[i]);
	for(int i=0;i<n;i++) tri(i);
	final(ans);
	return 0;
}
