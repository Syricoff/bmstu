namespace src;

public class MyClass
{
    private double _x;
    private double _y;
    private double _z;
    private double _b;

    public MyClass() { }

    public void Set(double x, double y, double z)
    {
        _x = x;
        _y = y;
        _z = z;
        _b = Run();
    }

    public void Print()
    {
        Console.WriteLine($"X = {_x}");
        Console.WriteLine($"Y = {_y}");
        Console.WriteLine($"Z = {_z}");
        Console.WriteLine("Результат работы");
        Console.WriteLine($"B = {_b}");
    }

    public double Run()
    {
        double innerSqrt = Math.Cbrt(_x);
        double outerSqrt = Math.Sqrt(10 * (innerSqrt + Math.Pow(_x, _y + 2)));
        double arcsin = Math.Asin(_z);
        double absDiff = Math.Abs(_x - _y);
        return outerSqrt * (Math.Pow(arcsin, 2) - absDiff);
    }
}
class Program
{
    static void Main()
    {
        double x = 16.55 * Math.Pow(10, -3);
        double y = -2.75;
        double z = 0.15;

        MyClass obj1 = new MyClass();
        obj1.Set(x, y, z);
        obj1.Print();
    }
}
