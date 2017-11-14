#include<cstdio>
int arr[55];
int main(void){
	int v,T;
	int x[1005],y[1005],ans[1005];
	scanf("%d",&T);
	for(v=1;v<=T;v++){
		int i,j,n,a,b;
		scanf("%d",&n);
		for(i=0;i<55;i++)
			arr[i]=0;
		for(i=0;i<n;i++){
			scanf("%d%d",&a,&b);
			x[i]=a;y[i]=b;
			arr[a]++;arr[b]++;
		}
		int flag=0;
		for(i=0;i<55;i++){
			if(arr[i]&1){
				printf("@1");
				flag=1;
				break;
			}
		}
		printf("Case #%d\n",v);
		if(flag==0){
			int count=0,dik=x[0],pic;
			while(count<n-2){
				for(i=0;i<n;i++){
					if(x[i]==dik||y[i]==dik){
						pic=i;
						break;
					}
				}
				ans[count++]=dik;
				if(x[pic]==dik)
					dik=y[pic];
				else
					dik=x[pic];
				if(dik==-1){
					printf("@2 pic=%d\n",pic);
					flag=1;
					break;
				}
				x[pic]=-1;y[pic]=-1;
			}
			printf("%d %d\n",n,count);
		}
		for(i=0;i<n;i++)
			printf("%d %d\n",x[i],y[i]);
		printf("\n");
		if(flag==1){
			printf("some beads may be lost\n");
		}
		else{
			for(i=0;i<n-1;i++){
				printf("%d %d\n",ans[i],ans[i+1]);
			}
			printf("%d %d\n",ans[n-1],ans[0]);
		}
		if(T!=v)
			printf("\n");
	}
	return 0;
}
