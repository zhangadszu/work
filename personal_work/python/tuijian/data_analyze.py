#!/usr/bin/python
# -*- coding: UTF-8 -*-
# file：data_analyze
# date: 2017/6/16  10:25

import csv
#from pylab import *

loop = 0
session_uin = {}
session_palytime = {}
session_video_count = {}
session_autoplay = {}
session_ftime = {}
tuijian_total_time = 0.0
tuijian_total_count = 0
first_total_time = 0.0
first_total_count = 0
with open("../data/offline_competition_act_data.csv", "r") as f:
    reader = csv.DictReader(f)
    for row in reader:
        #print("%s %s %s %s"%(row["session"], row["is_auto_play"], row["type"], row["play_time"]))
        if row["oper_type"] == "1" and len(row["play_time"]) > 0 and float(row["play_time"]) > 0\
                and len(row["uin"]) > 0:
            session = row["session"]
            uin = row["uin"]
            if session in session_palytime:
                session_palytime[session] += float(row["play_time"])
                session_video_count[session] += 1
            else:
                session_palytime[session] = float(row["play_time"])
                session_video_count[session] = 1
                session_autoplay[session] = row["is_auto_play"]
                session_uin[session] = uin
                session_ftime[session] = row["ftime"]
''''
            tuijian = row["type"]
            if len(tuijian) > 0:
                if tuijian == "棣栨潯":
                    first_total_time += float(row["play_time"])
                    first_total_count += 1
                else :
                    tuijian_total_time += float(row["play_time"])
                    tuijian_total_count += 1
#            loop += 1
#            if loop > 10000:
#                break
'''

with open("../data/seesion_playtime.csv", "w") as wf:
    writer = csv.writer(wf)
    writer.writerow(['session', 'uin', 'playtime', 'ftime'])
    for session in session_palytime:
        writer.writerow([session, session_uin[session], session_palytime[session], session_ftime[session]])


'''
auto_playtime_total = 0
auto_playtime_count = 0
auto_play_video_count_total = 0
noneauto_playtime_total = 0
noneauto_playtime_count = 0
noneauto_play_video_count_total = 0
for session in session_palytime:
    if session_autoplay[session] == "1":
        auto_playtime_total += session_palytime[session]
        auto_playtime_count += 1
        auto_play_video_count_total += session_video_count[session]
    else:
        noneauto_playtime_total += session_palytime[session]
        noneauto_playtime_count += 1
        noneauto_play_video_count_total += session_video_count[session]

print("auto play, total %f count %d mean %f"%(auto_playtime_total, auto_playtime_count, auto_playtime_total/auto_playtime_count))
print("none auto play, total %f count %d mean %f"%(noneauto_playtime_total, noneauto_playtime_count, noneauto_playtime_total/noneauto_playtime_count))

print("auto play, auto_play_video_count_total %d mean_count %d"%(auto_play_video_count_total, int(auto_play_video_count_total/auto_playtime_count)))
print("none auto play, noneauto_play_video_count_total %d mean_count %d"%(noneauto_play_video_count_total, int(noneauto_play_video_count_total/noneauto_playtime_count)))

print("头条 count %d mean %f"%(first_total_count, first_total_time/first_total_count))
print("推荐 count %d mean %f"%(tuijian_total_count, tuijian_total_time/tuijian_total_count))
'''






