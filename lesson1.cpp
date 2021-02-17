
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
int fibo(int n) {
  int a = 1, b = 1;
  if (n == 1) return a;
  if (n == 2) return b;
  for (int i=1; i<n; i++) {
    int t = a + b;
    a = b;
    b = t;
  }
  return a;
}

// Массивы

void fillArray(int n, int* a, int elem) {
  // a = new int[10];
  for (int i=0; i<n; i++) a[i] = elem;
}

void workArrays(int n) {
  bool b[8];
  int* a = new int[n];

  for (int i=0; i<8; i++) b[i]=false;
  for (int i=0; i<n; i++) {
    a[i] = 2*i;
    // *(a+i) = 2*i;
  }
  for (int i=0; i<n; i++) std::cout << a[i] << " ";
  std::cout << std::endl;

  fillArray(n,a,123);
  for (int i=0; i<n; i++) std::cout << a[i] << " ";
  std::cout << std::endl;

  // освобождение памяти
  delete[] a;
}

// Строки
void workStr(char* s) {
  std::cout << s[0] << std::endl;

  while (*s != '\0') {
    std::cout << (int)(*s) << " ";
    s++;
  }
  std::cout << (int)(*s) << std::endl;
}

// Напишите функцию toHex,
// которая принимает на вход
// число n и массив символов a,
// выделяет нужное количество памяти
// и записывает туда hex-представление массива
//
// toHex(5,"hello") == "68656b6b6e"
char hex(int a) {
  if (0 <= a && a <= 9)
    return a + '0';
  else
    return a-10 + 'a';
}

char* toHex(int n, char* a) {
  char* s = new char[2*n+1];
  for (int i=0; i<n; i++) {
    s[2*i]  = hex(a[i]/16);
    s[2*i+1]= hex(a[i]%16);
  }
  s[2*n+1] = '\0';
  return s;
}

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
  std::cout << fibo(1) << " " << fibo(10) << std::endl;

  workArrays(10);
  workStr("hello world!");

  char* s = toHex(6, "hello");
  std::cout << s << std::endl;
  delete[] s;

  int8_t x = 128;
  uint8_t y = 128;
  // uint16_t, uint32_t
  std::cout << (int)x << " " << (int)y << std::endl;
 
  // код возврата
  return 0;
}
