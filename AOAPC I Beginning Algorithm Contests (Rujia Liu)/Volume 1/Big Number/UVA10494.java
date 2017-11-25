import java.util.Scanner;
import java.math.BigInteger;
import javax.security.sasl.Sasl;

class Main{

    public static void main(String[] args){
        BigInteger n1B, n2B;
        String op, n1, n2;
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            n1 = sc.next();
            op = sc.next();
            n2 = sc.next();
            n1B = new BigInteger(n1);
            n2B = new BigInteger(n2);
            if(op.equals("/")) n1B = n1B.divide(n2B);
            else n1B = n1B.mod(n2B);
            System.out.println(n1B);
        }
    }
}