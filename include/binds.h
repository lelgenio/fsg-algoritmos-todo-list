#pragma once

enum Action {
    ACTION_NOOP,
    ACTION_UP,
    ACTION_DOWN,
    ACTION_LEFT,
    ACTION_RIGHT,
};

struct Keybind {
    char key;
    enum Action action;
};

struct Keybinds {
    int size;
    int capacity;
    struct Keybind *items;
};

struct Keybinds binds_create_keybinds();

void binds_resize(struct Keybinds *keybinds);

void binds_add_keybind(struct Keybinds *keybinds, char key, enum Action action);

enum Action binds_query_keybind(struct Keybinds *keybinds, char key);
