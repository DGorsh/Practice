# Вариант 1   Горшков Дмитрий  Решение уравнений
# Вместе с доп заданием. выводит результат в консоль, в файл и в логи
# Библиотеки: sympy     logging
# проверка на корректность выполняется.   логи по указанному шаблону
# построение графиков не удалось - не качает либу. но код представлен для построения (закомменчен). либа - matplotlib

from sympy.solvers import solve
from sympy import Symbol
import logging
#import matplotlib

#plt.xlabel("X")
#plt.ylabel("F(X)")
#plt.grid(True, linestyle='-', color='0.75')

logging.basicConfig(format = u'{[%(asctime)s] %(levelname)-1s %(message)s', level = logging.DEBUG,
                    datefmt = '%d.%m.%Y',
                    filename = u'mylog.log')
try:
    file = open('test.txt', 'r')
except IOError as error:
    print(str(error))
    logging.error(u'Нельзя открыть файл: файл не найден')
else:
    fileout = open('out.txt', 'w')
    x = Symbol('x')
    with file:
        for line in file:
            teststr = line
            teststr = teststr.replace('\n', '').replace('\r', '')
            print(teststr + '\nРешение = ', end='')
            fileout.write(teststr + '\nРешение = ')
            try:
                res = solve(teststr, x, dict=True)
            except:
                print('Нельзя решить. Возможно, что ввод некорректен.')
                fileout.write('Нельзя решить. Возможно, что ввод некорректен.')
                logging.info(u'equation: ' + teststr +', result: Cant solve this equation}')
            else:
                i=0
                teststr += ', result: [ '
#                X = [i for i in range(-100, 100)]
#                Y = teststr
#                plt.scatter(X, Y, edgecolors='r', s=10)
#                plt.title(teststr)
                while i < len(res):
                    print(str(res[i][x]), end=' ')
                    fileout.write(str(res[i][x]) + ' ')
                    teststr += str(res[i][x]) + ' '
                    i+=1
                if len(res) == 0:
                    print('Нет решений', end='')
                    fileout.write('Нет решений')
                    teststr += 'NaN '
 #               plt.show()
                logging.info(u'equation: ' + teststr +']}')
                print('\n')
                fileout.write('\n')
    fileout.close()