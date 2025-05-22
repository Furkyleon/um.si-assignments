package infrastructure;

public class Hall extends Venue {

    // attributes
    private boolean eveningGames;

    // constructors
    public Hall(boolean eveningGames) {
        this.eveningGames = eveningGames;
    }

    public Hall(String name, boolean eveningGames) {
        super(name);
        this.eveningGames = eveningGames;
    }

    public Hall(String name, String phoneNumber, boolean eveningGames) {
        super(name, phoneNumber);
        this.eveningGames = eveningGames;
    }

    public Hall(String name, String phoneNumber, int matchCapacity, boolean eveningGames) {
        super(name, phoneNumber, matchCapacity);
        this.eveningGames = eveningGames;
    }

    // getters and setters
    public boolean isEveningGames() {
        return eveningGames;
    }
    public void setEveningGames(boolean eveningGames) {
        this.eveningGames = eveningGames;
    }

    // toString
    @Override
    public String toString() {
        return "Hall: " + getName() + ", " + getPhoneNumber();
    }

    // methods
    @Override
    public double returnCapacity() {
        if (this.eveningGames) {
            return (double) (this.matchesList.length * 120) / 100;
        }
        else {
            return this.matchesList.length;
        }
    }
}
