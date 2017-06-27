#!/usr/bin/python
# -*- coding: UTF-8 -*-
# file：test_1
# date: 2017/5/18  15:07

import math
def func_get_prime(n):
    return filter(lambda x: not [x % i for i in range(2, int(math.sqrt(x)) + 1) if x % i == 0], range(2, n + 1))

func_get_prime(100)


