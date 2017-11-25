import java.math.BigInteger;
import java.util.Scanner;

class Main{
    public static void main(String[] args){
        String number = "1";
        BigInteger sum = BigInteger.ZERO;
        Scanner sc = new Scanner(System.in);
        while(!number.equals("0")){
            number = sc.next();
            BigInteger addS = new BigInteger(number);
            sum = sum.add(addS);
        }
        System.out.println(sum);
    }
}