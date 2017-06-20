#include<stdio.h>
#include<stdlib.h>
int main(void){
	int ncase,**f,i,j;
	f=(int **)malloc(sizeof(int *)*30);
	for(i=0;i<30;i++)
		f[i]=(int *)malloc(sizeof(int)*50000);
	scanf("%d",&ncase);
	while(ncase-->0){
		int n,n1,q,level=1,k,x,ans;
		scanf("%d %d",&n,&q);
		n1=n;
		while(n1>0){
			level++;
			n1/=2;
		}
		for(i=0;i<n;i++){
			scanf("%d",&f[0][i]);
//			printf("%d ",f[0][i]);
		}
//		printf("\n");
		for(i=1;i<30;i++){
			for(j=0;j<n;j++){
				f[i][j]=f[i-1][f[i-1][j]-1];
//				printf("%d ",f[i][j]);
			}
//			printf("\n");
		}
		while(q-->0){
			scanf("%d %d",&k,&x);i=0;
//			printf("4");
			if(k==0){
				printf("%d\n",x);
				continue;
			}
			while(k>0){
				if(k%2==0);
				else if(k%2==1){
					ans=f[i][x-1]-1;
					i++;k=k/2;break;
				}
				i++;k=k/2;
			}
//			printf("4.5");
			while(k>0){
				if(k%2==0);
				else if(k%2==1)
					ans=f[i][ans]-1;
				i++;k=k/2;
//				printf("k=%d\n",k);
			}
			printf("%d\n",ans+1);
		}
	}
	return 0;
}
