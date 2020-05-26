'''
Mario Less problem specification:

1. First Prompt the user with get_int for the half-pyramid's height. A positive integer between 1 and 8, inclusive.
2. If the user fails to provide a positive integer no greater than 8 you should re-prompt for the same again.
3. Then generate (with the help of print and one or more loops) the desired half-pyramid.
4. Take care to align the bottom-left corner of your half-pyramid with the left-hand edge of your terminal window.
'''
def pyramid():
    # pre-define integer varaiables and give them value 0 to use them later
    height = 0
    # checking if the value of user's input is a digit and in range of 1-8
    while (height <= 0) or (height > 8):
        # using a try except block to validate the user's input
        try:
            # try to get an integer value of rows
            height = int(input("Enter a height of pyramid between (1-8): "))
        except ValueError:
            # if the user printed a wrong dtype prompt again to input a number
            print('Wrong data type input. Enter a number between 1-8.')

    # if the user have inputed correct number print the pyramid
    for h in range(height):
        # for h in height print new line -> first none on the new line will be printed (0), (1), (3)...(height)
        for dots in range(height - h - 1):
            # how to calculate number of spaces -> spaces = height - h - 1; range(4) -> spaces(1) = 4 - 0 - 1 = 3; spaces(2) = 4 - 1 - 1 = 2 and etc.
            print(" ", end = "")
        for gate in range(h + 1):
            # how to calculate the number of hashes(1) = 0 + 1; -> hashes(2) = 1 + 1; -> hashes(3) = 2 + 1; and etc.
            print("#", end = "")
        # printing a new line
        print("")

pyramid()