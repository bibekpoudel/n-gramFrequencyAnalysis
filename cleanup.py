import string

def cleanup():
    filename = "file.txt"
    file = open(filename)
    text = []
    for line in file:
        for a in line:
            if a.lower() in string.ascii_lowercase:
                text.append(a.lower())
    cleanfile = open("clean_"+filename, "w" )
    cleanfile.write(''.join(text))



if __name__ == "__main__":
    cleanup()


            
    
