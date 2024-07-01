using System;
using System.Collections.Generic;

abstract class SoftwareProduct
{
    public abstract string Name { get; set; }
    public abstract string Vendor { get; set; }
    public abstract bool IsUsageAllowed(DateTime currentDate);
    public abstract void PrintInformation();
}

class FreeSoftware : SoftwareProduct
{
    private string name;
    private string vendor;

    public override string Name
    {
        get { return name; }
        set { name = value; }
    }

    public override string Vendor
    {
        get { return vendor; }
        set { vendor = value; }
    }

    public FreeSoftware(string name, string vendor)
    {
        Name = name;
        Vendor = vendor;
    }

    public override bool IsUsageAllowed(DateTime currentDate)
    {
        return true;
    }

    public override void PrintInformation()
    {
        Console.WriteLine($"Программное обеспечение: {Name}");
        Console.WriteLine($"Производитель: {Vendor}");
        Console.WriteLine($"Тип: Свободное");
        Console.WriteLine($"Допустимо использование: Да");
    }
}

class TrialSoftware : SoftwareProduct
{
    private string name;
    private string vendor;
    private DateTime installationDate;
    private int trialPeriod;

    public override string Name
    {
        get { return name; }
        set { name = value; }
    }

    public override string Vendor
    {
        get { return vendor; }
        set { vendor = value; }
    }

    public TrialSoftware(string name, string vendor, DateTime installationDate, int trialPeriod)
    {
        Name = name;
        Vendor = vendor;
        this.installationDate = installationDate;
        this.trialPeriod = trialPeriod;
    }

    public override bool IsUsageAllowed(DateTime currentDate)
    {
        return (currentDate - installationDate).TotalDays <= trialPeriod;
    }

    public override void PrintInformation()
    {
        Console.WriteLine($"Программное обеспечение: {Name}");
        Console.WriteLine($"Производитель: {Vendor}");
        Console.WriteLine($"Тип: Условно-бесплатное");
        Console.WriteLine($"Дата установки: {installationDate.ToShortDateString()}");
        Console.WriteLine($"Срок бесплатного использования: {trialPeriod} дней");
        Console.WriteLine($"Допустимо использование: {(IsUsageAllowed(DateTime.Now) ? "Да" : "Нет")}");
    }
}

class CommercialSoftware : SoftwareProduct
{
    private string name;
    private string vendor;
    private double price;
    private DateTime installationDate;
    private int licenseValidity;

    public override string Name
    {
        get { return name; }
        set { name = value; }
    }

    public override string Vendor
    {
        get { return vendor; }
        set { vendor = value; }
    }

    public CommercialSoftware(string name, string vendor, double price, DateTime installationDate, int licenseValidity)
    {
        Name = name;
        Vendor = vendor;
        this.price = price;
        this.installationDate = installationDate;
        this.licenseValidity = licenseValidity;
    }

    public override bool IsUsageAllowed(DateTime currentDate)
    {
        return (currentDate - installationDate).TotalDays <= licenseValidity;
    }

    public override void PrintInformation()
    {
        Console.WriteLine($"Программное обеспечение: {Name}");
        Console.WriteLine($"Производитель: {Vendor}");
        Console.WriteLine($"Тип: Коммерческое");
        Console.WriteLine($"Цена: {price} руб.");
        Console.WriteLine($"Дата установки: {installationDate.ToShortDateString()}");
        Console.WriteLine($"Срок использования: {licenseValidity} дней");
        Console.WriteLine($"Допустимо использование: {(IsUsageAllowed(DateTime.Now) ? "Да" : "Нет")}");
    }
}

class Program
{
    static void Main(string[] args)
    {
        List<SoftwareProduct> softwareProducts = new List<SoftwareProduct>
        {
            new FreeSoftware("LibreOffice", "The Document Foundation"),
            new TrialSoftware("Adobe Photoshop", "Adobe", new DateTime(2023, 5, 1), 30),
            new CommercialSoftware("Microsoft Office", "Microsoft", 12999.99, new DateTime(2022, 9, 15), 365)
        };

        Console.WriteLine("Информация о программном обеспечении:");
        foreach (var product in softwareProducts)
        {
            product.PrintInformation();
            Console.WriteLine();
        }

        Console.WriteLine("Программное обеспечение, допустимое к использованию:");
        foreach (var product in softwareProducts)
        {
            if (product.IsUsageAllowed(DateTime.Now))
            {
                product.PrintInformation();
                Console.WriteLine();
            }
        }
        Console.ReadLine();
    }
}
