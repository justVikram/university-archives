# Title     : TODO
# Objective : TODO
# Created by: avikram
# Created on: 4/30/21

# Variables - 2 ways to assign values

# x = 25  // Deprecated
mystr <- "hello world"
FALSE -> boolvar

# Arithmetic operators consist of +, -, *, /, ^, %% (modulo), and %/% (division that rounds off the value to floor)

a <- 11
b <- 5

a+b
a-b
a*b
a/b
a^b
a%%b
a%/%b # Should return 2, as (a/b = 2.2) and floor(a/b) = 2.

# Assignment operators consist of = (deprecated), <-, <<-, ->> ->
e <<- 50
e
100 ->> f
f

# Relational operators consist of >, <, ==, !=, >=, <=

f < e # False
f != e # True

# Logical operators consist of &, |, ! [they work on boolean variables]

newboolvar1 <- TRUE
newboolvar2 <- FALSE

newboolvar1 & newboolvar2
newboolvar1 | newboolvar2 # Comparable to OR
!newboolvar1 # Negation, thus returns FALSE

# Special operators consist of :, %in%

vector1 <- 1:7  # Creates series of numbers in sequence for a vector
vector1
6 %in% vector1 # Used to identify if an element belongs to a vector -- returns TRUE if found, else FALSE

# Data types consist of vectors, lists, matrices, arrays,  factors, data frames

# Vector is a sequence of data elements of the same basic type.
# There are 5 classes of vectors -- character, complex (complex numbers), integer, numeric (double), logical (T/F)
# If you try to store different data types in a vector, it upgrades the type of all the data members appropriately
vtr <- c(1, 2, 3, 4, 5)
vtr

# You can perform 'sort ()' on a vector

vtrtosort <- c(20, 1, 17, 45)
sortvtr <- sort(vtrtosort, TRUE)
sortvtr

# Access values of a vector using [] operator (index starts from 1, not 0)

vtrtosort [3]   # Prints 17
vtrtosort [-3]  # -x implies take all indices except x.
vtrtosort [1] <- 40  # Replace value at a particular index
vtrtosort [6] <- 100  # You can insert values beyond index range, but if an index has no value it will store 'NA'
vtrtosort

# Lists can store different kinds of datatypes, unlikes vectors (that can only store one kind of data type in a vector).

list1 <- list(5, "string", 12.5, FALSE)
list1

# You  can merge two lists using merge ().

list2 <- list(2, 3, TRUE)
list3 <- merge(list1, list2)
list3

# To directly merge contents of multiple lists during declaration,

list4 <- c(list1, list2)
list4

# To extract an element, use [] again.

list4[3]  # Element at third index is 12.5

# Arrays are used to store data in more than two dimensions. It takes vector as input and uses  values in the dim
# parameter to create an array.


vtr10 <- c(1, 2, 3, 4)
vtr11 <- c(5, 7, 9, 11)
arr1 <- array(vtr10)  # Single dimension array
arr2 <- array(c(vtr10, vtr11), dim = c(4, 4))  # Dim (R, C, No_of_Matrices) sets the dimension of an object. The data is
# stored continuously.
arr2

# Matrices are the object wherein the elements are arranged in a two-dimensional rectangular layout.
# Matrices are created using Matrix (data, nrow, ncol, byrow, dimnames) function.
# Data -> Input vector which becomes data element of the matrix.
# Nrow -> Number of rows to be created.
# Ncol -> Number of columns to be created.
# Byrow -> If TRUE, then elements are arranged by row.
# Dimnames -> Names assigned to rows and columns

mtr <- matrix(c(vtr10, vtr11), 4, 2)  # nrow/ncol needs to be a multiple of number of elements in vectors.
mtr

# Factors are used to categorize the data and store it as levels. They can store both integers and strings.
# Useful in data analysis for statistical modeling.
# It keeps a track of all unique data elements as levels.

vtr20 <- c(3, 5, 11, 2, 3, 5, 13, 19)
factvtr <- factor(vtr20)
factvtr

# Data frame is a table or a two-dimensional array-like structure in which each column contains values of one variable
# and each row contains one set of values from each column.

id <- 10:14
name <- c('Dave', 'Eric', 'Roshni', 'Pankaj', 'Neel')
emp_db <- data.frame(id, name)  # id and name must have same number of elements
emp_db

# Selector statements consist of if, if-else, and switch

myvar <- 15

if (myvar == 15)
{
  print("x is equal to 15")
} else  # write else right after closing bracket, else it will be interpreted as a completely new line
{
  print("x is NOT equal to 15")
}

# Switch statement syntax

newvtr  <- c(150, 200, 250, 300, 350, 400)
option <- 'mean'

switch (
  option,
  'mean' = mean (newvtr),
  'mode' = mode (vtr),
  'median' = median (vtr),
  print ('Invalid input') # Default statement
)

# Repeat will keep executing the same chunk of code inside of it until broken from it. It is an exit controlled loop.

a <- 2

repeat {
  a <- a ^ 2
  print (a)

  if (a > 100)
    break
}

# While loop -- self explanatory. Entry controlled loop.

b <- 2

while (b < 1000) {
  b <- b ^ 2
  print (b)
}

# For loop

newvtr2 <- c(7, 11, 2, 6, 8)
for (i in newvtr2) {
  print(i + 10)
}

# 'Next' statement. As soon as this keyword is encountered within a loop, it will skip the remaining code, and start
# the next iteration. Comparable to 'continue' in C++

for(i in 1 :15) {
  if (i %% 2 == 0)  # Prints odd numbers
    next

  print (i)
}

# Data visualization in R consists of : pie chart, bar chart, boxplot, histogram, line graph, scatterplot

# Plotting a pie chart

vtr <- c(14, 28, 11, 30, 17)   # Percentage contribution by each department
name <- c('R & D', 'Marketing', 'Corporate', 'Sales', 'Support')
pie (vtr, name, col = rainbow(length (vtr)))

# Bar charts are used to compare things between different groups or to track changes over time

vtr <- c(14, 28, 11, 30, 17)   # Percentage contribution by each department
name <- c('R & D', 'Marketing', 'Corporate', 'Sales', 'Support')
barplot(vtr)

# Box plot is used to summarize data from multiple sources and display the results in a single graph

mtcars  # Sample dataset present in R
boxplot (mpg ~ cyl, data = mtcars, xlab = 'Number of cylinders', ylab = 'Miles per gallon', main = 'mileage',
         col = c('red', 'yellow', 'blue'))

# Histograms are used to plot frequency of score occurrences in a continuous data set that has been divided into
# classes, called bins.

hist(vtr, col = rainbow(length(vtr)))

# Line graphs are used to track changes over short and long periods of time

plot (vtr, type = 'l', col = length(vtr)) # p -> only points, l -> only lines , o -> both points and lines

# Scatter plots show how much one variable is affected by another

plot (vtr10, vtr11) # N(vtr10) and N(vtr11) should be equal