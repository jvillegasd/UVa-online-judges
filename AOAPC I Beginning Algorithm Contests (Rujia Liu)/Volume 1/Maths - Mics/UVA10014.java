import java.util.Scanner;

class Main{ //UVA 10014
    
    public static void main(String[] args){
        int n, test, cont = 0;
        double firstCase = 1001, secondCase = 1001;
        double[] c = new double[3000];
        Scanner sc = new Scanner(System.in);
        test = sc.nextInt();
        while(test-- > 0){
            n = sc.nextInt();
            firstCase = sc.nextDouble();
            secondCase = sc.nextDouble();  
            for (int i = 1; i <= n; i++)
            {
                c[i] = sc.nextDouble();
            }
            double number = ecuation(n, firstCase, secondCase, n, c, 2);
            System.out.println(String.format("%.2f", number));
            if(cont != test) System.out.println();
        }
    }

    private static double ecuation(int n, double firstCase, double secondCase, int iteration, double[] c, int multiplier){
        if (iteration >= 1)
        {
            return ecuation(n, firstCase, secondCase, iteration - 1, c, multiplier + 2) - multiplier * c[iteration] / (n + 1); 
        }
        return (n * firstCase + secondCase) / (n + 1);
    }
}
/* Hey dude, for this exercise you need to catch a pattern and create an ecuation from it, I start at n case, the ecuation will be:
    a(n) = (a(n - 1) + a(n + 1))/2 - c(n), now we need to get n - 1 case, then the ecuation will be: 
    a(n - 1) = (a(n - 2) + a(n))/2 - c(n - 1). Now I going to use some algebra an the ecuation will be: 
    2 * a(n - 1) = a(n - 2) + a(n) - 2 * c(n - 1) (<- ecuation 1), doing the same algebra to the n case: 
    2 * a(n) = a(n - 1) + a(n + 1) - 2 * c(n) (<- ecuation 2). I have two ecuation, I put ecuation 2 into 
    ecuation 1 so the final ecuation is: 4 * a(n - 1) = 2 * a(n - 2) + a(n - 1) + a(n + 1) - 4 * c(n - 1) - 2 * c(n),
    3 * a(n - 1) = 2 * a(n - 2) + a(n + 1) - 4 * c(n - 1) - 2 * c(n), the pattern is when you get k cases before n case,
    you will finish at a(1) case (we need it!) and the ecuation always be:
    (z + 1) * a(n - z + 1) = z * a(n - z) + a(n + 1) - 2 * z * c(n - z + 1) - 2 * (z - 1) * c(n - z + 2) *...* 2 * c(n),
    (z + 1) * a(n - z + 1) = z * a(n - z) + a(n + 1) - 2 * summation from i = 1 to i = z of i * c(n - i + 1) when z is
    the actual iteration of k times, then the final ecuation will be:
    a(1) = [n * a(0) + a(n + 1) - 2 * summation from i = 1 to i = n of i * c(n - i + 1)] / (n + 1)*/