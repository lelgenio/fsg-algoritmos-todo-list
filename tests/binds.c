#include <stdlib.h>

#include "binds.h"
#include "test_util.h"

int main() {
    struct Keybinds binds = binds_create_keybinds();

    assert_eq(binds.size,0);

    binds_add_keybind(&binds, 'h', ACTION_LEFT);
    binds_add_keybind(&binds, 'j', ACTION_DOWN);

    assert_eq(binds.size,2);

    assert_eq(binds_query_keybind(&binds, 'h'), ACTION_LEFT);
    assert_eq(binds_query_keybind(&binds, 'j'), ACTION_DOWN);

    return 0;
}
