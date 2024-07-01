public class Program
{
    // 1. Переписать числа в обратном порядке
    static void ReverseNumbersInFile(string inputFileName, string
    outputFileName)
    {
        Stack<string> numbersStack = new Stack<string>();
        using (StreamReader sr = new StreamReader(inputFileName))
        {
            while (!sr.EndOfStream)
            {
                string line = sr.ReadLine();
                numbersStack.Push(line);
            }
        }
        using (StreamWriter sw = new StreamWriter(outputFileName))
        {
            while (numbersStack.Count > 0)
            {
                sw.WriteLine(numbersStack.Pop());
            }
        }
    }
    static void PrintReversedVowels(string fileName)
    {
        Stack<char> vowelsStack = new Stack<char>();
        using (StreamReader sr = new StreamReader(fileName))
        {
            while (!sr.EndOfStream)
            {
                char c = (char)sr.Read();
                if (IsVowel(c))
                {
                    vowelsStack.Push(c);
                }
            }
        }
        while (vowelsStack.Count > 0)
        {
            Console.Write(vowelsStack.Pop());
        }
        Console.WriteLine();
    }
    // 3. Напечатать литеры каждой строки в обратном порядке
    static void PrintCharactersInReverseOrder(string fileName)
    {
        using (StreamReader sr = new StreamReader(fileName))
        {
            while (!sr.EndOfStream)
            {
                string line = sr.ReadLine();
                char[] chars = line.ToCharArray();
                Array.Reverse(chars);
                Console.WriteLine(chars);
            }
        }
    }
    // Вспомогательная функция для определения гласных букв
    static bool IsVowel(char c)
    {
        return "aeiouAEIOU".IndexOf(c) != -1;
    }
    // 4. Проверка, является ли строка s2 обратной s1
    static bool IsReverseString(string s1, string s2)
    {
        if (s1.Length != s2.Length)
            return false;
        Stack<char> stack = new Stack<char>();
        foreach (char c in s1)
        {
            stack.Push(c);
        }
        foreach (char c in s2)
        {
            if (stack.Count == 0 || stack.Pop() != c)
                return false;
        }
        return true;
    }
    // 5. Подсчет выражения в префиксной форме
    static int EvaluatePrefixExpression(string expression)
    {
        Stack<int> stack = new Stack<int>();
        for (int i = expression.Length - 1; i >= 0; i--)
        {
            char c = expression[i];
            if (char.IsDigit(c))
            {
                stack.Push(c - '0');
            }
            else if (c == '+' || c == '-' || c == '*' || c == '/')
            {
                int operand1 = stack.Pop();
                int operand2 = stack.Pop();
                switch (c)
                {
                    case '+':
                        stack.Push(operand1 + operand2);
                        break;
                    case '-':
                        stack.Push(operand1 - operand2);
                        break;
                    case '*':
                        stack.Push(operand1 * operand2);
                        break;
                    case '/':
                        stack.Push(operand1 / operand2);
                        break;
                }
            }
        }
        return stack.Pop();
    }
    // 6. Преобразование выражения из инфиксной формы в префиксную
    static string ConvertInfixToPrefix(string infixExpression)
    {
        Stack<string> operatorStack = new Stack<string>();
        Stack<string> operandStack = new Stack<string>();
        string[] tokens = infixExpression.Split(' ');
        for (int i = tokens.Length - 1; i >= 0; i--)
        {
            string token = tokens[i];
            if (IsOperator(token))
            {
                while (operatorStack.Count > 0 &&
                Precedence(operatorStack.Peek()) >= Precedence(token))
                {
                    string operand1 = operandStack.Pop();
                    string operand2 = operandStack.Pop();
                    operandStack.Push(token + " " + operand1 + " " +
                    operand2);
                    operatorStack.Pop();
                }
                operatorStack.Push(token);
            }
            else
            {
                operandStack.Push(token);
            }
        }
        while (operatorStack.Count > 0)
        {
            string operand1 = operandStack.Pop();
            string operand2 = operandStack.Pop();
            operandStack.Push(operatorStack.Pop() + " " + operand1 + " " +
            operand2);
        }
        return operandStack.Pop();
    }
    // Проверка является ли символ оператором
    static bool IsOperator(string token)
    {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
    // Определение приоритета оператора
    static int Precedence(string op)
    {
        switch (op)
        {
            case "+":
            case "-":
                return 1;
            case "*:":
            case "/":
                return 2;
            default:
                return 0;
        }
    }
    // 7. Преобразование выражения из постфиксной формы в инфиксную
    static string ConvertPostfixToInfix(string postfixExpression)
    {
        Stack<string> stack = new Stack<string>();
        string[] tokens = postfixExpression.Split(' ');
        foreach (string token in tokens)
        {
            if (IsOperator(token))
            {
                string operand2 = stack.Pop();
                string operand1 = stack.Pop();
                stack.Push("(" + operand1 + " " + token + " " + operand2 +
                ")");
            }
            else
            {
                stack.Push(token);
            }
        }
        return stack.Pop();
    }
    // 8. Вычисление значения формулы из файла
    static int EvaluateFormulaFromFile(string fileName)
    {
        Stack<char> operators = new Stack<char>();
        Stack<int> values = new Stack<int>();
        using (StreamReader sr = new StreamReader(fileName))
        {
            string formula = sr.ReadLine();
            foreach (char c in formula)
            {
                if (c == '(')
                {
                    continue;
                }
                else if (char.IsDigit(c))
                {
                    values.Push(int.Parse(c.ToString()));
                }
                else if (c == 'm' || c == 'M')
                {
                    operators.Push(c);
                }
                else if (c == ')' && operators.Count > 0)
                {
                    int val1 = values.Pop();
                    int val2 = values.Pop();
                    int result;
                    if (operators.Pop() == 'M')
                    {
                        result = Math.Max(val1, val2);
                    }
                    else
                    {
                        result = Math.Min(val1, val2);
                    }
                    values.Push(result);
                }
            }
        }
        return values.Pop();
    }
    // 9. Преобразование формулы из файла по заданному правилу
    static int EvaluateFormulaWithRules(string fileName)
    {
        Stack<char> operators = new Stack<char>();
        Stack<int> values = new Stack<int>();
        using (StreamReader sr = new StreamReader(fileName))
        {
            string formula = sr.ReadLine();
            foreach (char c in formula)
            {
                if (c == '(')
                {
                    continue;
                }
                else if (char.IsDigit(c))
                {
                    values.Push(int.Parse(c.ToString()));
                }
                else if (c == 'm' || c == 'p')
                {
                    operators.Push(c);
                }
                else if (c == ')' && operators.Count > 0)
                {
                    int val1 = values.Pop();
                    int val2 = values.Pop();
                    int result;
                    if (operators.Pop() == 'm')
                    {
                        result = (val2 - val1) % 10;
                    }
                    else
                    {
                        result = (val2 + val1) % 10;
                    }
                    values.Push(result);
                }
            }
        }
        return values.Pop();
    }
    // 10. Преобразование текста с учетом символа "#"
    static string ProcessTextWithBackspace(string text)
    {
        Stack<char> stack = new Stack<char>();
        foreach (char c in text)
        {
            if (c != '#')
            {
                stack.Push(c);
            }
            else if (stack.Count > 0)
            {
                stack.Pop();
            }
        }
        char[] resultChars = stack.ToArray();
        Array.Reverse(resultChars);
        return new string(resultChars);
    }
    // 11. Печать элементов файла: сначала все символы, отличные от цифр, затем все цифры
    static void PrintFileElements(string fileName)
    {
        Queue<char> nonDigitChars = new Queue<char>();
        Queue<char> digitChars = new Queue<char>();
        using (StreamReader sr = new StreamReader(fileName))
        {
            while (!sr.EndOfStream)
            {
                char c = (char)sr.Read();
                if (char.IsDigit(c))
                {
                    digitChars.Enqueue(c);
                }
                else
                {
                    nonDigitChars.Enqueue(c);
                }
            }
        }
        while (nonDigitChars.Count > 0)
        {
            Console.Write(nonDigitChars.Dequeue());
        }
        while (digitChars.Count > 0)
        {
            Console.Write(digitChars.Dequeue());
        }
        Console.WriteLine();
    }
    // 12. Печать элементов файла: сначала числа из интервала [a,b], затем числа меньше a, затем числа больше b
    static void PrintFileElementsInRange(string fileName, int a, int b)
    {
        Queue<int> numbersInRange = new Queue<int>();
        Queue<int> numbersLessThanA = new Queue<int>();
        Queue<int> numbersGreaterThanB = new Queue<int>();
        using (StreamReader sr = new StreamReader(fileName))
        {
            while (!sr.EndOfStream)
            {
                int number = int.Parse(sr.ReadLine());
                if (number >= a && number <= b)
                {
                    numbersInRange.Enqueue(number);
                }
                else if (number < a)
                {
                    numbersLessThanA.Enqueue(number);
                }
                else
                {
                    numbersGreaterThanB.Enqueue(number);
                }
            }
        }
        while (numbersInRange.Count > 0)
        {
            Console.WriteLine(numbersInRange.Dequeue());
        }
        while (numbersLessThanA.Count > 0)
        {
            Console.WriteLine(numbersLessThanA.Dequeue());
        }
        while (numbersGreaterThanB.Count > 0)
        {
            Console.WriteLine(numbersGreaterThanB.Dequeue());
        }
    }
    // 13. Печать слов из файла: сначала слова, начинающиеся на гласную, затем на согласную
    static void PrintWordsByFirstLetter(string fileName)
    {
        Queue<string> vowelsWords = new Queue<string>();
        Queue<string> consonantsWords = new Queue<string>();
        using (StreamReader sr = new StreamReader(fileName))
        {
            while (!sr.EndOfStream)
            {
                string word = sr.ReadLine();
                if (!string.IsNullOrEmpty(word))
                {
                    char firstChar = word[0];
                    if (IsVowel(firstChar))
                    {
                        vowelsWords.Enqueue(word);
                    }
                    else
                    {
                        consonantsWords.Enqueue(word);
                    }
                }
            }
        }
        while (vowelsWords.Count > 0)
        {
            Console.WriteLine(vowelsWords.Dequeue());
        }
        while (consonantsWords.Count > 0)
        {
            Console.WriteLine(consonantsWords.Dequeue());
        }
    }
    // 14. Печать чисел из файла: сначала положительные числа, затем отрицательные числа
    static void PrintNumbersBySign(string fileName)
    {
        Queue<int> positiveNumbers = new Queue<int>();
        Queue<int> negativeNumbers = new Queue<int>();
        using (StreamReader sr = new StreamReader(fileName))
        {
            while (!sr.EndOfStream)
            {
                int number = int.Parse(sr.ReadLine());
                if (number >= 0)
                {
                    positiveNumbers.Enqueue(number);
                }
                else
                {
                    negativeNumbers.Enqueue(number);
                }
            }
        }
        while (positiveNumbers.Count > 0)
        {
            Console.WriteLine(positiveNumbers.Dequeue());
        }
        while (negativeNumbers.Count > 0)
        {
            Console.WriteLine(negativeNumbers.Dequeue());
        }
    }
    // 15. Печать слов из файла: сначала слова с прописной буквы, затем со строчной
    static void PrintWordsByCase(string fileName)
    {
        Queue<string> capitalizedWords = new Queue<string>();
        Queue<string> lowercasedWords = new Queue<string>();
        using (StreamReader sr = new StreamReader(fileName))
        {
            while (!sr.EndOfStream)
            {
                string word = sr.ReadLine();
                if (!string.IsNullOrEmpty(word))
                {
                    if (char.IsUpper(word[0]))
                    {
                        capitalizedWords.Enqueue(word);
                    }
                    else
                    {
                        lowercasedWords.Enqueue(word);
                    }
                }
            }
        }
        while (capitalizedWords.Count > 0)
        {
            Console.WriteLine(capitalizedWords.Dequeue());
        }
        while (lowercasedWords.Count > 0)
        {
            Console.WriteLine(lowercasedWords.Dequeue());
        }
    }
    // 16. Печать данных о сотрудниках: сначала данные о мужчинах, затем о женщинах
    static void PrintEmployeesByGender(string fileName)
    {
        Queue<string> maleEmployees = new Queue<string>();
        Queue<string> femaleEmployees = new Queue<string>(); using (StreamReader sr = new StreamReader(fileName))
        {
            while (!sr.EndOfStream)
            {
                string employeeData = sr.ReadLine();
                if (!string.IsNullOrEmpty(employeeData))
                {
                    string[] data = employeeData.Split(',');
                    string gender = data[3].Trim();
                    if (gender.ToLower() == "male")
                    {
                        maleEmployees.Enqueue(employeeData);
                    }
                    else if (gender.ToLower() == "female")
                    {
                        femaleEmployees.Enqueue(employeeData);
                    }
                }
            }
        }
        while (maleEmployees.Count > 0)
        {
            Console.WriteLine(maleEmployees.Dequeue());
        }
        while (femaleEmployees.Count > 0)
        {
            Console.WriteLine(femaleEmployees.Dequeue());
        }
    }
    // 17. Печать данных о сотрудниках: сначала данные о сотрудниках с зарплатой меньше 10000, затем остальные
    static void PrintEmployeesBySalary(string fileName)
    {
        Queue<string> lowSalaryEmployees = new Queue<string>();
        Queue<string> otherEmployees = new Queue<string>();
        using (StreamReader sr = new StreamReader(fileName))
        {
            while (!sr.EndOfStream)
            {
                string employeeData = sr.ReadLine();
                if (!string.IsNullOrEmpty(employeeData))
                {
                    string[] data = employeeData.Split(',');
                    int salary = int.Parse(data[5].Trim());
                    if (salary < 10000)
                    {
                        lowSalaryEmployees.Enqueue(employeeData);
                    }
                    else
                    {
                        otherEmployees.Enqueue(employeeData);
                    }
                }
            }
        }
        while (lowSalaryEmployees.Count > 0)
        {
            Console.WriteLine(lowSalaryEmployees.Dequeue());
        }
        while (otherEmployees.Count > 0)
        {
            Console.WriteLine(otherEmployees.Dequeue());
        }
    }
    // 18. Печать данных о сотрудниках: сначала данные о сотрудниках младше 30 лет, затем остальные
    static void PrintEmployeesByAge(string fileName)
    {
        Queue<string> youngEmployees = new Queue<string>();
        Queue<string> otherEmployees = new Queue<string>();
        using (StreamReader sr = new StreamReader(fileName))
        {
            while (!sr.EndOfStream)
            {
                string employeeData = sr.ReadLine();
                if (!string.IsNullOrEmpty(employeeData))
                {
                    string[] data = employeeData.Split(',');
                    int age = int.Parse(data[4].Trim());
                    if (age < 30)
                    {
                        youngEmployees.Enqueue(employeeData);
                    }
                    else
                    {
                        otherEmployees.Enqueue(employeeData);
                    }
                }
            }
        }
        while (youngEmployees.Count > 0)
        {
            Console.WriteLine(youngEmployees.Dequeue());
        }
        while (otherEmployees.Count > 0)
        {
            Console.WriteLine(otherEmployees.Dequeue());
        }
    }
    // 19. Печать данных о студентах: сначала данные о студентах, успешно сдавших сессию, затем остальные
    static void PrintStudentsBySessionResult(string fileName)
    {
        Queue<string> passedStudents = new Queue<string>();
        Queue<string> otherStudents = new Queue<string>();
        using (StreamReader sr = new StreamReader(fileName))
        {
            while (!sr.EndOfStream)
            {
                string studentData = sr.ReadLine();
                if (!string.IsNullOrEmpty(studentData))
                {
                    string[] data = studentData.Split(',');
                    int mark1 = int.Parse(data[4].Trim());
                    int mark2 = int.Parse(data[5].Trim());
                    int mark3 = int.Parse(data[6].Trim());
                    if (mark1 >= 4 && mark2 >= 4 && mark3 >= 4)
                    {
                        passedStudents.Enqueue(studentData);
                    }
                    else
                    {
                        otherStudents.Enqueue(studentData);
                    }
                }
            }
        }
        while (passedStudents.Count > 0)
        {
            Console.WriteLine(passedStudents.Dequeue());
        }
        while (otherStudents.Count > 0)
        {
            Console.WriteLine(otherStudents.Dequeue());
        }
    }
    // 20. Печать данных о студентах: сначала данные о студентах, успешно обучающихся на оценки 4 и 5, затем остальные
    static void PrintStudentsByGoodMarks(string fileName)
    {
        Queue<string> goodStudents = new Queue<string>();
        Queue<string> otherStudents = new Queue<string>();
        using (StreamReader sr = new StreamReader(fileName))
        {
            while (!sr.EndOfStream)
            {
                string studentData = sr.ReadLine();
                if (!string.IsNullOrEmpty(studentData))
                {
                    string[] data = studentData.Split(',');
                    int mark1 = int.Parse(data[4].Trim());
                    int mark2 = int.Parse(data[5].Trim());
                    int mark3 = int.Parse(data[6].Trim());
                    if (mark1 == 4 || mark1 == 5 && mark2 == 4 || mark2 == 5
                    && mark3 == 4 || mark3 == 5)
                    {
                        goodStudents.Enqueue(studentData);
                    }
                    else
                    {
                        otherStudents.Enqueue(studentData);
                    }
                }
            }
        } while (goodStudents.Count > 0)
        {
            Console.WriteLine(goodStudents.Dequeue());
        }
        while (otherStudents.Count > 0)
        {
            Console.WriteLine(otherStudents.Dequeue());
        }
    }
    static void Main(string[] args)
    {
        // Вызов функций для решения задач с использованием класса Stack
        Console.WriteLine("Задачи с использованием класса Stack:");
        Console.WriteLine();
        // 1. Переписать в другой файл все числа в обратном порядке
        ReverseNumbersInFile("input.txt", "output.txt");
        // 2. Распечатать гласные буквы текстового файла в обратном порядке
        PrintReversedVowels("text.txt");
        // 3. Напечатать содержимое текстового файла, выписывая литеры каждой строки в обратном порядке
        PrintCharactersInReverseOrder("text.txt");
        // 4. Проверка строки s2 на обратность по отношению к s1
        string s1 = "hello";
        string s2 = "olleh";
        bool isReverse = IsReverseString(s1, s2);
        Console.WriteLine($"Строка s2 обратна строке s1: {isReverse}");
        // 5. Вычисление выражения в префиксной форме
        string prefixExpression = "+ 3 * 4 5";
        int prefixResult = EvaluatePrefixExpression(prefixExpression);
        Console.WriteLine($"Результат выражения в префиксной форме:{prefixResult}");
        // 6. Преобразование выражения из инфиксной формы в префиксную
        string infixExpression = "3 + 4 * 5";
        string prefixExpressionConverted = ConvertInfixToPrefix(infixExpression);
        Console.WriteLine($"Префиксная форма выражения:{prefixExpressionConverted}");
        // 7. Преобразование выражения из постфиксной формы в инфиксную
        string postfixExpression = "3 4 5 * +";
        string infixExpressionConverted =
        ConvertPostfixToInfix(postfixExpression);
        Console.WriteLine($"Инфиксная форма выражения:{infixExpressionConverted}");
        // 8. Вычисление значения формулы из текстового файла
        int formulaValue = EvaluateFormulaFromFile("formula.txt");
        Console.WriteLine($"Значение формулы: {formulaValue}");
        // 9. Вычисление значения формулы с операциями m и p из текстового файла
        int formulaValue2 = EvaluateFormulaWithRules("formula2.txt");
        Console.WriteLine($"Значение формулы с операциями m и p:{formulaValue2}");
        // 10. Преобразование текста с учетом символа "#"
        string processedText = ProcessTextWithBackspace("abc#d##c");
        Console.WriteLine($"Обработанный текст: {processedText}");
        Console.WriteLine();
        Console.WriteLine("Задачи с использованием класса Queue:");
        Console.WriteLine();
        // Вызов функций для решения задач с использованием класса Queue
        // 11. Печать элементов файла: сначала все символы, отличные от цифр, затем все цифры
        PrintFileElements("text.txt");
        // 12. Печать элементов файла: сначала числа из интервала [a,b], затем числа меньше a, затем числа больше b
        PrintFileElementsInRange("numbers.txt", 3, 7);
        // 13. Печать слов из файла: сначала слова, начинающиеся на гласную, затем на согласную
        PrintWordsByFirstLetter("words.txt");
        // 14. Печать чисел из файла: сначала положительные числа, затем отрицательные числа
        PrintNumbersBySign("numbers.txt");
        // 15. Печать слов из файла: сначала слова с прописной буквы, затем со строчной
        PrintWordsByCase("words.txt");
        // 16. Печать данных о сотрудниках: сначала данные о мужчинах, затем о женщинах
        PrintEmployeesByGender("employees.txt");
        // 17. Печать данных о сотрудниках: сначала данные о сотрудниках с зарплатой меньше 10000, затем остальные
        PrintEmployeesBySalary("employees.txt");
        // 18. Печать данных о сотрудниках: сначала данные о сотрудниках младше 30 лет, затем остальные
        PrintEmployeesByAge("employees.txt");
        // 19. Печать данных о студентах: сначала данные о студентах, успешно сдавших сессию, затем остальные
        PrintStudentsBySessionResult("students.txt");
        // 20. Печать данных о студентах: сначала данные о студентах, успешно обучающихся на оценки 4 и 5, затем остальные
        PrintStudentsByGoodMarks("students.txt");
        Console.ReadLine();
    }
}