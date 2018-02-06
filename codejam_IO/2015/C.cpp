#include<bits/stdc++.h>
using namespace std;

int ans,n;
int solve(int k){
	int i;
	double a=0;
	for(i=9000;i>0;i-=k)
		a+=log10(i);
	return (int)ceil(a);
 }
int main(void){
	int T,Case=1;
	int a,b;
	scanf("%d",&T);
	while(T-->0){
		scanf("%d",&n);
		if(n<5)
			printf("Case #%d: ...\n",Case++);
		else{
			int l=1,r=8999,mid,e;
			while(l<=r){
				mid=(l+r)/2;
				e=solve(mid);
				if(e<n)
					r=mid-1;
				else
					l=mid+1;
			}
			printf("Case #%d: IT'S OVER 9000",Case++);
			for(int i=0;i<l;i++)
				printf("!");
			printf("\n");
		}
	}
	return 0;
}