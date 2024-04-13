/* 
1.Составить подпрограмму определения минимального элемента в одномерном массиве X=(x1, x2, …, xn). 
Используя её, найти максимум функции z=-x2-y2-4x+6y-8 в следующих сечениях:
при x=-1, 2<=y<=4, hy=0,2
при y=3, -2<=x<=0, hx=0,2
для вычисления z рекомендуется использовать функцию.

2.Составить подпрограмму для определения максимума функции у = f(х), 
заданной в дискретных, точках отрезка [а, b] с постоянным шагом h. 
Используя ее, найти максимумы функций:
y1 = ех*соs2х - 1 на отрезке [1; 2], h = 0.1; 
у2 = х*1n|х + 1| на отрезке [0; 2], h = 0.2.

3. Пусть дано натуральное число n и вещественные числа а1 … аn. 
В последовательности а1 … аn все отрицательные члены увеличьте на 0,5, 
а положительные, меньшие среднего арифметического, замените на 0,1.

4.
Найти количество простых чисел в массиве.
Перевернуть все нечетные строки матрицы.
Перевернуть каждое четное слово в строке.

5.Удалить элемент с заданным ключом (значением)
Добавить строку в конец матрицы

*/


using System;
using System.Linq;
using System.Collections.Generic;


namespace PR1
{
    class Program
    {
        static void Main()
        {
            Task1();
            Task2();
            Task3();
            Task4();
            Task5();
        }
        static void Task1()
        {
            int[] X = [5, 3, 8, 1, 9, 2];
            Console.WriteLine($"Минимальный элемент в массиве: {FindMinElement(X)}");
            Console.WriteLine($"Максимум функции z: {FindMaxZ()}");

        }

        static void Task2()
        {
            // Максимум функции y1 = e^x * cos(2x) - 1 на отрезке [1; 2], h = 0.1
            double max1 = FindMax(Function1, 1, 2, 0.1, 1, double.MinValue);
            Console.WriteLine("Максимум функции y1 на отрезке [1; 2] равен: " + max1);

            // Максимум функции y2 = x * ln(|x| + 1) на отрезке [0; 2], h = 0.2
            double max2 = FindMax(Function2, 0, 2, 0.2, 0, double.MinValue);
            Console.WriteLine("Максимум функции y2 на отрезке [0; 2] равен: " + max2);
        }

        static void Task3()
        {
            int n = 5;
            double[] arr = { -2.5, 1.3, -0.7, 0.8, -1.2 };

            Console.WriteLine("Исходный массив:");
            foreach (double num in arr)
            {
                Console.Write(num + ", ");
            }
            Console.WriteLine();

            ProcessArray(arr);

            Console.WriteLine("Преобразованный массив:");
            foreach (double num in arr)
            {
                Console.Write(num + ", ");
            }
            Console.WriteLine();
        }

        static void Task4()
        {
            int[] numbers = { 2, 3, 5, 7, 10, 11, 13, 17 };
            int primeCount = CountPrimes(numbers);
            Console.WriteLine("Количество простых чисел в массиве: " + primeCount);

            int[,] matrix = new int[,]
            {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {10, 11, 12}
            };

            ReverseOddRows(matrix);

            Console.WriteLine("Матрица с перевернутыми нечетными строками:");
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    Console.Write(matrix[i, j] + " ");
                }
                Console.WriteLine();
            }

            string sentence = "Hello world, this is a test sentence";
            string[] words = sentence.Split(' ');

            ReverseEvenWords(words);

            string reversedSentence = string.Join(" ", words);
            Console.WriteLine("Строка с перевернутыми четными словами: " + reversedSentence);
        }

        static void Task5()
        {
            List<int> numbers = new List<int> { 1, 2, 3, 4, 5 };
            int key = 3;

            if (numbers.Contains(key))
            {
                numbers.Remove(key);
                Console.WriteLine("Элемент с ключом " + key + " удален из списка.");
            }
            else
            {
                Console.WriteLine("Элемент с ключом " + key + " не найден в списке.");
            }

            List<List<int>> matrix = new List<List<int>>
        {
            new List<int> {1, 2, 3},
            new List<int> {4, 5, 6},
            new List<int> {7, 8, 9}
        };

            List<int> newRow = new List<int> { 10, 11, 12 };
            matrix.Add(newRow);

            Console.WriteLine("Матрица после добавления строки:");
            foreach (var row in matrix)
            {
                foreach (int num in row)
                {
                    Console.Write(num + " ");
                }
                Console.WriteLine();
            }
        }

        static bool IsPrime(int num)
        {
            if (num <= 1)
            {
                return false;
            }

            for (int i = 2; i <= Math.Sqrt(num); i++)
            {
                if (num % i == 0)
                {
                    return false;
                }
            }

            return true;
        }

        static int CountPrimes(int[] arr)
        {
            int count = 0;
            foreach (int num in arr)
            {
                if (IsPrime(num))
                {
                    count++;
                }
            }
            return count;
        }

        static void ReverseOddRows(int[,] matrix)
        {
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                if (i % 2 != 0)
                {
                    for (int j = 0; j < matrix.GetLength(1) / 2; j++)
                    {
                        int temp = matrix[i, j];
                        matrix[i, j] = matrix[i, matrix.GetLength(1) - 1 - j];
                        matrix[i, matrix.GetLength(1) - 1 - j] = temp;
                    }
                }
            }
        }

        static void ReverseEvenWords(string[] words)
        {
            for (int i = 0; i < words.Length; i++)
            {
                if (i % 2 == 1)
                {
                    char[] charArray = words[i].ToCharArray();
                    Array.Reverse(charArray);
                    words[i] = new string(charArray);
                }
            }
        }
        static double FindAveragePozitive(double[] arr)
        {
            double sum = 0;
            int count = 0;

            // Находим сумму всех положительных чисел в массиве и их количество
            foreach (double num in arr)
            {
                if (num > 0)
                {
                    sum += num;
                    count++;
                }
            }

            return sum / count;
        }

        static void ProcessArray(double[] arr)
        {
            double average = FindAveragePozitive(arr);

            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] < 0)
                {
                    arr[i] += 0.5; // Увеличиваем отрицательные числа на 0.5
                }
                else if (arr[i] < average)
                {
                    arr[i] = 0.1; // Заменяем положительные числа, меньшие среднего, на 0.1
                }
            }
        }

        static double Function1(double x)
        {
            return Math.Exp(x) * Math.Cos(2 * x) - 1;
        }

        static double Function2(double x)
        {
            return x * Math.Log(Math.Abs(x) + 1);
        }

        static double FindMax(Func<double, double> func, double a, double b, double step, double currentX, double max)
        {
            if (currentX > b)
            {
                return max;
            }

            double y = func(currentX);

            if (y > max)
            {
                max = y;
            }

            return FindMax(func, a, b, step, currentX + step, max);
        }

        static int FindMinElement(int[] array)
        {
            int min = array[0];
            for (int i = 1; i < array.Length; i++)
            {
                if (array[i] < min)
                {
                    min = array[i];
                }
            }
            return min;
        }

        static double FunctionZ(double x, double y)
        {
            return -Math.Pow(x, 2) - Math.Pow(y, 2) - 4 * x + 6 * y - 8;
        }

        static double FindMaxZ()
        {
            double maxZ = double.MinValue;

            // При x=-1, 2<=y<=4, hy=0,2
            for (double y = 2; y <= 4; y += 0.2)
            {
                double currentZ = FunctionZ(-1, y);
                if (currentZ > maxZ)
                {
                    maxZ = currentZ;
                }
            }

            // При y=3, -2<=x<=0, hx=0,2
            for (double x = -2; x <= 0; x += 0.2)
            {
                double currentZ = FunctionZ(x, 3);
                if (currentZ > maxZ)
                {
                    maxZ = currentZ;
                }
            }

            return maxZ;
        }
    }
}