#!/usr/bin/env python3

n = int(input())

cards = sorted([int(c) for c in input().split()])
score = cards[0]
for i in range(1, n):
    if cards[i] == cards[i - 1] + 1:
        continue
    score += cards[i]

print(score)
