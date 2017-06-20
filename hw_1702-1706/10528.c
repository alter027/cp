#include<stdio.h>
int c2[20],c5[20];
int set_two(void){
    int num=1,i;
    c2[0]=1;
    c2[1]=2;
    for(i=2;i<20;i++){
        c2[i]=(c2[i-1]*c2[i-1])%10000;
    }
    return 0;
}
int set_five(void){
    int num=1,i;
    c5[0]=1;
    c5[1]=5;
    for(i=2;i<20;i++){
        c5[i]=(c5[i-1]*c5[i-1])%10000;
    }
    return 0;
}
int five_(int num){
    int i=1,j=0,ans=1;
    while(i<=num){
        i=i*2;
        j++;
    }
    while(i>=1){
        if(num>=i){
            ans=(ans*c5[j+1])%10000;
            num=num-i;
        }
        j--;i/=2;
    }
    return ans;
}
int two_(int num){
    int i=1,j=0,ans=1;
    while(i<=num){
        i=i*2;
        j++;
    }
    while(i>=1){
        if(num>=i){
            ans=(ans*c2[j+1])%10000;
            num=num-i;
        }
        j--;i/=2;
    }
    return ans;
}
int main(void){
    int ncase;
    scanf("%d",&ncase);
    set_five();
    set_two();
    int i;
    while(ncase-->0){
        long long int ans=1,input;
        int n,five=0,two=0,situ=0;
        scanf("%d",&n);
        while(n-->0){
            scanf("%lld",&input);
            while(input%2==0&&input!=0){
                input=input/2;
                two++;
            }
            while(input%5==0&&input!=0){
                input=input/5;
                five++;
            }
            if(situ==1)
            	ans=(ans*input%10000)%10000;
            else if(input>10000){
            	ans=(ans*input%10000)%10000;
            	situ=1;
			}
            else{
            	ans=ans*input;
            	if(ans>10000){
            		situ=1;
            		ans=ans%10000;
				}
			}
        }
        if(situ==0){
        	if(two<=14&&five<=6){
        		for(i=0;i<two;i++){
        			ans=ans*2;
				}
				for(i=0;i<five;i++){
					ans=ans*5;
				}
				if(ans>=10000){
					while(ans%10==0)
						ans=ans/10;
					ans=ans%10000;
				}
      		    printf("%04lld\n",ans);
      		    continue;
			}
		}
        if(five==0&&two==0);
        else if(five>two){
            five=five-two;
            ans=(ans*five_(five))%10000;
        }
        else if(two>five){
            two=two-five;
            ans=(ans*two_(two))%10000;
        }
        printf("%04lld\n",ans);
    }
    return 0;
}
