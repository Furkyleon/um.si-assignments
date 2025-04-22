package sport;

import java.time.LocalDate;

public class Athlete {

    // attributes
    private String name;
    private String surname;
    private int athleteNumber;
    private LocalDate birthDate;
    private SportsDiscipline sportsDiscipline;

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

    // toString
    @Override
    public String toString() {
        return "Athlete:" + name + "," + surname + "," + athleteNumber + "," + birthDate + "," + sportsDiscipline;
    }

}
