#!/usr/bin/python
# -*- coding: UTF-8 -*-
# file：data_plot
# date: 2017/6/23  20:41

import csv
from pylab import *

ftime_playtime_total = {}
ftime_playtime_count = {}
with open("../data/seesion_playtime.csv", "r") as f:
    reader = csv.DictReader(f)
    for row in reader:
        playtime = row["playtime"]
        ftime = row["ftime"]
        if len(playtime) > 0 and len(ftime) == 10:
            ftime = ftime[8:]
            playtime = float(playtime)
            if playtime < 300:
                continue
            if ftime in ftime_playtime_total:
                ftime_playtime_total[ftime] += playtime
                ftime_playtime_count[ftime] += 1
            else:
                ftime_playtime_total[ftime] = playtime
                ftime_playtime_count[ftime] = 1

plt.rcParams['font.sans-serif']=['SimHei'] #用来正常显示中文标签
plt.rcParams['axes.unicode_minus']=False #用来正常显示负号
plt.figure(1)

ftime_v = []
ftime_playtime_v = []
ftime_count_v = []
print("#gender#")
for ftime in ftime_playtime_total:
    total = ftime_playtime_total[ftime]
    count = ftime_playtime_count[ftime]
    mean = total / count
    ftime_v.append(ftime)
    ftime_playtime_v.append(mean)
    ftime_count_v.append(count)
    print("gender:%s total:%f count:%d mean:%d"%(ftime, total, count, mean))

plt.subplot(211)
#plt.ylim(0, 450)
plt.scatter(ftime_v, ftime_playtime_v, marker = '+')
plt.xlabel('ftime')
plt.ylabel('playtime')
plt.title('ftime-playtime')

plt.subplot(212)
#plt.ylim(0, 450)
plt.scatter(ftime_v, ftime_count_v, marker = '+')
plt.xlabel('ftime')
plt.ylabel('playcount')
plt.title('ftime-playcount')

grid(True)
savefig("../data/ftime_playtime.png")
show()