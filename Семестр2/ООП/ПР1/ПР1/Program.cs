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
*/

using System;

namespace PR1
{
    class Program
    {
        static void Main()
        {
            Task1();
        }
        static void Task1()
        {
            int[] X = [5, 3, 8, 1, 9, 2];
            Console.WriteLine($"Минимальный элемент в массиве: {FindMinElement(X)}");
            Console.WriteLine($"Максимум функции z: {FindMaxZ()}");

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