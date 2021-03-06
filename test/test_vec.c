#include "../src/co_vec.h"

int main(int argc, char const *argv[])
{
    covec_t *vec = covec_new(sizeof(int));

    int i, v;
    for (i = 0; i < 20; ++i) {
        covec_push_tail(vec, &i);
    }
    for (i = 20; i < 40; ++i) {
        covec_push_head(vec, &i);
    }
    for (i = 40; i < 60; ++i) {
        covec_push(vec, -1, &i);
    }

    for (i = 0; i < covec_size(vec); ++i) {
        covec_get(vec, i, &v);
        printf("index=%d, value=%d\n", i, v);
    }

    v = 100;
    covec_set(vec, 0, &v);
    covec_set(vec, 1, &v);

    for (i = 0; i < 2; ++i) {
        covec_get(vec, i, &v);
        printf("index=%d, value=%d\n", i, v);
    }

    for (i = 0; i < 50; ++i) {
        covec_del(vec, 0, NULL);
    }

    for (i = 0; i < covec_size(vec); ++i) {
        covec_get(vec, i, &v);
        printf("index=%d, value=%d\n", i, v);
    }

    covec_t *vec2 = covec_new(sizeof(int));
    covec_copy(vec, vec2);

    for (i = 0; i < covec_size(vec2); ++i) {
        covec_get(vec2, i, &v);
        printf("index=%d, value=%d\n", i, v);
    }

    covec_free(vec);
    covec_free(vec2);
    return 0;
}
