# Title     : R Assessment
# Created by: Aditya Vikram (01fe19bcs220)
# Created on: 6/23/21

# Q1.a
weather_data <- read.csv('weatherAUS.csv')
print('The weather details of Australia are as follows:')
weather_data

# Q1.b
gust_speed_is_50 <- subset(weather_data, weather_data$WindGustSpeed == 50)
reqd_attrs <- gust_speed_is_50[, c(1, 2, 3)]

print('The tuples consisting of location, min temp, and max temp when the gust speed is 50 are:')
reqd_attrs

# Q1.c
humidity_lt_20 <- subset(weather_data, weather_data$Humidity3pm < 20)
write.csv(humidity_lt_20, 'q1-c.csv', row.names = FALSE)
print('Data has been written to file q1-c.csv!')

#Q2
pressure_9_am <- weather_data[, 8]
pressure_3_pm <- weather_data[, 9]

# Boxplot
boxplot_pressure_comparison <- boxplot(pressure_9_am, pressure_3_pm, col = rainbow(2), names =
  c('Pressure @ 9 AM','Pressure @ 3 PM' ))
print('From the boxplot, we conclude that the the pressure at 9 AM has values that are far apart
from each other than pressure at 3 PM.
The boxplot for 9 AM is negatively skewed, while that for 3 AM is positively skewed')

# Outliers
outlier_9_am <- boxplot_pressure_comparison$out[1]
print(paste('Outlier of Pressure at 9 AM is', outlier_9_am))

outlier_3_pm <- boxplot_pressure_comparison$out[2]
print(paste('Outlier of Pressure at 3 PM is', outlier_3_pm))

# Quantiles
print('Quantile data for Pressure at 9 AM is as follows:')
quantile(pressure_9_am)

print('Quantile data for Pressure at 3 AM is as follows:')
quantile(pressure_3_pm)
