# Q1
import os
dir_contents = os.listdir()  # Fetch and store directory contents
extension = input('Enter file extension: ')

for file in dir_contents:
    if file.endswith(f'.{extension}'):
        print(file)


# Q2
import os
Number_of_files_reqd = int(input('Enter number of files to select: '))
dir_contents = os.listdir()

selected_files = []

for file in dir_contents:
    if file.find('.') > 0:  # Ignores hidden files and directories
        selected_files.append(file)

    if selected_files.__len__() == Number_of_files_reqd:
        break

print(selected_files)
