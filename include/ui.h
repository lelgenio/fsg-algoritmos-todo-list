#pragma once

#include "include/todo.h"

enum View {
    VIEW_TODO_LIST,
    VIEW_TODO_ITEM,
};

struct State {
    enum View view;
    struct Todo_list todo_list;
};
