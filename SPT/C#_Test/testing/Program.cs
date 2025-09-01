using System;
using System.ComponentModel.DataAnnotations;

// <summary>
// Ein simples Programm zum checken einer Primzahl
// </summary>

namespace primzahl;
public class Test
{
    public static void Main(String[] args)
    {
        string? rawInput;
        int? inputInt = 0;

        Console.WriteLine($"short min = {short.MinValue}");
        Console.WriteLine($"short max = {short.MaxValue}");
        Console.WriteLine($"long min = {long.MinValue}");
        Console.WriteLine($"long max = {long.MaxValue}");
        Console.WriteLine($"decimal min = {decimal.MinValue}");
        Console.WriteLine($"decimal max = {decimal.MaxValue}\n\n");

        Console.WriteLine($"Der Integer Wert: {byte.MaxValue}\t\t\t--> HEX-Wert: {byte.MaxValue.ToString("X")}\nDer Integer Wert: {ushort.MaxValue}\t\t\t--> HEX-Wert: {ushort.MaxValue.ToString("X")}\n\nDas Produkt der Zahlen: {ushort.MaxValue * byte.MaxValue}\t--> HEX-Wert: {(ushort.MaxValue * byte.MaxValue).ToString("X")}");

        Console.ReadKey();

        while (true)
        { 
            Console.Clear();
            Console.WriteLine("Bitte gib Zahl oder 'Exit'");

            rawInput = Console.ReadLine();

            if (rawInput?.ToLower() == "exit")
            {
                return;
            }

            try
            {
                inputInt = Convert.ToInt32(rawInput);
            } 
            catch (Exception ex)
            {
                Console.WriteLine($"Bitte eine gültige Zahl eingeben. ({ex.Message})");
                return;
            }

            Console.WriteLine(IsPrime(inputInt));
            Console.ReadKey();
        }
    }
    private static bool IsPrime(int? num)
    {
        if (num == null || num <= 2)
        {
            return false;
        }

        for (int x = 2; x < num; x++)
        {
            if (num % x == 0)
            {
                //Console.WriteLine($"Found: {num % x} ({num} and {x})");
                return false;
            }
        }

        return true;
    }
}
