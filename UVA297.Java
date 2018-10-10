import java.util.Scanner;

public class Main {

    static int index = 0, maxLvl = 0, bpc = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        while(tc-- > 0){
            String qt1 = sc.next();
            String qt2 = sc.next();
            index = -1;
            maxLvl = bpc = 0;
            Node quadtree1 = new Node();
            quadtree1.data = '-';
            buildQuadtree(qt1, 0, quadtree1);
            index = -1;
            Node quadtree2 = new Node();
            quadtree2.data = '-';
            buildQuadtree(qt2, 0, quadtree2);
            quadtree1 = quadtree1.children[0];
            quadtree2 = quadtree2.children[0];
            sumQuadtrees(quadtree1, quadtree2);
            int numNodes = (int)Math.pow(4, maxLvl);
            int bp = (1024/numNodes) * bpc;
            System.out.println("There are " + bp + " black pixels.");
        }
    }
    
    static void sumQuadtrees(Node qt1, Node qt2){
        if(qt1 == null && qt2 == null) return;
        else if(qt1 != null && qt1.isLeaf() && qt1.lvl != maxLvl && qt1.data == 'f') bpc+=4;
        else if(qt1 != null && qt1.isLeaf() && qt1.lvl == maxLvl && qt1.data == 'f') bpc+=1;
        else if(qt2 != null && qt2.isLeaf() && qt2.lvl != maxLvl && qt2.data == 'f') bpc+=4;
        else if(qt2 != null && qt2.isLeaf() && qt2.lvl == maxLvl && qt2.data == 'f') bpc+=1;
        else{
            for(int i = 0; i < 4; i++){
                Node childqt1 = (qt1 == null)?null:qt1.children[i];
                Node childqt2 = (qt2 == null)?null:qt2.children[i];
                sumQuadtrees(childqt1, childqt2);
            }
        }
    }
    
    static void buildQuadtree(String qt, int lvl, Node parent){
        index++;
        if(lvl > maxLvl) maxLvl = lvl;
        Node node = new Node();
        node.data = qt.charAt(index);
        node.lvl = lvl;
        parent.add(node);
        if(qt.charAt(index) == 'p') for(int i = 0; i < 4; i++) buildQuadtree(qt, lvl + 1, node);
    }
    
    static class Node{
        Node[] children = new Node[4];
        int size = 0;
        int lvl = 0;
        char data = ' ';
        
        void add(Node node){
            children[size] = node;
            size++;
        }
        
        boolean isLeaf(){
            return size == 0;
        }
    }
}