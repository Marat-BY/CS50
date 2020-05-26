# Implementation of hello function
def hello():
    """
    The hello() function prints the hello response to the user name.
    Example: hello()
             What is you name?
    User's input: David.
    Response: Hello, David.
    """
    a  = input("What is your name?\n")
    print("hello, {}".format(a))

# Call the function
hello()