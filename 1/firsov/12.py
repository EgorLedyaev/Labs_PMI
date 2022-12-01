
#Программа должна строить ломаную с вершинами в заданных
#точках на плоскости, такую что никакие два звена этой ломаной не
#пересекаются. Каждая заданная точка должна являться одной из
#вершин ломаной. Все координаты точек целочисленные.
#Входные данные. Конечная последовательность точек на
#плоскости, заданных своими целочисленными координатами.
#Выходные данные. Вершины ломаной в порядке их соединения
#звеньями ломаной. Звенья ломаной не должны пересекаться.


#Пример текстового интерфейса пользователя
#Simple polyline construction
#Input the number of points>4
#Input integer coordinates of the point #1>1 2
#Input integer coordinates of the point #2>5 1
#Input integer coordinates of the point #3>4 4
#Input integer coordinates of the point #4>3 -1
#Result:
#(1, 2)
#(4, 4)
#(5, 1)
#(3, -1)
#Continue? (Y/N)>Y
#Input the number of points>5
#Input integer coordinates of the point #1>1 2
#Input integer coordinates of the point #2>5 1
#Input integer coordinates of the point #3>4 4
#Input integer coordinates of the point #4>3 -1
#Input integer coordinates of the point #5>3 2
#Result:
#(1, 2)
#(4, 4)
#(5, 1)
#(3, -1)
#(3, 2)
#Continue? (Y/N)>N


#функция для приема числа точек
def input_number():
    while True:
        try:
            n = int(input("Input the number of points>"))
            if n > 0:
                return n
            else:
                print("The number must be positive")
        except ValueError:
            print("The number must be integer")

# функция для приема координат точки
def input_point():
    while True:
        try:
            x, y = map(int, input("Input integer coordinates of the point> ").split())
            return x, y
        except ValueError:
            print("The coordinates must be integer")

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

# функция для построения ломаной c вершинами в заданных точках и записи их в порядке их соединения
def polyline(points):
    # сортируем точки в порядке их соединения
    points.sort(key=lambda point: point[0])
    # записываем первую точку
    result = [points[0]]
    # записываем последнюю точку
    result.append(points[-1])
    # записываем остальные точки
    for i in range(1, len(points) - 1):
        # если точка лежит слева от отрезка
        if points[i][1] < min(result[0][1], result[-1][1]) or points[i][1] > max(result[0][1], result[-1][1]):
            result.insert(0, points[i])
        else:
            result.append(points[i])
    return result

# функция для вывода ломаной
def print_polyline(polyline):
    for point in polyline:
        print(point)

# функция для вывода результата
def print_result(polyline):
    print("Result:")
    print_polyline(polyline)
    print()


# основная программа
while True:
    # прием числа точек
    n = input_number()
    # прием координат точек
    points = [input_point() for i in range(n)]
    # построение ломаной
    polyline = polyline(points)
    # вывод результата
    print_result(polyline)
    # прием ответа пользователя
    if not input_answer():
        break