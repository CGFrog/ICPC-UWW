#!/usr/bin/env python3

n = int(input())

if n == 1:
    print("1")
else:
    gs = [0] + [int(g) for g in input().split()]
    gi = list(enumerate(gs))
    gzs = sorted(gi, key = lambda t: t[1])
    order = [g[0] + 1 for g in gzs]
    print(*order)
