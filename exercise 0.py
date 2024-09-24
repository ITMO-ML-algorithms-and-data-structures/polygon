# Найти первый индекс числа N, если его нет, вернуть -1
def index_of_number(array,n): # n - число
    for i in range(len(array)):
        if array[i] == n:
            return i
    return -1