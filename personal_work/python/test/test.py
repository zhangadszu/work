#!/usr/bin/python
# -*- coding: UTF-8 -*-
# 文件名：test.py

import os
import sys

import first_package
from first_package.my_interface_2 import my_interface_a as fpm2ia
from first_package.my_interface_1 import my_interface_a
#import second_package.package2_interface
import second_package.child_package.child_interface
from second_package import package2_interface

print("Hello world and Tencent!")

total = 999


def mysum(a, b):
    "my sum function"
    total = a + b
    return total


print("before call function, total = %d" % (total))

t = mysum(111, 222)
print("fsum(111, 222) = %d %s" % (t, "abc"))

print("after call function, total = %d" % total)

if __name__ == "__main__":
    pass
    first_package.my_interface_1.my_interface_a()
    first_package.my_interface_1.my_interface_b()
    first_package.my_interface_2.my_interface_a()
    fpm2ia()
    my_interface_a()


    second_package.package2_interface.my_interface1()
    second_package.child_package.child_interface.second_package_child_package_interface()

#    str = raw_input("请输入：");
#    print ("你输入的内容是: %s" % (str))

