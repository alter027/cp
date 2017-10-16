#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[200050];
int b[200050],c[100050];
void sort(long long *x,int *y,int n);
int main(void){
	int T;
	scanf("%d",&T);
	int n;
	while(T-->0){
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++){
			scanf("%lld",a+(2*i));
			scanf("%lld",a+(2*i+1));
			b[2*i]=i;b[2*i+1]=i;
		}
		int k,ans=0,overlap=0;
		k=2*n;
		sort(a,b,k);
		for(i=0;i<n;i++)
			c[i]=0;
		for(i=0;i<k;i++){
			if(c[b[i]]==0)
				overlap++;
			else if(c[b[i]]==1)
				overlap--;
			c[b[i]]++;
			if(overlap>ans)
				ans=overlap;
		}
		printf("%d\n",ans);
	}
	return 0;
}
void sort(long long *x,int *y,int n){
	int i=0,j=n/2,k=0;
	if(n<2)
		return;
	long long *p=new long long[n];
	int *q=new int[n];
	sort(x,y,n/2);sort(x+n/2,y+n/2,n-n/2);
	while(i<n/2&&j<n){
		if(x[i]<=x[j]){
			p[k]=x[i];
			q[k++]=y[i++];
		}
		else if(x[j]<x[i]){
			p[k]=x[j];
			q[k++]=y[j++];
		}
	}
	while(i<n/2){
		p[k]=x[i];
		q[k++]=y[i++];
	}
	while(j<n){
		p[k]=x[j];
		q[k++]=y[j++];
	}
	for(i=0;i<n;i++){
		x[i]=p[i];
		y[i]=q[i];
	}
	delete []p;delete []q;
	return;
}
