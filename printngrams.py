import os

def printngrams(num, c, filename):
    command = "./a.out ./%s/%s " % (c, filename)
    command += str(num)
    #print command 
    os.system(command)

    # command = "./a.out clean_10001.txt " + str(num)
    # os.system(command)



# if __name__ == "__main__":
#     num = 2 #int(input())
#     temp = "temp"
#     printngrams(num, temp)

    
