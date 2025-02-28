# Лабораторная работа №3
<img src="http://img.shields.io/badge/license-MIT-brightgreen.svg" alt="MIT License"> <img src="https://img.shields.io/badge/language-F%23-green.svg" alt="F# Language">

Лабораторная работа №3 по ФП

### Задание
1. Разработайте функцию, которая принимает три параметра обобщенных типов и возвращает их в виде кортежа. Модифицируйте функцию: не указывая явно типы параметров, задавая выражения в теле функции, сделайте так, чтобы параметры были типов int, float, string.
2. С использованием двухэтапного создания обобщенных функций реализуйте функции, которые осуществляют сложение:
	* трех аргументов типа int;
	* трех аргументов типа float;
	* трех аргументов типа string.
3. С использованием list comprehension для четных элементов списка [1..10] верните список кортежей. Каждый кортеж содержит элемент списка, его квадрат и куб.
4. На основе пункта 3.8.1 [в методичке](http://sfm2007.narod.ru/data/fp.pdf) напишите два варианта функции, которая принимает на вход список и возвращает квадраты его значений. Необходимо использовать свойства списка Head и Tail. Первый вариант функции использует оператор if, второй вариант использует сопоставление с образцом на уровне функции.
5. Последовательно примените к списку функции map, sort, filter, fold, zip, функции агрегирования. Функции применяются в любом порядке и произвольно используются в трех комбинациях.
	* Первая комбинация заканчивается функцией агрегирования (например, сумма элементов списка). Cписок предварительно может быть отсортирован, отфильтрован и т.д.
	* Вторая комбинация заканчивается функцией fold, которая осуществляет свертку списка. Вторая комбинация выполняет те же действия, что и первая комбинация и должна возвращать такой же результат.
	* Третья комбинация заканчивается функцией zip, которая соединяет два списка.
6. Реализуйте предыдущий пункт с использованием оператора потока « |> ».
7. Реализуйте предыдущий пункт с использованием оператора композиции функций « >> ».
