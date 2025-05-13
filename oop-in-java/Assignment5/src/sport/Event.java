package sport;

public class Event {

    // attributes
    private String title;
    private ScheduledDate scheduledDate;
    private boolean cancelled;

    public Event(){}

    public Event(String title) {
        this.title = title;
    }

    public Event(String title, ScheduledDate scheduledDate) {
        this(title);
        this.scheduledDate = scheduledDate;
    }

    public Event(String title, ScheduledDate scheduledDate, boolean cancelled) {
        this(title, scheduledDate);
        this.cancelled = cancelled;
    }

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

    @Override
    public String toString() {
        return "Event:"+ title + "," + scheduledDate + "," + cancelled;
    }

}
