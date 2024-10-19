// В Count_vectorizer.h два метода. Один для вектора,а второй для файла.
// В Count_vectorizer_tests.h там 4 теста для разных проверок и пятая проверка на тест лимитов.
// для генерации использовал пятого теста использовал
// python generate_dataset.py --mode text --max-length 100 --num-rows 10000 --charset default --enter 1 --min-unique 100 --output-file dataset.txt --delimiter \n
#include "Count_vectorizer_tests.h"
using namespace std;
int main () {
  Count_vectorize_tests::test1();
  // Count_vectorize_tests::tests();
  // Count_vectorize_tests::test6();
}
