/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package task1;

public class visit {
    protected double total_cost;
    protected int num_of_visits;

    public visit(int num_of_visits) {
        this.num_of_visits = num_of_visits;
    }

    public double getTotal_cost(double cost_afterdiscount) {
        total_cost=cost_afterdiscount*num_of_visits;
        return total_cost;
    }
    
    
}
