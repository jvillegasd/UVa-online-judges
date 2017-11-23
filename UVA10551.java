import java.util.Scanner;
import java.math.BigInteger;

class Main{
  
  public static void main(String[] args){
     int test, base;
     String input;
     String[] inputA = new String[3];
     Scanner sc = new Scanner(System.in);
     while(true){
       input = sc.nextLine();
       if(input.equals("0")) break;
       inputA = input.split(" ");
       base = Integer.parseInt(inputA[0]);
       BigInteger n1 = new BigInteger(inputA[1], base);
       BigInteger n2 = new BigInteger(inputA[2], base);
       BigInteger n3 = new BigInteger(String.valueOf(n1.mod(n2)));
       System.out.println(n3.toString(base));
     }
  }
}