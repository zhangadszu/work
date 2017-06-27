#!/usr/bin/python
# -*- coding: UTF-8 -*-
# file：pandas_test
# date: 2017/6/23  17:29

import pandas as pd

d = pd.read_csv("../data/offline_competition_user_age_gender_edu.csv")
#d = pd.read_csv("../data/offline_competition_act_data.csv")

print(d)
