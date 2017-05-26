# -*- coding: utf-8 -*-

from accumulators import Accumulator


def test_mean():
    acc = Accumulator()
    acc(1.5)
    acc(3)
    acc(9)
    assert acc.mean() == 4.5
