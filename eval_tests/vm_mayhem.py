import os
import subprocess
import difflib



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
champsDir = 'champs/strugglers/'
all_champs = os.listdir(champsDir)
n = len(all_champs)
i = 0
j = 0
corewar = './corewar ' + champsDir + all_champs[i] + ' ' + champsDir + all_champs[j] + ' -dump '
corewar42 = './42/corewar42 ' + champsDir + all_champs[i] + ' ' + champsDir + all_champs[j] + ' -d '
corewar_text = './logs/corewar.txt'
corewar42_text = './logs/corewar42.txt'
passed = 0
failed = 0

# Settings
twenty = True
thirty = True

while (i < n):
	j = 0
	while (j < n):
		# Introduce contestants
		print(blue(all_champs[i] + '   vs   ' + all_champs[j]))
		#print(yellow('Testing dump after 1k cycles...'))
		# Open text files, run the programs w/dump after 10k cycles and write outputs to text files.
		with open(corewar_text, 'w') as f1:
			subprocess.run(corewar + str(1000), shell=True, stdout=f1)
		with open(corewar42_text, 'w') as f2:
			subprocess.run(corewar42 + str(1000), shell=True, stdout=f2)
		# Compare text files.
		with open(corewar_text, 'r') as f1:
			output = f1.read()
		with open(corewar42_text, 'r') as f2:
			output42 = f2.read()
		s = difflib.SequenceMatcher(None, output, output42)
		# Print results w/dump after 10k cycles.
		if s.ratio() == 1.0:
			print(green('-dump 1000: OK'))
			passed += 1
		else:
			print(red('-dump 1000: difference found!'))
			failed += 1

		# Same test after 20k cycles the settings is on (twenty = True)
		if (twenty == True):
			#print(yellow('Testing dump after 2k cycles...'))
			with open(corewar_text, 'w') as f1:
				subprocess.run(corewar + str(1000), shell=True, stdout=f1)
			with open(corewar42_text, 'w') as f2:
				subprocess.run(corewar42 + str(1000), shell=True, stdout=f2)
			with open(corewar_text, 'r') as f1:
				output = f1.read()
			with open(corewar42_text, 'r') as f2:
				output42 = f2.read()
			s = difflib.SequenceMatcher(None, output, output42)
			if s.ratio() == 1.0:
				print(green('-dump 2000: OK'))
				passed += 1
			else:
				print(red('-dump 2000: difference found!'))
				failed += 1

		# Same test after 30k cycles the settings is on (twenty = True)
		if (twenty == True):
			#print(yellow('Testing dump after 3k cycles..'))
			with open(corewar_text, 'w') as f1:
				subprocess.run(corewar + str(1000), shell=True, stdout=f1)
			with open(corewar42_text, 'w') as f2:
				subprocess.run(corewar42 + str(1000), shell=True, stdout=f2)
			with open(corewar_text, 'r') as f1:
				output = f1.read()
			with open(corewar42_text, 'r') as f2:
				output42 = f2.read()
			s = difflib.SequenceMatcher(None, output, output42)
			if s.ratio() == 1.0:
				print(green('-dump 3000: OK'))
				passed += 1
			else:
				print(red('-dump 3000: difference found!'))
				failed += 1

		# Iterate second champ.
		j +=1
	i += 1

# Print total results
total = passed + failed
print(green('\nTests passed: ' + str(passed) + '/' + str(total)))
if (failed != 0):
	print(red('Tests failed: ' + str(failed) + '/' + str(total)))
