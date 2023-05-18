# Техническое задание 

## Описание программного продукта 
---
Генератор паролей (PWGEN) - программа, которая способна генерировать различные пароли с определенными опциями. 
___

## Функциональность проекта: 

Запуск программного продукта происходит через консоль в формате ./pwdgen [OPTION], где: 

[OPTION] – флаг пароля (аргументы командной строки). 

Программа выводит один сгенерированный пароль в консоли, состоящий из 8 символов. В нем содержатся буквы верхнего и нижнего регистра английского языка, а также специальные символы и цифры. 

После вывода пароля всегда следует подсказка, которая поясняет, как открыть справочник. (Enter "./pwdgen -h " to see info..) В справочнике содержится информация об использовании программы, о существующих опциях и пример запуска. 



Пользователь может воспользоваться данными опциями, которые позволят генерировать пароль с определенными условиями, такими как: количество паролей, длина, содержание различных символов. Эти опции можно использовать одновременно. 



## Формат входных данных: 

В качестве входных данных программа получает аргументы командной строки. Описание аргументов командной строки 
~~~
-l, --lowercase  – сгенерированный пароль будет содержать только буквы нижнего регистра. 

-u, --uppercase  – сгенерированный пароль будет содержать только буквы верхнего регистра. 

-d, --digit – cгенерированный пароль будет содержать только цифры. 

-s, --special – сгенерированный пароль будет содержать только специальные символы. 

-с, --count [number] – изменяет количество генерируемых паролей. 

-n, --lenght [number] – изменяет количество символов в генерируемых паролях. 

-h, --help – выводит справочник. 
~~~
## Интерфейс приложения: 
---
Консольное приложение, которое принимает на вход некоторые параметры (аргументы командной строки) в формате: 

./pwdgen [OPTION] 
___
 

## Алгоритм реализации работы функций приложения: 

Приложение генерирует пароли из букв английского алфавита (нижнего и верхнего регистров), цифр, специальных символов, с помощью следующего алгоритма для генерации паролей. 

Данные для генерации пароля выбираются при помощи класса random_device, использующей функцию rd() и объект mt19937(генератор псевдослучайных чисел) из библиотеки random. Класс random_device равномерно распределенный целочисленный генератор случайных чисел, который производит недетерминированные случайные числа.   

Для генерации пароля с опциями мы нашли, скачали и подключили библиотеку cxxopts.h.