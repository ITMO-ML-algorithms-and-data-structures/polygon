import pathlib
import typing as tp
import random
T = tp.TypeVar("T")


def read_sudoku(path: tp.Union[str, pathlib.Path]) -> tp.List[tp.List[str]]:
    """ Прочитать Судоку из указанного файла """
    path = pathlib.Path(path)
    with path.open() as f:
        puzzle = f.read()
    return create_grid(puzzle)


def create_grid(puzzle: str) -> tp.List[tp.List[str]]:
    digits = [c for c in puzzle if c in "123456789."]
    grid = group(digits, 9)
    return grid


def display(grid: tp.List[tp.List[str]]) -> None:
    """Вывод Судоку """
    width = 2
    line = "+".join(["-" * (width * 3)] * 3)
    for row in range(9):
        print(
            "".join(
                grid[row][col].center(width) + ("|" if str(col) in "25" else "") for col in range(9)
            )
        )
        if str(row) in "25":
            print(line)
    print()


def group(values: tp.List[T], n: int) -> tp.List[tp.List[T]]:
    """
    Сгруппировать значения values в список, состоящий из списков по n элементов

    >>> group([1,2,3,4], 2)
    [[1, 2], [3, 4]]
    >>> group([1,2,3,4,5,6,7,8,9], 3)
    [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    """
    result = []
    for i in range(0, len(values), n):
        result.append(values[i:i + n])

    return result


def get_row(grid: tp.List[tp.List[str]], pos: tp.Tuple[int, int]) -> tp.List[str]:
    """Возвращает все значения для номера строки, указанной в pos

    >>> get_row([['1', '2', '.'], ['4', '5', '6'], ['7', '8', '9']], (0, 0))
    ['1', '2', '.']
    >>> get_row([['1', '2', '3'], ['4', '.', '6'], ['7', '8', '9']], (1, 0))
    ['4', '.', '6']
    >>> get_row([['1', '2', '3'], ['4', '5', '6'], ['.', '8', '9']], (2, 0))
    ['.', '8', '9']
    """
    return grid[pos[0]]

def get_col(grid: tp.List[tp.List[str]], pos: tp.Tuple[int, int]) -> tp.List[str]:
    """Возвращает все значения для номера столбца, указанного в pos

    >>> get_col([['1', '2', '.'], ['4', '5', '6'], ['7', '8', '9']], (0, 0))
    ['1', '4', '7']
    >>> get_col([['1', '2', '3'], ['4', '.', '6'], ['7', '8', '9']], (0, 1))
    ['2', '.', '8']
    >>> get_col([['1', '2', '3'], ['4', '5', '6'], ['.', '8', '9']], (0, 2))
    ['3', '6', '9']
    """
    return grid[pos[1]]


def get_block(grid: tp.List[tp.List[str]], pos: tp.Tuple[int, int]) -> tp.List[str]:
    """Возвращает все значения из квадрата, в который попадает позиция pos

    >>> grid = read_sudoku('puzzle1.txt')
    >>> get_block(grid, (0, 1))
    ['5', '3', '.', '6', '.', '.', '.', '9', '8']
    >>> get_block(grid, (4, 7))
    ['.', '.', '3', '.', '.', '1', '.', '.', '6']
    >>> get_block(grid, (8, 8))
    ['2', '8', '.', '.', '.', '5', '.', '7', '9']
    """
    stroka = (pos[0] // 3) * 3
    stolbec = (pos[1] // 3) * 3

    kvadrat = []
    for i in range(3):
        for j in range(3):
            kvadrat.append(grid[stroka + i][stolbec + j])

    return kvadrat



def find_empty_positions(grid: tp.List[tp.List[str]]) -> tp.Optional[tp.Tuple[int, int]]:
    """Найти первую свободную позицию в пазле

    >>> find_empty_positions([['1', '2', '.'], ['4', '5', '6'], ['7', '8', '9']])
    (0, 2)
    >>> find_empty_positions([['1', '2', '3'], ['4', '.', '6'], ['7', '8', '9']])
    (1, 1)
    >>> find_empty_positions([['1', '2', '3'], ['4', '5', '6'], ['.', '8', '9']])
    (2, 0)
    """
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == '.':
                return (i, j)
    return None




def find_possible_values(grid: tp.List[tp.List[str]], pos: tp.Tuple[int, int]) -> tp.Set[str]:
    """Вернуть множество возможных значения для указанной позиции"""
    stroka = (pos[0] // 3) * 3
    stolbec = (pos[1] // 3) * 3

    all_numbers_in_kvadrat = set()
    for i in range(3):
        for j in range(3):
            if grid[stroka + i][stolbec + j] in '123456789':
                all_numbers_in_kvadrat.add(grid[stroka + i][stolbec + j])

    possible_numbers = set('123456789')
    missing_numbers = possible_numbers - all_numbers_in_kvadrat

    return missing_numbers


def solve(grid: tp.List[tp.List[str]]) -> tp.Optional[tp.List[tp.List[str]]]:
    """ Решение пазла, заданного в grid """
    empty_pos = find_empty_position(grid)  # Найти свободную позицию
    if not empty_pos:  # Если свободных позиций нет, значит, судоку решено
        return grid


def check_solution(solution: tp.List[tp.List[str]]) -> bool:
    """ Если решение solution верно, то вернуть True, в противном случае False """
    for i in range(9):
        if len(set(get_row(solution, (i, 0)))) != 9:
            return False
        if len(set(get_col(solution, (0, i)))) != 9:
            return False

    for i in range(3):
        for j in range(3):
            block = get_block(solution, (i * 3, j * 3))
            if len(set(block)) != 9:
                return False

    return True


def generate_sudoku(N: int) -> tp.List[tp.List[str]]:
    """Генерация судоку, заполненного на N элементов"""
    # Создаем начальную пустую сетку
    grid = list(map(lambda _: ['.'] * 9, range(9)))  # или любой другой способ создания сетки

    # Заполняем сетку до полного решения
    for _ in range(81 - N):
        while True:
            row = random.randint(0, 8)
            col = random.randint(0, 8)
            num = random.choice('123456789')

            if (grid[row][col] == '.' and
                num not in get_row(grid, (row, 0)) and
                num not in get_col(grid, (0, col)) and
                num not in get_block(grid, (row, col))):
                grid[row][col] = num
                break

    solution = solve(grid)
    if not solution:
        raise Exception("Не удалось сгенерировать допустимую конфигурацию Судоку.")

    for _ in range(81 - N):
        while True:
            row = random.randint(0, 8)
            col = random.randint(0, 8)
            if grid[row][col] != '.':
                grid[row][col] = '.'
                break

    return grid


if __name__ == "__main__":
    # Тестируем генерацию и отображение Судоку
    for fname in ["puzzle1.txt", "puzzle2.txt", "puzzle3.txt"]:
        grid = read_sudoku(fname)
        display(grid)
        solution = solve(grid)
        if not solution:
            print(f"Загадка {fname} не может быть решена")
        else:
            display(solution)