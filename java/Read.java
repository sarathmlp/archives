class Read
{
    public static void main(String[] args)
    {
        System.out.print("Enter the string: ");
        String input = System.console().readLine();
        char[] input_arr = input.toCharArray();

        char[] arr = new char[100];
        for(int i=0; i < input_arr.length; i++)
        {
            arr[i] = input_arr[i];
        }

        arr[(input_arr.length)] = '\u0000';
        FillArray(arr, input_arr.length);

        System.out.println("The string is: " + new String(arr));
    }
    public static void FillArray(char[] data, int length)
    {
        int spaceCount = 0;
        for (int i=0; i < length; i++)
        {
            if (data[i] == ' ')
            {
                spaceCount++;
            }
        }

        int newLength = length + spaceCount;
        data[newLength] = '\u0000';

        for (int i = length - 1 ; i >= 0; i--)
        {
            if (data[i] == ' ')
            {
                data[--newLength] = 'y';
                data[--newLength] = 'x';
            }
            else
            {
                data[--newLength] = data[i];
            }
        }
    }
}
