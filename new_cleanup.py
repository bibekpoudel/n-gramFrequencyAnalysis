import string, os

def cleanup(file, filename, dirname):    
    text = []
    for line in file:
        for a in line:
            if a.lower() in string.ascii_lowercase:
                text.append(a.lower())
    cleanfile = open(os.path.join(dirname, "clean_" + filename), "w")
    cleanfile.write(''.join(text))
    print "Done cleaning file " + filename

    
if __name__ == "__main__":
    cleanup()
