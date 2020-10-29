/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package task1;

public class customer {
    private String membership;
    protected static double product_discount;
    protected static double services_discount;
    protected static double products_cost;
    protected static double services_cost;
    
   
    public customer(String type){
    membership=type.toLowerCase();
    product_discount=.1;
}
    public void discount_percentage(){
        if(membership.equals("premium"))
            services_discount=.2;
        else if(membership.equals("gold"))
            services_discount=.15;
        else if(membership.equals("silver"))
            services_discount=.1;
        else
            services_discount=0.0;
    }
    public void setProducts_cost(double products_cost) {
        this.products_cost = products_cost;
    }

    public void setServices_cost(double services_cost) {
        this.services_cost = services_cost;
    }
    public static void setProduct_discount(double product_discount) {
        customer.product_discount = product_discount;
    }
}
