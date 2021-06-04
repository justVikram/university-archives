# Title     : TODO
# Objective : TODO
# Created by: avikram
# Created on: 5/29/21

# Q1
users <- c(50,17, 11, 7, 22, 44, 28, 21, 19, 23, 37, 51, 54, 42, 88, 41, 78, 56, 72, 56, 7, 69, 80, 30, 33, 46, 39,
         20, 18, 29, 73, 77, 39, 30, 62, 54, 67, 39, 31, 53, 44)

n <- ceiling(1 + 3.322 * log10(41))
H <- max(users)
L <- min(users)

class_width <- ceiling((H - L) / n)

class_interval <- seq(L, 91, by=class_width)

make_tallies <- cut(users, class_interval, right = F)
frequency_distbn_table <- table(make_tallies)
cbind(frequency_distbn_table)

par(mfrow<- c(1,2)) # Tells how many figures to display side by side (1 row

histogram_of_users <- hist(users, breaks = class_interval, xlab = "internet users", xlim = c(0, 110), right = F)

text(histogram_of_users$mids, histogram_of_users$counts, label = histogram_of_users$counts, adj = c(-0.5, 0.5))

plot(histogram_of_users$mids, frequency_distbn_table, type = "o", main = 'Frequency Polygon of Users')

# Less than ogive
lt_cumulative_frequency <- c(0, cumsum(frequency_distbn_table))
lt_cumulative_frequency
plot(class_interval, lt_cumulative_frequency, main = "Less than ogive")
lines(class_interval, lt_cumulative_frequency)


# More than ogive
gt_cumulative_frequency <- sum(frequency_distbn_table) - lt_cumulative_frequency
gt_cumulative_frequency
plot(class_interval, gt_cumulative_frequency, main = "More than ogive")
lines(class_interval, gt_cumulative_frequency)
 # end of question#


# Q9 From LP
students <- c(75, 89, 66, 52, 90, 68, 83, 94, 77, 60, 38, 47, 87, 65, 97, 49, 65, 70, 73, 81, 85, 77, 83, 56, 63, 79,
              69, 82, 84, 70, 62, 75, 29, 88, 74, 37, 81, 76, 74, 63, 69, 73, 91, 87, 76, 58, 63, 60, 71, 82)

n <- ceiling(1 + 3.322 * log10(50))
H <- max(students)
L <- min(students)

class_width <- ceiling((H - L) / n)

class_interval <- seq(L, 99, by=class_width)  # REMEMBER TO CHANGE THIS TO ALTER VALUE

make_tallies <- cut(students, class_interval, right = F)
frequency_distbn_table <- table(make_tallies)
cbind(frequency_distbn_table)

# Right F -> Exclude upper limits
histogram_of_students <- hist(students, breaks = class_interval, xlab = "Students", xlim = c(0, 110), right = F, col = rainbow(7))

text(histogram_of_students$mids, histogram_of_students$counts, label = histogram_of_students$counts, adj = c(-0.5, 0.5))

plot(histogram_of_students$mids, frequency_distbn_table, type = "o", main = 'Frequency Polygon of Students')

# Less than ogive
lt_cumulative_frequency <- c(0, cumsum(frequency_distbn_table))
lt_cumulative_frequency
plot(class_interval, lt_cumulative_frequency, main = "Less than ogive")
lines(class_interval, lt_cumulative_frequency)


# More than ogive
gt_cumulative_frequency <- sum(frequency_distbn_table) - lt_cumulative_frequency
gt_cumulative_frequency
plot(class_interval, gt_cumulative_frequency, main = "More than ogive")
lines(class_interval, gt_cumulative_frequency)
# end of question #


# Using sample data
airquality
attach(airquality)
hist(Temp)