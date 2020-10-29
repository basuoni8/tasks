package task1;

import java.util.Scanner;


public class Task1 {

    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.println("what is membership of customer?");
        String membership=input.next(); 
        customer person=new customer(membership);
        System.out.println("Enter products cost for a visit");
        person.setProducts_cost(input.nextDouble());
        System.out.println("Enter services cost for a visit");
        person.setServices_cost(input.nextDouble());
        person.discount_percentage();
        double afterdiscount=discount.after_discount();
        System.out.println("Enter number of visits");
        visit v=new visit(input.nextInt());
        double Total=v.getTotal_cost(afterdiscount);
        System.out.println("Total cost is "+ Total);
    }
    
}
