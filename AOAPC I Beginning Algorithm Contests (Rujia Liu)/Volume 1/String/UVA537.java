import java.util.Scanner;

class Main{

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n, cont = 0;
        n = sc.nextInt();
        sc.nextLine();
        while(cont < n){
            String input = sc.nextLine();
            char mult = ' ';
            double P = 0, U = 0, I = 0;
            for(int i = 1; i < input.length(); i++){
                if(input.charAt(i) == '='){
                    if(input.charAt(i-1) == 'P'){
                        i++;
                        String number = "";
                        while(Character.isDigit(input.charAt(i)) || input.charAt(i) == '.'){
                            number += input.charAt(i);
                            i++;
                        }
                        P = Double.parseDouble(number);
                        mult = input.charAt(i);
                        if(mult == 'm') P *= 0.001;
                        else if(mult == 'k') P *= 1000;
                        else if(mult == 'M') P *= 1000000;
                    }
                    if(input.charAt(i-1) == 'I'){
                        i++;
                        String number = "";
                        while(Character.isDigit(input.charAt(i)) || input.charAt(i) == '.'){
                            number += input.charAt(i);
                            i++;
                        }
                        I = Double.parseDouble(number);
                        mult = input.charAt(i);
                        if(mult == 'm') I *= 0.001;
                        else if(mult == 'k') I *= 1000;
                        else if(mult == 'M') I *= 1000000;
                    }
                    if(input.charAt(i-1) == 'U'){
                        i++;
                        String number = "";
                        while(Character.isDigit(input.charAt(i)) || input.charAt(i) == '.'){
                            number += input.charAt(i);
                            i++;
                        }
                        U = Double.parseDouble(number);
                        mult = input.charAt(i);
                        if(mult == 'm') U *= 0.001;
                        else if(mult == 'k') U *= 1000;
                        else if(mult == 'M') U *= 1000000;
                    }
                }
            }
            System.out.println("Problem #" + (cont + 1));
            if(P == 0){
                P = I * U;
                System.out.println("P=" + String.format("%.2f", P) + "W");
            } else if(I == 0){
                I = P / U;
                System.out.println("I=" + String.format("%.2f", I) + "A");
            } else{
                U = P / I;
                System.out.println("U=" + String.format("%.2f", U) + "V");
            }
            if(cont < n) System.out.println();
            cont++;
        }
    }
}