# -*- coding: utf-8 -*-

from accumulators import Accumulator

acc = Accumulator()

for i in range(1, 16):
    acc(i)

print(acc.mean())
