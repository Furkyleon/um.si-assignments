import java.time.LocalDate;

public class Training {

    // attributes
    private String title;
    private ScheduledDate scheduledDate;
    private String trainerName;
    private boolean cancelled;

    // constructor
    public Training(String title) {
        this.title = title;
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

    public String getTrainerName() {
        return trainerName;
    }

    public void setTrainerName(String trainerName) {
        this.trainerName = trainerName;
    }

    public boolean isCancelled() {
        return cancelled;
    }

    public void setCancelled(boolean cancelled) {
        this.cancelled = cancelled;
    }

}
