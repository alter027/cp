#include<stdio.h>
#include<stdlib.h>
struct ins{
	int first;
	int last;
	int middle;
};
long long int step(long long int top,long long int floor);
int test(long long int i);
int n,k;
int *s;
int main(void){
	long long int top,floor,i;
	int high,low,count,j;
	scanf("%d %d",&n,&k);
	s=(int *)malloc(sizeof(int)*n);
	scanf("%d",&s[0]);
	top=s[0];
	floor=s[0];
	for(i=1;i<n;i++){
		scanf("%d",&s[i]);
		if(s[i]>top)
			top=s[i];
		else if(s[i]<floor)
			floor=s[i];
	}
	top=(top-floor);
	if(n!=k){
		if(test(0)==1){
			i=0;
		}
		else
			i=step(top,floor);
	}
	struct ins *ans=(struct ins*)malloc(sizeof(struct ins)*k);
	count=0;high=s[0];low=s[0];
	ans[0].first=1;j=1;
	while(n-j!=k-count-1){
		if(s[j]>high&&s[j]-low<=i*2){
			high=s[j];
		}
		else if(s[j]<low&&high-s[j]<=i*2){
			low=s[j];
		}
		else if(s[j]<=high&&s[j]>=low);
		else{
			ans[count].last=j;
			ans[count].middle=(high+low)/2;
			count++;
			high=s[j];low=s[j];
			ans[count].first=j+1;
		}
		if(n-j==k-count-1){
			break;
		}
		j++;
	}
	if(n-j==k-count-1){
		ans[count].last=j;
		ans[count].middle=((long long int)high+low)/2;
		count++;
	}
	for(j=j;j<n;j++){
		ans[count].first=j+1;
		ans[count].last=j+1;
		ans[count++].middle=s[j];
	}
	for(j=0;j<k;j++){
		printf("%d %d %d\n",ans[j].first,ans[j].last,ans[j].middle);
	}
	return 0;
}
long long int step(long long int top,long long int floor){
	int k=test((top+floor)/2);
	if(k==1){
		top=(top+floor)/2;
	}
	else if(k==0){
		floor=(top+floor)/2+1;
	}
	if(top==floor){
		return top;
	}
	return step(top,floor);
	
}
int test(long long int i){
	int count=1,j=1;
	int high=s[0],low=s[0];
	while(count<=k){
		if(s[j]>high&&(long long int)s[j]-low<=i*2){
			high=s[j];
		}
		else if(s[j]<low&&(long long int)high-s[j]<=i*2){
			low=s[j];
		}
		else if(s[j]<=high&&s[j]>=low);
		else{
			count++;
			high=s[j];low=s[j];
		}
		if(n-j-1==k-count){
			return 1;
		}
		j++;
	}
	return 0;
}
