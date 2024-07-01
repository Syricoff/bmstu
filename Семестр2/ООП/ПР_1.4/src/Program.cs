using System;
using System.Text.RegularExpressions;
using System.IO;
using System.Text;


namespace ПР3
{
    /* 
    Постройте таблицу значений функции f(x) для x[a, b] с шагом h 
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

        public string ReduceTime(int hoursToSubtract)
        {
            return Regex.Replace(text, @"\b(?:[01]?\d|2[0-3]):[0-5]?\d\b", match =>
            {
                string time = match.Value;
                return SubtractHours(time, hoursToSubtract);
            });
        }

        private string SubtractHours(string time, int hoursToSubtract)
        {
            string[] parts = time.Split(':');
            int hours = int.Parse(parts[0]);
            int minutes = int.Parse(parts[1]);

            hours -= hoursToSubtract;

            if (hours < 0)
            {
                hours += 24;
            }
            else if (hours >= 24)
            {
                hours -= 24;
            }
            return $"{hours:D2}:{minutes:D2}";
        }
    }

    /*
    Работа с двоичными файлами:
    Создать файл, состоящий из слов. 
    Вывести на экран все слова, которые начинаются на ту же букву, что и последнее слово.
    */

    public class WordBinaryFile
    {
        private string filePath;

        public WordBinaryFile(string filePath)
        {
            this.filePath = filePath;
        }

        public void CreateFile(string[] words)
        {
            using (BinaryWriter writer = new BinaryWriter(File.Open(filePath, FileMode.Create)))
            {
                foreach (string word in words)
                {
                    byte[] wordBytes = Encoding.UTF8.GetBytes(word);
                    writer.Write(wordBytes.Length);
                    writer.Write(wordBytes);
                }
            }
        }

        public void PrintWordsStartingWithLastLetter()
        {
            using (BinaryReader reader = new BinaryReader(File.Open(filePath, FileMode.Open)))
            {
                string lastWord = "";
                while (reader.PeekChar() != -1)
                {
                    int wordLength = reader.ReadInt32();
                    byte[] wordBytes = reader.ReadBytes(wordLength);
                    string word = Encoding.UTF8.GetString(wordBytes);

                    if (lastWord.Length > 0 && word.StartsWith(lastWord[lastWord.Length - 1].ToString(), StringComparison.OrdinalIgnoreCase))
                    {
                        Console.WriteLine(word);
                    }

                    lastWord = word;
                }
            }
        }
    }

    public class TextFileProcessor
    {
        private string inputFilePath;
        private string outputFilePath;

        public TextFileProcessor(string inputFilePath, string outputFilePath)
        {
            this.inputFilePath = inputFilePath;
            this.outputFilePath = outputFilePath;
        }

        public void ProcessFile()
        {
            string[] lines = File.ReadAllLines(inputFilePath);

            using (StreamWriter writer = new StreamWriter(outputFilePath))
            {
                foreach (string line in lines)
                {
                    string modifiedLine = RemoveEvenPositionChars(line);
                    writer.WriteLine(modifiedLine);
                }
            }
        }

        private string RemoveEvenPositionChars(string str)
        {
            StringBuilder sb = new StringBuilder();

            for (int i = 0; i < str.Length; i++)
            {
                if (i % 2 != 0)
                {
                    sb.Append(str[i]);
                }
            }

            return sb.ToString();
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Function f = new Function(-10, 10, 0.2m);
            f.TableOfValues();

            String s = new String("Hello, World!");
            Console.WriteLine($"Количество различных символов в строке: {s.CountOfDifferentSymbols()}");
            s.WordsInAscendingOrder();

            string message = "Встреча в 24:50. Не забудь забрать детей в 00:20.";
            TimeReducer timeReducer = new TimeReducer(message);
            Console.WriteLine(timeReducer.ReduceTime(2));

            string filePath = "words.bin";
            string[] words = { "банан", "абрикос", "сок", "крендель", "ламинат", "огурец" };

            WordBinaryFile wordBinaryFile = new WordBinaryFile(filePath);
            wordBinaryFile.CreateFile(words);
            wordBinaryFile.PrintWordsStartingWithLastLetter();

            string inputFilePath = "input.txt";
            string outputFilePath = "output.txt";

            TextFileProcessor fileProcessor = new TextFileProcessor(inputFilePath, outputFilePath);
            fileProcessor.ProcessFile();

            Console.WriteLine("Файл обработан. Результат сохранен в " + outputFilePath);
        }
    }
}