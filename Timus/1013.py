# 不知道為甚麼 python2 可以過但 python3 無法 QAQ
def mul(left,right,m):
    rec = [[0,0],[0,0]]
    for i in range(2):
        for j in range(2):
            tmp = 0
            for k in range(2):
                tmp += left[i][k]*right[k][j]
            rec[i][j] = tmp%m
    return rec

def calc(mat, n, m):
    if n == 1:
        return mat
    tmp = calc(mat, n/2, m)
    tmp = mul(tmp, tmp, m)
    if n % 2 == 0:
        return tmp
    else:
        return mul(tmp,mat,m)

n = int(input())
k = int(input())
m = int(input())

mat = [[k-1,k-1], [1,0]]
result = calc(mat,n-1,m)
ans = result[0][0]*(k-1)+result[1][0]*(k-1)
print(ans % m )
