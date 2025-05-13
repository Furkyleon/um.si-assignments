package sport;

import infrastructure.Venue;

import java.time.LocalDate;

public class Athlete implements Competition {

    // attributes
    private String name;
    private String surname;
    private int athleteNumber;
    private LocalDate birthDate;
    private SportsDiscipline sportsDiscipline;
    private Match[] ownMatchList = new Match[5];

    // constructors
    public Athlete() {}

    public Athlete (String name, String surname) {
        this();
        this.name = name;
        this.surname = surname;
    }

    public Athlete (String name, String surname, int athleteNumber, LocalDate birthDate) {
        this(name, surname);
        this.athleteNumber = athleteNumber;
        this.birthDate = birthDate;
    }

    // getters and setters
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getSurname() {
        return surname;
    }
    public void setSurname(String surname) {
        this.surname = surname;
    }
    public int getAthleteNumber() {
        return athleteNumber;
    }
    public void setAthleteNumber(int athleteNumber) {
        this.athleteNumber = athleteNumber;
    }
    public LocalDate getBirthDate() {
        return birthDate;
    }
    public void setBirthDate(LocalDate birthDate) {
        this.birthDate = birthDate;
    }
    public SportsDiscipline getSportsDiscipline() {
        return sportsDiscipline;
    }
    public void setSportsDiscipline(SportsDiscipline sportsDiscipline) {
        this.sportsDiscipline = sportsDiscipline;
    }
    public Match[] getOwnMatchList() {
        return ownMatchList;
    }

    // toString
    @Override
    public String toString() {
        return "Athlete:" + name + "," + surname + "," + athleteNumber + "," + birthDate + "," + sportsDiscipline;
    }

    // Method checkValidity in Athlete checks whether the athlete is assigned to a match from the venue.
    // When doing that check using the method from assignment 2 that checks using the surname of the athletes.
    // If the athlete has been assigned to at least one match at the venue, add the match to the array ownMatchList.
    @Override
    public void checkValidity(Venue venue) {
        if (venue != null) {
            for (int i = 0; i < venue.getMatchesList().length; i++) {
                if (venue.getMatchesList()[i] != null) {
                    if (venue.getMatchesList()[i].athleteExists(surname)) {
                        for (int j = 0; j < ownMatchList.length; j++) {
                            if (ownMatchList[j] == null) {
                                ownMatchList[j] = venue.getMatchesList()[i];
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}
