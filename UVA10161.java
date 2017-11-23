import java.util.Scanner;
import java.math.BigInteger;

class Main{

    public static void main(String[] args){
        int numero;
        String input;
        Scanner sc = new Scanner(System.in);
        while(true){
            input = sc.nextLine();
            numero = Integer.parseInt(input);
            if(numero == 0) break;
            System.out.println(getResultado(numero));
        }
    }

    private static String getResultado(int numero){
        String resultado = "";
        int segmento = (int)Math.ceil(Math.sqrt(numero));
        int mitadSegmento = (int)Math.pow(segmento, 2) - segmento + 1;
        int x, y;
        if(segmento % 2 == 0){
            if(numero > mitadSegmento){
                x = segmento;
                y = segmento - (numero - mitadSegmento);
            }else{
                x = segmento - (mitadSegmento - numero); 
                y = segmento;
            }
        }else{
            if(numero > mitadSegmento){
                x = segmento - (numero - mitadSegmento);
                y = segmento;
            }else{
                x = segmento; 
                y = segmento - (mitadSegmento - numero);
            }
        }
        resultado = x + " " + y;
        return resultado;
    }
    /*
    Formulas:
    - Ubicacion segmento = el techo de sqrt(numero).
    - No de datos de un segmento = 2*segmento - 1.
    - Mitad del segmento encontrado = segmento^2 - segmento + 1 = MS.
    - X,Y pueden variar entre el segmento o la formula: segmento - Math.abs(MS - numero) 
      dependiendo si segmento es par o no.
    */
}