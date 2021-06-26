import os


def read_from_file(base_dir):
    new_dir = base_dir
    with open('my_text_file.txt', 'r') as fp:
        lines = fp.readlines()

        for line in lines:
            words = line.split('\t')

            for word in words:
                if word.find('/') == 0:
                    dir_name = word[word.rfind('/') + 1:]

                elif word.find(' ') != -1:
                    file_names = word.split(' ')

                elif word.isdigit() is False:
                    extension = word

                elif word.isdigit() is True:
                    break

            if new_dir[new_dir.rfind('/') + 1:] != dir_name:
                new_dir += f'/{dir_name}'

            os.mkdir(new_dir)
            os.chdir(new_dir)

            for file in file_names:
                open(f'{file}.{extension}', 'a').close()

            print("Done!")


if __name__ == '__main__':
    base_dir = input('Enter dir:')
    read_from_file(base_dir)
