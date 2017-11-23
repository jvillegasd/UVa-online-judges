import java.util.Scanner;
import java.math.BigInteger;
class Main{
    
    public static void main(String[] args){
        String input = "";
        int n;
        Scanner sc = new Scanner(System.in);
        n = Integer.parseInt(sc.nextLine());
        for(int i = 0; i < n; i++){
          input = sc.nextLine();
          System.out.println(fraccion(input));
        }
    }
    private static String fraccion(String input){
      String[] inputArray = new String[3];
      inputArray = input.split(" ");
      BigInteger numerador = new BigInteger(inputArray[0]);
      BigInteger denominador = new BigInteger(inputArray[2]);
      BigInteger mcd = maximo(numerador, denominador);  
      return (numerador.divide(mcd)) + " / " + (denominador.divide(mcd));
    }
    
    private static BigInteger maximo(BigInteger n, BigInteger m){
      if(m.compareTo(BigInteger.ZERO) == 0){
        return n;
      }
      return maximo(m, n.mod(m));
    }
}