print("Hello" + 'world')  # Use either double or single quotes for strings

print('''To print
multiline strings, use triple single quotes''')


# Data types for variables are automatically deduced

a = "string"
b = 234
c = 123.45


# Data types: int, float, strings, bools, none

bool_true = True
# Used mainly for functions to signify that nothing is being returned
var_none = None


# To get type of variable, use type(var)

print(type(var_none))


# Logical operators: and, not, or

var_true = True
var_false = False
print(var_true and var_false)
print(not var_true)


# Typecasting: Use int(), str(), etc to force type conversion

a = "16"  # It is a string
b = 4
print(int(a) + 4)


# input() function: Used to take input from the user

# No matter what the input, it will always be stored as a string
age = input('What is your age: ')
print(type(age))
age = int(age)  # Explicit type casting
print(type(age))


# String concatenation

greeting = 'Good Morning'
name = 'Aditya'
# '+' is overloaded, it concatenates strings
greet_aditya = greeting + ' ' + name
print(greet_aditya)


# Obtain individual characters from string using [] operator

print(name[0])


#  Strings are immutable -> a[x] = 'Y' is not allowed


# String slicing: [n, m] extracts characters from index n to (m - 1)

print(name[0: 3])  # 0, 1, 2 i.e exclude last index
print(name[: 4])  # Will take min valid index by default
print(name[0:])  # Will take max valid index by default
name = 'Aditya'
print(name[1: 5: 2])  # Skip every 2nd value from 1 to 4
# No need to mention first and end value if doing it for full string
print(name[:: 2])


# Use negative indices to start extraction from the end

print(name[-1])  # -1 is assigned to right most character
# To convert to positive value, add |len(name)| to both indices
print(name[-3: -1])
print(name[3: 5])  # -3 + 6 = 3, and -1 + 6 = 5


#  String functions. They support \n and \t.

story = 'a quick brown fox jumped over the lazy dog'
print(len(story))  # Returns length of string
print(story.endswith('dog'))  # Does story end with dog? T or F
# Count occurrence of a character or sequence of characters
print(story.count('fox'))
print(story.capitalize())  # Capitalizes first letter of story
print(story.find("brown"))  # Returns index of first occurrence of input string
print(story.replace('dog', 'cat'))


# Lists : Containers to store a set of values of any data type.
# They preserve the order and individual elements can be accessed
# just like the way we do in strings

even_nos = [2, 4, 6, 8, 10]
print(even_nos)
print(even_nos[0])

# They are mutable

even_nos[0] = 12
print(even_nos)

# Illustrating how values of different data types can be stored in a list

my_list = ['hello', True, 23.45, 100]
print(my_list[0][0: 4])  # Access individual characters of a string

# Lists can be sliced

print(my_list[0: 2])

# List methods

my_list = [6, 3, 8, 2, 11, 4, 7]
my_list.sort()
# sort() sorts the list in-place, i.e the actual list is modified
print(my_list)

# sorted () is better as it returns sorted list without modifying original list
desc_order = sorted(my_list)
print(desc_order)

my_list.append(15)
print(my_list)

my_list = [6, 3, 8, 2, 11, 4, 7]
my_list.insert(2, 9)  # Inserts 9 at index 2
print(my_list)

popped_item = my_list.pop(2)  # Removes the element at index 2
print(popped_item)
print(my_list)

my_list.remove(11)  # Removes the value passed from the list
print(my_list)


# Tuples: Similar to lists, but are immutable

# Put a comma after listing the element for a singleton tuple
singleton_tuple = (1, )

my_tuple = (1, 9, 7, 6.7, 'sequence', 'string', 7)
print(my_tuple)

# Tuple methods

print(my_tuple.count(7))  # Returns number of occurrences of the parameter
print(my_tuple.index('string'))


# Dictionaries: Collection of key-value pairs

my_dict = {
    "first": 1,
    "second": 2,
    "third": 3,
    "list": [4, 5, 6, 7],

    "my_second_dict": {
        "letter_a": 'A',
        "letter_b": 'B',
    }
}

# Lists are unordered, mutable, indexed and cannot contain duplicates

print(my_dict)
print(my_dict['second'])  # Access value of a key
print(my_dict['list'][2])  # Access elements of embedded list
print(my_dict['my_second_dict']['letter_a'])

# Dictionary methods

print(my_dict.keys())  # Returns a dict_key which can be converted into a list
# print(list(my_dict.keys()))
print(my_dict.values())
print(my_dict.items())

# Adds the key-value pairs to the dict if they do not already exist,
# else updates values for specified keys
my_dict.update({'third': 4, 'fifth': 5})
print(my_dict)

# Difference between getting values through [] and get().
#  Apart from this, they work the same way

print(my_dict.get('this key does not exist'))  # This one returns none
print(my_dict['this key does not exist'])  # This throws an error


# Sets: Collection of non-repetitive elements

my_set = {1, 3, 4, 5, 1}
print(my_set)

my_empty_set = set()  # set={} makes it of type dictionary, so use this syntax
print(type(my_empty_set))

# Sets  can only contain hashable data, which means mutable DS such as
# dictionaries and lists cannot be part of it

my_set.add((10, 11))  # Tuples can be a part of sets
print(my_set)

# Sets are unordered, unindexed, immuttable, can't contain duplicates

# Sets methods

my_set.add(6)
print(my_set)

print(len(my_set))  # Returns number of unique elements

my_set.remove(5)
my_set.pop()  # Removes a random value from a set

my_set.clear()  # Empties the set

set_a = {1, 3, 10}
set_b = {2, 4, 10}

my_union_set = set_a.union(set_b)
my_intersection_set = set_a.intersection(set_b)
print(my_union_set)
print(my_intersection_set)


# Conditional expressions: if-else, elif (if-else-if ladder)

my_num = 30

if(my_num == 10):
    print('Value is 10')
elif(my_num == 20):
    print('Value is 20')
else:
    print("Value is 30")

# if-else using 'in' and 'is' operators

foo = None

if(foo is None):
    print('Use this when "none" is returned')

my_list = [1, 5, 7]

if(5 in my_list):
    print('5 is present')


# Loops - 'while' loop  and 'for' loop

# while loop

fruits_list = ['mango', 'apple', 'banana', 'orange', 'pineapple']
i = 3
while(i >= 0):
    print(fruits_list[i])
    i = i - 1

# for loop: Used to iterate over a sequence like list, tuple or string

fruits_list = ['mango', 'apple', 'banana', 'orange', 'pineapple']

for item in fruits_list:
    print(item)

# for-else loop

for i in range(5):
    # F-strings, whatever is between {} is evaluated
    print(f"Adding 5 to each iteration yields {i + 5}")
else:
    # executes only upon successful termination of for-loop
    # (won't be executed when breaking from loop)
    print('i >= 5')


# Using range (): Used to generate a sequence of numbers

for i in range(0, 7):  # range (m, n) -> m to n-1. Also equivalent to range(7)
    print(i)


# Functions

def calc_percentage(marks=[100, 100, 100, 100]):  # Specifying default value
    return sum(marks) / len(marks)


marks_list = [88, 91, 79, 69]
print(f'The percentage obtained is: {calc_percentage(marks_list)}')
print(f'The percentage obtained is: {calc_percentage()}')


# File I/O

txt_file = open('sample_text.txt', 'r')  # Default mode is read itself

# Reads first 5 characters, if not specified, then reads everything
data = txt_file.read(5)
print(data)

read_line = txt_file.readline()
print(read_line)

txt_file.close()

txt_file = open('sample_text.txt', 'a')
txt_file.write('\nThas line was added thru Python code')
txt_file.close()

# Best way to use files (opening/closing done     automatically)
with open('sample_text.txt') as txt_file:
    first_line = txt_file.readline()


# OBJECT ORIENTED PROGRAMMING #


class Employee:
    company_name = 'Google'     # Class variable

    def __init__(self, name, salary):
        self.name = name    # Instance variable
        self.salary = salary    # Instance variable

        print(f'Welcome {self.name}!')

    @classmethod
    def alter_company_name(cls, company_name):
        cls.company_name = company_name

    # (GETTER) A method that acts as an attribute.
    # Use it when deriving values from other attributes.
    @property
    def bonus(self):
        return self._bonus

    @bonus.setter
    def bonus(self, bonus_multiplier):
        self._bonus = bonus_multiplier * self.salary

    @property
    def total_salary(self):
        return self.bonus + self.salary

    @staticmethod   # Can't access class variables or instance variables,
    # can only be used for utility
    def check_name(name):
        if len(name) > 1:
            print('Valid name')

        else:
            print('Invalid name')

    def __str__(self):
        # Used to override what is displayed with print(obj_name)
        return f'This is {self.name} from {self.company_name}'


e1 = Employee('Aditya', '10000')

Employee.check_name(e1.name)
print(e1)

if (hasattr(e1, 'salary')):
    print(f'Old salary: {e1.salary}')
    setattr(e1, 'salary', 15000)
    print(f'New salary: {e1.salary}')

print('Before changing company_name:')
print(getattr(e1, 'company_name'))
print('After changing company_name:')
Employee.company_name = 'Apple'  # Change a class variable's value
print(getattr(e1, 'company_name'))

print('Before changing company_name again:')
print(getattr(e1, 'company_name'))
print('After changing company_name: again')
Employee.alter_company_name('Microsoft')
print(getattr(e1, 'company_name'))

e1.bonus = 0.1
print(f"{e1.name}'s bonus: {e1.bonus}")
print(f"{e1.name}'s total salary: {e1.total_salary}")

e1.bonus = 0.2
print(f"{e1.name}'s new bonus: {e1.bonus}")
print(f"{e1.name}'s new total salary: {e1.total_salary}")


# INHERITANCE ##

class Employee:
    company = 'Google Inc.'

    def show_details(self):
        print('This is from employee')


class Programmer(Employee):
    language = 'Python'

    def show_language(self):
        print(f'The language is {self.language}')

    def show_details(self):  # Method overriding
        super().show_details()
        print('This is from programmer')


emp_1 = Employee()
programmer_1 = Programmer()

emp_1.show_details()
programmer_1.show_details()


# Illustrating how nothing is private in Python
# https://www.tutorialsteacher.com/python/public-private-protected-modifiers

class Test:
    __slots__ = ()  # Prevents addition of attributes outside the class

    public = 10
    _protected = 15  # Only a convention
    __private = 20

    def change_val(self, pub, pro, priv):
        self.public = pub
        self._protected = pro
        self.__private = priv

    def view_val(self):
        print(self.public)
        print(self._protected)
        print(self.__private)


obj = Test()
obj.change_val(20, 30, 40)
obj.view_val()

print('Changing values of all attributes from outside the class:')
obj.public = 50
obj._protected = 60
obj._Test__private = 70
obj.view_val()

Test._Test__private = 70

obj2 = Test()
obj2.view_val()
