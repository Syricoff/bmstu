using System;
using System.Text.RegularExpressions;


namespace ПР3
{
    /* 
    Задание: Постройте таблицу значений функции f(x) для x[a, b] с шагом h 
    Если в некоторой точке функция не определена, то выведите на экран сообщение об этом.
    При решении данной задачи использовать вспомогательный метод f(x), 
    реализующий заданную функцию, а также проводить обработку возможных исключений.

    f(x) = 1/ln(x+7) + ln(1 - abs(x))
    */
    class Function
    {
        private decimal a;
        private decimal b;
        private decimal h;
        public Function(decimal a, decimal b, decimal h)
        {
            this.a = a;
            this.b = b;
            this.h = h;
        }
        public decimal Calculate(decimal x)
        {
            if (x <= -1 || x >= 1)
            {
                throw new Exception($"Функция не определена в точке x = {x}");
            }
            return 1 / (decimal)Math.Log((double)(x + 7)) + (decimal)Math.Log(1 - Math.Abs((double)x));
        }
        public void TableOfValues()
        {
            for (decimal x = this.a; x <= this.b; x += this.h)
            {
                try
                {
                    Console.WriteLine($"f({x}) = {Calculate(x):0.00000f}");
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.Message);
                }
            }
        }
    }

    /*
    Разработать программу, которая для заданной строки s:
    определяет, сколько различных символов встречается в строке.

    Дана строка, в которой содержится осмысленное текстовое сообщение. 
    Слова сообщения разделяются пробелами и знаками препинания.
    Вывести слова сообщения в порядке возрастания их длин.
    */

    class String
    {
        private string s;
        public String(string s)
        {
            this.s = s;
        }
        // A
        public int CountOfDifferentSymbols()
        {
            return s.Distinct().Count();
        }
        // B
        public void WordsInAscendingOrder()
        {
            string[] words = s.Split(new char[] { ' ', ',', '.', '!', '?', ':' }, StringSplitOptions.RemoveEmptyEntries);
            Array.Sort(words, (a, b) => a.Length.CompareTo(b.Length));
            foreach (string word in words)
            {
                Console.WriteLine(word);
            }
        }
    }

    /*
    Регулярные выражения C#

    Дана строка, в которой содержится осмысленное текстовое сообщение. 
    Слова сообщения разделяются пробелами и знаками препинания.

    В сообщении может содержаться время в формате чч:мм. 
    В заданном формате чч - целое число из диапазона от 00 до 24, 
    мм - целое число из диапазона от 00 до 60 (если какая-то часть формата нарушена, 
    то данная подстрока в качестве даты не рассматривается). 
    Уменьшите время на n часов.
    */

    public class TimeReducer
    {
        private string text;

        public TimeReducer(string text)
        {
            this.text = text;
        }

        public string ReduceTime(int n)
        {
            return Regex.Replace(text, @"(\d{2}:\d{2})", match =>
            {
                var timeParts = match.Groups[1].Value.Split(':');
                var hours = int.Parse(timeParts[0]);
                var minutes = int.Parse(timeParts[1]);

                hours -= n;
                if (hours < 0)
                {
                    hours += 24;
                }

                return $"{hours:D2}:{minutes:D2}";
            });
        }
    }

    /*
    Работа с двоичными файлами:
    Создать файл, состоящий из слов. 
    Вывести на экран все слова, которые начинаются на ту же букву, что и последнее слово.
    */


    class Program
    {
        static void Main(string[] args)
        {
            Function f = new Function(-10, 10, 0.2m);
            // f.TableOfValues();

            String s = new String("Hello, World!");
            Console.WriteLine($"Количество различных символов в строке: {s.CountOfDifferentSymbols()}");
            s.WordsInAscendingOrder();

            TimeReducer timeReducer = new TimeReducer("Hello, World! It's 12:30 now.");
            Console.WriteLine(timeReducer.ReduceTime(2));
        }
    }
}