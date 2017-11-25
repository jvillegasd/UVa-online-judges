import java.math.BigInteger;
import java.util.Scanner;

class Main{
    public static void main(String[] args){
        BigInteger n1, n2;
        Scanner sc = new Scanner(System.in);
        String n1S, n2S;
        while(sc.hasNext()){
            n1S = sc.next();
            n2S = sc.next();
            n1 = new BigInteger(n1S);
            n2 = new BigInteger(n2S);
            n1 = n1.multiply(n2);
            System.out.println(n1);
        }
    }
}