#include <stdlib.h>

#include "binds.h"

struct Keybinds binds_create_keybinds() {
    struct Keybind *items = malloc(sizeof(struct Keybind));
    struct Keybinds keybinds = {0, 64, items};
    return keybinds;
}

void binds_resize(struct Keybinds *keybinds) {
    if (keybinds->size < keybinds->capacity)
        return;

    keybinds->capacity *= 2;
    keybinds->items = realloc(keybinds->items, keybinds->capacity);
}

void binds_add_keybind(struct Keybinds *keybinds, char key,
                       enum Action action) {
    binds_resize(keybinds);
    struct Keybind keybind = {key, action};
    keybinds->items[keybinds->size] = keybind;
    keybinds->size++;
}

enum Action binds_query_keybind(struct Keybinds *keybinds, char key) {
    for (int i = 0; i < keybinds->size; i++)
        if (keybinds->items[i].key == key)
            return keybinds->items[i].action;
    return ACTION_NOOP;
}
