import os 
import os.path
import subprocess
from os import path

errors42 = []
errorsOurs = []

def assembly_versions(filename):
	path_to_file = sample_files + '/' + filename
	output_filename = filename.replace('.s', '.cor')
	path_to_output = sample_files + '/' + output_filename
	
	os.system('./asm ' + path_to_file)
	if os.path.exists(path_to_output):
		errors42.append(path_to_file)
		os.system('rm ' + path_to_output)
	
	os.system('../asm ' + path_to_file)
	# cmd = 'leaks -atExit -- ../asm ' + path_to_file
	# exit_code = subprocess.call(cmd.split())
	# print("\nEXIT CODE IS " + str(exit_code) + "\n")
	# if exit_code == 1:
	# 	os.system("echo '" + output_filename + "' >> leaksError.txt")
	if os.path.exists(path_to_output):
		errorsOurs.append(path_to_file)
		os.system('rm ' + path_to_output)

def common_member(a, b):
    a_set = set(a)
    b_set = set(b)
    if (a_set & b_set):
        print("\nCommon elements of two assembled arrays are: ", a_set & b_set)
    else:
        print("No common elements")

sample_files = "error_files"


for filename in os.listdir(sample_files):
	assembly_versions(filename)
print("\n\n\t42 asm assembled following files: ", errors42)
print("\n\tOur asm assemled following files: ", errorsOurs)

common_member(errors42, errorsOurs)


