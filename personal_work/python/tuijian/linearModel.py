#!/usr/bin/python
#################################################################
#
#    file: linearModel.py
#   usage: ./linearModel.py
#   brief:
#  author: *******
#   email: *******
# created: 2017-06-21 17:34:06
#
#################################################################
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn import linear_model
from sklearn.externals import joblib
from sklearn.metrics import mean_squared_error
from sklearn.kernel_ridge import KernelRidge

def encode(x): return 1 if x == 'Partial' else 0
def encodevideo(x): return 1 if x == 'iphone' else 0
class linearModel:

    def __init__(self):
        pass

    def exploreFeature(self):
        train = pd.read_csv('./data/train.csv')
        test = pd.read_csv('./data/test.csv')
        train = train[train['GarageArea'] < 1200]
        train['enc_street'] = pd.get_dummies(train.Street, drop_first=True)
        test['enc_street'] = pd.get_dummies(test.Street, drop_first=True)
        train['condition'] = train.SaleCondition.apply(encode)
        test['condition'] = test.SaleCondition.apply(encode)
        return train,test

    def exploreTrain(self,train):
        data = train.select_dtypes(include=[np.number]).interpolate().dropna()
        y = np.log(data.SalePrice)
        X = data.drop(['SalePrice', 'Id'], axis=1)
        X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=42, test_size=.33)
        return X_train,X_test,y_train,y_test

    def trainlrModel(self,train):
        X_train, X_test, y_train, y_test = self.exploreTrain(train)
        lr = linear_model.LinearRegression()
        model = lr.fit(X_train, y_train)
        predictions = model.predict(X_test)
        print mean_squared_error(y_test, predictions)
        joblib.dump(model,'lrmodel.pkl')

    def trainrmModel(self,train):
        X_train, X_test, y_train, y_test = self.exploreTrain(train)
        alpha = 0.001
        rm = linear_model.Ridge(alpha=alpha)
        ridge_model = rm.fit(X_train, y_train)
        preds_ridge = ridge_model.predict(X_test)
        print mean_squared_error(y_test,preds_ridge)
        joblib.dump(ridge_model,'rmmodel.pkl')

    def predictModel(self,test):
        model = joblib.load('lrmodel.pkl')
        submission = pd.DataFrame()
        submission['Id'] = test.Id
        feats = test.select_dtypes(include=[np.number]).drop(['Id'], axis=1).interpolate()
        predictions = model.predict(feats)
        final_predictions = np.exp(predictions)
        submission['SalePrice'] = final_predictions
        submission.to_csv('predict.csv', index=False)

    def exploreVideFeature(self):
        train = pd.read_csv('./data/data.csv')
        train['os'] = train.os_version.apply(encodevideo)
        train = train[['os','time_delta','play_time']]
        train = train[train['time_delta'] > 0 ]
        return train

    def exploreVideoTrain(self,train):
        y = train.play_time
        X = train.drop(['play_time'], axis=1)
        X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=42, test_size=.33)
        return X_train,X_test,y_train,y_test

    def trainlrVideoModel(self,train):
        X_train, X_test, y_train, y_test = self.exploreVideoTrain(train)
        alpha = 0.001
        rm = linear_model.Ridge(alpha=alpha)
        ridge_model = rm.fit(X_train, y_train)
        preds_ridge = ridge_model.predict(X_test)
        print mean_squared_error(y_test,preds_ridge)

if __name__  == '__main__':
    linear = linearModel()
    data = linear.exploreVideFeature()
    linear.trainlrVideoModel(data)
