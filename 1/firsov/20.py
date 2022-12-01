# функция для приема количества элементов массива
def input_number():
    while True:
        try:
            n = int(input("Input the number integers>"))
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

# функция для приема границ участка
def input_bounds(n):
    while True:
        try:
            a, b = map(int, input("Input bounds of the segment>").split())
            if a > 0 and b > 0 and a <= n and b <= n and a < b:
                return a, b
            else:
                print("The bounds must be positive and a < b")
        except ValueError:
            print("The bounds must be integer")

# функция для приема порядка сортировки
def input_order():
    while True:
        order = input("Input an order of sorting (asc/desc)>")
        if order == "asc" or order == "desc":
            return order
        else:
            print("The order must be asc or desc")

# функция для сортировки участка массива
def sort_array(arr, a, b, order):
    if order == "asc":
        arr[a-1:b] = sorted(arr[a-1:b])
    else:
        arr[a-1:b] = sorted(arr[a-1:b], reverse=True)
    return arr

# функция для вывода массива
def print_array(arr):
    print("Current array: {}".format(arr))

# функция для приема ответа пользователя
def input_answer():
    while True:
        answer = input("Continue? (Y/N)>")
        if answer == "Y" or answer == "N":
            return answer
        else:
            print("The answer must be Y or N")

# основная функция
def main():
    n = input_number()
    arr = input_array(n)
    print_array(arr)
    while True:
        a, b = input_bounds(n)
        order = input_order()
        arr = sort_array(arr, a, b, order)
        print_array(arr)
        answer = input_answer()
        if answer == "N":
            break


if __name__ == "__main__":
    main()
