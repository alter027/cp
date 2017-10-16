#include<stdio.h>
#include<string.h>
char str[100050];
int main(void){
	int T;
	scanf("%d",&T);
	while(T-->0){
		scanf("%s",&str);
		int len;len=strlen(str);
		int i,L=0,O=0,V=0,E=0;
		for(i=0;i<len;i++){
			if(str[i]=='L')
				L++;
			else if(str[i]=='O'&&L>O)
				O++;
			else if(str[i]=='V'&&O>V)
				V++;
			else if(str[i]=='E'&&V>E)
				E++;
		}
		printf("%d\n",E);
	}
	return 0;
} 
