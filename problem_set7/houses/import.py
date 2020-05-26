# TODO
# import.py imports data from a CSV file
# Your program should accept the name of a CSV file as a command-line argument
#      -- If the incorrect number of command-line arguments are provided your program should print an error and exit.
#      -- You may assume that the CSV fule will exist and will have columns -> name, house and birth
# For each student in the CSV file, insert the student into the students table in the students.db database.
#      -- While the CSV file provided to you has just a name column, the database has separate columns for first, middle, and last names.
#      -- You’ll thus want to first parse each name and separate it into first, middle, and last names.
#      -- You may assume that each person’s name field will contain either two space-separated names (a first and last name)
#      -- or three space-separated names (a first, middle, and last name).
#      -- For students without a middle name, you should leave their middle name field as NULL in the table.

# importing the modules that are needed to read a file
from csv import reader, DictReader
from sys import argv
from cs50 import SQL

# check the length of command-line arguments to run the program. The length should be no greater than 3 (python[0] import.py[1] filename.csv[2])
if len(argv) < 2:
    print("Incorrect usage of the program script.\nTry the following: '>>>python import.py filename.csv'")
    exit()

# Creating a value that will store db adress and connection:
db = SQL("sqlite:///students.db")

# open the file that user has provided in the command-line argument
with open(argv[1], 'r') as rawfile:
    # read the new file in variable called reader
    reader = reader(rawfile)
    # iterate through the array
    for row in reader:
        # if the array row first value is equal name
        if row[0] == 'name':
            continue
        # then take this row and split by ' ' by default and store it in fullname variable
        fullname = row[0].split()
        # if fullname does not have a middle name
        if len(fullname) < 3:
            # insert this values into students table with fullname[] none value
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", fullname[0], None, fullname[1], row[1], row[2])
        else:
            # else insert all
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", fullname[0], fullname[1], fullname[2], row[1], row[2])