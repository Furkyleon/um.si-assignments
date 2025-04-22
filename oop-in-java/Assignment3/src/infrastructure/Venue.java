package infrastructure;

import sport.Match;
import sport.SportsDiscipline;

public abstract class Venue {

    // attributes
    private String name;
    private String phoneNumber;
    protected Match[] matchesList;
    private SportsDiscipline sportsDiscipline;

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

    public Venue(String name, String phoneNumber, int matchCapacity) {
        this(name, phoneNumber);
        matchesList = new Match[matchCapacity];
    }

    // getters and setters
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getPhoneNumber() {
        return phoneNumber;
    }
    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }
    public SportsDiscipline getSportsDiscipline() {
        return sportsDiscipline;
    }
    public void setSportsDiscipline(SportsDiscipline sportsDiscipline) {
        this.sportsDiscipline = sportsDiscipline;
    }

    // toString
    @Override
    public String toString() {
        return "Venue:" + name + "," + phoneNumber + "," + sportsDiscipline;
    }

    // methods

    // adds a match to the venue:
    public void addMatch(Match match) {
        for (int i = 0; i < matchesList.length; i++) {
            if (matchesList[i] == null) {
                matchesList[i] = match;
                break;
            }
        }
    }

    // removes all matches from the venue:
    public void removeMatches(){
        for (int i = 0; i < matchesList.length; i++) {
            if (matchesList[i] != null) {
                matchesList[i] = null;
            }
        }
    }

    // returns the venue's occupancy percentage based on scheduled matches:
    public double returnOccupancy(){
        double occupancy = 0;
        for (int i = 0; i < matchesList.length; i++) {
            if (matchesList[i] != null) {
                occupancy++;
            }
        }
        return (occupancy/this.returnCapacity())*100;
    }

    // an abstract method that returns the venue’s capacity:
    // (the total number of potential matches it can host)
    public abstract double returnCapacity();

}
