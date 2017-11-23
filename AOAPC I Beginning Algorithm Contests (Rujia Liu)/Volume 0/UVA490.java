import java.util.Scanner;

class Main{

    public static void main(String[] args){
        String line;
        Scanner sc = new Scanner(System.in);
        char[][] oraciones = new char[101][101];
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                oraciones[i][j] = ' ';
            }
        }
        int indexI = 0, indexJ = 0;
        while(sc.hasNextLine()){
          line = sc.nextLine();
          if(line.length()==0) break;
          char[] lineArray = line.toCharArray();
          for(int i = 0; i < lineArray.length; i++){
              oraciones[indexI][i] = lineArray[i];
          }
          indexI++;
          if(lineArray.length > indexJ) indexJ = lineArray.length;
        }
        for(int i = 0; i < indexJ; i++){
            for(int j = indexI-1; j >= 0; j--){
                System.out.print(oraciones[j][i]);
            }
            System.out.println();
        }
    }
}