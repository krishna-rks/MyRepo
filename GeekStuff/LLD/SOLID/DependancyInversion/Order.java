package DependancyInversion;


/*
 * Reference
 * https://www.waytoeasylearn.com/learn/dependency-inversion-principle/
 * https://medium.com/@kedren.villena/simplifying-dependency-inversion-principle-dip-59228122649a
 * 
 */
public class Order {
    // This class is going to act as client/payment gateway
    public Order(BankCard pBankCard)
    {
        // Now I have BankCard object handy as soon as the Order object is created.
        // we can have multiple such interface objects handy when Order object is created.
        this.bankCard = pBankCard;
    }
    
    public void receiveOrder(String orderName, int amount)
    {
        System.out.println("Order received for " +orderName);
        System.out.println("Cook is preparing the order");
        // Here we don't know the implementation/card type of doTransaction function.
        // Irrespective of the payment mode it would work. Even if we add new payment method also
        // we can easily add it without touching the code.
        bankCard.doTransaction(amount);
        System.out.println("Delivery boy picked up your order");
        System.out.println("Your order is delivered successfully");
    }
    // Here we are injecting the interface object
    private BankCard bankCard;



    public static void main(String[] args)
    {
        // Get the payment/card type from the client
        BankCard bankCard1 = new DebitCard();
        Order order1 = new Order(bankCard1);
        order1.receiveOrder("parota", 100);

        System.out.println("\n");
        // This time I am going to pay with credit card
        BankCard bankCard2 = new CreditCard();
        Order order2 = new Order(bankCard2);
        order2.receiveOrder("chicken curry", 150);
    }
}
