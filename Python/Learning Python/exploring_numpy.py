import numpy as np

my_list = [1, 2, 3, 4, 5]
single_dim_array = np.array(my_list, np.int16)  # Specifies data type of array
print(single_dim_array)

# Each list is like a row, and each element inside is a column
arr_2d = np.array([[2, 4, 6, 8], [3, 5, 7, 9], [10, 11, 12, 13]])
print(arr_2d)
print(arr_2d[2, 0])  # 0th row, 1st column

# Array elements are mutable
arr_2d[1, 0] = 1
print(arr_2d)


# A few useful attributes of arrays
print(arr_2d.dtype)  # Prints the data type
print(arr_2d.shape)  # Prints the order of the matrix
print(arr_2d.size)  # Prints the total number of entries in the matrix
print(arr_2d.ndim)  # Prints the dimension of array (1d, 2d, ...)
print(arr_2d.nbytes)  # Prints the number of bytes


# Create object arrays with dictionaries
obj_arr = np.array({'do', 'not', 'use', 'this'})
print(obj_arr.dtype)


# Creating matrix of zeros of desired order
zeros = np.zeros((2, 3))
print(zeros)


# Gives an array with elements from 0 to N-1
rng = np.arange(10)
print(rng)

# Linspace (x, y, z) Gives z linearly spaces numbers from x to y
eq_spaced_nums = np.linspace(7, 30, 4)
print(eq_spaced_nums)

# Create an array with similar dimensions as that of input
similar_md_arr = np.empty_like(arr_2d)
print(similar_md_arr)
print(similar_md_arr.shape)


# Make identity matrix
iden_mtr = np.identity(5)  # Order: 5x5
print(iden_mtr)


# Changes order of array. The new order should be equal to the old order
# when R and C are multiplied
rng = np.reshape(rng, (5, 2))
print(rng.shape)
print(rng)

# To get a simple 1D array again
rng = rng.ravel()
print(rng)


# An n-dimensional array has n axis.
# Axis 0 is toward south, and axis 1 is toward east in the case of 2D array
x = [[1, 2, 3], [4, 5, 6], [8, 9, 10]]
arr = np.array(x)
print(arr.sum(axis=0))  # Column sum
print(arr.sum(axis=1))  # Rum sum


# Get transpose
print(arr.T)


# Gives a 1D array to iterate over
for item in arr.flat:
    print(item)


# Get index of max and min element
print(arr.argmax())
print(arr.argmin())
print(arr.argmin(axis=0))


# Get actual max and min element
print(arr.max())
print(arr.min())


# Get indices of the theoretically sorted array
print(arr.argsort())


# Operations on arr
arr1 = np.array([[1, 6, 3], [7, 4, 9]])
arr2 = np.array([[4, 2, 3], [8, 7, 5]])
print(arr1 + arr2)
print(arr1 * arr2)
print(np.sqrt(arr1))


# Find elements in arrays
print(np.where(arr1 > 8))


# Get count of non-zero elements
print(np.count_nonzero(arr1))
