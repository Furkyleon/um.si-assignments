import sport.*;
import infrastructure.*;

import java.time.LocalDate;

public class Main {
    public static void main(String[] args) {

        ScheduledDate scheduledDate = new ScheduledDate(LocalDate.of(2025, 6, 15));
        System.out.println(scheduledDate);

        Athlete athlete1 = new Athlete("Janez", "Novak", 10, LocalDate.of(2010, 3, 21));
        Athlete athlete2 = new Athlete("Matic", "Kranjc", 11, LocalDate.of(2008, 5, 10));
        athlete1.setSportsDiscipline(SportsDiscipline.ATHLETICS);
        athlete2.setSportsDiscipline(SportsDiscipline.VOLLEYBALL);
        System.out.println(athlete1);
        System.out.println(athlete2);

        Event event1 = new Match("Handball", scheduledDate);
        Event event2 = new Training("Winter training", scheduledDate, "Marko Kovac");
        System.out.println(event1);
        System.out.println(event2);

        Match match1 = new Match("National youth championship", scheduledDate);
        Match match2 = new Match("Finals", scheduledDate);
        System.out.println(match1);
        System.out.println(match2);

        match1.addAthleteToMatch(athlete1);
        match1.addAthleteToMatch(athlete2);
        System.out.println(match1.getNumberOfAthletesInMatch());
        System.out.println(match1.athleteExists("Novak"));

        Hall hall = new Hall("Center Hall", "012345678", 5, true);
        System.out.println(hall);
        System.out.println(hall.returnCapacity());
        Stadium stadium = new Stadium("Stadium Arena", "098765432", 3);
        System.out.println(stadium);
        System.out.println(stadium.returnCapacity());

        hall.addMatch(match1);
        hall.addMatch(match2);
        System.out.println(hall.returnOccupancy());

        hall.removeMatches();
        System.out.println(hall.returnOccupancy());
    }
}
