#!/usr/bin/python
# -*- coding: UTF-8 -*-
# file：__init__.py
# date: 2017/5/15  15:36

if __name__ == '__main__':
    print ('ran as main')
else:
    print ('package second_package.child_package init %s'% __name__)

#import child_interface