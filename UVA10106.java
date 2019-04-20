import java.util.Scanner;
import java.math.BigInteger;

class Main{
    
    public static void main(String args[]){
        BigInteger x, y;
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextBigInteger()){
            x = sc.nextBigInteger();
            y = sc.nextBigInteger();
            System.out.println(x.multiply(y));
        }
    }
}