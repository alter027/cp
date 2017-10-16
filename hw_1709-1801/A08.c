#include<stdio.h>
int arr[25][105]={0};
int pass[105]={0},s1[105]={0},s2[105]={0};
int c1,c2,a,a1,b,b1,l1,l2,t;
int spec[105][2]={0},n,m; 
int pick(int a,int b){
	if(a==0&&b==0)
		return 3;
	if(a==0)
		return 1;
	if(b==0)
		return 2;
	return -1;
}
int detect(void){
	int i,j,k,count;
	for(i=m-1;i>=0;i--){
		count=0,a1=0;b1=0;
		for(j=n-1;j>=0;j--){
			if(pass[arr[j][i]]==0){
				c1=l1-1;c2=l2-1;
				for(k=i+1;k<m;k++){
					if(arr[j][k]==s1[c1])
						c1--;
					if(arr[j][k]==s2[c2])
						c2--;
//				printf("arr=%d,c1=%d,c2=%d\n",arr[j][k],c1,c2);
				}
//				printf("num=%d,c1=%d,c2=%d\n",arr[j][i],c1,c2);
				if(count==0)
					a=arr[j][i],a1=pick(c1,c2);
				else if(count==1)
					b=arr[j][i],b1=pick(c1,c2);
				else if(count==2){
//					printf("$1\n");
					return -1;
				}
				count++;
//				printf("a1=%d,b1=%d\n",a1,b1);
				if(a1==-1||b1==-1){
//					printf("$2\n");
					return -1;
				}
			}
			pass[arr[j][i]]=1;
		}
//		printf("a1=%d,b1=%d\n",a1,b1);
		if(count==1){
			if(a1==1)
				s1[l1++]=a;
			else if(a1==2)
				s2[l2++]=a;
			else{
				s1[l1]=a,s2[l2]=a;
				spec[t][0]=l1,spec[t][1]=l2;
				l1++,l2++,t++;
			}
		}
		else if(count==2){
			if(a1==3&&b1==3){
				if(a>b)
					s1[l1++]=b,s2[l2++]=a;
				else
					s1[l1++]=a,s2[l2++]=b;
			}
			else{
				if(a1==1)
					s1[l1++]=a;
				else if(a1==2)
					s2[l2++]=a;
				if(b1==1)
					s1[l1++]=b;
				else if(b1==2)
					s2[l2++]=b;
				if(a1+b1!=3){
//					printf("$3.a1=%d,b1=%d\n");
					return -1;
				}
			}
		}
	}
	return 0;
}
int main(void){
	int T;
	scanf("%d",&T);
	int i,j,k;
	while(T-->0){
		for(i=0;i<100;i++){
			pass[i]=0;
			s1[i]=0;s2[i]=0;
		}
		l1=1;l2=1;t=0;
		int i,j,k;
		int flag=0;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&arr[i][j]);
		flag=detect();
//		printf("I'm here.\n");
		if(flag==0){
			int tmp;
			for(i=t-1;i>=0;i--){ //spec
//				printf("i=%d\n",i);
				if(spec[i][0]==l1-1)
					s2[spec[i][1]]=-1;
				else{
					tmp=spec[i][0]+1;
					while(s1[tmp]==-1){
						tmp++;
					}
//					printf("cur=%d,aft=%d\n",s1[spec[i][0]],s1[tmp]);
					if(s1[spec[i][0]]>s1[tmp]){
						s1[spec[i][0]]=-1;
					}
					else
						s2[spec[i][1]]=-1;
				}
			}
			for(i=1;i<l1;i++)
				if(s1[i]!=-1)
					printf("%d ",s1[i]);
			for(i=l2-1;i>=1;i--)
				if(s2[i]!=-1)
					printf("%d ",s2[i]);
			printf("\n");
		}
		else
			printf("Muggles!\n");
	}
	return 0;
}
