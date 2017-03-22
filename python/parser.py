#!/usr/bin/python
# script to match the allocated vs freed handle id
# Sarath V
import sys

def main():
    alloc_list = []
    free_count = 0
    alloc_count = 0
    i          = 0
    keystring = 'fish'
    file_name = sys.argv[1]
    field = 16
    starting_index = int(sys.argv[2])

    for line in open(file_name,'r').readlines():
        line = line.strip('\n')
        if keystring in line:
            if i == starting_index:
                if 'allocated' in line:
                    alloc_count += 1
                    b = line.split(' ')[field]
                    alloc_list.append(b)
                if 'freed' in line:
                    a = line.split(' ')[field]
                    if a in alloc_list:
                        alloc_list.remove(a)
                        free_count += 1
            else:
                i += 1

    print ('\nTotal allocations: %d ' % alloc_count)
    print ('Total free: %d' % free_count)
    print ('To free: %d' % len(alloc_list))
    print ('Handles to free:- ', alloc_list)
    print('\n')

if __name__ == '__main__':
    main()
