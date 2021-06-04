# Title     : TODO
# Objective : TODO
# Created by: avikram
# Created on: 6/4/21

# ifelse (<condition>, YES, NO) function

a <- c(1, 2, 3, 4)
ifelse(a %% 2 == 0, "even", "odd")


# if-else-if ladder

b <- c(3, 4, 5, 6)

for (i in b) {
  if (i %% 3 == 0) {
    print("Divisible by 3")
  } else if (i %% 3 == 1) {
    print("Divisible by 3 with remainder 1")
  } else {
    print ("Divisible by 3 with remainder 2")
  }
}


# Defining functions () in R

calculateFactorial <- function (n) {
  factorial <- 1
  while (n > 0) {
    factorial <- n * factorial
    n <-  n - 1
  }
  print(paste("Factorial is", factorial))
}

calculateFactorial(5)


# Import text files

my_text_data <- read.table("~/Documents/Programming/R/Datasets/Sample_Data.txt")
my_text_data


# Import CSV

my_csv_data <- read.csv("~/Documents/Programming/R/Datasets/Sample_CSV_Data.csv")
my_csv_data


# Operations related to information associated with imported data

print(is.data.frame(my_csv_data))
print(ncol(my_csv_data))
print(nrow(my_csv_data))

max_id <- max(my_csv_data$ID)
print(max_id)

# Print details of person with ID 2

reqd_details <- subset(my_csv_data, ID == 2) # In parameters, the condition should be logical
reqd_details


# Performing operations on date

some_data <- subset(my_csv_data, as.Date(some_date) > as.Date('2014-01-01')) # Don't execute as there is no DATE field


# Writing values to another file

write.csv(reqd_details, "Sample_Output.csv", row.names = FALSE) # Stores in PWD


# Extract specific columns

extract_col_1 <- my_csv_data[ , 1] # For multiple columns: c(col1, col2, col3...)
extract_col_1


## Example ##

revenue <- c(100, 20, 500)
margin <- revenue * 0.02
city <- c('Hubli', 'Dharwad', 'Belgaum')

sales_data <- data.frame(revenue, margin, city)
write.csv(sales_data, "Sales_Data.csv", row.names = FALSE)

sales_data


# rbind () - The name of the rbind R function stands for row-bind.
# The rbind function can be used to combine several vectors, matrices and/or data frames by rows.

x1 <- c(7, 4, 4, 9)                  # Column 1 of data frame
x2 <- c(5, 2, 8, 9)                  # Column 2 of data frame
x3 <- c(1, 2, 3, 4)                  # Column 3 of data frame
data_1 <- data.frame(x1, x2, x3)     # Create example data frame
data_1
new_row <- c(9, 8, 7)
data_1 <- rbind(data_1, new_row)  # Insert new row
data_1


## Example to demonstrate rbind () ##

data_frame_1 <- data.frame(ID = 1:6, Product = c(rep("Toaster", 3), rep("Radio", 3)))
data_frame_1

data_frame_2 <- data.frame(ID = 1:4, Product = c(rep("TV", 3), rep("Mobile", 1)))
data_frame_2

appended_data_frame <- rbind(data_frame_1, data_frame_2)
appended_data_frame

# data.table() instead of data.frame() enables you to perform SQL-like operations (such as join, etc.)