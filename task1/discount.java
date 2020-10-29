/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package task1;

public class discount extends customer{
    protected static double cost_afterdiscount;
   
    public discount(String type) {
        super(type);
    }
    public static double after_discount(){
        cost_afterdiscount= (products_cost - products_cost*product_discount)+(services_cost - services_cost*services_discount);
        return cost_afterdiscount;
    }

    
    
}
