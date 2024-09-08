namespace BubbleSort;

public class Program
{

    public static void Main()
    {
        int[] toSort = new int[] { 666, 6, 9, 420, 80085 };
        int[] sorted = Sort(toSort);
        
        foreach (var i in sorted)
        {
            Console.WriteLine(i);
        }

    }

    public static int[] Sort(int[] input)
    {
        int temp = 0;
        for (int write = 0; write < input.Length; write++) {

            for (int sort = 0; sort < input.Length - 1; sort++) {
                if (input[sort] > input[sort + 1]) {
                    temp = input[sort + 1];
                    input[sort + 1] = input[sort];
                    input[sort] = temp;
                }
            }
        }

        return input;
    }
}

