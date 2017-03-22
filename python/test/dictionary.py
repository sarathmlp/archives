#!/usr/bin/python

import os, urllib, sys, time, random, re

count = 1
os.system('clear')
for line in open('MyWords.txt','r').readlines():
    #line = random.choice(file)
    line = line.strip('\n')
    filename = 'http://dictionary.reference.com/search?' + \
            urllib.urlencode({'q': line})
    cmd = os.popen("lynx -dump %s" % filename)
    os.system('clear')
    print "Word:",count,line
    hitFlag = 0
    lastFlag = 0
    for data in cmd.readlines():
        if lastFlag == 1:
            display = re.sub(r'\[.*?\]', '',data) 
            print display
            if sys.argv[1] == "auto":
                time.sleep(5)
            else:
                raw_input("continue:")
            break
        data = data.strip('\n')
        if "1." in data:
            print data
            hitFlag = 1
        else:
            if hitFlag == 1:
                display = re.sub(r'\[.*?\]', '',data) 
                print display
                if "3." in data:
                    lastFlag = 1
    cmd.close()
    count += 1
