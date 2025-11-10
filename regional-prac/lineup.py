#!/usr/bin/env python3

n = int(input())

# if n == 1:
#     print("1")
# else:
#     gs = [1] + [int(g) + 1 for g in input().split()]
#     gi = [(y, x) for x, y  in list(enumerate(gs))]
#     gzs = [y for x, y in sorted(gi)]
#     print(*gzs)

print(*[y for x,y in sorted([(y,x) for x,y in list(enumerate([1] + [int(g) + 1 for g in input().split()]))])])
