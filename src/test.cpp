#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

/*
как же я **** с этими тестами :sad
*/

// фильтруем вывод. возможно код кривой возможно так и надо
// в трех словах - надо из первой строки удалить от `size` до последней `>`
void filter_output(char* buffer) {
    char* read_pos = buffer;

    char* pos = strrchr(read_pos, '>');
    if (pos) {
        read_pos = pos + 1; 
    }
    memmove(buffer, read_pos, strlen(read_pos) + 1);
}

int run(const char* input, const char* expected_output) {
    FILE* input_file = freopen("input.txt", "w+", stdin);
    FILE* output_file = freopen("output.txt", "w+", stdout);

    if (!input_file || !output_file) {
        return -1;
    }

    fprintf(input_file, "%s", input);
    rewind(input_file);

    int result = system("./main"); 

    fflush(stdout);
    freopen("/dev/tty", "a", stdout);

    FILE* actual_output = fopen("output.txt", "r");
    if (!actual_output) {
        return -1;
    }

    char buffer[2048];
    fread(buffer, sizeof(char), sizeof(buffer) - 1, actual_output);
    buffer[sizeof(buffer) - 1] = '\0';

    fclose(actual_output);
    fclose(input_file);
    filter_output(buffer);


    // дебажим, чзх почему там вывод кривой, но тесты правильные должен проходить (спойлер - какая-то кака выкидывается и не проходит)
    printf("Actual Output:\n%s\n", buffer);
    printf("Expected Output:\n%s\n", expected_output);

    return strcmp(buffer, expected_output) == 0 ? 0 : 1;
}

void test() {
    struct {
        const char* input;
        const char* expected_output;
    } tests[] = {
        /*
            тут еще шутка в чем, из за всяких манипуляций не возможно заранее предсказать вывод ))
            1) взять готовое решение и тестировать на нем. но могут быть отличия из-за реализации
            2) преподам заготовить по-больше примеров для тестов :?

            иначе пока не вижу в тестах смысл, они делаются для галочки, с божьей помощью llm`ок и гугла

            вообще на подумать - написать готовый тестовый скриптик, который берет из файлика test1 : [ввод, вывод], а там уже сами дотыкают всякие фильтры и тд
        */
        
        {"4\nh w !\nh\nw\n!\n", "1 1 1 \n1 0 0 \n0 1 0 \n0 0 1 \n"},
        {"2\nabc def\nghi jkl\n", "1 0 1 0 \n0 1 0 1 \n"},
        {"3\nabc def\nghi jkl\nmno pqr\n", "1 0 0 1 0 0 \n0 1 0 0 1 0 \n0 0 1 0 0 1 \n"},
        {"1\nfoo bar\n", "1 1 \n"},
        {"1\nhe he\n", "1 \n"},
        {"5\na b c d\ne f a b\na b c d\na b\na a a a\n", "1 1 1 1 0 0 \n1 0 1 0 1 1 \n1 1 1 1 0 0 \n1 0 1 0 0 0 \n1 0 0 0 0 0 \n"},
    };

    int size = sizeof(tests) / sizeof(tests[0]);
    for (int i = 0; i < size; i++) {
        int result = run(tests[i].input, tests[i].expected_output);
        CU_ASSERT_EQUAL(result, 0);
    }
}

int main() {
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }

    CU_pSuite pSuite = CU_add_suite("Lab1Test", 0, 0);
    if (pSuite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_add_test(pSuite, "main", test);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
