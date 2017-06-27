#!/usr/bin/python
# -*- coding: UTF-8 -*-
# file：num_combine
# date: 2017/5/16  16:01

for i in range(1, 10, 1):
    for j in range(1, 10, 1):
        for k in range(1, 10, 1):
            if (i > j) and (j > k):
                print(i, j, k)
