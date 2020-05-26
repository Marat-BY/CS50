# a sequence of DNA and STR counts contains the DNA file from https://www.fbi.gov/services/laboratory/biometric-analysis/codis
# The scrypt outputs the person's probabiity of DNA sequence
from csv import reader, DictReader
from sys import argv

if len(argv) < 4:
    print("Incorrect usage of the python script.\nTry out: python dna.py databases/filename.csv sequences/filename.txt")
