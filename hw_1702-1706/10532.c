#include<stdio.h>
#include<stdlib.h>
int n;
int long_seq(int *a1,int *l1);
int main(void){
	int ncase,*a1,*a2,*l1,*l2;
	a1=(int *)malloc(sizeof(int)*100000);
	a2=(int *)malloc(sizeof(int)*100000);
	l1=(int *)malloc(sizeof(int)*100000);
	l2=(int *)malloc(sizeof(int)*100000);
	scanf("%d",&ncase);
	while(ncase-->0){
		int i,ans=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a1[i]);
			a2[n-i-1]=a1[i];
		}
		long_seq(a1,l1);
		long_seq(a2,l2);
/*		for(i=0;i<n;i++)
			printf("%d ",l1[i]);
		printf("\n");
		for(i=0;i<n;i++)
			printf("%d ",l2[n-1-i]);
		printf("\n");
*/		for(i=0;i<n;i++){
			if(l1[i]+l2[n-1-i]>ans&&l1[i]!=0&&l2[n-1-i]!=0)
				ans=l1[i]+l2[n-1-i];
		}
		if(ans==0)
			printf("0\n");
		else
			printf("%d\n",ans+1);
	}
	return 0;
}
int long_seq(int *a1,int *l1){
//	printf("long_seq\n");
	int *n1=(int *)malloc(sizeof(int)*n);
	int i,j,count=1,num;
	n1[0]=a1[0];l1[0]=0;
	for(i=1;i<n;i++){
		int c1=count,base=-1,top=count;
		while((base+top)/2!=base){
			num=(base+top)/2;
//			printf("base=%d\n",base);
			if(n1[num]<a1[i]){
				top=num;
			}
			else if(n1[num]>a1[i]){
				base=num;
			}
			else if(n1[num]==a1[i]){
				top=num;base=num;
				break;
			}
			if(base==-1&&top==0)
				break;
		}
		num=base;
		if(num==-1&&a1[i]>n1[0]){
			n1[0]=a1[i];
			l1[i]=0;
		}
		else if(num==count-1&&a1[i]<n1[num]){
			n1[num+1]=a1[i];
			l1[i]=num+1;
			count++;
		}
		else if(n1[num]==a1[i]){
			l1[i]=num;
		}
		else if(n1[num]>a1[i]){
			l1[i]=num+1;
			n1[num+1]=a1[i];
		}
/*		for(j=0;j<count;j++)
			printf("%d ",n1[j]);
		printf("\n");
		printf("l1[%d]=%d,num=%d,count=%d\n",i,l1[i],num,count);
*/	}
}




