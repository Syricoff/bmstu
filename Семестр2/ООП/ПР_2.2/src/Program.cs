using System;
abstract class BaseClass
{
    protected int field1;
    protected int field2;
    public BaseClass(int value1, int value2)
    {
        field1 = value1;
        field2 = value2;
    }
    public abstract int this[int index] { get; set; }
}
interface IInterface
{
    int Method(int argument);
}
class DerivedClass : BaseClass, IInterface
{
    public DerivedClass(int value1, int value2) : base(value1, value2)
    {
    }
    public override int this[int index]
    {
        get
        {
            if (index % 2 == 0)
                return field1;
            else
                return field2;
        }
        set
        {
            if (index % 2 == 0)
                field1 = value;
            else
                field2 = value;
        }
    }
    public int Method(int argument)
    {
        return (field1 + field2) * argument;
    }
}
class Program
{
    static void Main(string[] args)
    {
        DerivedClass obj = new DerivedClass(5, 10);

        // Доступ к элементам через индексатор
        Console.WriteLine("Доступ к элементам через индексатор:");
        Console.WriteLine("Значение при четном индексе: " + obj[0]);
        Console.WriteLine("Значение при нечетном индексе: " + obj[1]);

        obj[0] = 15;
        obj[1] = 20;

        Console.WriteLine("Новые значения:");
        Console.WriteLine("Значение при четном индексе: " + obj[0]);
        Console.WriteLine("Значение при нечетном индексе: " + obj[1]);

        int result = obj.Method(3);
        Console.WriteLine("Результат: " + result);
    }
}