#Порядковая статистика
#Назовём число первым по величине в конечной заданной
#последовательности целых чисел, если в этой последовательности нет
#чисел, меньших его. Назовём число k-ым по величине для k > 1, если
#оно больше (k – 1)-го по величине числа, но не существует элементов
#последовательности, которые меньше него и больше (k – 1)-го по
#величине числа. Программа должна находить k-е по величине число в
#заданной конечной последовательности целых чисел.
#Входные данные. Конечная последовательность целых чисел и
#целое положительное число k.
#Выходные данные. Число из этой последовательности, которое
#является k-м по величине числом этой последовательности.
#Пример текстового интерфейса пользователя
#k-th order statistics
#Input k>2
#Input the number of integers>5
#Input the integer #1>2
#Input the integer #2>4
#Input the integer #3>2
#Input the integer #4>3
#Input the integer #5>4
#Result: 3
#Continue? (Y/N)>Y
#Input k>3
#Input the number of integers>5
#Input the integer #1>5
#Input the integer #2>4
#Input the integer #3>3
#Input the integer #4>2
#Input the integer #5>4
#Result: 4
#Continue? (Y/N)>N

# функци для принятия и проверки k
def k_input():
    while True:
        try:
            k = int(input("Input k>"))
            if k > 1:
                return k
            else:
                print("k must be greater than 1")
        except ValueError:
            print("k must be an integer")

# функци для принятия и проверки количества чисел
def n_input():
    while True:
        try:
            n = int(input("Input the number of integers>"))
            if n > 0:
                return n
            else:
                print("n must be greater than 0")
        except ValueError:
            print("n must be an integer")

# функция для принятия и проверки чисел
def numbers_input(n):
    numbers = []
    for i in range(n):
        while True:
            try:
                number = int(input("Input the integer #{}>".format(i+1)))
                numbers.append(number)
                break
            except ValueError:
                print("Number must be an integer")
    return numbers

# функция для нахождения k-го по величине числа
def kth_order_statistic(numbers, k):
    numbers.sort()
    return numbers[k]

# функция для принятия и проверки ответа
def answer_input():
    while True:
        answer = input("Continue? (Y/N)>")
        if answer == "Y":
            return True
        elif answer == "N":
            return False
        else:
            print("Answer must be Y or N")

# основная функция
def main():
    while True:
        k = k_input()
        n = n_input()
        numbers = numbers_input(n)
        print("Result: {}".format(kth_order_statistic(numbers, k)))
        if not answer_input():
            break

if __name__ == "__main__":
    main()