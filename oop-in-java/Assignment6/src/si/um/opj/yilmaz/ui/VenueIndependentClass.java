package si.um.opj.yilmaz.ui;

import infrastructure.*;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class VenueIndependentClass implements ActionListener {
    private final JList<Venue> venueList;
    private final DefaultListModel<Venue> venueModel;
    private final JTextField venueNameTF;
    private final JTextField venuePhoneTF;
    private final JComboBox<String> venueTypeCB;
    private final JTextField venueCapacityTF;
    private final ArrayList<Venue> venues;

    public VenueIndependentClass(ArrayList<Venue> venues, JList<Venue> venueList, DefaultListModel<Venue> venueModel, JTextField venueNameTF, JTextField venuePhoneTF, JComboBox<String> venueTypeCB, JTextField venueCapacityTF) {
        this.venues = venues;
        this.venueList = venueList;
        this.venueModel = venueModel;
        this.venueNameTF = venueNameTF;
        this.venuePhoneTF = venuePhoneTF;
        this.venueTypeCB = venueTypeCB;
        this.venueCapacityTF = venueCapacityTF;

        venueList.addListSelectionListener(e -> {
            if (!e.getValueIsAdjusting()) {
                int selectedIndex = venueList.getSelectedIndex();
                if (selectedIndex != -1) {
                    Venue selectedVenue = venueModel.get(selectedIndex);
                    venueNameTF.setText(selectedVenue.getName());
                    venuePhoneTF.setText(selectedVenue.getPhoneNumber());
                    venueCapacityTF.setText(String.valueOf(selectedVenue.getMatchesList().length));
                    venueTypeCB.setSelectedItem(selectedVenue instanceof Hall ? "Hall" : "Stadium");
                } else {
                    venueNameTF.setText("");
                    venuePhoneTF.setText("");
                    venueCapacityTF.setText("");
                    venueTypeCB.setSelectedIndex(0);
                }
            }
        });
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getActionCommand().equals("Create")) {
            Venue venue;
            String venueType = venueTypeCB.getSelectedItem().toString();

            try {
                int capacity = Integer.parseInt(venueCapacityTF.getText());

                if ("Hall".equals(venueType)) {
                    venue = new Hall(
                            venueNameTF.getText(),
                            venuePhoneTF.getText(),
                            capacity,
                            false
                    );
                } else if ("Stadium".equals(venueType)) {
                    venue = new Stadium(
                            venueNameTF.getText(),
                            venuePhoneTF.getText(),
                            capacity
                    );
                } else {
                    JOptionPane.showMessageDialog(null, "Invalid venue type selected.");
                    return;
                }

                venues.add(venue);
                venueModel.addElement(venue);
                venueList.setModel(venueModel);

                // clearing the text fields after adding the venue
                venueNameTF.setText("");
                venuePhoneTF.setText("");
                venueTypeCB.setSelectedIndex(0);
                venueCapacityTF.setText("");
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(null, "Please enter a valid capacity.");
            }
        }
        else if (e.getActionCommand().equals("Delete")) {
            int selectedIndex = venueList.getSelectedIndex();
            if (selectedIndex != -1) {
                venueModel.remove(selectedIndex);
                venues.remove(selectedIndex);
            }
        }
        else if (e.getActionCommand().equals("Edit")) {
            int selectedIndex = venueList.getSelectedIndex();
            if (selectedIndex != -1) {
                Venue venue = venueModel.get(selectedIndex);
                String selectedType = venueTypeCB.getSelectedItem().toString();

                try {
                    int capacity = Integer.parseInt(venueCapacityTF.getText());

                    if ("Hall".equals(selectedType) && !(venue instanceof Hall)) {
                        venue = new Hall(
                                venueNameTF.getText(),
                                venuePhoneTF.getText(),
                                capacity,
                                false
                        );
                    } else if ("Stadium".equals(selectedType) && !(venue instanceof Stadium)) {
                        venue = new Stadium(
                                venueNameTF.getText(),
                                venuePhoneTF.getText(),
                                capacity
                        );
                    } else {
                        venue.setName(venueNameTF.getText());
                        venue.setPhoneNumber(venuePhoneTF.getText());
                    }

                    venueModel.set(selectedIndex, venue);
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(null, "Please enter a valid capacity.");
                }
            }
        }
    }
}