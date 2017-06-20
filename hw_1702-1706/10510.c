#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long int cal(char *str);
int main(void){
	char str[2500];
	while(fgets(str, sizeof(str), stdin)!=NULL){
		strtok(str,"\n");
		printf("%lld\n",cal(str)%1000000007);
	}
	return 0;
}
long long int cal(char *str){
	int i,j=0;
	for(i=strlen(str)-1;i>=0;i--){
		if(str[i]==')')
			j++;
		else if(str[i]=='(')
			j--;
		if(j==0&&str[i]=='+'){
			str[i]='\0';
			return (long long int)cal(str)%1000000007+cal(str+i+1)%1000000007;
		}
	}
	for(i=strlen(str)-1;i>=0;i--){
		if(str[i]==')')
			j++;
		else if(str[i]=='(')
			j--;
		if(j==0&&str[i]=='*'){
			str[i]='\0';
			return (long long int)cal(str)%1000000007*cal(str+i+1)%1000000007;
		}
	}
	i=strlen(str);
	if(str[0]=='('&&str[i-1]==')'){
		str[i-1]='\0';
		return (long long int)cal(str+1)%1000000007;
	}
	return (long long int)atoi(str)%1000000007;
}
