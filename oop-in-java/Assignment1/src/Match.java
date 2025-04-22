import java.time.LocalDate;

public class Match {

    // attributes
    private String title;
    private ScheduledDate scheduledDate;
    private boolean cancelled;

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

}
