#include<stdio.h>
#include<stdbool.h>
int n,m,i,j,x,a[100050],b[100050];
bool on[100050];
char s[5];
int main(void){
	scanf("%d %d",&n,&m);
	for(i=2;i<=n;i++){
		if(a[i]==0){
			for(j=i;j<=n;j+=i)
				a[j]=i;
		}
	}
	for(i=0;i<m;i++){
		scanf("%s",s);
		scanf("%d",&x);
		if(s[0]=='+'){
			if(on[x])
					puts("Already on");
			else{
				for(j=x;j>1;j/=a[j])
					if(b[a[j]]!=0)
						break;
				if(j==1){
					on[x]=true;
					for(j=x;j>1;j/=a[j])
						b[a[j]]=x;
					puts("Success");
				}
				else
					printf("Conflict with %d\n",b[a[j]]);
			}
		}
		else{
			if(on[x]){
				on[x]=false;
				for(j=x;j>1;j/=a[j])
					b[a[j]]=0;
				puts("Success");
			}
			else
				puts("Already off");
		}
	}
	return 0;
}
