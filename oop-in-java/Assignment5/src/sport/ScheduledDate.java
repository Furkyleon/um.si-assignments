package sport;

import java.time.LocalDate;

public class ScheduledDate {

    // attribute
    private LocalDate scheduledDate;

    // constructor
    public ScheduledDate(LocalDate scheduledDate) {
        this.scheduledDate = scheduledDate;
    }

    // getter and setter
    public LocalDate getScheduledDate() {
        return scheduledDate;
    }
    public void setScheduledDate(LocalDate scheduledDate) {
        this.scheduledDate = scheduledDate;
    }

    // toString method
    @Override
    public String toString() {
        return "ScheduledDate:"+ scheduledDate;
    }

    public int getDay() {
        return scheduledDate.getDayOfMonth();
    }
}
