#pragma once

struct Todo_item  {
    char* title;
    char* text;
};

struct Todo_list {
    int size;
    int capacity;
    struct Todo_item* items;
};
