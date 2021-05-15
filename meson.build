project('todo-list', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

###################################################

ncurses = dependency('ncurses')

###################################################

sources = files(
    'src/main.c',
    'src/binds.c',
    'src/config.c',
    'src/csv.c',
    'src/input.c',
    'src/list.c',
    'src/ui.c',
)

###################################################

exe = executable(
    'todo_list',
    sources,
    include_directories: include_directories('include'),
    install : true,
    dependencies: [
        ncurses,
    ]
)


###################################################

subdir('tests')
