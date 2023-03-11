package abstractDemo;

public class Main {
    public static void main(String[] args) {
        // we can create a child class object and upcast to parent abstract class.
        // This can be done in a regular parent/child class also.
        Animal a = new Dog("Tuffi", 2 );
        a.breathe();
        a.walk();
    }
}
