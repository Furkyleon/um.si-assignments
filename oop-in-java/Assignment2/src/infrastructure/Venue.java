package infrastructure;

public class Venue {

    // attributes
    private String name;
    private String phoneNumber;

    // constructors
    public Venue() {}

    public Venue(String name) {
        this();
        this.name = name;
    }

    public Venue(String name, String phoneNumber) {
        this(name);
        this.phoneNumber = phoneNumber;
    }

    // toString
    @Override
    public String toString() {
        return "Venue:" + name + "," + phoneNumber;
    }

}
