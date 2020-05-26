import re
def colemanLiau():
    '''
    Implementation of the program that computes the aapproximate
    grade level needed to comprehend some text. The call of the
    function colemanLiau() calculates the Grade Level based on
    the some text input.

    The Coleman-Liau index is computed as:
    0.0588 * L - 0.296 * S - 15.8, where
    L - is the average number of letters per 100 words in the text.
    S - is the average number of sentences per 100 words in the text.
    '''
    text = []
    while len(text) == 0:
        try:
            text = str(input("Enter the text you want to grade: "))
        except ValueError:
            print("Your input is not a text.")
    # counting the number of letters in the text
    letters = len(text.replace(" ", ""))
    # counting the number of words sequences in the text
    words = text.count(" ") + 1
    # counting the number of sentences in the text
    sentences = len(re.split(r'[.!?]+', text))

    # computing the CLI (coleman - liau index) for the readability value
    cli = (0.0588 * (100 * letters / words) - 0.296 * (100 * sentences / words) - 15.8)

    # output the result
    if cli >= 16:
        print("Grade 16+")
    elif cli <= 1:
        print("Before Grade 1")
    else:
        print("Grade {}".format(round(cli)))

# call the function
colemanLiau()