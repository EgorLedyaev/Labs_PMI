// игра в один игральный кубик с компьютером
// после каждого броска выводится промежуточный счет
// после 4 бросков выводится итоговый счет и победитель

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void check_res(int sum1, int sum2){
    if (sum1 > sum2)
        cout << "Вы победили!" << endl;
    else if (sum1 < sum2)
        cout << "Вы проиграли!" << endl;
    else
        cout << "Ничья!" << endl;
}

int main()
{
    int i;
    int a, b, e, f;
    int sum1, sum2;
    char ch;
    srand(time(0));

    while (true){
        sum1 = 0;
        sum2 = 0;
        for (i = 1; i <= 4; i++)
        {
            cout << "Бросок №" << i << endl;
            a = rand() % 6 + 1;
            b = rand() % 6 + 1;
            e = rand() % 6 + 1;
            f = rand() % 6 + 1;
            cout << "Вы: " << a << " " << b  << endl;
            cout << "Компьютер: " << e << " " << f << endl;
            sum1 = sum1 + a + b;
            sum2 = sum2 + e + f;
            cout << "Счет: " << sum1 << " : " << sum2 << endl;
            cout << ' '<< endl;
        }
        cout << "Итоговый счет: " << sum1 << " : " << sum2 << endl;

        check_res(sum1, sum2);

        cout << "Хотите сыграть еще раз? (y/n): ";
        cin >> ch;
        if (ch == 'n'){
            return 0;
        }
    }
}
