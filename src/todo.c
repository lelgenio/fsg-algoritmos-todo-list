#include <stdlib.h>
#include <string.h>

#include "todo.h"

struct Todo_list todo_list_create() {
    struct Todo_list todo_list = {
        0,
        0,
        NULL,
    };
    return todo_list;
}

void todo_list_add(struct Todo_list *todo_list, char *title, char *text) {

    struct Todo_item *new_item = malloc(sizeof(struct Todo_item));

    new_item->title = malloc(sizeof(char) * 1024);
    new_item->text = malloc(sizeof(char) * 1024);

    strcpy(new_item->title, title);
    strcpy(new_item->text, text);

    new_item->id = todo_list->next_id++;
    new_item->next = NULL;

    if (todo_list->first == NULL) {
        todo_list->first = new_item;
    } else {
        struct Todo_item *next_item = todo_list->first;
        while (next_item->next != NULL)
            next_item = next_item->next;
        next_item->next = new_item;
    }

    todo_list->size++;
}

struct Todo_item *todo_list_query(struct Todo_list *todo_list, int index) {
    if (todo_list->size < index || todo_list->size == 0)
        return NULL;

    struct Todo_item *item = todo_list->first;
    while (index--)
        item = item->next;

    return item;
}

void todo_list_item_free(struct Todo_item *todo_item) {
    free(todo_item->title);
    free(todo_item->text);
    free(todo_item);
}

void todo_list_remove(struct Todo_list *todo_list, int id) {
    if (todo_list->first->id == id) {
        struct Todo_item *second_item = todo_list->first->next;
        todo_list_item_free(todo_list->first);
        todo_list->first = second_item;
        todo_list->size--;
        return;
    }

    for (struct Todo_item *item = todo_list->first; item; item = item->next) {
        if (item->next->id == id) {
            struct Todo_item *second_next_item = item->next->next;
            todo_list_item_free(item->next);
            item->next = second_next_item;
            todo_list->size--;
        }
    }
}

// struct Todo_list todo_list_read_from_file(struct Todo_list *todo_list, int
// id) {
// }

// void todo_list_save_to_file(struct Todo_list *todo_list) {}
