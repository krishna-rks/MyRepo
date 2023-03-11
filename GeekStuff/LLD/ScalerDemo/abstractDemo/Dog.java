package abstractDemo;

public class Dog extends Animal{

    // We can make use of attributes of abstract class(parent) here
    public Dog(String dogName, int dogAge) {
        name = dogName;
        age = dogAge;
    }

    // Abstract method implementation.
    @Override
    public void walk() {
        System.out.println("Dog is running");
    }
}
