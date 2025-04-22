import infrastructure.Venue;
import sport.Athlete;
import sport.Match;
import sport.ScheduledDate;
import sport.Training;

import java.time.LocalDate;

public class Main {
    public static void main(String[] args) {
        ScheduledDate scheduledDate = new ScheduledDate(LocalDate.of(2025, 6, 15));
        System.out.println(scheduledDate);

        Athlete athlete1 = new Athlete("Janez", "Novak", 10, LocalDate.of(2010, 3, 21));
        Athlete athlete2 = new Athlete("Matic", "Kranjc", 11, LocalDate.of(2008, 5, 10));
        System.out.println(athlete1);
        System.out.println(athlete2);

        Match match = new Match("National youth championship", scheduledDate);
        System.out.println(match);

        // Dodajanje sportnikov na tekmo
        match.addAthleteToMatch(athlete1);
        match.addAthleteToMatch(athlete2);
        System.out.println(match.getNumberOfAthletesInMatch());
        System.out.println(match.athleteExists("Novak"));
        System.out.println(match.athleteExists("Kranjc"));

        // Odstranjevanje sportnikov
        match.removeAthleteFromMatch(athlete1);
        System.out.println(match.getNumberOfAthletesInMatch());
        System.out.println(match.athleteExists("Novak"));

        // Ustvarjanje prizorisca
        Venue venue = new Venue("Dvorana Center", "012345678");
        System.out.println(venue);
    }

}
