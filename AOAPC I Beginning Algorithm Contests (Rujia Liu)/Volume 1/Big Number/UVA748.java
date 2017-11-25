import java.math.BigDecimal;
import java.util.Scanner;

class Main{

    public static void main(String[] args){
        int exp;
        BigDecimal base;
        Scanner sc = new Scanner(System.in);
        String ans;
        while(sc.hasNext()){
            base = sc.nextBigDecimal();
            exp = sc.nextInt();
            base = base.pow(exp).stripTrailingZeros();
            ans = base.toPlainString();
            int index = ans.indexOf(".");
            if(index == 1 && ans.substring(0,1).equals("0")) ans = ans.substring(1);
            System.out.println(ans);
        }
    }
}