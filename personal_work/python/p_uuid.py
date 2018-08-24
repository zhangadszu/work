# -*- coding:utf-8 -*-  

import math
import sys

def puuid(N, D, L):
    print N,D,L
    return 1 - math.exp(- N * N / 2 / math.pow(D, L))

def Usage():
    print "pytohn p_uuid.py N(总数) D(单个向量维度) L(向量个数)"
    sys.exit(0)

if len(sys.argv) < 4:
    Usage()
else:
    print puuid(int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3]))