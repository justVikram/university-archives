# EXCEPTIONAL HANDLING #

def calc_factorial(n):
    factorial = 1

    for i in range(1, n):
        factorial += factorial * i

    return factorial


print(__name__)
if __name__ == '__main__':
    # It signifies that the following code should only run if the
    # name of the file to be executed is the same as the name of the
    # file where this code is present

    # This is useful when you're importing this file as a module
    # into another file, and don't want this file's useless code to be executed

    while(True):

        num = input('Enter a number [q to quit]: ')

        if(num == 'q'):
            print('Thank you for playing!')
            break

        try:
            if(int(num) > 0):
                print(f'The factorial of {num} is {calc_factorial(int(num))}')

        # Catch an exception based on type of error it raises
        except ValueError as e:
            print(f'ERROR - You did not enter a number! Reason: {e}')

        # except:  # Occurs when all other exceptions are not caught
        #     print('Erroneous Input')
            # raise ValueError
            # Raise your own error to stop execution of program

        else:   # Executed after every successful execution of 'try' block
            print(f'Great stuff! You could calculate the factorial of {num}!')

        finally:
            # Executed no matter what, regardless of the program exiting or
            # an exception being raised
            print("Let's do this again.")


# GLOBAL VARIABLES #

foo = 100  # This is a global variable


def bar():

    foo = 50  # Local variable, won't change value of global foo
    print(f"I am local variable foo, my value is {foo}")


def bar2():

    global foo
    foo = 150
    print(f"I can change global foo's value. It is {foo} now")


bar()
print(f"I am global foo and I am still the same -- {foo}")

bar2()
print(f"I am global foo and I have changed to -- {foo}")


# ENUMERATE #

my_list = ['True', 4, 7, 'Aditya']

for index, item in enumerate(my_list):
    print(f'Item no. {index} -- {item}')


# LIST COMPREHENSION #

mixed_list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

even_list = [i for i in mixed_list if i % 2 == 0]

odd_list = [i for i in mixed_list if i % 2 == 1]

print(f'{even_list}\n{odd_list}')

# Can be used with dictionaries and tuples too


# LAMBDA FUNCTIONS #

# Functions created using an expression using 'lambda' keyword

calc_square = lambda x: x * x

print(calc_square(6))

# It simply returns the result after evaluating expression
sum_of_nos = lambda a, b: a + b

print(sum_of_nos(10, 15))


# MAP() #

def calc_square(x): return x * x


my_list = [1, 2, 3, 4]

my_squared_list = list(map(calc_square, my_list))
print(my_squared_list)


# FILTER #

greater_than_5 = lambda x: x > 5

my_list = [1, 17, 14, 3, 6]
my_modified_list = list(filter(greater_than_5, my_list))
print(my_modified_list)


# REDUCE #
from functools import reduce

sum = lambda a, b: a + b

my_list = [1, 2, 3, 4]
sum_of_list = reduce(sum, my_list)
print(sum_of_list)
