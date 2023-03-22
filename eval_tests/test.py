import os
import filecmp
import time
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

# Make and copy new corewar to this folder.
#os.system('cd .. && make corewar && cp corewar ./eval_tests/corewar && cd eval_tests')

# Set the starting cycle of comparing outputs of our corewar and the original corewar.
# First difference:
cycle = 1
# Set the cycle to print info.
info = 1

# Define champs
champs = ' ./champs/compiled/bigzork.cor ./champs/champs/tchupka.cor ./champs/compiled/Kappa.cor' #./champs/dubo.cor #./champs/Gagnant.cor'

# Define commands and log files
corewar = '../corewar' + champs + ' -dump '
corewar42 = './42/corewar42' + champs + ' -d '
corewar_text = './logs/corewar.txt'
corewar42_text = './logs/corewar42.txt'
info_text = './logs/info.txt'

while cycle < 1000:
	# Open text files, run the programs and write outputs to text files.
	with open(corewar_text, 'w') as f1:
		subprocess.run(corewar + str(cycle), shell=True, stdout=f1)
	with open(corewar42_text, 'w') as f2:
		subprocess.run(corewar42 + str(cycle), shell=True, stdout=f2)
	# Compare text files.
	with open(corewar_text, 'r') as f1:
		output = f1.read()
	with open(corewar42_text, 'r') as f2:
		output42 = f2.read()
	s = difflib.SequenceMatcher(None, output, output42)
	# Print results.
	if s.ratio() == 1.0:
		print(green('Cycle ' + str(cycle) + ' : OK'))
	else:
		print(red('Cycle ' + str(cycle) + ' : Difference found!'))
		break
	# Iterate cycle for dump.
	cycle += 1
