class Find
{
    public static void main(String[] args)
    {
        System.out.print("Enter the string: ");
        String input = System.console().readLine();
        String outString = FindNChange(input);

        System.out.println("The string is: " + outString);
    }
    public static String FindNChange(String input)
    {
        char tmp = input.charAt(0);
        String newString = "";
        int findCount = 1;

        for (int i=1; i < input.length(); ++i)
        {
            if (input.charAt(i) == tmp)
            {
                findCount++;
            }
            else
            {
                newString += tmp + "" + findCount;
                tmp = input.charAt(i);
                findCount = 1;
            }
        }
        return newString + tmp + findCount;
    }
}
