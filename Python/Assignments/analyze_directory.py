import os

dir_and_extensions = {}


def analyse_directory(path):

    extension_and_files = {}
    os.chdir(path)

    dir_contents = os.listdir()

    for item in dir_contents:
        if item.find('.') == -1:
            analyse_directory(item)
            os.chdir('..')

        elif item.find('.') > 0:
            file_extension = item[item.find('.'):]

            if extension_and_files.get(file_extension) is None:
                extension_and_files.update({file_extension: [item]})

            else:
                similar_files = extension_and_files.get(file_extension)
                similar_files.append(item)
                extension_and_files.update({file_extension: similar_files})

    global dir_and_extensions
    dir_and_extensions.update({path: extension_and_files})


def summarize_directory(dict):

    with open('../Assignments/my_text_file.txt', 'w') as fp:
        file_type_and_count = {}

        for dir_name, files in dict.items():

            fp.write(f'\n{dir_name} contains:\n')

            for file_type, file_names in files.items():
                fp.write(f'\n{file_names}')
                fp.write(f'\nTotal number of {file_type} files: \
                    {len(file_names)}\n')

                if file_type_and_count.get(file_type) is None:
                    file_type_and_count.update({file_type: len(file_names)})

                else:
                    count = file_type_and_count.get(file_type)
                    count = count + len(file_names)
                    file_type_and_count.update({file_type: count})

        fp.write(f'\n\nTotal count of files of each type: \
            {file_type_and_count}')


if __name__ == '__main__':

    analyse_directory('../Learning Python')
    print(dir_and_extensions)
    summarize_directory(dir_and_extensions)
