package si.um.opj.yilmaz.ui;

import sport.*;
import infrastructure.*;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.time.LocalDate;
import java.util.ArrayList;

public class AppGUI {
    private JPanel MainPanel;
    private JTabbedPane tabbedPane1;

    private JPanel Athlete;
    private JList athleteList;
    private JTextField AthNameTF;
    private JTextField AthSurnameTF;
    private JTextField AthNumTF;
    private JTextField AthBDTF;
    private JComboBox AthSportDisCB;
    private JLabel AthNumLabel;
    private JLabel AthSurnameLabel;
    private JLabel AthNameLabel;
    private JLabel AthBirthLabel;
    private JLabel AthSportDisLabel;
    private JButton createButton1;
    private JButton deleteButton1;
    private JButton editButton1;

    private JPanel Event;
    private JList eventList;
    private JTextField EventTitleTF;
    private JTextField EventSDTF;
    private JTextField TrainerNameTF;
    private JComboBox EventTypeCB;
    private JLabel TrainerNameLabel;
    private JLabel EventTitleLabel;
    private JLabel EventSDLabel;
    private JLabel EventTypeLabel;
    private JButton createButton;
    private JButton deleteButton;
    private JButton editButton;

    private JPanel Venue;
    private JTextField VenueNameTF;
    private JTextField VenuePhoneTF;
    private JComboBox VenueTypeCB;
    private JTextField venueCapacityTF;
    private JLabel VenueNameLabel;
    private JLabel VenuePhoneLabel;
    private JLabel VenueTypeLabel;
    private JLabel venueCapacity;
    private JList venueList;
    private JButton createButton2;
    private JButton deleteButton2;
    private JButton editButton2;

    private JPanel Management;
    private JTabbedPane ManagementTabs;

    private JPanel AthleteToEvent;
    private JList AthleteList;
    private JList MatchList1;
    private JLabel AthleteListLabel;
    private JLabel EventListLabel;
    private JButton addAthleteToMatchButton;
    private JButton removeAthleteFromMatchButton;

    private JPanel MatchToVenue;
    private JList MatchList2;
    private JList VenueList;
    private JLabel MatchListLabel;
    private JLabel VenueListLabel;
    private JButton addMatchToVenueButton;
    private JButton removeMatchFromVenueButton;

    // array lists and models
    private ArrayList<Athlete> athletes = new ArrayList<>();
    private DefaultListModel<Athlete> athleteModel = new DefaultListModel<>();

    private ArrayList<Event> events = new ArrayList<>();
    private DefaultListModel<Event> eventModel = new DefaultListModel<>();

    private ArrayList<Venue> venues = new ArrayList<>();
    private DefaultListModel<Venue> venueModel = new DefaultListModel<>();

    private ArrayList<Match> matches = new ArrayList<>();
    private DefaultListModel<Match> matchModel = new DefaultListModel<>();

    public AppGUI() {
        // athlete tab
        athleteList.setModel(athleteModel);
        createButton1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Athlete ath = new Athlete(
                        AthNameTF.getText(),
                        AthSurnameTF.getText(),
                        Integer.parseInt(AthNumTF.getText()),
                        LocalDate.parse(AthBDTF.getText())
                );
                ath.setSportsDiscipline(SportsDiscipline.valueOf(AthSportDisCB.getSelectedItem().toString()));
                athletes.add(ath);
                athleteModel.addElement(ath);

                // clearing the text fields after adding the athlete
                AthNameTF.setText("");
                AthSurnameTF.setText("");
                AthNumTF.setText("");
                AthBDTF.setText("");
                AthSportDisCB.setSelectedIndex(0);
            }
        });

        deleteButton1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int selectedIndex = athleteList.getSelectedIndex();
                if (selectedIndex != -1) {
                    athleteModel.remove(selectedIndex);
                    athletes.remove(selectedIndex);
                }

                // clearing the text fields after adding the athlete
                AthNameTF.setText("");
                AthSurnameTF.setText("");
                AthNumTF.setText("");
                AthBDTF.setText("");
                AthSportDisCB.setSelectedIndex(0);
            }
        });

        editButton1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int selectedIndex = athleteList.getSelectedIndex();
                if (selectedIndex != -1) {
                    Athlete ath = athletes.get(selectedIndex);
                    ath.setName(AthNameTF.getText());
                    ath.setSurname(AthSurnameTF.getText());
                    ath.setAthleteNumber(Integer.parseInt(AthNumTF.getText()));
                    ath.setBirthDate(LocalDate.parse(AthBDTF.getText()));
                    ath.setSportsDiscipline(SportsDiscipline.valueOf(AthSportDisCB.getSelectedItem().toString()));
                    athleteModel.set(selectedIndex, ath);
                }
            }
        });

        athleteList.addListSelectionListener(e -> {
            if (!e.getValueIsAdjusting()) {
                int selectedIndex = athleteList.getSelectedIndex();
                if (selectedIndex != -1) {
                    Athlete selectedAthlete = athletes.get(selectedIndex);
                    AthNameTF.setText(selectedAthlete.getName());
                    AthSurnameTF.setText(selectedAthlete.getSurname());
                    AthNumTF.setText(String.valueOf(selectedAthlete.getAthleteNumber()));
                    AthBDTF.setText(selectedAthlete.getBirthDate().toString());
                    AthSportDisCB.setSelectedItem(selectedAthlete.getSportsDiscipline().toString());
                }
            }
        });

        // event tab
        eventList.setModel(eventModel);

        createButton.addActionListener(new EventInnerClass());
        deleteButton.addActionListener(new EventInnerClass());
        editButton.addActionListener(new EventInnerClass());

        eventList.addListSelectionListener(e -> {
            if (!e.getValueIsAdjusting()) {
                int selectedIndex = eventList.getSelectedIndex();
                if (selectedIndex != -1) {
                    Event selectedEvent = events.get(selectedIndex);
                    EventTitleTF.setText(selectedEvent.getTitle());
                    EventSDTF.setText(selectedEvent.getScheduledDate().getScheduledDate().toString());
                    EventTypeCB.setSelectedItem(selectedEvent instanceof Training ? "Training" : "Match");

                    if (selectedEvent instanceof Training) {
                        TrainerNameTF.setText(((Training) selectedEvent).getTrainerName());
                    } else {
                        TrainerNameTF.setText("");
                    }
                }
            }
        });

        // venue tab
        venueList.setModel(venueModel);

        VenueIndependentClass venueIndependentClass = new VenueIndependentClass(venues, venueList, venueModel, VenueNameTF, VenuePhoneTF, VenueTypeCB, venueCapacityTF);
        createButton2.addActionListener(venueIndependentClass);
        deleteButton2.addActionListener(venueIndependentClass);
        editButton2.addActionListener(venueIndependentClass);

        // management tab
        AthleteList.setModel(athleteModel);
        MatchList1.setModel(matchModel);
        MatchList2.setModel(matchModel);
        VenueList.setModel(venueModel);

        addAthleteToMatchButton.addActionListener(new ManagementInnerClass());
        addMatchToVenueButton.addActionListener(new ManagementInnerClass());
        removeAthleteFromMatchButton.addActionListener(new ManagementInnerClass());
        removeMatchFromVenueButton.addActionListener(new ManagementInnerClass());
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Sport Application");
        frame.setSize(600, 300);
        frame.setContentPane(new AppGUI().MainPanel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }

    class EventInnerClass implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            if (e.getSource() == createButton) {
                String eventType = EventTypeCB.getSelectedItem().toString();
                Event event;

                if ("Match".equals(eventType)) {
                    event = new Match(
                            EventTitleTF.getText(),
                            new ScheduledDate(LocalDate.parse(EventSDTF.getText()))
                    );
                    matches.add((Match) event);
                    matchModel.addElement((Match) event);
                }
                else if ("Training".equals(eventType)) {
                    event = new Training(
                            EventTitleTF.getText(),
                            new ScheduledDate(LocalDate.parse(EventSDTF.getText())),
                            TrainerNameTF.getText()
                    );
                }
                else {
                    JOptionPane.showMessageDialog(null, "Invalid event type selected.");
                    return;
                }

                events.add(event);
                eventModel.addElement(event);

                // clearing the text fields after adding the event
                EventTitleTF.setText("");
                EventSDTF.setText("");
                TrainerNameTF.setText("");
                EventTypeCB.setSelectedIndex(0);
            }
            else if (e.getSource() == deleteButton) {
                int selectedIndex = eventList.getSelectedIndex();
                if (selectedIndex != -1) {
                    Event selectedEvent = events.get(selectedIndex);

                    if (selectedEvent instanceof Match) {
                        matches.remove(selectedEvent);
                        matchModel.removeElement(selectedEvent);
                    }

                    events.remove(selectedIndex);
                    eventModel.remove(selectedIndex);

                    EventTitleTF.setText("");
                    EventSDTF.setText("");
                    TrainerNameTF.setText("");
                    EventTypeCB.setSelectedIndex(0);
                } else {
                    JOptionPane.showMessageDialog(null, "Please select an event to delete.");
                }
            }
            else if (e.getSource() == editButton) {
                int selectedIndex = eventList.getSelectedIndex();
                if (selectedIndex != -1) {
                    Event event = events.get(selectedIndex);
                    String selectedType = EventTypeCB.getSelectedItem().toString();

                    if ("Match".equals(selectedType) && event instanceof Training) {
                        events.remove(selectedIndex);
                        eventModel.remove(selectedIndex);
                        if (event instanceof Training) {
                            Training training = (Training) event;
                            event = new Match(
                                    EventTitleTF.getText(),
                                    new ScheduledDate(LocalDate.parse(EventSDTF.getText()))
                            );
                        }
                        matches.add((Match) event);
                        matchModel.addElement((Match) event);
                    }
                    else if ("Training".equals(selectedType) && event instanceof Match) {
                        events.remove(selectedIndex);
                        eventModel.remove(selectedIndex);
                        matches.remove(event);
                        matchModel.removeElement(event);
                        event = new Training(
                                EventTitleTF.getText(),
                                new ScheduledDate(LocalDate.parse(EventSDTF.getText())),
                                TrainerNameTF.getText()
                        );
                    }
                    else {
                        event.setTitle(EventTitleTF.getText());
                        event.setScheduledDate(new ScheduledDate(LocalDate.parse(EventSDTF.getText())));
                        if (event instanceof Training) {
                            ((Training) event).setTrainerName(TrainerNameTF.getText());
                        }
                    }

                    events.add(event);
                    eventModel.addElement(event);
                }
            }
        }
    }

    class ManagementInnerClass implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            if (e.getSource() == addAthleteToMatchButton) {
                int selectedAthleteIndex = AthleteList.getSelectedIndex();
                int selectedMatchIndex = MatchList1.getSelectedIndex();

                if (selectedAthleteIndex != -1 && selectedMatchIndex != -1) {
                    Athlete selectedAthlete = athletes.get(selectedAthleteIndex);
                    Match selectedMatch = matches.get(selectedMatchIndex);
                    selectedMatch.addAthleteToMatch2(selectedAthlete);
                    JOptionPane.showMessageDialog(null, "Athlete added to Match successfully.");
                } else {
                    JOptionPane.showMessageDialog(null, "Please select both an Athlete and a Match.");
                }
            }
            else if (e.getSource() == addMatchToVenueButton) {
                int selectedMatchIndex = MatchList2.getSelectedIndex();
                int selectedVenueIndex = VenueList.getSelectedIndex();

                if (selectedMatchIndex == -1 || selectedVenueIndex == -1) {
                    JOptionPane.showMessageDialog(null, "Please select both a Match and a Venue.");
                    return;
                }

                Match selectedMatch = matches.get(selectedMatchIndex);
                Venue selectedVenue = venues.get(selectedVenueIndex);

                try {
                    selectedVenue.addMatch(selectedMatch);
                    JOptionPane.showMessageDialog(null, "Match successfully added to Venue.");
                } catch (AddingMatchException ex) {
                    JOptionPane.showMessageDialog(null, ex.getMessage());
                }
            }
            else if (e.getSource() == removeAthleteFromMatchButton) {
                int selectedAthleteIndex = AthleteList.getSelectedIndex();
                int selectedMatchIndex = MatchList1.getSelectedIndex();

                if (selectedAthleteIndex != -1 && selectedMatchIndex != -1) {
                    Athlete selectedAthlete = athletes.get(selectedAthleteIndex);
                    Match selectedMatch = matches.get(selectedMatchIndex);
                    selectedMatch.removeAthleteFromMatch(selectedAthlete);
                    JOptionPane.showMessageDialog(null, "Athlete removed from Match successfully.");

                } else {
                    JOptionPane.showMessageDialog(null, "Please select both an Athlete and a Match.");
                }
            }
            else if (e.getSource() == removeMatchFromVenueButton) {
                int selectedMatchIndex = MatchList2.getSelectedIndex();
                int selectedVenueIndex = VenueList.getSelectedIndex();

                if (selectedMatchIndex != -1 && selectedVenueIndex != -1) {
                    Match selectedMatch = matches.get(selectedMatchIndex);
                    Venue selectedVenue = venues.get(selectedVenueIndex);

                    selectedVenue.removeMatch(selectedMatch);
                    JOptionPane.showMessageDialog(null, "Match removed from Venue successfully.");
                } else {
                    JOptionPane.showMessageDialog(null, "Please select both a Match and a Venue.");
                }
            }
        }
    }
}
