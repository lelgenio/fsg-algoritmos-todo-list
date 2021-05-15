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
