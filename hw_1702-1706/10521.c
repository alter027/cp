#include<stdio.h>
#include<stdlib.h>
int search(int *cri,int **ptr);
int cmp(int *cri,int *cmp);
int n,m;
int main(void){
	int ncase;
	scanf("%d",&ncase);
	while(ncase-->0){
		int q,**ptr,i,j,*cri,num;
		scanf("%d %d %d",&n,&m,&q);
		ptr=(int **)malloc(sizeof(int*)*m);
		i=0;
		while(i<m){
			scanf("%d",&num);
			ptr[i]=(int *)malloc(sizeof(int)*(num+1));
			ptr[i][0]=num;
			for(j=1;j<=num;j++)
				scanf("%d",&ptr[i][j]);
			i++;
		}
		cri=(int *)malloc(sizeof(int)*n);
		while(q-->0){
			scanf("%d",&cri[0]);
			for(j=1;j<=cri[0];j++){
				scanf("%d",&cri[j]);
			}
			search(cri,ptr);
		}
		free(ptr);
		free(cri);
	}
	return 0;
}
int search(int *cri,int **ptr){
	int i,j,top,floor,check;
	top=m;
	floor=-1;
	while(floor!=top-1){
//		printf("(floor+top)/2=%d\n",(floor+top)/2);
		check=cmp(cri,ptr[(top+floor)/2]);
		if(check==0)
			floor=(top+floor)/2;
		else if(check==1)
			top=(top+floor)/2;
		else if(check==2){
			printf("%d\n",(top+floor)/2+1);
			return 0;
		}
	}
	if(floor==-1)
		printf("<1\n");
	else if(top==m)
		printf(">%d\n",m);
	else
		printf("%d %d\n",floor+1,top+1);
	return 0;
}
int cmp(int *cri,int *cmp){
	int i,j,k;
	if(cri[0]>cmp[0]){
		for(i=1;i<=cmp[0];i++){
			if(i%2==1){
				if(cri[i]<cmp[i])
					return 0;
				else if(cri[i]>cmp[i])
					return 1; 
			}
			else if(i%2==0){
				if(cri[i]<cmp[i])
					return 1;
				else if(cri[i]>cmp[i])
					return 0; 
			}
		}
		return 2;
	}
	else{
		for(i=1;i<=cri[0];i++){
			if(i%2==1){
				if(cri[i]<cmp[i])
					return 0;
				else if(cri[i]>cmp[i])
					return 1; 
			}
			else if(i%2==0){
				if(cri[i]<cmp[i])
					return 1;
				else if(cri[i]>cmp[i])
					return 0; 
			}
		}
		return 2;
	}
}
