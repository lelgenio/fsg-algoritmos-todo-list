#include <stdio.h>
#include <ncurses.h>

#define PROJECT_NAME "todo-list"

int main() {
    initscr();

    printw("Hello world");

    refresh();

    getch();

    endwin();
}
