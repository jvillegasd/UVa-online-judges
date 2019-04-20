import java.util.Scanner;

class Main {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int space;
        String input;
        String[] array;
        while(sc.hasNext()){
            input = sc.nextLine();
            space = 0;
            for(int i = 0; i < input.length(); i++){
                if(Character.isLetter(input.charAt(i))){
                    while(Character.isLetter(input.charAt(i))) i++;
                    i--;
                    space++;
                }
            }
            System.out.println(space);
        }
    }
}