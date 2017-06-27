#!/usr/bin/python
# -*- coding: UTF-8 -*-
# file：data_analyze_plot
# date: 2017/6/20  17:24

import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif']=['SimHei'] #用来正常显示中文标签
plt.rcParams['axes.unicode_minus']=False #用来正常显示负号

plt.figure(1)

plt.subplot(211)
plt.bar(left = (0,1),height = (3783820, 2242913),width = 0.5)
plt.xlabel("1：自动播放0：手动播放")
plt.ylabel("次")
plt.title('session播放次数')

plt.subplot(212)
plt.bar(left = (0,1),height = (158, 536),width = 0.5)
plt.xlabel("1：自动播放0：手动播放")
plt.ylabel("秒")
plt.title('session平均播放时长')

plt.show()