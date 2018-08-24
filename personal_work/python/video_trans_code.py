#!/usr/bin/python
# -*- coding: UTF-8 -*-
import os
import sys

feedid = sys.argv[1]
vid = sys.argv[2]

cmd = "curl -d 'vid=%s&feedid=%s'  '10.210.155.148:5780/videoCreateWebReq'" % (vid, feedid)

print "cmd:", cmd
print "result:", os.system(cmd)



