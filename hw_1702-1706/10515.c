#include<stdio.h>
#include<stdlib.h>
int *cross(int *s1,int *s2,int state,int n1,int n2,int *memory);
int *ans,num,*s1,*s2;
int *cross(int *s1,int *s2,int n,int m);
int *mid_item(int *l1,int *h1,int n1,int n2);
int *combi(int *a1,int *a2,int *a3,int n,int m);
int *for_loop(int *s1,int *s2,int n,int m);
void print_(int n,int *ans){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
}
int main(void){
	int time,i,*ans;
	scanf("%d",&time);
	while(time-->0){
		scanf("%d",&num);
		s1=(int *)malloc(sizeof(int)*num);
		s2=(int *)malloc(sizeof(int)*num);
		for(i=0;i<num;i++){scanf("%d",&s1[i]);}
		for(i=0;i<num;i++){scanf("%d",&s2[i]);}
		ans=cross(s1,s2,num,num);//2*num-1;
		print_(2*num-1,ans);
	}
	return 0;
}
int *cross(int *s1,int *s2,int n,int m){
	if(n<=32||m<=32){
		return for_loop(s1,s2,n,m);
	}
//	while(1){
	int *l1=s1,*h1=s1+n/2,*l2=s2,*h2=s2+m/2;
	int *m1,*m2,*a1,*a2,*a3,*a4;
	m1=mid_item(l1,h1,n/2,n-n/2);//n-n/2
	m2=mid_item(l2,h2,n/2,m-n/2);//m-m/2
	a1=cross(l1,l2,n/2,n/2);
	a2=cross(h1,h2,n-n/2,m-n/2);
	if(n>m)
		a3=cross(m1,m2,n-n/2,n/2);
	else
		a3=cross(m1,m2,n-n/2,m-n/2);
	a4=combi(a1,a2,a3,n,m);
	free(m1);free(m2);free(a1);free(a2);free(a3);
//	}
	return a4;
}
int *mid_item(int *l1,int *h1,int n1,int n2){
	int i,*m;
	if(n1>=n2){
		m=(int *)malloc(sizeof(int)*n1);
		for(i=0;i<n2;i++)
			m[i]=l1[i]+h1[i];
		for(i=n2;i<n1;i++)
			m[i]=l1[i];
	}
	else{
		m=(int *)malloc(sizeof(int)*n2);
		for(i=0;i<n1;i++)
			m[i]=l1[i]+h1[i];
		for(i=n1;i<n2;i++)
			m[i]=h1[i];
	}
	return m;
}
int *combi(int *a1,int *a2,int *a3,int n,int m){
	int i,j;
	int d1,d2,d3,state=n/2;
	if(n>m){
		d1=(n/2)*2-1;
		d2=n-n/2+m-n/2-1;
		d3=n-1;
	}
	else{
		d1=(n/2)*2-1;
		d2=n-n/2+m-n/2-1;
		d3=n-n/2+m-n/2-1;
	}
	int *a4=(int *)malloc(sizeof(int)*(n+m-1));
	for(i=0;i<n+m-1;i++)
		a4[i]=0;
	for(i=0;i<d1;i++){
		a4[i]=a4[i]+a1[i];
		a4[state+i]=a4[state+i]-a1[i];
	}
	for(i=0;i<d2;i++){
		a4[state*2+i]=a4[state*2+i]+a2[i];
		a4[state+i]=a4[state+i]-a2[i];
	}
	for(i=0;i<d3;i++){
		a4[state+i]=a4[state+i]+a3[i];
	}
	return a4;
}
int *for_loop(int *s1,int *s2,int n,int m){
	int i,j;
	int *ans=(int *)malloc(sizeof(int)*(n+m-1));
	for(i=0;i<n+m-1;i++)
		ans[i]=0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			ans[i+j]=ans[i+j]+s1[i]*s2[j];
		}
	}
	return ans;
}
