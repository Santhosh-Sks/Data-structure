///Single-linked-list in java Language //

import java.util.Scanner;
class myNode{
    int data;
    myNode next;
    myNode(int data){   ///Create new node and
    /// Initialize value
        this.data= data;
        this.next = null;
    }
}
class singleLL{
    myNode head;
    void insertNode(int data){
        myNode newNode = new myNode(data);
        if(head==null) {
            newNode.next = head;
            head = newNode;
            return;
        }
        myNode curr = head;
        while (curr.next!=null) {
            curr=curr.next;
        }
        curr.next = newNode;
        newNode.next =null;
        return;



    }
    void inbegin(int data) {
        myNode newNode = new myNode(data);
        if(head==null) {
            newNode.next=head; //Check list is empty
            head = newNode;
            return;
        }
        else {
            newNode.next=head;  //if existing node change address
            head = newNode;
        }
    }
    void endin(int data) {
        myNode newNode = new myNode(data); // Node creation
        if(head == null) {
            head = newNode;
            return;
        }
        else {
            myNode curr=head;
            while(curr.next!=null) {
                curr = curr.next; //if any node is existing change is next part
            }
            curr.next = newNode;
            newNode.next =null;
        }
    }
    void position(int data,int pos) {
        myNode newNode = new myNode(data);
        if(head==null) {
            System.out.println("List is empty,insert as first node");
            return;
        }
        if(head.data==pos){
            inbegin(data);
        }
        myNode curr = head;
        int count=0;
        while(curr!=null) {
            curr = curr.next;
            count++;
            if(count==pos-1) {
                newNode.next=curr.next;
                curr.next=newNode;
            }

        }
        System.out.println("Invalid Position");
    }
    void delete(int data){
        if(head==null){
            System.out.println("ListNode is empty");
            return;
        }
        if(head.data==data){
            head = head.next;
            return;
        }
        myNode curr = head;
        while(curr.next!=null){
            if(curr.next.data==data){
                curr.next =curr.next.next;
                return;
            }
            curr=curr.next;
        }
        System.out.println("Value not found");
    }
    void search(int data){
        if(head==null){
            System.out.println("List is empty");
            return;
        }
        myNode curr = head;
        int count=1;
        while(curr.next!=null){
            if(curr.data==data){
                System.out.println("Node value is found at position "+count);
                return;
            }
            count++;
            curr=curr.next;
        }
        System.out.println("Node value not found !");
    }
    void selectsorting(){
        if(head==null){
            System.out.println("List is empty");
            return;
        }
        for(myNode curr=head;curr!=null;curr=curr.next){
            myNode MinNode = curr;
            for(myNode temp=curr.next;temp!=null;temp=temp.next){
                if(temp.data<MinNode.data){
                    MinNode=temp;
                }
            }
            if(MinNode!=curr){
                int tempData=curr.data;
                curr.data=MinNode.data;
                MinNode.data=tempData;
            }
        }
        System.out.println("Elements to be sorted ");
    }
    void display() {
        if(head == null) {
            System.out.println("List is empty");
            return;
        }
        myNode curr = head;
        System.out.print("Head--> ");
        while(curr.next!=null) {
            System.out.print(curr.data+"--> ");
            curr = curr.next;

        }
        if(curr.next==null) {
            System.out.print(curr.data+" --> Null");
            return;
        }

    }
}
public class singlelinked {
    public static void main(String[] args) {
        singleLL sl = new singleLL();
        Scanner sc = new Scanner(System.in);
        int num,pos,choice =0;
        while(choice<9) {
            System.out.println();
            System.out.println("1.Insert at Begin");
            System.out.println("2.Insert at End");
            System.out.println("3.Insert a node value  ");
            System.out.println("4.Insert at given position");
            System.out.println("5.Delete node value ");
            System.out.println("6.Search node value");
            System.out.println("7.Display elements");
            System.out.println("8.sort elements");
            System.out.println("9.Exist");
            System.out.println("Enter your choice : ");
            choice = sc.nextInt();
            switch(choice) {
                case 1:
                    System.out.println("Enter a Node value at begin : ");
                    num = sc.nextInt();
                    sl.inbegin(num);
                    System.out.println("Node add in begin successfully ");
                    break;
                case 2:
                    System.out.println("Enter a Node value at end : ");
                    num = sc.nextInt();
                    sl.endin(num);
                    System.out.println("Node add in end successfully ");
                    break;
                case 3:
                    System.out.println("Enter a Node value : ");
                    num = sc.nextInt();
                    sl.insertNode(num);
                    System.out.println("Node inserted successfully ");
                    break;
                case 4:
                    System.out.println("Enter a Node value : ");
                    num = sc.nextInt();
                    System.out.println("Enter position to insert value : ");
                    pos = sc.nextInt();
                    sl.position(num,pos);
                    System.out.println("Value inserted successfully");
                    break;
                case 5:
                    System.out.println("Enter a Node value to delete : ");
                    num = sc.nextInt();
                    sl.delete(num);
                    System.out.println("Value deleted successfully");
                    break;
                case 6:
                    System.out.println("Enter a node value to search : ");
                    num = sc.nextInt();
                    sl.search(num);
                    break;
                case 7:
                    sl.display();
                    break;
                case 8:
                    sl.selectsorting();
                    System.out.println("Node sorted successfully");
                    break;
                case 9:
                    System.out.println("Existing.....!");
                    break;
                default:
                    System.out.println("Choice valid choice");
                    break;

            }
        }
        sc.close();
    }

}
