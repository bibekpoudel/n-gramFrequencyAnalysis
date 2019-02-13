# CISS451 Cryptography assignment 3, English frequency analysis
# Main python file, gets ebooks into clean format ready for analysis

# NOTE! This file assumes download was completed using
# wget -w 2 -m -H "http://www.gutenberg.org/robot/harvest?filetypes[]=txt&langs[]=en
# command.
# If not, replace all instances 'aleph.gutenberg.org' with directory name
# where zip files are located.
# Also, probably no need for first part of this program (removing repeat files)
# if above command was not used.

import os
from cleanup import *
from printngrams import *

dirname = "clean-textfiles"
# os.system('mkdir %s' % dirname) # create folder for cleaned text files in CWD
#os.system('mkdir data')
os.system('g++ main.cpp')

# # REMOVE ALL REPEAT FILES FROM DOWNLOADS
# for c, d, f in os.walk('aleph.gutenberg.org'):
#     for element in f:
#         try:
#             i = element.index('-8')
#             if i != -1:
#                 os.system('cd %s; rm %s' % (c, element))
#         except:
#             continue 

        
# # # UNTAR ALL ZIP FILES IN ALEPH.GUTENBERG.ORG FOLDER
# for c, d, f in os.walk('temp'):#'aleph.gutenberg.org'):
#     for element in f:
#         try:
#             i = element.index('.zip')
#             if i != -1:
#                 os.system('cd %s; unzip %s' % (c, element))
#         except:
#             continue


# # CLEANS UP EACH TEXT FILE & PLACES IN clean_textfiles FOLDER,
# # THEN DELETES OLD TEXT FILE
# for c, d, f in os.walk('temp'):
#     for element in f:
#         try:
#             j = element.index('.txt')
#             if j != -1:
#                 filename = element
#                 script_dir = os.path.dirname(__file__)
#                 relative_path = ("%s/%s" % (c, element))
#                 abs_file_path = os.path.join(script_dir,
#                                              relative_path)
#                 file = open(abs_file_path)
#                 cleanup(file, filename, dirname)
#                 os.system('cd %s; rm %s' % (c, element))
#         except:
#             continue 


# FINDS N-GRAMS FOR ALL FILES IN clean_textfiles FOLDER
num_ngrams = 1
for c, d, f in os.walk('%s' % dirname):
    for element in f:
        printngrams(num_ngrams, c, element)
        #print "ELEMENT IS: ", element
