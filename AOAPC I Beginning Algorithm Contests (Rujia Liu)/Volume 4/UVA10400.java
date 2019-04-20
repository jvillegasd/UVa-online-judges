import java.util.Scanner;
import java.io.IOException;

class Main {

    static boolean[][] matrizA;
    static String input, operacion;
    static long respO;
    static String[] numeros;
    static int index;

    public static void main(String[] args) throws IOException{
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        sc.nextLine();
        while (n-- > 0) {
            matrizA = new boolean[120][65000];
            operacion = "";
            input = sc.nextLine();
            numeros = input.split(" ");
            respO = Long.parseLong(numeros[numeros.length - 1]);
            index = Integer.parseInt(numeros[0]);
            if (DFS(Long.parseLong(numeros[1]), 2, numeros[1])) {
                System.out.println(operacion + "=" + respO);
            } else {
                System.out.println("NO EXPRESSION");
            }
        }
    }

    public static boolean DFS(long sum, int i, String tResp) {
        if (opValida(sum) && matrizA[i][(int) (sum + 32000)]) {
            return false;
        }
        if (i <= index) {
            int oNum = Integer.parseInt(numeros[i]);
            if(opValida(sum)) matrizA[i][(int) (sum + 32000)] = true;
            if (opValida(sum + oNum) && DFS(sum + oNum, i + 1, tResp + "+" + oNum)) {
                return true;
            }
            if (opValida(sum - oNum) && DFS(sum - oNum, i + 1, tResp + "-" + oNum)) {
                return true;
            }
            if (opValida(sum * oNum) && DFS(sum * oNum, i + 1, tResp + "*" + oNum)) {
                return true;
            }
            if (oNum != 0 && sum % oNum == 0 && opValida(sum / oNum) && DFS(sum / oNum, i + 1, tResp + "/"+ oNum)) {
                return true;
            }
        } else {
            if (i == index + 1) {
                if (sum == respO) {
                    operacion = tResp;
                    return true;
                }
                return false;
            }
        }
        return false;
    }

    private static boolean opValida(long num) {
        return num <= 32000 && num >= -32000;
    }
}