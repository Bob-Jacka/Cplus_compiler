###App variables
###App author do not sure that this utility won't corrupt computer filesystem
###App made for python 3.12 or above
import os.path

STATIC_FILE_NAME_WITH_DIRECTIVES = 'Custom_operators.hpp'  # file with directives
STATIC_DIRECTIVE_START = '#define'  # directive start in C++
STATIC_PREPREPROCESSOR_START = 'core'  # define this variable if you have another start dir, where you store another directories

exclude_file_names: list[str] = ['Test', 'dependencies',
                                 'Tests', 'Variables', 'Constants', 'CplusModel', 'Processor_registers',
                                 'NeuroNetwork']  # exclude files or maybe dir with these names from sin...

directives: dict[str, str] = dict()  # key is default value from C++ and value custom directive
version = '1.1.0'


def help_user():
    """
    Simple help function for user
    :return: None
    """
    print('PrePreprocessor app, made by my strange ideas')
    print('Scans file for directives in C++ and replace with super strange directive (macro)')
    print(f'To use this app you will need - {STATIC_FILE_NAME_WITH_DIRECTIVES} file, where C++ directives contains.')
    print(f'App will start work for replace words from - {STATIC_DIRECTIVE_START} directory and move through dirs.')
    print(f'These files or maybe directories with names are not using - {exclude_file_names}.')
    print(f'App version - {version}.')


def init_directives_from_file():
    """
    Open file with C++ directives and copy new custom types to dict
    Example:
        #define elif else if - proceed into elif : 'else if'
    :return: None
    """
    with open(STATIC_FILE_NAME_WITH_DIRECTIVES, 'r') as file:
        try:
            for line in file.readlines():
                if line.startswith(STATIC_DIRECTIVE_START) and not line.endswith('_HPP\n'):
                    line = line.replace(STATIC_DIRECTIVE_START, '')
                    line = line[0: line.find('//')]  # look for comments in C++
                    values = line.split(' ')  # split into list of lexemes
                    for val in values:
                        if val == '':
                            values.remove(val)  # remove empty string value

                    size = len(values)
                    if size == 2:
                        directives[values[1]] = values[0]  # values2 - original operator or two words
                    if size == 3:
                        directives[values[1] + ' ' + values[2]] = values[0]  # values2 - original operator or two words
        except Exception as e:
            print(f'Error occurred in init directives from file - {e}.')
            raise Exception(f'Error occurred in init directives from file - {e}.')


def prepreprocess():
    """
    Main cycle function of the app.
    Proceed directories for directives to replace
    :return: None
    """
    if os.path.exists(STATIC_PREPREPROCESSOR_START):
        print('Prepreprocessor start found')
        traverse(STATIC_PREPREPROCESSOR_START)
    else:
        raise Exception(
            f'Pre-pre processor start file was not found. Please add {STATIC_PREPREPROCESSOR_START} or define your start.')


def __get_filename_from_path(path: str):
    """
    Function for receiving filename from given path,
    :param path: given path
    :return: file name
    """
    cond = os.path.sep in path
    if cond:
        return path[path.rfind(os.path.sep):]
    else:
        return path


def __contains_one_of_exclude(name: str) -> bool:
    """
    Function for checking that filename do not contain in exclude list.
    :param name: name for checking
    :return: boolean result
    """
    if name is not None:
        for exclude_fragment in exclude_file_names:
            if exclude_fragment in name:
                return True
    return False


def traverse(path: str) -> None:
    """
    Recursive function for directories proceed
    :param path: path to proceed
    :return: None
    """
    file_name = __get_filename_from_path(path)
    if not __contains_one_of_exclude(file_name):
        if os.path.isfile(path):
            __process_file(path)
        elif os.path.isdir(path):
            for entry in os.listdir(path):
                traverse(os.path.join(path, entry))
        else:
            print(f"{path}: nor file or dir")
    else:
        print(f'Name of the element ({file_name}) in exclude list!')


def __process_file(file: str):
    """
    Function for proceeding file for directives
    :return: None
    """
    try:
        print(f'Started processing file with name - {file}.')
        with open(file, 'r') as f:
            data = f.read()
            for directive in directives.keys():
                data = data.replace(directive, directives.get(directive))
        print(f'Writing into file with name - {file}.')
        with open(file, 'w') as f:
            f.write(data)
    except Exception as e:
        print(f'Error occurred in process file - {e}.')


def init_app():
    """
    Initialize app
    :return: None
    """
    if os.path.exists(STATIC_FILE_NAME_WITH_DIRECTIVES):
        print('Start init directives from file.')
        init_directives_from_file()
        print(f'Directives inited with - {str(directives.values())[13:-2]}')
        print(f'Excluded files - {str(exclude_file_names)[9:-1]}')
    else:
        raise Exception('No file with directives was found.')


if __name__ == '__main__':
    init_app()
    while True:
        print('App usage:')
        print('1. Start preprocess')
        print('2. Help')
        print('3. Exit')
        user_input = int(input('>> '))
        match user_input:
            case 1:
                prepreprocess()
            case 2:
                help_user()
            case 3:
                print('Bye')
                exit(0)
            case _:
                print('Try again')
                continue
    print('App ended work.')
