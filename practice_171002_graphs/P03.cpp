#include<stdio.h>
int T,x[210000],y[210000],x1[210000],y1[210000],count[2050],a[2050],b[2050],c[2050],stack[2050],n,m;
using namespace std;
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
		y1[count[y[i]]]=y[i];x1[count[y[i]]]=x[i];
		count[y[i]]++;
	}
	
/*	printf("\n");
	for(i=0;i<m;i++){
		printf("%d %d\n",x1[i]+1,y1[i]+1);
	}
	printf("\n");
*/	
		
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
		y[count[x1[i]]]=y1[i];x[count[x1[i]]]=x1[i];
		count[x1[i]]++;
	}
	return;
}
int bfs(int n){
	if(a[n]!=0)
		return 0;
	if(c[n]==-1){
		c[n]=0;
	}
	int i,p=(c[n]+1)%2;
	for(i=b[n];i<b[n+1];i++){
		if(c[y[i]]==-1)
			c[y[i]]=p;
		else if(c[y[i]]!=p){
			printf("y[i]=%d\n",y[i]);
			return 1;
		}
	}
	int flag=0;
	for(i=b[n];i<b[n+1];i++){
		a[y[i]]=1;
		flag=bfs(y[i]);
			if(flag==1){
				return 1;
			}
	}
	return 0;
}
int main(void){
	int n,m;
	while(scanf("%d%d",&n,&m)&&!(n==0&&m==0)){
		for(i=0;i<m;i++){
			scanf("%d%d",&y[i],&x[i]);
		}
	}
	return 0;
}
