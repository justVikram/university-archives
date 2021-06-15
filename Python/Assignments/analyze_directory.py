import os

dir_and_extensions = {}
cumulative_count = 0


def analyse_directory(path):

    extension_and_files = {}
    os.chdir(path)

    dir_contents = os.listdir()

    for item in dir_contents:
        if item.find('.') == -1:
            relative_path = f'{path}/{item}'
            analyse_directory(relative_path)
            os.chdir('..')

        elif item.find('.') > 0:
            file_extension = item[item.find('.') + 1:]
            file_name = item[:item.find('.')]

            if extension_and_files.get(file_extension) is None:
                extension_and_files.update({file_extension: [file_name]})

            else:
                similar_files = extension_and_files.get(file_extension)
                similar_files.append(file_name)
                extension_and_files.update({file_extension: similar_files})

    global dir_and_extensions
    dir_and_extensions.update({path: extension_and_files})


def summarize_directory(dict):

    with open('../Assignments/my_text_file.txt', 'w') as fp:
        cols = 'DIR NAME\tLIST OF FILES\tEXTENSION\tCOUNT\tCUMULATIVE_COUNT\n'
        fp.write(cols)

        for dir_name, extension_with_files in reversed(dict.items()):
            for file_type, file_names in extension_with_files.items():

                write_to_file = f'{dir_name}\t\t\t'
                string_of_file_names = str()

                for file in file_names:
                    string_of_file_names += f'{file} '

                write_to_file += f'{string_of_file_names}\t\t'
                write_to_file += f'{file_type}\t\t'
                write_to_file += f'{len(file_names)}\t\t'

                global cumulative_count
                cumulative_count += len(file_names)

                write_to_file += f'{cumulative_count}'

                fp.write(f'{write_to_file}\n')


if __name__ == '__main__':
    full_path = os.getcwd()
    analyse_directory(full_path)
    summarize_directory(dir_and_extensions)
