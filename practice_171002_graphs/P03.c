#include<stdio.h>
int T,x[210000],y[210000],x1[210000],y2[210000];
int n,m;
int a[2050],b[2050],c[2050],count[2050];
int tik;
void sort(void){
	int i,tmp;
	for(i=0;i<n;i++)
		a[i]=0;
	for(i=0;i<m;i++)
		a[y[i]]++;
	count[0]=0;
	for(i=1;i<n;i++){
		count[i]=count[i-1]+a[i-1];
	}
	for(i=0;i<m;i++){
		y2[count[y[i]]]=y[i];x1[count[y[i]]]=x[i];
		count[y[i]]++;
	}
		
	for(i=0;i<n;i++)
		a[i]=0;
	for(i=0;i<m;i++)
		a[x1[i]]++;
	count[0]=0;b[0]=0;
	for(i=1;i<=n;i++){
		count[i]=count[i-1]+a[i-1];
		b[i]=count[i];
	}
	for(i=0;i<m;i++){
		y[count[x1[i]]]=y2[i];x[count[x1[i]]]=x1[i];
		count[x1[i]]++;
	}
	return;
}
int bfs(int u){
	int i;
	if(a[u]==1)
		return 0;
	a[u]=1;
	for(i=b[u];i<b[u-1];i++)
		bfs(y[u]);
	if(tik!=n){
		printf("%d ",u+1);
		tik++;
	}
	else
		printf("%d\n",u+1);
	return 0;
}
int main(void){
	int i;
	while(scanf("%d%d",&n,&m)&&!(n==0&&m==0)){
		tik=0;
		for(i=0;i<m;i++){
			scanf("%d%d",&y[i],&x[i]);
			y[i]--;x[i]--;
		}
		sort();
		for(i=0;i<n;i++)
			a[i]=0;
		for(i=0;i<n;i++)
			bfs(i);
	}
	return 0;
}

