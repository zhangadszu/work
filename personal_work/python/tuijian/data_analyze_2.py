#!/usr/bin/python
# -*- coding: UTF-8 -*-
# file：data_analyze_2
# date: 2017/6/21  16:59

import csv
from pylab import *

uin_info = {}
with open("../data/offline_competition_user_age_gender_edu.csv", "r") as f:
    reader = csv.DictReader(f)
    for row in reader:
        uin = row["uin"]
        gender = row["gender"]
        age = row["age"]
        edu = row["edu"]
        if len(uin) > 0 and len(gender) > 0 and len(age) > 0 and len(edu) > 0:
            uin_info[uin] = (gender, age, edu)

gender_playtime_total = {}
gender_playtime_count = {}
age_playtime_total = {}
age_playtime_count = {}
edu_playtime_total = {}
edu_playtime_count = {}
with open("../data/s_p.csv", "r") as f:
    reader = csv.DictReader(f)
    for row in reader:
        #print("%s %s %s %s"%(row["session"], row["is_auto_play"], row["type"], row["play_time"]))
        uin = row["uin"]
        session = row["session"]
        if len(session) > 0 and len(uin) > 0 and uin in uin_info\
                and len(row["playtime"]) > 0 and float(row["playtime"]) > 0:
            gender = uin_info[uin][0]
            age = uin_info[uin][1]
            edu = uin_info[uin][2]

            playtime = float(row["playtime"])
            if gender in gender_playtime_total:
                gender_playtime_total[gender] += playtime
                gender_playtime_count[gender] += 1
            else:
                gender_playtime_total[gender] = playtime
                gender_playtime_count[gender] = 1
            if age in age_playtime_total:
                age_playtime_total[age] += playtime
                age_playtime_count[age] += 1
            else:
                age_playtime_total[age] = playtime
                age_playtime_count[age] = 1
            if edu in edu_playtime_total:
                edu_playtime_total[edu] += playtime
                edu_playtime_count[edu] += 1
            else:
                edu_playtime_total[edu] = playtime
                edu_playtime_count[edu] = 1

import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif']=['SimHei'] #用来正常显示中文标签
plt.rcParams['axes.unicode_minus']=False #用来正常显示负号
plt.figure(1)


gender_v = []
gender_playtime_v = []
print("#gender#")
for gender in gender_playtime_total:
    total = gender_playtime_total[gender]
    count = gender_playtime_count[gender]
    mean = total / count
    gender_v.append(gender)
    gender_playtime_v.append(mean)
    print("gender:%s total:%f count:%d mean:%d"%(gender, total, count, mean))

plt.subplot(311)
plt.ylim(0, 450)
plt.scatter(gender_v, gender_playtime_v, marker = '+')
plt.xlabel('gender')
plt.ylabel('playtime')
plt.title('gender-playtime')

age_v = []
age_playtime_v = []
print("#age#")
for age in age_playtime_total:
    total = age_playtime_total[age]
    count = age_playtime_count[age]
    mean = total / count
    age_v.append(age)
    age_playtime_v.append(mean)
    print("age:%s total:%f count:%d mean:%d"%(age, total, count, mean))

plt.subplot(312)
plt.ylim(0, 450)
plt.scatter(age_v, age_playtime_v, marker = '+')
plt.xlabel('age')
plt.ylabel('playtime')
plt.title('age-playtime')


edu_v = []
edu_playtime_v = []
print("#edu#")
for edu in edu_playtime_total:
    total = edu_playtime_total[edu]
    count = edu_playtime_count[edu]
    mean = total / count
    edu_v.append(edu)
    edu_playtime_v.append(mean)
    print("edu:%s total:%f count:%d mean:%d"%(edu, total, count, mean))

plt.subplot(313)
plt.ylim(0, 450)
plt.scatter(edu_v, edu_playtime_v, marker = '+')
plt.xlabel('edu')
plt.ylabel('playtime')
plt.title('edu-playtime')

grid(True)
savefig("../data/user_playtime.png")
show()