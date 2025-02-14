# Лабораторная работа №4
<img src="http://img.shields.io/badge/license-MIT-brightgreen.svg" alt="MIT License"> <img src="https://img.shields.io/badge/language-F%23-green.svg" alt="F# Language">

Лабораторная работа №4 по ФП

### Задание

#### Часть 1
1. Программа должна быть разработана в виде консольного приложения на языке F#.
2. Абстрактный класс «Геометрическая фигура» содержит виртуальный метод для вычисления площади фигуры.
3. Класс «Прямоугольник» наследуется от класса «Геометрическая фигура». Ширина и высота объявляются как свойства (property). Класс должен содержать конструктор по параметрам «ширина» и «высота».
4. Класс «Квадрат» наследуется от класса «Прямоугольник». Класс должен содержать конструктор по длине стороны.
5. Класс «Круг» наследуется от класса «Геометрическая фигура». Радиус объявляется как свойство (property). Класс должен содержать конструктор по параметру «радиус».
6. Для классов «Прямоугольник», «Квадрат», «Круг» переопределить виртуальный метод Object.ToString(), который возвращает в виде строки основные параметры фигуры и ее площадь.
7. Разработать интерфейс IPrint. Интерфейс содержит метод Print(), который не принимает параметров и возвращает void. Для классов «Прямоугольник», «Квадрат», «Круг» реализовать наследование от интерфейса IPrint. Переопределяемый метод Print() выводит на консоль информацию, возвращаемую переопределенным методом ToString().

#### Часть 2
1. Реализуйте класс геометрическая фигура в виде алгебраического типа (discriminated union), который содержит варианты (дискриминаторы) «Прямоугольник», «Квадрат», «Круг» с необходимыми параметрами.
2. Разработайте для данного класса функцию вычисления площади. Функция должна принимать параметр типа «геометрическая фигура» и вычислять различные варианты площади в зависимости от дискриминатора. Необходимо использовать механизм сопоставления с образцом. (Используйте пример вычисления корней квадратного уравнения).
