import java.util.Scanner;
class Main{
    
    public static void main(String[] args){
        String[] months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        int[] mdays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int n, pdays, pyear, day, cont = 0;
        String input;
        String[] inputA = new String[3];
        Scanner sc = new Scanner(System.in);
        n = Integer.parseInt(sc.nextLine());
        while(cont < n){
          input = sc.nextLine();
          inputA = input.split("-");
          int index = java.util.Arrays.asList(months).indexOf(inputA[1]);
          pyear = Integer.parseInt(inputA[0]);
          day = Integer.parseInt(inputA[2]);
          pdays = Integer.parseInt(sc.nextLine());
          mdays = esBisiesto(pyear, mdays);
          if(day + pdays <= mdays[index]){
            System.out.println("Case " + (cont + 1) + ": " + pyear + "-" + months[index] + "-" + String.format("%02d", day + pdays));
            break;
          }
          if(day + pdays > mdays[index]){
            pdays = pdays + day - mdays[index];
              while(true){
                if(index < 11){
                  index++;
                }else {
                  index = 0; 
                  pyear++;
                  mdays = esBisiesto(pyear, mdays);
                }
                if(mdays[index] - pdays >= 0){
                  System.out.println("Case " + (cont + 1) + ": " + pyear + "-" + months[index] + "-" + String.format("%02d", pdays));
                  break;
                }
                pdays = Math.abs(mdays[index] - pdays);
              }
          }
          cont++;
        }
    }
    
    private static int[] esBisiesto(int pyear, int[] mdays){
       if(pyear % 4 == 0 && (pyear % 100 != 0 || pyear % 400 == 0)){
          mdays[1] = 29;
       }else{mdays[1] = 28;}
       return mdays;
    }
}