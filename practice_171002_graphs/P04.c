#include<stdio.h>
int main(void){
//	�C�H�����@�W����	//�M��̪�����l
	int i,n,arr[2000];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		arr[i]--;
	}
	int ans=0,ra,tmp;
	for(i=0;i<n;i++){
		ra=1;
		tmp=arr[i];
		while(tmp!=-2){
			tmp=arr[tmp];
			ra++;
		}
		ans=ans>ra?ans:ra;
	}
	printf("%d\n",ans);
	 
	return 0;
}
