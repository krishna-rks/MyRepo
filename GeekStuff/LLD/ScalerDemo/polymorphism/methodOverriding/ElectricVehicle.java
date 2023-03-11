package polymorphism.methodOverriding;

public class ElectricVehicle extends Vehicle{

    @Override
    public void startEngine(){
        // *super keyword is used here to call parent class' function which is overridden here. *
        super.startEngine();
        System.out.println("Start electric motors");
        System.out.println("Started electric vehicle");
    }

    public void blowHorn(){
        System.out.println("Blowing horn in ElectricVehicle");
    }
}
