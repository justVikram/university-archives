# Title     : Lung Data Analysis
# Created by: avikram
# Created on: 6/5/21

lung_data <- read.csv('~/Documents/Programming/R/Datasets/Lung_Data.csv')

class(lung_data)

dim(lung_data) # Check dimension of data frame

head(lung_data) # Get first few entries of data frame

lung_data[5:9, ] # Specify columns after comma, leave blank for all columns
lung_data[c(1, 3, 5), ]

mean(lung_data$Age)
mean(lung_data$Age [lung_data$Gender == 'female']) # Mean age of females
mean(lung_data$Age [lung_data$Gender == 'male']) # Mean age of males


# Making subsets using data variables

female_data <- subset(lung_data, lung_data$Gender == 'female')
female_data

male_data <- subset(lung_data, lung_data$Gender == 'male')
male_data

summary(female_data) # Gives summary of the dataset
summary(male_data)

male_over_age_15 <- subset(male_data, male_data$Age > 15)
male_over_age_15

female_over_age_15 <- subset(female_data, female_data$Age > 15)
female_over_age_15

people_who_smoke <- subset(lung_data, lung_data$Smoke == 'yes')
people_who_smoke


# Boxplot

boxplot(female_over_age_15$LungCap, male_over_age_15$LungCap, col = rainbow(2), horizontal = TRUE,
        names = c('Female', 'Male'))

boxplot_of_males <- boxplot(male_over_age_15$LungCap, col = rainbow(1), horizontal = TRUE, names = 'Male')

boxplot_of_males$out # Get outliers

male_outliers <- subset(male_over_age_15, male_over_age_15$LungCap == 6.450 | male_over_age_15$LungCap == 7.175)
male_outliers #TODO

lung_cap_of_females_who_smoke <- subset(lung_data, lung_data$Gender == 'female' & lung_data$Smoke == 'yes')

lung_cap_of_females_who_dont_smoke <- subset(lung_data, lung_data$Gender == 'female' & lung_data$Smoke == 'no')

boxplot(lung_cap_of_females_who_smoke$LungCap, lung_cap_of_females_who_dont_smoke$LungCap,
        col = rainbow(2), names = c('Female Smoke', 'Female  non-Smoke'))

a_division <- read.csv('~/Documents/Programming/R/Datasets/Minor1_A.csv')
b_division <- read.csv('~/Documents/Programming/R/Datasets/Minor1_B.csv')

boxplot(a_division$M.1, b_division$M.1, col = rainbow(2), names = c('A Division', 'B division'))

