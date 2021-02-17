
// Компиляция:
// g++ -Wall -Wextra -o lesson1 lesson1.cpp

#include <iostream>

// Функции:
int sumS(int n) {
  // Объявление переменной и инициализация
  int s = 0;
  // Циклы: for, while, do-while
  for (int i=0; i<n; i++) {
    // Условия: if-else, switch-case
    if (i % 2 == 0) {
      s += i;
    }
  }
  return s;
}

// Напишите функцию fibo,
// которой на вход подаётся n
// и которая возвращает n-е число Фибоначчи
//
// fibo(1) == 1
// fibo(2) == 1
//
// 1 2 3 4 5 6  7  8  9 10 11 ...
// 1 1 2 3 5 8 13 21 34 55 89 ...

// Точка входа
int main() {
  // ввод с клавиатуры
  int n;
  std::cin >> n;
  // вывод на экран (endl - перевод строки)
  std::cout << sumS(n) << std::endl;
  // если надоело std::
  // в начале написать
  // using namespace std;
 
  // код возврата
  return 0;
}
