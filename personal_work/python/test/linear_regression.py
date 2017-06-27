#!/usr/bin/python
# -*- coding: UTF-8 -*-
# file：linear_regression
# date: 2017/5/16  14:50

from sklearn import linear_model

reg = linear_model.LinearRegression()
reg.fit ([[0, 0], [1, 1], [2, 2]], [0, 1, 2])
linear_model.LinearRegression(copy_X=True, fit_intercept=True, n_jobs=1, normalize=False)
reg.coef_