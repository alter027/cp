#include<stdio.h>
#include<stdlib.h>
long long int cut(int *p,int n);
int main(void){
	int ncase,i,n;
	long long int num;
	scanf("%d",&ncase);
	while(ncase-->0){
		scanf("%d",&n);
		int *s=(int *)malloc(sizeof(int)*n);
		for(i=0;i<n;i++){
			scanf("%d",&s[i]);
		}
		num=cut(s,n);
		printf("%lld\n",num);
		free(s);
	}
	return 0;
}
long long int cut(int *p,int n){
	int i=0,j=n/2,k=0;
	long long int num=0;
	if(n<2)
		return 0;
	num=num+cut(p,n/2);
	num=num+cut(p+n/2,n-n/2);
	int *q=(int *)malloc(n*sizeof(int));
	while(i<n/2&&j<n){
		if(p[i]<=p[j]){
			q[k++]=p[i++];
		}
		else if(p[j]<p[i]){
			num=num+(n/2-i);
//			printf("n/2=%d,i=%d,num=%d\n",n/2,i,num);
			q[k++]=p[j++];
		}
	}
	while(i<n/2)
		q[k++]=p[i++];
	while(j<n)
		q[k++]=p[j++];
	for(i=0;i<n;i++)
		p[i]=q[i];
	free(q);
	return num;
}
