
# Алгоритмы сортировки

Этот репозиторий содержит три алгоритма сортировки (Comb Sort, Heap Sort, Bucket Sort) вместе с модульными тестами, написанными с использованием CUnit. Следуйте шагам ниже, чтобы склонировать репозиторий, собрать проект и запустить тесты.

## Требования

Перед началом убедитесь, что у вас установлены следующие компоненты:

1. **CMake** (версии 3.10 или выше)
2. **Ninja** (в качестве системы сборки)
3. **Компилятор Clang/MinGW** (или GCC, если Clang недоступен)
4. **CUnit** (фреймворк для модульного тестирования на C++)

## Пошаговая инструкция

### 1. Клонируйте репозиторий

```bash
git clone https://github.com/your-username/sorting-algorithms.git
cd sorting-algorithms
```

### 2. Установите зависимости

#### Для Windows

- Установите CUnit через MSYS2:
  ```bash
  pacman -S mingw-w64-x86_64-cunit
  ```

- Убедитесь, что `clang` или `gcc` находятся в переменной PATH.

#### Для Linux

- Установите CUnit:
  ```bash
  sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev
  ```

- Убедитесь, что `gcc` и `clang` установлены.

#### Для macOS

- Установите CUnit через Homebrew:
  ```bash
  brew install cunit
  ```

- Убедитесь, что `clang` установлен (идет в составе Xcode Command Line Tools).

### 3. Создайте папку для сборки

```bash
mkdir build
cd build
```

### 4. Сконфигурируйте проект

```bash
cmake .. -G "Ninja" -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
```

### 5. Соберите проект

```bash
ninja
```

### 6. Запустите модульные тесты

Каждый тест собирается в исполняемый файл, расположенный в папке `build/test`. Вы можете запустить их по отдельности:

```bash
cd test
./test_comb_sort
./test_heap_sort
./test_bucket_sort
```

Результаты выполнения тестов отобразятся в консоли.
(Если не получится собрать проект с первого раз, то не расстрииваейтесь. Дорогу осилит идущий!)