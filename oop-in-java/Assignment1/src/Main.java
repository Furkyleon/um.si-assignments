import java.time.LocalDate;

public class Main {
    public static void main(String[] args) {
        ScheduledDate scheduledDate = new ScheduledDate(LocalDate.of(2025, 6, 15));
        System.out.println("ScheduledDate:" + scheduledDate.getScheduledDate());

        Athlete athlete1 = new Athlete("Janez", "Novak");
        athlete1.setAthleteNumber(10);
        athlete1.setBirthDate(LocalDate.of(2010, 3, 21));
        System.out.println("Athlete:" + athlete1.getName() + "," + athlete1.getSurname() + "," + athlete1.getAthleteNumber() +","+ athlete1.getBirthDate());

        Athlete athlete2 = new Athlete();
        athlete2.setName("Marija");
        athlete2.setSurname("Hribar");
        athlete2.setBirthDate(LocalDate.of(1998, 5, 1));
        athlete2.setAthleteNumber(66);

        Match match = new Match("Handball", scheduledDate);
        System.out.println("Match:" + match.getTitle() + "," + match.getScheduledDate().getScheduledDate());

        System.out.println("Can compete:" + match.canCompete(athlete1));
        System.out.println("Can compete:" + match.canCompete(athlete2));

        Training training = new Training("Winter training");
        training.setScheduledDate(scheduledDate);
        training.setTrainerName("Marko Kovac");
        System.out.println("Training:" + training.getTitle() + "," + training.getTrainerName() + "," + training.getScheduledDate().getScheduledDate());
    }
}
