def main():
    infile = open('test.py', 'r')
    content = infile.read()
    infile.close()
    print(content)

main()
