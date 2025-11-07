#!/usr/bin/env python3

n, d = [int(x) for x in input().split()]

q = {}

for x in input().split():
    a = int(x) // d;
    q[a] = q.get(a, 0) + 1

print(sum([(q[s] * (q[s] - 1))//2 for s in q]))
