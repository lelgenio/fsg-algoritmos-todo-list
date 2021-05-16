#pragma once

struct Todo_item {
    char *title;
    char *text;
    int id;
    struct Todo_item* next;
};

struct Todo_list {
    int size;
    int next_id;
    struct Todo_item *first;
};

struct Todo_list todo_list_create();

void todo_list_add(struct Todo_list *todo_list, char *title, char *text);

void todo_list_remove(struct Todo_list *todo_list, int id);

struct Todo_item *todo_list_query(struct Todo_list *todo_list, int index);

struct Todo_list todo_list_read_from_file(struct Todo_list *todo_list, int id);

void todo_list_save_to_file(struct Todo_list *todo_list);
