package si.um.opj.yilmaz.ui;
import infrastructure.Venue;
import sport.Athlete;
import sport.Event;
import sport.Match;

import java.io.*;
import java.util.ArrayList;
import java.util.zip.GZIPInputStream;
import java.util.zip.GZIPOutputStream;

public class DataStorage {

    private static final String FILE_NAME = "SportApplication.gz";

    public static void saveData(AppGUI appGUI) {
        try (ObjectOutputStream oos = new ObjectOutputStream(new GZIPOutputStream(new FileOutputStream(FILE_NAME)))) {
            oos.writeObject(appGUI.getAthletes());
            oos.writeObject(appGUI.getEvents());
            oos.writeObject(appGUI.getVenues());
            oos.writeObject(appGUI.getMatches());
        }
        catch (FileNotFoundException e) {
            System.out.println("File not found: " + FILE_NAME);
            e.printStackTrace();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }

    @SuppressWarnings("unchecked")
    public static void loadData(AppGUI appGUI) {
        File file = new File(FILE_NAME);
        if (!file.exists()) {
            return;
        }

        try (ObjectInputStream ois = new ObjectInputStream(new GZIPInputStream(new FileInputStream(FILE_NAME)))) {
            appGUI.setAthletes((ArrayList<Athlete>) ois.readObject());
            appGUI.setEvents((ArrayList<Event>) ois.readObject());
            appGUI.setVenues((ArrayList<Venue>) ois.readObject());
            appGUI.setMatches((ArrayList<Match>) ois.readObject());
        }
        catch (FileNotFoundException e) {
            System.out.println("File not found: " + FILE_NAME);
            e.printStackTrace();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
        catch (ClassNotFoundException e) {
            System.out.println("Class not found: " + e.getMessage());
            e.printStackTrace();
        }
    }
}
