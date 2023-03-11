package abstractDemo;

public abstract class Animal {
    public String name;
    public int age;
    public int numberOfLegs; //4

    // here constructor is used only for initialising the variables
    // we can't create object of an abstract class
    // we can have parameter constructor also.
    public Animal() {
        this.numberOfLegs = 4; //maintain number of connection ->
    }

    // we can have a concrete method like this also.
    public void breathe(){
        System.out.println("Animal is breathing");
    }

    public abstract void walk();
}
// Always Interface is preferred over Abstract classes.
