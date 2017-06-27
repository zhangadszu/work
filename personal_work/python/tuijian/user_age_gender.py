#!/usr/bin/python
# -*- coding: UTF-8 -*-
# file：user_age_gender
# date: 2017/6/14  15:15

import csv


gender_d = {}#{ '1':0, '2':0}
gender_count = 0
total_age = 0
age_count = 0
age_d = {}
edu_d = {}
edu_count = 0
with open("../data/offline_competition_user_age_gender_edu.csv", "r") as f:
    reader = csv.reader(f)
    for row in reader:
        if len(row[1]) > 0 and row[1] != "gender" :
            gender_count += 1
            if row[1] in gender_d :
                gender_d[row[1]] += 1
            else:
                gender_d[row[1]] = 1
        if len(row[2]) > 0 and row[2] != "age":
            total_age += int(row[2])
            age_count += 1
            age = int(row[2])
            age //= 10
            if age in age_d :
                age_d[age] += 1
            else:
                age_d[age] = 1
        if len(row[2]) == 0:
            age = -1
            if age in age_d :
                age_d[age] += 1
            else:
                age_d[age] = 1
        if len(row[3]) > 0 and row[3] != "edu":
            edu_count += 1
            edu = row[3]
            if edu in edu_d :
                edu_d[edu] += 1
            else:
                edu_d[edu] = 1

print("age:")
print("avg age %f"%(total_age / age_count))
for k,v in age_d.items():
    print("%d-%d: %d %f%%" %(int(k) * 10, (int(k) + 1) * 10, int(v), int(v) / age_count * 100))

print("gender:")
for k,v in gender_d.items():
    #print(k, v)
    print("%d %d %f%%"%(int(k), int(v), int(v) / gender_count * 100))

print("edu:")
edu_map = {1 : "小学", 2 : "初中", 3 : "高中", 4 : "专科", 5 : "大学", 6: "硕士", 7 : "博士"}
for k,v in edu_d.items():
    print("%s %d %f%%"%(edu_map[int(k)], int(v), int(v) / edu_count * 100))