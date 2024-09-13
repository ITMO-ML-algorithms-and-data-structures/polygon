#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

int run(const char* input) {
    FILE* tmpfile = fopen("input.txt", "w");
    if (tmpfile == NULL) return -1;

    fprintf(tmpfile, "%s", input);
    fclose(tmpfile);

    char command[256];
    snprintf(command, sizeof(command), "cat input.txt | src/output/main");
    return system(command); // тут не без помощи гугла, но на первый взгяд, это оочень просто можно ломается :pls не бейте за безопасность
}

void test() {
    struct {
        const char* input;
        int expected_return;
    } tests[] = {
        {"(){}[]", 0},
        {"([)]\n", 256},
        {"(\n", 256},
        {")\n", 256},
        {"{]\n", 256},
        {"{[()]}\n", 0},
        {"{[(])}\n", 256},
        {"abc123\n", 256},
        {"{[()(()]}\n", 256}
    };

    int size = sizeof(tests) / sizeof(tests[0]);
for (int i = 0; i < size; i++) { 
    auto t = tests[i]; // за авто извени
    int result = run(t.input);
    CU_ASSERT_EQUAL(result, t.expected_return);
    }
}

int main() {
    // гордо спёрто с cunit quickstart 
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }

    CU_pSuite pSuite = CU_add_suite("lab1test", 0, 0);
    if (pSuite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_add_test(pSuite, "lab1test", test);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}