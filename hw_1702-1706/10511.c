#include<stdio.h>
int main(void){
	int n,m,i,f[5],check,count;
	while(scanf("%d",&n)!=EOF&&n!=0){
		int v[5]={0};
		check=1;count=0;
		for(i=0;i<n;i++){
			scanf("%d",&f[i]);
			if(f[i]==i+1)
				v[i]=1;
		}
		for(i=0;i<n;i++){
			if(v[f[i]-1]==0){
				check=0;
				break;
			}
		}
		if(check==1)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
