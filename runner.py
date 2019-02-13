import os

def printngrams(num, filename):
    command = "./a.out %s " % filename 
    os.system(command + str(num))

    # command = "./a.out clean_10001.txt " + str(num)
    # os.system(command)



# if __name__ == "__main__":
#     num = 2 #int(input())
#     temp = "temp"
#     printngrams(num, temp)

