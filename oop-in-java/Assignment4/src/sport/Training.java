package sport;

public class Training extends Event {

    // attributes
    private String trainerName;

    // constructor
    public Training(){}

    public Training(String title){
        super(title);
    }

    public Training(String title, ScheduledDate scheduledDate) {
        super(title, scheduledDate);
    }

    public Training(String title, ScheduledDate scheduledDate, String trainerName) {
        super(title, scheduledDate);
        this.trainerName = trainerName;
    }

    public Training(String title, ScheduledDate scheduledDate, boolean cancelled, String trainerName) {
        super(title, scheduledDate, cancelled);
        this.trainerName = trainerName;
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
    public String getTrainerName() {
        return trainerName;
    }
    public void setTrainerName(String trainerName) {
        this.trainerName = trainerName;
    }

    // toString method
    @Override
    public String toString() {
        return super.toString() + "," + trainerName;
    }

}
