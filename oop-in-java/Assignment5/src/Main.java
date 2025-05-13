import infrastructure.Hall;
import infrastructure.Stadium;
import sport.*;

import java.time.LocalDate;

public class Main {
    public static void main(String[] args) {

        ScheduledDate scheduledDate1 = new ScheduledDate(LocalDate.of(2025, 6, 15));
        ScheduledDate scheduledDate2 = new ScheduledDate(LocalDate.of(2025, 6, 25));
        System.out.println(scheduledDate1);
        System.out.println(scheduledDate2);

        Athlete athlete1 = new Athlete("Janez", "Novak", 10, LocalDate.of(2015, 3, 21));
        Athlete athlete2 = new Athlete("Matic", "Kranjc", 11, LocalDate.of(2008, 5, 10));
        Athlete athlete3 = new Athlete();
        athlete1.setSportsDiscipline(SportsDiscipline.ATHLETICS);
        athlete2.setSportsDiscipline(SportsDiscipline.VOLLEYBALL);
        System.out.println(athlete1);
        System.out.println(athlete2);
        System.out.println(athlete3);

        Match match1 = new Match("National youth championship", scheduledDate1);
        Match match2 = new Match("Finals", scheduledDate1);
        Match match3 = new Match("Finals", scheduledDate2);
        System.out.println(match1);
        System.out.println(match2);
        System.out.println(match3);

        try {
            match1.addAthleteToMatch(athlete2);
            match1.addAthleteToMatch(athlete1);
        } catch (AddingAthleteException e) {
            System.out.println("Exception:" + e.getMessage());
        }
        System.out.println(match1.getNumberOfAthletesInMatch());

        Hall hall = new Hall("Center Hall", "012345678", 5, true);
        Stadium stadium = new Stadium("Stadium Arena", "098765432", 3);
        System.out.println(hall);
        System.out.println(stadium);

        try {
            hall.addMatch(match1);
            stadium.addMatch(match2);
            stadium.addMatch(match3);
        }
        catch (AddingMatchException e){
            System.out.println("Exception:"+e.getMessage());
        }

        System.out.println(hall.returnOccupancy());
        System.out.println(stadium.returnOccupancy());

        match1.checkValidity(hall);
        match2.checkValidity(stadium);
        match3.checkValidity(stadium);
        athlete1.checkValidity(stadium);
        athlete2.checkValidity(hall);

        for (Match m : athlete1.getOwnMatchList()) {
            if (m != null) {
                System.out.println(m);
            }
        }
        for (Match m : athlete2.getOwnMatchList()) {
            if (m != null) {
                System.out.println(m);
            }
        }

        hall.removeMatches();
        System.out.println(hall.returnOccupancy());
    }
}
