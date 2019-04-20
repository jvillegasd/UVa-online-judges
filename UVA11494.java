import java.util.Scanner;
class Main{
    
    public static void main(String[] args){
        String input;
        String[] inputArray = new String[4];
        int x1, y1, x2, y2;
        Scanner sc = new Scanner(System.in);
        while (true)
        {
            input = sc.nextLine();
            inputArray = input.split(" ");
            x1 = Integer.parseInt(inputArray[0]);
            y1 = Integer.parseInt(inputArray[1]);
            x2 = Integer.parseInt(inputArray[2]);
            y2 = Integer.parseInt(inputArray[3]);
            if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)
            {
                break;
            }
            if (itsDiagonal(x1, y1, x2, y2) || itsHoriVer(x1, y1, x2, y2))
            {
                System.out.println(1);
            }else if(x1 != x2 && y1 != y2){
                System.out.println(2);
            }else{
                System.out.println(0);
            }
        }
    }

    private static boolean itsDiagonal(int x1, int y1, int x2, int y2){
        if(Math.abs(x1 - x2) == Math.abs(y1 - y2) && Math.abs(x1 - x2) != 0)
        {
            return true;
        }
        return false;
    }

    private static boolean itsHoriVer(int x1, int y1, int x2, int y2){
        if(y1 == y2 && x1 != x2){
            return true;
        }
        if (x1 == x2 && y1 != y2)
        {
            return true;
        }  
        return false;
    }
}