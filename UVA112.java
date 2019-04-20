import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (br.ready()) {
            sb.append((char) br.read());
        }
        String brArbol = sb.toString();
        Scanner scConvertir = new Scanner(brArbol);
        while (scConvertir.hasNextInt()) {
            long suma = scConvertir.nextInt();
            String arbol = convertir(scConvertir);
            if (existeSuma(new Scanner(arbol), suma, 0).equals("yes")) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }
    }

    private static String convertir(Scanner sc) {
        StringBuilder sb = new StringBuilder();
        int parentesisFaltantes = 0;
        while (sc.hasNext()) {
            String linea = sc.next();
            sb.append(' ');
            sb.append(linea);
            parentesisFaltantes = parentesisFaltantes + parentActual(linea);
            if(parentesisFaltantes == 0) break;
        }
        String arbol = sb.toString();
        arbol = arbol.replace("(", " ( ");
        arbol = arbol.replace(")", " ) ");
        return arbol;
    }

    private static int parentActual(String linea) {
        int parentesis = 0;
        for (int i = 0; i < linea.length(); i++) {
            char p = linea.charAt(i);
            if (p == '(') {
                parentesis++;
            }
            if (p == ')') {
                parentesis--;
            }
        }
        return parentesis;
    }

    private static String existeSuma(Scanner scArbol, long suma, long sumaActual) {
        scArbol.next();
        String numero = scArbol.next();
        if (numero.equals(")")) {
            return "noHijo";
        } else {
            int hijo = Integer.parseInt(numero);
            sumaActual = sumaActual + hijo;
            String hijoIzq = existeSuma(scArbol, suma, sumaActual);
            if (hijoIzq.equals("yes")) {
                return "yes";
            }
            String hijoDer = existeSuma(scArbol, suma, sumaActual);
            if (hijoDer.equals("yes")) {
                return "yes";
            }
            scArbol.next();
            if (hijoIzq.equals("noHijo") && hijoDer.equals("noHijo") && suma == sumaActual) {
                return "yes";
            } else {
                return "no";
            }
        }
    }
}