import java.util.Scanner;

class Main{
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n;
        String input1 = "", input2 = "";
        n = sc.nextInt();
        sc.nextLine();
        while(n-- > 0){
            input1 = sc.nextLine();
            boolean fC = true;
            String s2 = "", s3 = "", s4 = "", s5 = "", total = "";
            for(int i = 0; i < input1.length(); i++){
                if(input1.charAt(i) == '<' && fC){
                    while(input1.charAt(i) != '>') {
                        if(input1.charAt(i) == '<'){
                            i++;
                            continue;
                        }
                        s2 += input1.charAt(i);
                        i++;
                    }
                    fC = false;
                }
                if(input1.charAt(i) != '<' && input1.charAt(i) != '>' && !fC && s4.equals("")){
                    s3 += input1.charAt(i);
                }
                if(input1.charAt(i) == '<' && !fC){
                    while(input1.charAt(i) != '>') {
                        if(input1.charAt(i) == '<'){
                            i++;
                            continue;
                        }
                        s4 += input1.charAt(i);
                        i++;
                    }
                }
                if(input1.charAt(i) != '<' && input1.charAt(i) != '>' && !fC && !s4.equals("")){
                    s5 += input1.charAt(i);
                }
            }
            total = s4 + s3 + s2 + s5;
            input2 = sc.nextLine();
            input2 = input2.replace("...", total);
            input1 = input1.replace("<","");
            input1 = input1.replace(">","");
            System.out.println(input1);
            System.out.println(input2);
        }
    }
}