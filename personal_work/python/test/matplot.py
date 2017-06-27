#!/usr/bin/python
# -*- coding: UTF-8 -*-
# file：matplot
# date: 2017/5/16  17:17

from pylab import *
x_values = arange(0.0, math.pi * 4, 0.01)
y_values = sin(x_values)
plot(x_values, y_values, linewidth=1.0)
xlabel('x')
ylabel('sin(x)')
title('Simple plot')
grid(True)
savefig("../data/sin.png")
show()
