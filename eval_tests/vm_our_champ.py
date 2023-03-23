import os
import subprocess

# Define colors.
def red(text):
    return '\033[31m' + text + '\033[0m'
def green(text):
    return '\033[32m' + text + '\033[0m'
def yellow(text):
    return '\033[33m' + text + '\033[0m'
def blue(text):
    return '\033[34m' + text + '\033[0m'

# Define champs, commands, log files and variables
champsDir = 'champs/compiled'
all_champs = os.listdir(champsDir)
n = len(all_champs)
i = 0
j = 0

# Do you want to print the output
print_result = False

while (i < n):
	# Print contestants
	corewar = '../corewar ./Roadman.cor ' + champsDir + all_champs[i]
	print(blue('Roadman   vs   ' + all_champs[i] + ' '), end='')
	# Get output of the program and check if leaks were found
	result = subprocess.run(corewar.split(), capture_output=True)

	if ('\"Roadman\", has won !' in result.stdout.decode('utf-8')):
		print(green('Roadman won! Man\'s a big ting round \'ere ya get me'))
		if (print_result):
			print(result.stdout.decode('utf-8'))
	else:
		print(red('Roadman lost. Peak bruv :('))
		if (print_result):
			print(result.stdout.decode('utf-8'))
	i += 1
