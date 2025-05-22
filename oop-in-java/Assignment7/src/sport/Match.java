package sport;

import infrastructure.Venue;

import java.io.Serializable;
import java.time.LocalDate;

public class Match extends Event implements Competition, Serializable {

    private static final long serialVersionUID = 1L;

    // attributes
    private Athlete[] athletesList = new Athlete[10];

    // constructor
    public Match(){}

    public Match(String title){
        super(title);
    }

    public Match(String title, ScheduledDate scheduledDate) {
        super(title, scheduledDate);
    }

    public Match(String title, ScheduledDate scheduledDate, boolean cancelled) {
        super(title, scheduledDate, cancelled);
    }

    // getters and setters
    public String getTitle() {
        return super.getTitle();
    }
    public void setTitle(String title) {
        super.setTitle(title);
    }
    public ScheduledDate getScheduledDate() {
        return super.getScheduledDate();
    }
    public void setScheduledDate(ScheduledDate scheduledDate) {
        super.setScheduledDate(scheduledDate);
    }
    public boolean isCancelled() {
        return super.isCancelled();
    }
    public void setCancelled(boolean cancelled) {
        super.setCancelled(cancelled);
    }

    // toString method
    @Override
    public String toString() {
        return "Match: " + getTitle() + " on " + getScheduledDate().getScheduledDate();
    }

    // methods

    // checks whether the athlete can compete at the Youth national championship:
    // (only athletes between the ages of (including) 14 and 18, can compete at the championship)
    public boolean canCompete(Athlete athlete){
        int birthYear = athlete.getBirthDate().getYear();
        int thisYear = LocalDate.now().getYear();
        int age = thisYear - birthYear;

        if (age >= 14 && age <= 18){
            return true;
        }
        else {
            return false;
        }
    }

    // which adds an athlete to the match (adds the athlete to the athletesList array):
    // Also supplement the addAthleteToMatch() to first check whether the athlete can compete (use the existing method).
    // If the athlete is not eligible to compete, trigger the custom exception AddingAthleteException;
    public void addAthleteToMatch(Athlete athlete) {
        for (int i = 0; i < athletesList.length; i++) {
            if (athletesList[i] == null) {
                if (!canCompete(athlete)){
                    throw new AddingAthleteException("AddingAthleteException");
                }
                else {
                    athletesList[i] = athlete;
                    break;
                }
            }
        }
    }

    // add athlete to match (new function):
    public void addAthleteToMatch2(Athlete athlete){
        for (int i = 0; i < athletesList.length; i++) {
            if (athletesList[i] == null) {
                athletesList[i] = athlete;
                break;
            }
        }
    }

    // which allows for the removal of an athlete from the match (removes the athlete from the athletesList array)
    public void removeAthleteFromMatch(Athlete athlete) {
        for (int i = 0; i < athletesList.length; i++) {
            if (athletesList[i] != null) {
                if (athletesList[i].equals(athlete)) {
                    athletesList[i] = null;
                    break;
                }
            }
        }
    }

    // which allows the removal of an athlete from the match based on their athlete number
    public boolean removeAthleteFromMatch(int athleteNumber) {
        for (int i = 0; i < athletesList.length; i++) {
            if (athletesList[i].getAthleteNumber() == athleteNumber) {
                athletesList[i] = null;
                return true;
            }
        }
        return false;
    }

    // which returns the number of athletes in the match
    public int getNumberOfAthletesInMatch() {
        int counter = 0;
        for (int i = 0; i < athletesList.length; i++) {
            if (athletesList[i] != null) {
               counter++;
            }
        }
        return counter;
    }

    // which checks if an athlete with a specific last name has already been added to the match
    public boolean athleteExists(String surname) {
        for (int i = 0; i < athletesList.length; i++) {
            if (athletesList[i] != null) {
                if (athletesList[i].getSurname().equals(surname)) {
                    return true;
                }
            }
        }
        return false;
    }

    // In the class Match checks whether the match has been assigned to the given venue.
    // If yes, the method should print "Match X can be performed" otherwise "Match X has not been added to venue".
    // (Replace X with Match title).
    @Override
    public void checkValidity(Venue venue) {
        if (venue.getMatchesList() != null) {
            for (int i = 0; i < venue.getMatchesList().length; i++) {
                if (venue.getMatchesList()[i] != null) {
                    if (venue.getMatchesList()[i].equals(this)) {
                        System.out.println("Match " + this.getTitle() + " can be performed");
                        return;
                    }
                }
            }
            System.out.println("Match " + this.getTitle() + " has not been added to venue");
        }
    }
}
