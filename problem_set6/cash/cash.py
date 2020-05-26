'''
Implement a program that calculates the minimum of coins required to give a user change.

1. Get the user's input and print to output your answer. The only coins available are quarters($0.25), dimes($0.1), nickels($0.05), and pennies ($0.01).
2. We ask the user input and provide the change to give the user.
3. If the user fails to provide a non-negative value your program should re-prommpt the user for a valid amount again and again until the user compiles.
'''
def change():
    '''Calculating the user's change'''
    # I prefer to predefine the coins values in order to further use it in the change calculation
    pennies = 1
    nickels = 5
    dimes = 10
    quarters = 25
    change = 0

    # get the input from user to calculate the amount of change
    while change <= 0:
        try:
            change = float(input("What amount owed: "))
        except ValueError:
            print("Wrong number of money entered, Try again.")

    # calculation of the amount that we owe to the user, all values are rounded in order not to obtain a round in nearest bigger number
    change = change * 100
    quarters_owed = int(change // quarters)
    dimes_owed = int((change % quarters) / dimes)
    nickels_owed = int(((change % quarters) % dimes) // nickels)
    pennies_owed = int(((change % quarters) % dimes) % nickels // pennies)

    # Final result
    coins = round(quarters_owed + dimes_owed + nickels_owed + pennies_owed)
    print("The amount of coins to give: {}".format(coins))




change()