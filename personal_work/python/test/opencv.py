#!/usr/bin/python
# -*- coding: UTF-8 -*-
# file：opencv
# date: 2017/5/16  17:03

import cv2

img = cv2.imread("../data/sin.png")
cv2.namedWindow("Image")
cv2.imshow("Image", img)
cv2.waitKey(0)
cv2.destroyAllWindows()