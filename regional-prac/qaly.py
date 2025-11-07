#!/usr/bin/env python3

N = int(input())

Q = 0
for i in range(N):
    q, p = [float(v) for v in input().split()]
    Q += q * p

print(Q)
