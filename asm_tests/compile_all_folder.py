import os

def assembly_versions(filename):
	path_to_file = sample_files + '/' + filename
	os.system('./asm ' + path_to_file)
sample_files = "./valid_files"

for filename in os.listdir(sample_files):
	assembly_versions(filename)
