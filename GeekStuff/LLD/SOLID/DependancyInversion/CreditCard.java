package DependancyInversion;

public class CreditCard implements BankCard {
    public void doTransaction(int amount)
    {
        System.out.println("Payment done using credit card for Rs " +amount);
    }
}
