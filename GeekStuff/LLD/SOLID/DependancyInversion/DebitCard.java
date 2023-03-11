package DependancyInversion;

public class DebitCard implements BankCard{
    public void doTransaction(int amount)
    {
        System.out.println("Payment done using debit card for Rs " +amount);
    }
}
