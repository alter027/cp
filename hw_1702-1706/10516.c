#include<stdio.h>
#include<stdlib.h>
int print_();
int create_table(void);
int change_alive(int i);
int n,*a,binary_l,s[100000];
int main(void){
	int ncases;
	scanf("%d",&ncases);
	while(ncases-->0) {
		int i,k;
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&s[i]);
		a=(int *)malloc(sizeof(int)*n);
		binary_l=create_table();
		int alive=n,step=k+1,cur=0;
		while(alive>1){
			step=step%alive;
			cur=(cur+step)%alive;
			if(cur==0)
				cur=alive;
			step=change_alive(cur--);
			alive--;
		}
		print_();
	}
	return 0;
}
int print_(){
	int i;
	for(i=0;i<n;i++){
		if(a[i]==1){
			printf("%d\n",s[i]);
			break;
		}
	}
	return 0;
}
int create_table(void){
	int i=1,j,k;
	while(i<=n){
		for(j=i;j<=n;j=j+2*i){
			a[j-1]=i;
		}
		i=i*2;
	}
	k=i/2;
	return k;
}
int change_alive(int i){
	int total=0,m=binary_l,bot=0,j,step;
	while(m>0){
		if((bot+m<=n)&&(total+a[bot+m-1])<i){
			total=total+a[bot+m-1];
			bot=bot+m;
		}
		m=m/2;
	}
	step=s[bot];
	bot++;
	for(i=bot;i<=n;i=i+(i&-i)){
		a[i-1]--;
	}
	return step;
}
