#include "test_util.h"
#include <stdlib.h>

#include "todo.h"

int main() {
    struct Todo_list todo_list = todo_list_create();

    assert_eq(todo_list.size, 0);

    todo_list_add(&todo_list, "my title 1", "my text 1");
    todo_list_add(&todo_list, "my title 2", "my text 2");

    assert_eq(todo_list.size, 2);

    assert_eq(todo_list_query(&todo_list, 1)->title[0], 'm');
    assert_eq(todo_list_query(&todo_list, 1)->title[1], 'y');

    todo_list_remove(&todo_list, 0);
    todo_list_remove(&todo_list, 1);

    assert_eq(todo_list.size, 0);

    return 0;
}
