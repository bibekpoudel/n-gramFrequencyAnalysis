import os

def printngrams(a):
    command = "./a.out clean_file.txt " + str(a)
    os.system(command)



if __name__ == "__main__":
    a = int(input())
    printngrams(a)
