#!/usr/bin/python

#*******************************-*-PYTHON-*-*********************************
 #                                                                          *
 #          Copyright 2013 Diametriq, LLC All Rights Reserved.              *
 #            Manufactured in the United States of America.                 *
 #      1990 W. New Haven Ste. 303, Melbourne, Florida, 32904 U.S.A.        *
 #                                                                          *
 #   This product and related documentation is protected by copyright and   *
 #   distributed under licenses restricting its use, copying, distribution  *
 #   and decompilation.  No part of this product or related documentation   *
 #   may be reproduced in any form by any means without prior written       *
 #   authorization of Diametriq and its licensors, if any.                  *
 #                                                                          *
 #   RESTRICTED RIGHTS LEGEND:  Use, duplication, or disclosure by the      *
 #   government is subject to restrictions as set forth in subparagraph     *
 #   (c)(1)(ii) of the Rights in Technical Data and Computer Software       *
 #   clause at DFARS 252.227-7013 and FAR 52.227-19.                        *
 #                                                                          *
 #***************************************************************************/

##
 # FILE:    copyRightCheckAdd.py
 # Purpose: To check and add diametriq copyright to .h, .cpp, .java files
 # Author:  hemanth
 #
 # Created on Dec 28, 2013, 7:39 PM
 #/


import sys
import os
import commands

def AddCopyright(file_path, file_extension):
	file_path_temp = file_path + ".temp"

	fd = open(file_path, 'r')
	fd_temp = open(file_path_temp, 'w')

	if file_extension == ".h":
		fd_temp.write('/*********************************-*-H-*-************************************\n')
	elif file_extension == ".cpp":
		fd_temp.write('/********************************-*-CPP-*-***********************************\n')
	elif file_extension == ".java":
		fd_temp.write('/*******************************-*-JAVA-*-***********************************\n')
	fd_temp.write(' *                                                                          *\n')
	fd_temp.write(' *          Copyright 2013 Diametriq, LLC All Rights Reserved.              *\n')
	fd_temp.write(' *            Manufactured in the United States of America.                 *\n')
	fd_temp.write(' *      1990 W. New Haven Ste. 303, Melbourne, Florida, 32904 U.S.A.        *\n')
	fd_temp.write(' *                                                                          *\n')
	fd_temp.write(' *   This product and related documentation is protected by copyright and   *\n')
	fd_temp.write(' *   distributed under licenses restricting its use, copying, distribution  *\n')
	fd_temp.write(' *   and decompilation.  No part of this product or related documentation   *\n')
	fd_temp.write(' *   may be reproduced in any form by any means without prior written       *\n')
	fd_temp.write(' *   authorization of Diametriq and its licensors, if any.                  *\n')
	fd_temp.write(' *                                                                          *\n')
	fd_temp.write(' *   RESTRICTED RIGHTS LEGEND:  Use, duplication, or disclosure by the      *\n')
	fd_temp.write(' *   government is subject to restrictions as set forth in subparagraph     *\n')
	fd_temp.write(' *   (c)(1)(ii) of the Rights in Technical Data and Computer Software       *\n')
	fd_temp.write(' *   clause at DFARS 252.227-7013 and FAR 52.227-19.                        *\n')
	fd_temp.write(' *                                                                          *\n')
	fd_temp.write(' ****************************************************************************/\n')

	for line in fd.readlines():
		fd_temp.write(line)

	fd.close()
	fd_temp.close()

	command = "mv -f " + file_path + ".temp " + file_path
	os.system(command)

	print "\tupdated %s"%(file_path)

def CheckCopyright(file_path):
	command1 = "grep -c " + "\"Copyright\" " + file_path
	pattern_count1 = commands.getoutput(command1)

	command2 = "grep -c " + "\"LLC All Rights Reserved\" " + file_path
	pattern_count2 = commands.getoutput(command2)

	if (pattern_count1 == "0") | (pattern_count2 == "0"):
		return 0
	else:
		return 1


if __name__ == '__main__':
	if len(sys.argv) < 2:
		#stoping the program and printing an error message
		print "Usage: python copyRightCheckAdd.py [dir/file] path."
		sys.exit("Must provide the [dir/file] path to check and add copyright !!!")

	dir_file_path = sys.argv[1]
	if not os.path.exists(dir_file_path):
		print "Usage: python copyRightCheckAdd.py [dir/file] path."
		sys.exit("Invalid path !!!")

	print 'Check and Adding........'

	if not os.path.isdir(dir_file_path):
		file_extension = os.path.splitext(dir_file_path)[1]
		if (file_extension == ".h") | (file_extension == ".cpp") | (file_extension == ".java"):
			file_path = os.path.abspath(dir_file_path)
			isAdded = CheckCopyright(file_path)
			if isAdded == 0:
				AddCopyright(file_path, file_extension)
	else:
		for root, subFolders, files in os.walk(dir_file_path):
			for file in files:
				file_extension = os.path.splitext(file)[1]
				if (file_extension == ".h") | (file_extension == ".cpp") | (file_extension == ".java"):
					file_path = os.path.join(root,file)
					file_path = os.path.abspath(file_path)

					isAdded = CheckCopyright(file_path)
					if isAdded == 0:
						AddCopyright(file_path, file_extension)

	print "DONE !!!"
