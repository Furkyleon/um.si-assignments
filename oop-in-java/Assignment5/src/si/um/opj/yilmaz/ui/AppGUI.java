package si.um.opj.yilmaz.ui;

import javax.swing.*;

public class AppGUI {
    private JPanel MainPanel;
    private JTextField AthNameTF;
    private JTextField AthSurnameTF;
    private JTextField AthNumTF;
    private JButton createButton1;
    private JLabel AthNumLabel;
    private JLabel AthSurnameLabel;
    private JLabel AthNameLabel;
    private JTabbedPane tabbedPane1;
    private JPanel Event;
    private JPanel Athlete;
    private JPanel Venue;
    private JTextField AthBDTF;
    private JComboBox AthSportDisCB;
    private JLabel AthBirthLabel;
    private JLabel AthSportDisLabel;
    private JLabel EventTitleLabel;
    private JLabel EventSDLabel;
    private JTextField EventTitleTF;
    private JTextField EventSDTF;
    private JTextField VenueNameTF;
    private JTextField VenuePhoneTF;
    private JButton Create;
    private JLabel VenueNameLabel;
    private JLabel VenuePhoneLabel;
    private JList eventList;
    private JList athleteList;
    private JList venueList;
    private JPanel Management;
    private JList AthleteList;
    private JList EventList;
    private JLabel AthleteListLabel;
    private JLabel EventListLabel;
    private JTabbedPane ManagementTabs;
    private JPanel AthleteToEvent;
    private JPanel MatchToVenue;
    private JList MatchList;
    private JList VenueList;
    private JLabel MatchListLabel;
    private JLabel VenueListLabel;
    private JButton deleteButton;
    private JButton deleteButton1;
    private JButton editButton;
    private JButton editButton1;
    private JButton editButton2;
    private JButton deleteButton2;
    private JButton createButton;
    private JButton createButton2;
    private JComboBox EventTypeCB;
    private JComboBox VenueTypeCB;
    private JLabel EventTypeLabel;
    private JLabel VenueTypeLabel;
    private JButton addMatchToVenueButton;
    private JButton addAthleteToEventButton;
    private JButton removeAthleteFromEventButton;
    private JButton removeMatchFromVenueButton;
    private JTextField TrainerNameTF;
    private JLabel TrainerNameLabel;


    public static void main(String[] args) {
        JFrame frame = new JFrame("Sport Application");
        frame.setSize(350, 200);
        frame.setContentPane(new AppGUI().MainPanel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }

}
