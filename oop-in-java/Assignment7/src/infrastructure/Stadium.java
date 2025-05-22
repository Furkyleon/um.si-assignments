package infrastructure;

public class Stadium extends Venue{

    // constructors
    public Stadium() {
    }

    public Stadium(String name) {
        super(name);
    }

    public Stadium(String name, String phoneNumber) {
        super(name, phoneNumber);
    }

    public Stadium(String name, String phoneNumber, int matchCapacity) {
        super(name, phoneNumber, matchCapacity);
    }


    // toString
    @Override
    public String toString() {
        return "Stadium: " + getName() + ", " + getPhoneNumber();
    }

    // methods
    @Override
    public double returnCapacity() {
        return this.matchesList.length;
    }
}
