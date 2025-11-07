#!/usr/bin/env python3

n, h, v = [int(x) for x in input().split()]

dh, dv = n - h, n - v

hf = max(dh, h)
vf = max(dv, v)

print(4 * vf * hf)
