tests = [
    'binds.c',
]

foreach test : tests
    sources = files (
        test,
        '../src' / test
    )
    exe = executable(
        test,
        sources,
        include_directories: include_directories('../include'),
        dependencies: [
            ncurses,
        ]
    )

    test(tests , exe)
endforeach
