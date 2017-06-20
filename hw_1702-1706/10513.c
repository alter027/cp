#include<stdio.h>
#define SIZE 9
int solution[SIZE];
int check(int x);
void backtrack(int x);
void print_solution();
int x0,y0;
int count;
int main(void){
	int num;
	scanf("%d",&num);
	while(num-->0){
		scanf("%d %d",&x0,&y0);
		count=0;
		x0=x0-1;
		y0=y0-1;
		solution[x0]=y0;
		backtrack(0);
		printf("%d\n",count);
	}
	return 0;
}
void backtrack(int x){
	int y;
//	printf("%d",x);
    if(x == SIZE){
        count++;
        return;
    }
    if(x==x0)
    	backtrack(x+1);
    else
	    for(y=0;y<SIZE;y++){
	        solution[x] = y;
	        if(check(x)==1)
	        	backtrack(x+1);
    }
}
int check(int x){
	int i;
	if(x==0)
		if(solution[x0]==solution[x])
			return 0;
		else if(x0+solution[x0]==x+solution[x])
			return 0;
		else if(x0-solution[x0]==x-solution[x])
			return 0;
	for(i=0;i<x;i++){
		if(solution[i]==solution[x])
			return 0;
		else if(i+solution[i]==x+solution[x])
			return 0;
		else if(i-solution[i]==x-solution[x])
			return 0;
	}
	if(x<x0){
		if(solution[x0]==solution[x])
			return 0;
		else if(x0+solution[x0]==x+solution[x])
			return 0;
		else if(x0-solution[x0]==x-solution[x])
			return 0;
	}
	return 1;
}
void print_solution(){
	int i,j;
	printf("  ");
	for(i=0;i<SIZE;i++)
		printf("%d ",i+1);
	printf("\n");
	for(i=0;i<SIZE;i++){
		printf("%d ",i+1);
		for(j=0;j<SIZE;j++){
			if(j==solution[i])
				printf("q ");
			else
				printf("  ");
		}
		printf("\n");
	}
}
