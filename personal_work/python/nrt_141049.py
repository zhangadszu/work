#!/usr/bin/python
#coding=utf-8

import MySQLdb
import sys
import datetime
import os

reload(sys)
sys.setdefaultencoding('utf8')

#删除旧的数据文件
os.system("rm /usr/local/services/XXXXX-1.0/bin/data/nrt_data_* -f")

# 打开数据文件
yesterdayDataTime = (datetime.date.today() - datetime.timedelta(days=1)).strftime("%Y%m%d") 
filePath = "/usr/local/services/XXXXX-1.0/bin/data/nrt_data_%s" % yesterdayDataTime
nrtDataFile = open(filePath, "w")

# 打开数据库连接
db = MySQLdb.connect(host="XXXXXX",port=XXXX,user="XXXX",passwd="XXXXX",db="XXXXXX",charset="utf8");

# 使用cursor()方法获取操作游标 
cursor = db.cursor()

# SQL 查询语句
startId = 0
num = 50000
while True:
	sql = "SELECT * FROM feed_data where id>%d ORDER BY id ASC LIMIT %d" % (startId,num)

	# 执行SQL语句
	cursor.execute(sql)

	# 获取所有记录列表
	results = cursor.fetchall()
	for row in results:
		i = 0
		for item in row:
			if i != 0:
				nrtDataFile.write("\t")
			i += 1
			nrtDataFile.write(str(item).replace("\t", " ").replace("\n", " "))
		nrtDataFile.write("\n")

	print "sql:",sql,"result num:",len(results)
	
	if len(results) < num:
		break;
	
	startId = results[len(results) - 1][0]

# 关闭数据文件
nrtDataFile.close();

# 关闭数据库连接
db.close()

# NRT 上报
cmd = "/usr/local/services/XXXXX-1.0/bin/XXXXXX -i nrt141049 -t %s -f %s -c" % (yesterdayDataTime, filePath)
reportResult = os.system(cmd)
print "cmd:",cmd,"reportResult:",reportResult
