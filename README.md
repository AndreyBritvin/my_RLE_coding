<p align="center">
  <a href="" rel="noopener">
 <img width=220px height=150px src="picture/LOGO_arrays.png" alt="Project logo"></a>
</p>

<h3 align="center">Массивные эксперименты</h3>

<div align="center">

[![Status](https://img.shields.io/badge/status-active-success.svg)]()
[![GitHub Issues](https://img.shields.io/github/issues/AndreyBritvin/Massive_Experiments)](https://github.com/AndreyBritvin/Massive_Experiments/issues)
[![GitHub Pull Requests](https://img.shields.io/github/issues-pr/AndreyBritvin/Massive_Experiments)](https://github.com/AndreyBritvin/Massive_Experiments/pulls)
[![License](https://img.shields.io/badge/license-MIPT-blue.svg)](/LICENSE)

</div>

---

<p align="center"> Решение квадратных уравнений.
    <br>
</p>

## 📝 Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [Deployment](#deployment)
- [Usage](#usage)
- [Built Using](#built_using)
- [TODO](TODO.md)
- [Authors](#authors)
- [Acknowledgments](#acknowledgement)

## 🧐 About <a name = "about"></a>

В этой программе реализованы функции с действиями над матрицами:
 - Вывод матрицы
 - Нахождение определителя
  - Нахождение минора
   - Нахождение обратной матрицы
   - Печать треугольной матрицы
   - Суммирование матриц
   - Перемножение матриц
   - Нахождение алгебраического дополнения
   - Почти реализовано транспонирование
## 🏁 Getting Started <a name = "getting_started"></a>

### Installing

Склонируйте репозиторий и запустите [Makefile](Makefile) (подробнее в [Deployment](#Deployment))



## 🎈 Usage <a name="usage"></a>

Для вывода встроенного результата используйте
```
a.out
```

И смотрите на результат функции. Пока что матрицы только внутри кода, в будущем будет доступен ввод с клавиатуры

## 🚀 Deployment <a name = "deployment"></a>

Убедитесь, что [Makefile](Makefile) соответствует настройкам вашей системы

Введите
```
make
```
Для создания исполняемого файла a.out (или a.exe для Windows 👎)

### Doxygen setting
Для визуализации структуры проекта установите и запустите Doxygen:
```
sudo apt-get install doxygen
```
Перейдите в папку проекта и введите
```
doxygen Doxyfile
```
Для визуализации графов зависимостей необходимо установить graphviz:
```
sudo apt-get install graphviz
```
## ✍️ Authors <a name = "authors"></a>

- [@AndreyBritvin](https://github.com/AndreyBritvin) - основная работа

## 🎉 Acknowledgements <a name = "acknowledgement"></a>

- Спасибо [Деду](https://github.com/ded32) и ментору за летку
