import os
import pickle


def print_sub_dirs():

    dir_contents = os.listdir()

    selected_sub_dirs = []

    for file in dir_contents:
        if file.find('.') == -1:
            selected_sub_dirs.append(file)

    print(selected_sub_dirs)


def make_directory():

    dir_contents = os.listdir()

    for file in dir_contents:
        if file == 'sub_dir_2':
            os.chdir('sub_dir_2')
            os.mkdir('My_Folder')

            print("Directory 'My_Folder' created successfully!")


def transfer_file_contents():

    os.chdir('sub_dir_3')

    with open('read_me.txt') as txt_file:
        data = txt_file.read()

    os.chdir('..')
    os.chdir('sub_dir_4')

    with open('new_text_file.txt', 'w') as new_txt_file:
        new_txt_file.write(data)

    print('Contents of read_me.txt have been copied to new_txt_file.txt')


def write_to_pkl_file():

    list_of_int = []

    for i in range(0, 10):
        var_int = int(input('Enter a number: '))
        list_of_int.append(var_int)

    pickle.dump(list_of_int, open('my_pickle_file.pkl', 'wb'))
    print('The numbers entered have been saved to my_pickle_file.pkl!')


def get_directory_structure():

    dir_contents = os.listdir()

    contained_sub_dirs = []

    for file in dir_contents:
        if file.find('.') == -1:
            contained_sub_dirs.append(file)

    for sub_dir in contained_sub_dirs:
        os.chdir(sub_dir)
        print(f'In {sub_dir}:')
        print(os.listdir())
        print('\n')
        os.chdir('..')

    print('Files contained within sub-directories have been displayed!')


if __name__ == '__main__':

    # Sub-question: a
    print_sub_dirs()

    # Sub-question: b
    make_directory()

    # Sub-question: c
    transfer_file_contents()

    # Sub-question: d
    write_to_pkl_file()

    # Sub-question: e
    get_directory_structure()
