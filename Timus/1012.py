n=int(input())
k=int(input())
arr = []*(n+1)
for i in range(3,n+1):
	arr[i]=(k-1)*(arr[i-1]+arr[i-1])
print arr[n]
