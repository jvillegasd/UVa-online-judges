import java.math.BigInteger;
import java.util.Scanner;

class Main{

    public static void main(String[] args){
        String maxInt = "2147483647", n1, n2, op;
        BigInteger n1B, n2B;
        BigInteger maxI = new BigInteger(maxInt);
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            n1 = sc.next();
            op = sc.next();
            n2 = sc.next();
            System.out.println(n1 + " " + op + " " + n2);
            n1B = new BigInteger(n1);
            n2B = new BigInteger(n2);
            if(n1B.compareTo(maxI) > 0) System.out.println("first number too big");
            if(n2B.compareTo(maxI) > 0) System.out.println("second number too big");
            if(op.equals("+")) n1B = n1B.add(n2B);
            if(op.equals("*")) n1B = n1B.multiply(n2B);
            if(n1B.compareTo(maxI) > 0) System.out.println("result too big");
        }
    }
}