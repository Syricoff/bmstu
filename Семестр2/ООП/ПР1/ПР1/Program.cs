// 3. Составить подпрограмму определения минимального элемента в одномерном массиве X=(x1, x2, …, xn). 
// Используя её, найти максимум функции z=-x2-y2-4x+6y-8 в следующих сечениях:
// при x=-1, 2<=y<=4, hy=0,2
// при y=3, -2<=x<=0, hx=0,2
// для вычисления z рекомендуется использовать функцию.
using System;


namespace PR1
{
    class Program
    {
        static void Main()
        {
            // Определяем одномерный массив
            int[] X = [5, 3, 8, 1, 9, 2];

            // Вызываем подпрограмму для нахождения минимального элемента
            int minElement = FindMinElement(X);

            Console.WriteLine($"Минимальный элемент в массиве: {minElement}");
            FindMaxZ();
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

        static void FindMaxZ()
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

            Console.WriteLine($"Максимум функции z: {maxZ}");
        }
    }
}