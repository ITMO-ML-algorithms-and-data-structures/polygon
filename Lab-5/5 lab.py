def odd_even(data):
    n = len(data)
    isSorted = 0
    while isSorted == 0:
        isSorted = 1
        for i in range(1, n - 1, 2):
            if data[i] > data[i + 1]:
                data[i], data[i + 1] = data[i + 1], data[i]
                isSorted = 0
                  
        for i in range(0, n - 1, 2):
            if data[i] > data[i + 1]:
                data[i], data[i + 1] = data[i + 1], data[i]
                isSorted = 0
    return data


def Merge_Sort(A):
    if len(A) == 1 or len(A) == 0:
        return A
    
    L = Merge_Sort(A[:len(A) // 2])
    R = Merge_Sort(A[len(A) // 2:]) 
    n = m = k = 0
    C = [0] * len(A)
    while n < len(L) and m < len(R):
        if L[n] <= R[m]:
            C[k] = L[n]
            n += 1
        else:
            C[k] = R[m]
            m += 1
        k += 1
        
    while n < len(L):
        C[k] = L[n]
        n += 1
        k += 1
        
    while m < len(R):
        C[k] = R[m]
        m += 1
        k += 1
        
    for i in range(len(A)):
        A[i] = C[i]
        
    return A


def Counting_Sort(inputArray):
    # Найдём максимальный элемент во входном массиве
    maxElement = max(inputArray)
    countArrayLength = maxElement+1
    # Инициализируем счётный массив (countArray) нулями
    countArray = [0] * countArrayLength
    # Пройдёмся по входному массиву и увеличим соответствующий счёт для каждого элемента на 1
    for el in inputArray:
        countArray[el] += 1
        # print(countArray)
    # Для каждого элемента в счётном массиве суммируем его значение со значением предыдущего элемента и затем сохраняем это значение как значение текущего элемента
    for i in range(1, countArrayLength):
        countArray[i] += countArray[i-1]
        # print(countArray)
    # Вычислим положение элемента на основе значений счётного массива
    outputArray = [0] * len(inputArray)
    i = len(inputArray) - 1
    while i >= 0:
        currentEl = inputArray[i]
        countArray[currentEl] -= 1
        newPosition = countArray[currentEl]
        outputArray[newPosition] = currentEl
        i -= 1
    return outputArray


data = [2, 3, 4, 5, 1, 7, 5, 4, 10, 15]
print(Counting_Sort(data))
