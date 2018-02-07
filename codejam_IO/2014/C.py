#!/usr/bin/env python

from itertools import *

ch = [[0]*21 for i in range(21)]
ch[0][0] = 1
for i in range(21):
	ch[i][0] = 1
	ch[i][i] = 1
	for j in range (1,i):
		ch[i][j] = ch[i-1][j-1]+ch[i-1][j]

fact = [0]*21
fact[0] = 1
for i in range(1, 21):
	fact[i] = fact[i-1]*i

for case in range(int(raw_input())):
	n, k = map(int, raw_input().split())

	ans = fact[n]
	if n%k == 0:
		d1 = n/k # people
		t1 = k   # number for different kinds of desk
	else:
		d1 = n/k
		d2 = d1+1
		t2 = n%k
		t1 = k-t2
		ans /= (pow(fact[d2],t2)*fact[t2])
		if d2 > 2:
			ans *= pow(fact[d2-1]/2,t2)

	ans /= (pow(fact[d1],t1)*fact[t1])
	if d1 > 2:
		ans *= pow(fact[d1-1]/2,t1)

	print "Case #%d: %s" % (case+1,ans)