package sport;

import java.time.LocalDate;

public class Match {

    // attributes
    private String title;
    private ScheduledDate scheduledDate;
    private boolean cancelled;
    private final Athlete[] athletesList = new Athlete[10];

    // constructor
    public Match(String title, ScheduledDate scheduledDate) {
        this.title = title;
        this.scheduledDate = scheduledDate;
    }

    // getters and setters
    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public ScheduledDate getScheduledDate() {
        return scheduledDate;
    }

    public void setScheduledDate(ScheduledDate scheduledDate) {
        this.scheduledDate = scheduledDate;
    }

    public boolean isCancelled() {
        return cancelled;
    }

    public void setCancelled(boolean cancelled) {
        this.cancelled = cancelled;
    }

    // toString method
    @Override
    public String toString() {
        return "Match:"+ title + "," + scheduledDate + "," + cancelled;
    }

    // methods
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

    // which adds an athlete to the match (adds the athlete to the athletesList array)
    public void addAthleteToMatch(Athlete athlete) {
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

}
