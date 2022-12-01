#Количество различных чисел
#Программа должна вычислять количество различных чисел в
#конечной последовательности целых чисел.
#Входные данные. Конечная последовательность целых чисел.
#Выходные данные. Количество различных чисел, содержащихся в
#этой последовательности.
#Пример текстового интерфейса пользователя
#Count-distinct problem
#Input the number of integers>5
#Input the integer #1>2
#Input the integer #2>3
#Input the integer #3>2
#Input the integer #4>3
#Input the integer #5>4
#Result: 3
#Continue? (Y/N)>Y
#Input the number of integers>5
#Input the integer #1>2
#Input the integer #2>1
#Input the integer #3>1
#Input the integer #4>1
#Input the integer #5>2
#Result: 2
#Continue? (Y/N)>N


# функция для приема количества элементов массива
def input_number():
    while True:
        try:
            n = int(input("Input the number of integers>"))
            if n > 0:
                return n
            else:
                print("The number must be positive")
        except ValueError:
            print("The number must be integer")

# функция для приема элементов массива
def input_array(n):
    arr = []
    for i in range(n):
        while True:
            try:
                arr.append(int(input("Input the integer #{}>".format(i+1))))
                break
            except ValueError:
                print("The number must be integer")
    return arr

# функция для подсчета количества различных чисел
def count_distinct(arr):
    return len(set(arr))

# функция для приема ответа пользователя
def input_answer():
    while True:
        answer = input("Continue? (Y/N)>")
        if answer == 'Y':
            return True
        elif answer == 'N':
            return False
        else:
            print("The answer must be Y or N")

# функция для вывода результата
def print_result(n, arr):
    print("Result: {}".format(count_distinct(arr)))

# функция для вывода результата
def main():
    while True:
        n = input_number()
        arr = input_array(n)
        print_result(n, arr)
        if not input_answer():
            break

if __name__ == "__main__":
    main()