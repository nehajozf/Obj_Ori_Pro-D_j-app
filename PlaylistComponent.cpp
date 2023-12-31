/*
  ==============================================================================

    PlaylistComponent.cpp
    Created: 13 Feb 2023 5:44:44am
    Author:  Neha Joseph

  ==============================================================================
*/

#include <JuceHeader.h>
#include "PlaylistComponent.h"

#include <string>

//other people new code 2
//#include <time.h>
//other people till here 2


//others 3
//#include <algorithm>
//till here 3




//==============================================================================
/*
//new code 3
PlaylistComponent::PlaylistComponent(juce::AudioFormatManager& _formatManager)
                  : formatManager(_formatManager)
{
//till here
*/


PlaylistComponent::PlaylistComponent()

{





    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
   /*
    trackTitles.push_back("Track 1");
    trackTitles.push_back("Track 2");
    trackTitles.push_back("Track 3");
    trackTitles.push_back("Track 4");
    trackTitles.push_back("Track 5");
    trackTitles.push_back("Track 6");
    
    //new code
    
    trackTitles.push_back("Track 7");
    trackTitles.push_back("Track 8");
    trackTitles.push_back("Track 9");
    trackTitles.push_back("Track 10");
    
    //till here
    
    
    tableComponent.getHeader().addColumn("Track title", 1, 400);
    
    tableComponent.getHeader().addColumn("Play", 2, 100);
    
   // tableComponent.getHeader().addColumn("Artist", 2, 400);
    
    
    //new code
    tableComponent.getHeader().addColumn("Deck 1", 3, 150);
    
    tableComponent.getHeader().addColumn("Deck 2", 4, 150);
    
    //till here
  */
    
    
    //other people new codes 2
    tableComponent.getHeader().addColumn("Track title", 1, 300);
        tableComponent.getHeader().addColumn("Duration(hhmmss)", 2, 100);
        tableComponent.getHeader().addColumn("Load into", 3, 150);
        tableComponent.getHeader().addColumn("Load into", 4, 150);
        tableComponent.getHeader().addColumn("Delete", 5, 100);
    //other people till here 2
  
    
    
   
    
    
    tableComponent.setModel(this);
    
    addAndMakeVisible(tableComponent);
    
   
    //other peoples new codes 2
    addAndMakeVisible(libraryLoadButton);
        addAndMakeVisible(librarySearch);
        libraryLoadButton.addListener(this);
        formatManager.registerBasicFormats();
       // librarySearch.addListener(this);
    
    
    //creates a text file named playlist.txt and inserts a placeholder "0" as to which deckGUI to be put into. This is for loading playlist files into either deck 1 or 2
    std::ofstream myfile("playlist.txt");
    myfile << stdstring << std::endl << "0" << std::endl;
    myfile.close();

    //creats a text file named PlaylistHistory.txt, which stores the current playlist audio file URLs so that the playlist data persists when reopening
    std::ifstream file("PlaylistHistory.txt");
    std::string str;
    std::vector<std::string> lines;
    while (std::getline(file, str))
    {
        lines.push_back(str);
    }

    //If text file contains audio file URLs, add each line into existing files array
    for (int i = 0; i < lines.size(); ++i) {
        existingFiles.push_back(lines[i]);
    }

    //If there are existing files before
    if (existingFiles.size() != 0) {

        //adds existing files into my files
        for (int i = 0; i < existingFiles.size(); ++i) {
            myFiles.add(juce::File{ existingFiles[i] });

        }

        for (int i = 0; i < myFiles.size(); ++i) { //for every file, get the file name and duration and prepares them for reading

            fileName = juce::URL::removeEscapeChars(juce::URL{ myFiles[i] }.getFileName()); //gets file name
            fileNames.add(fileName); //adds file name into filenames array, to be displayed in playlist table component
            juce::AudioFormatReader* reader = formatManager.createReaderFor(myFiles[i]); //creates reader for each file
            duration = reader->lengthInSamples / reader->sampleRate; //gets duration of the file by dividing length by sample rate
            myFilesDuration.add(duration); //adds duration into duration array to be displayed in playlist table component

        }
        tableComponent.updateContent(); //updates the table component to display the file names and duration
    }
    
    //other people till here 2
    
   
  
    
    /*
    //new code 3
    //set up playlist library
        tableComponent.getHeader().addColumn("Track Title", 1, 250);
        tableComponent.getHeader().addColumn("Duration", 2, 100);
        tableComponent.getHeader().addColumn("Add file to Left Channel", 3, 250);
        tableComponent.getHeader().addColumn("Add file to Right channel", 4, 250);
        tableComponent.getHeader().addColumn("Delete file", 5, 100);
        tableComponent.setModel(this);
        addAndMakeVisible(tableComponent);
        
        //to save playlist of tracks
        addAndMakeVisible(saveLibButton);
        saveLibButton.addListener(this);

        readingFile();

        //add search bar and listener
        addAndMakeVisible(searchBar);
        searchBar.addListener(this);

        //add label for search bar
        addAndMakeVisible(searchLabel);
        searchLabel.setText("Search Track: ", juce::dontSendNotification);
    //till here 3
    */
 
  
    
    

}

PlaylistComponent::~PlaylistComponent()
{
    
}

void PlaylistComponent::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("PlaylistComponent", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
    
    /*
    //new code 3
    //to set the colour of the buttons
        saveLibButton.setColour(juce::TextButton::buttonColourId, juce::Colours::lightblue);
        saveLibButton.setColour(juce::TextButton::textColourOffId, juce::Colours::black);
    //till here 3
    */
}

void PlaylistComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    
   // tableComponent.setBounds(0, 0, getWidth(), getHeight());
    
   /*
    //new code
    
    tableComponent.setBounds(0, 50, getWidth() , getHeight() * 4);
    
    //tableComponent.setBounds(0, getHeight() / 9, getWidth(), 8* getHeight() /9);
    
    //till here
    
    */
    
    
   
    //other people new code 2
    double rowH = getHeight() / 7;
        libraryLoadButton.setBounds(0, 0, getWidth() / 2, rowH);
        librarySearch.setBounds(getWidth() / 2, 0, getWidth() / 2, rowH);
        tableComponent.setBounds(0, rowH, getWidth(), getHeight());

        //playlist header columns
        tableComponent.getHeader().setColumnWidth(1, (getWidth() / 8) * 3);
        tableComponent.getHeader().setColumnWidth(2, getWidth() / 8);
        tableComponent.getHeader().setColumnWidth(3, (getWidth() / 8) * 1.5);
        tableComponent.getHeader().setColumnWidth(4, (getWidth() / 8) * 1.5);
        tableComponent.getHeader().setColumnWidth(5, (getWidth() / 8));

        tableComponent.setColour(juce::ListBox::backgroundColourId, juce::Colours::mediumaquamarine);
        
        //search bar
        librarySearch.setTextToShowWhenEmpty("Search for tracks...", juce::Colours::orange);
        librarySearch.setFont(20.0f);

    //till here new code 2
  
   
    
    /*
    //new code 3
    // This method is where you should set the bounds of any child
        // components that your component contains..
        double rowH = getHeight() / 8;
        double colW = getWidth() / 6;

        //set position of search bar functionality
        searchLabel.setBounds(0, 0, colW, rowH);
        searchBar.setBounds(colW, 0, colW * 4, rowH);


        //setting the position of the table
        tableComponent.setBounds(0, rowH, getWidth(), rowH*7);

        //set position of save playlist button
        saveLibButton.setBounds(colW * 5, 1, colW, rowH);
    //till here 3
    */
 
    
 
    
    
    
}


int PlaylistComponent::getNumRows()
{
    
    
   // return trackTitles.size();
    
    
    //new codes 2
    return fileNames.size();
    //till here 2
   
 /*
 //new code 3
    return interestedTitles.size();
//till here 3
 */
    
    
    
    
}

void PlaylistComponent::paintRowBackground(juce::Graphics & g,
                        int rowNumber,
                        int width,
                        int height,
                        bool rowIsSelected)
{
    
    if(rowIsSelected)
    {
        g.fillAll(juce::Colours::orange);
    }
    else
    {
        g.fillAll(juce::Colours::darkgrey);
    }
    
}

void PlaylistComponent::paintCell(juce::Graphics & g,
               int rowNumber,
               int columnId,
               int width,
               int height,
               bool rowIsSelected)
{
    
   // g.drawText(trackTitles[rowNumber],
    //           2, 0,
   //            width - 4,
   //            height,
   //            juce::Justification::centredLeft,
  //             true);
   
    
   
    //new code 2
    if (columnId == 1) {//column 1 shows the file name of the audio file
                g.drawText(fileNames[rowNumber],
                    2, 0,
                    width - 4, height,
                    juce::Justification::centredLeft,
                    true);
            }
            if (columnId == 2) {// column 2 shows the file's duration, in the format of hh:mm:ss
                std::time_t seconds(myFilesDuration[rowNumber]);
                tm* p = gmtime(&seconds);
                std::string hhmmss;
                std::string hours;
                std::string mins;
                std::string secs;
                //converting file duration from double into seconds and then into hours, minutes and seconds
                if (p->tm_hour < 10) {
                    hours = "0" + std::to_string(p->tm_hour);
                }
                else {
                    hours = std::to_string(p->tm_hour);
                }
                if (p->tm_min < 10) {
                    mins = "0" + std::to_string(p->tm_min);
                }
                else {
                    mins = std::to_string(p->tm_min);
                }
                if (p->tm_sec < 10) {
                    secs = "0" + std::to_string(p->tm_sec);
                }
                else {
                    secs = std::to_string(p->tm_sec);
                }

                hhmmss = hours + ":" + mins + ":" + secs;
                g.drawText(hhmmss,
                    2, 0,
                    width - 4, height,
                    juce::Justification::centredLeft,
                    true);
            }

    //till here 2
   
   
    
    
 /*
    //new code 3
    if (columnId == 1)
        {
            g.drawText (interestedTitles[rowNumber],
                1, rowNumber,
                width - 4, height,
                juce::Justification::centredLeft,
                true);
        }
    
    if (columnId == 2)
        {
             g.drawText ((interestedDuration[rowNumber]) + "s",
                1, rowNumber,
                width - 4, height,
                juce::Justification::centredLeft,
                true);
        }
    
    //till here 3
 */
    
    
 
}


juce::Component* PlaylistComponent::refreshComponentForCell(int rowNumber,
                                   int columnId,
                                   bool isRowSelected,
                                   Component *existingComponentToUpdate)
{
   
//    if(columnId == 2)
//    {
//        if(existingComponentToUpdate == nullptr)
//        {
            
//            juce::TextButton* btn = new juce::TextButton{"play"};
            
//            juce::String id{std::to_string(rowNumber)};
            
//            btn->setComponentID(id);
            
            
//            btn->addListener(this);
            
           // existingComponentToUpdate = new juce::TextButton{"play"};
            
//            existingComponentToUpdate = btn;
           
           
            
            /*
            //other people new code
            juce::TextButton* btn = new juce::TextButton{"LOAD"};
            juce::String rowid{std::to_string(rowNumber)};
            juce::String colid{std::to_string(columnId)};
            btn->setComponentID(colid + rowid);
            btn->addListener(this);
            existingComponentToUpdate = btn;
            
            //other people till here
           */
//        }
//    }
    
    
  
    //new codes 2
    if (columnId == 3) {//column 3 is a button that loads the audio file into deck 1
            if (existingComponentToUpdate == nullptr) {
                juce::TextButton* btn = new juce::TextButton{ "Deck 1" }; //creates button with deck 1 as the text
                juce::String id{ std::to_string(rowNumber) };
                btn->setComponentID(id); //set component id to button for identifying which button was clicked
                btn->addListener(this); //adding listener to the button
                existingComponentToUpdate = btn;
                btn->onClick = [this] {loadFileIntoDeck1(); }; //loadFileIntoDeck1() runs when button is clicked
            }
        }
    //till here 2
    
 
    
   /*
    //new code 3
    if (columnId == 3)
        {
            if (existingComponentToUpdate == nullptr)
            {
                juce::TextButton* btn = new juce::TextButton{"Add to Left Channel"};
                  juce::String id{ std::to_string(rowNumber) };
                  btn->setComponentID(id);
                  btn->addListener(this);
                  existingComponentToUpdate = btn;
                  btn->setColour(juce::TextButton::buttonColourId, juce::Colours::darkslategrey);
            }
        }
    //till here 3
   */
    
    
   
    
    //new code
    
//    if(columnId == 3)
//    {
//        if(existingComponentToUpdate == nullptr)
//        {
           
//            juce::TextButton* btn = new juce::TextButton{"Play in Deck 1"};

//            juce::String id{std::to_string(rowNumber)};
            
//            btn->setComponentID(id);
            
            
//            btn->addListener(this);
            
           // existingComponentToUpdate = new juce::TextButton{"play"};
            
//            existingComponentToUpdate = btn;
            
            /*
            //other people new code
            juce::TextButton* btn = new juce::TextButton{"Deck 1"};
            juce::String rowid{std::to_string(rowNumber)};
            juce::String colid{std::to_string(columnId)};
            btn->setComponentID(colid + rowid);
            btn->addListener(this);
            existingComponentToUpdate = btn;
            
            //other people till here
           */
//        }
//    }
    
    
    
    //new codes 2
    if (columnId == 4) {//column 4 is a button that loads the audio file into deck 2
           if (existingComponentToUpdate == nullptr) {
               juce::TextButton* btn = new juce::TextButton{ "Deck 2" }; //creates button with deck 2 as the text
               juce::String id{ std::to_string(rowNumber) };
               btn->setComponentID(id);
               btn->addListener(this);
               existingComponentToUpdate = btn;
               btn->onClick = [this] {loadFileIntoDeck2(); }; //loadFileIntoDeck2() runs when button is clicked
           }
       }
    //till here 2
   
   
    
    
    
   /*
    //new code 3
    if (columnId == 4)
        {
            if (existingComponentToUpdate == nullptr)
            {
                juce::TextButton* btn = new juce::TextButton{"Add to Right Channel"};
                // add 100 to id to allow buttons to be processed differently between channels
                juce::String id{ std::to_string(rowNumber + 100) };
                  btn->setComponentID(id);
                  btn->addListener(this);
                  existingComponentToUpdate = btn;
                  btn->setColour(juce::TextButton::buttonColourId, juce::Colours::darkslategrey);
            }
        }
    //till here 3
 */
    
    
    
    
//    if(columnId == 4)
//    {
//        if(existingComponentToUpdate == nullptr)
//        {
           
//            juce::TextButton* btn = new juce::TextButton{"Play in Deck 2"};
            
//            juce::String id{std::to_string(rowNumber)};
            
//            btn->setComponentID(id);
            
            
//            btn->addListener(this);
            
           // existingComponentToUpdate = new juce::TextButton{"play"};
            
//            existingComponentToUpdate = btn;
             
            /*
            //other people new code
            juce::TextButton* btn = new juce::TextButton{"Deck 2"};
            juce::String rowid{std::to_string(rowNumber)};
            juce::String colid{std::to_string(columnId)};
            btn->setComponentID(colid + rowid);
            btn->addListener(this);
            existingComponentToUpdate = btn;
            
            //other people till here
            */
 //       }
//  }
    
    //till here
    
    
   
    //new codes 2
    if (columnId == 5) {//column 5 is a button that deletes the audio file
            if (existingComponentToUpdate == nullptr) {
                juce::TextButton* btn = new juce::TextButton{ "Delete" }; //creates button with delete as the text
                juce::String id{ std::to_string(rowNumber) };
                btn->setComponentID(id);
                btn->addListener(this);
                existingComponentToUpdate = btn;
                btn->onClick = [this] {deleteFile(); };//deleteFile() runs when button is clicked
                        

            }
        }
    //till here 2
  
    
    
    
  /*
    //new code 3
    if (columnId == 5)
        {
            if (existingComponentToUpdate == nullptr)
            {
                  juce::TextButton* btn = new juce::TextButton{"X"};
                  // add 200 to id to allow buttons to be processed differently between channels
                juce::String id{ std::to_string(rowNumber + 200) };
                  btn->setComponentID(id);
                  btn->addListener(this);
                  existingComponentToUpdate = btn;
                  btn->setColour(juce::TextButton::buttonColourId, juce::Colours::darksalmon);
            }
        }

    //till here 3
  */
    
    
    
    
   /*
    //other people new code
    if(columnId == 5){
        if(existingComponentToUpdate == nullptr){
            
            
            juce::TextButton* btn = new juce::TextButton{"Delete"};
            juce::String rowid{std::to_string(rowNumber)};
            juce::String colid{std::to_string(columnId)};
            btn->setComponentID(colid + rowid);
            btn->addListener(this);
            existingComponentToUpdate = btn;
            
            
        }
    }
    //other people till here
    */
    
    return existingComponentToUpdate;

}

/*
//new code 3
void PlaylistComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate){}
void PlaylistComponent::getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill){}
void PlaylistComponent::releaseResources(){}

//till here 3
*/




void PlaylistComponent::buttonClicked(juce::Button* button)
{
    
    //my code
    
    //    int id = std::stoi(button->getComponentID().toStdString());
    
    // std::cout<<"PlaylistComponent::buttonClicked " << button->getComponentID() << std::endl;
    
    //    std::cout<<"PlaylistComponent::buttonClicked " << trackTitles[id] << std::endl;
    
    
   
    //new codes 2
    if (button == &libraryLoadButton) {//If button is clicked and matchs the library load button
        //lets the user choose for one or multiple files at once
        juce::FileChooser choosers{ "Select for file(s) to add to the library...", juce::File() , "*.mp3;*.wav;*.aiff" };
        
        
        //video code   juce::FileChooser choosers ("Choose a Wav or AIFF File", juce::File::getSpecialLocation(juce::File::userDesktopDirectory), "*.wav; *.mp3");
        
        if (choosers.browseForMultipleFilesToOpen()) {
            // if (choosers.launchAsync((int flags, std::function<void (const juce::FileChooser &)>)){
            
            // if (choosers.browseForFileToOpen()){     video code
            myFiles = choosers.getResults(); //myFiles is an array of files
            for (int i = 0; i < myFiles.size(); ++i) { //for loop repeats for myFiles size
                
                if (existingFiles.size() != 0 || i == 0) { //if there are existing files, or it is the first iteration of the loop
                    for (int j = 0; j < existingFiles.size(); ++j) { //loops through number of times based on how many existing files there is
                        if (myFiles[i].getFullPathName().toStdString() == existingFiles[j]) { //loops through the existing files, if any matches, do not add the index
                            DBG("There are duplicates");
                            
                            //creates alert window alerting user they have added a duplicate file, and it will not be added
                            juce::AlertWindow alertDuplicate("Duplicate file added", "Duplicated file " + juce::URL::removeEscapeChars(juce::URL{ myFiles[i] }.getFileName()) + " has not been added", juce::MessageBoxIconType::InfoIcon);
                            alertDuplicate.addButton("Continue",0);
                            alertDuplicate.setUsingNativeTitleBar(true);
                            
                              int result = alertDuplicate.runModalLoop();
                            
                            duplicateIndex = i; //taking note of which file index is a duplicated
                            break;
                        }
                        
                        
                    }
                    
                    if (i != duplicateIndex) { //If the file is not a duplicated file index, add the file
                        fileName = juce::URL::removeEscapeChars(juce::URL{ myFiles[i] }.getFileName()); //get the file name and adds them to the fileNames array for display
                        fileNames.add(fileName);
                        juce::AudioFormatReader* reader = formatManager.createReaderFor(myFiles[i]);
                        duration = reader->lengthInSamples / reader->sampleRate; //gets duration of the file by dividing the length in samples by the sample rate
                        myFilesDuration.add(duration); //adds duration into myFilesDuration, which is used in paint cell
                        DBG(fileNames[i]);
                        DBG(duration);
                        
                        existingFiles.push_back(myFiles[i].getFullPathName().toStdString()); //file path is added to the existingFiles array
                        
                    }
                    
                }
                
            }
            
            
            
            std::ofstream history("PlaylistHistory.txt"); //Opens PlaylistHistory.txt file
            
            for (int i = 0; i < existingFiles.size(); ++i) { //For each file in existingFiles
                history << existingFiles[i] << std::endl; //Writes the added file path into the text file
            }
            history.close(); //closes the text file
            
            
            tableComponent.updateContent();
            
            
        }
        
    }
    
    
    
    rowclicked = button->getComponentID().getDoubleValue(); //gets which row(file) the user has clicked, used for deleting or adding files into deck 1/2
    
    
    //till here 2
    
   
    
    
    
  /*
    //new code 3
    
    //get id of button
        int id = std::stoi(button->getComponentID().toStdString());
        //if id is less than 100, it should be allocated to the left channel GUI player.
        if (id < 100)
        {
            addToChannelList(interestedFiles[id], 0);
        }
        //if id between 100 and 200, it should be allocated to the right chanel GUI player
        if ( id > 99 && id < 200)
        {
            addToChannelList(interestedFiles[id - 100], 1);
        }
        
         //if id is above 200, it should invoked the delete function to delete the track
        if (id > 199)
        {
            deleteTrack(id);
        }

        if (button == &saveLibButton)
        {
            DBG("Save Button");
            DBG("Writing into file");
            writingIntoFile();
        }
    
    //till here 3
   */
    
    
    
}
    
    
//}


//new codes 2

void PlaylistComponent::textEditorTextChanged(juce::TextEditor& editor) { //Search bar input
    
    searchInput = librarySearch.getText(); //Gets the text which the user has typed in the search bar

    for (int i = 0; i < fileNames.size(); ++i) {//Loops through all the files names of existing files
        if (fileNames[i].containsWholeWord(searchInput) && searchInput != "") { // Matches the user's search input with any of the file names
            tableComponent.selectRow(i, false, true); //Selects the row which has a match
        }
    }
    
}

void PlaylistComponent::deleteFile() {//only runs when user clicks on the delete button on a file
    
    DBG(rowclicked);

    for (int i = 0; i < myFiles.size(); ++i) {//loops through myFiles
        if (rowclicked == i) { //matches row(file) which the user clicked on
            //creates alert window for confirm deleting of the audio file
            juce::AlertWindow confirmDelete("Delete File", "Are you sure you want to delete this file?", juce::MessageBoxIconType::QuestionIcon);
            confirmDelete.setUsingNativeTitleBar(true);
            confirmDelete.addButton("Delete", true); //If delete button is clicked, returns true
            confirmDelete.addButton("Cancel", false); //If cancel button is clicked, returns false

            bool result = confirmDelete.isEnabled();

            if (result == true) {//If true, deletes file
                DBG("deletefile");
                fileNames.remove(i); //Removes file name from fileNames array
                myFilesDuration.remove(i); //Removes file duration from myFilesDuration array
                existingFiles.erase(existingFiles.begin() + i); //Removes the file from the existingFiles array
            }
            else{ //If false, exits the alert window and does nothing
                confirmDelete.exitModalState(true); //exits the alert window
            }




        }
    }
    //Opens the PlaylistHistory text file, to remove the deleted file and update the current existing files
    std::ofstream history("PlaylistHistory.txt");
    for (int i = 0; i < existingFiles.size(); ++i) {
        history << existingFiles[i] << std::endl;
    }
    history.close();

    tableComponent.updateContent();
}

    
void PlaylistComponent::loadFileIntoDeck1() { //only runs when user clicks on "Deck 1" button on the file
    for (int i = 0; i < myFiles.size(); ++i) { //Loops through myFiles
        juce::AudioFormatReader* reader = formatManager.createReaderFor(myFiles[i]); //creates reader for the file
        if (rowclicked == i) { //Matches the row(file) which the user clicked to be added into Deck 1
            DBG("loadintodeck1");
            DBG(myFiles[i].getFileName());
            DBG(reader->getFormatName());
            fileToDeckGUI = myFiles[i].getFullPathName();//Gets the path of the file
            stdstring = fileToDeckGUI.toStdString();//Converts the path from juce string into std string
            std::replace(stdstring.begin(), stdstring.end(), '\\', '/');//Replaces all \ in path to /, as reading the path into a file requires back slash"/"
            DBG(stdstring);

            std::ofstream myfile("playlist.txt");//Opens text file named playlist.txt
            myfile << stdstring << std::endl << "1" << std::endl; //writes the path of the file, and "1" into the text file, indicating loading into deck 1
            myfile.close(); //closes the text file
        }
    }
}
void PlaylistComponent::loadFileIntoDeck2() { //only runs when user clicks on "Deck 2" button on the file
    for (int i = 0; i < myFiles.size(); ++i) {
        juce::AudioFormatReader* reader = formatManager.createReaderFor(myFiles[i]);
        if (rowclicked == i) {
            DBG("loadintodeck2");
            DBG(myFiles[i].getFileName());
            DBG(reader->getFormatName());
            fileToDeckGUI = myFiles[i].getFullPathName();
            stdstring = fileToDeckGUI.toStdString();
            std::replace(stdstring.begin(), stdstring.end(), '\\', '/');
            DBG(stdstring);
            std::ofstream myfile("playlist.txt");
            myfile << stdstring << std::endl << "2" << std::endl; //writes the path of the file, and "2" into the text file, indicating loading into deck 2
            myfile.close();

            
        }
    }
}
// other people till here 2



/*
//new code 3
bool PlaylistComponent::isInterestedInFileDrag(const juce::StringArray& files)
{
    return true; // allows files to be dragged and dropped
}

void PlaylistComponent::filesDropped(const juce::StringArray& files, int x, int y)
{
    //perform if files have been dropped (mouse released with files)
    for (juce::String filename : files)
    {
        //for each file URL, get filepath and file name
        std::string filepath = juce::String(filename).toStdString();
        std::size_t startFilePos = filepath.find_last_of("/");
        std::size_t startExtPos = filepath.find_last_of(".");
        std::string extn = filepath.substr(startExtPos + 1, filepath.length() - startExtPos);
        std::string file = filepath.substr(startFilePos + 1, filepath.length() - startFilePos - extn.size() - 2);
        
        //update vectors for file details
        inputFiles.push_back(filepath);
        trackTitles.push_back(file);
        
        //compute adudio length of the file and update vectors for file details
       // getAudioLength(juce::URL{ {file{filepath}} });
    

    }
    //Initialise interested titles as the full list.
    //This will be updated when text is entered in the search bar
    interestedTitles = trackTitles;
    interestedFiles = inputFiles;

    //update the music library table to include added files
    tableComponent.updateContent();
    tableComponent.repaint();
}


void PlaylistComponent::textEditorTextChanged(juce::TextEditor& textEditor)
{
    //whenever the search box is modified, clear the vectors that will be used for the table
    interestedTitles.clear();
    interestedDuration.clear();
    interestedFiles.clear();

    // start at position 0 of the original library list and increment until the last element of the list
    int pos = 0;
    for (std::string track : trackTitles)
    {
        //check if the texts typed in the search box is a substring of the track title we are currently processing
        if (track.find(searchBar.getText().toStdString()) != std::string::npos)
        {
            //if there is a match, push the item to the vector used for displaying values in the table
            interestedTitles.push_back(trackTitles[pos]);
            interestedDuration.push_back(trackDurations[pos]);
            interestedFiles.push_back(inputFiles[pos]);
        }
        ++pos;
    }
    //update the contents of the table after looping
    tableComponent.updateContent();
    tableComponent.repaint();

}


void PlaylistComponent::addToChannelList(std::string filepath, int channel)
{
    if (channel == 0) //left
    {
        playListLeft.push_back(filepath);
        juce::AlertWindow::showMessageBox(juce::AlertWindow::AlertIconType::InfoIcon,
            "Add to Deck Information:",
            "Track added to left playlist on Deck",
            "OK",
            nullptr);
        
        tableComponent.updateContent();
    }
    if (channel == 1) //right
    {
        playListRight.push_back(filepath);
        juce::AlertWindow::showMessageBox(juce::AlertWindow::AlertIconType::InfoIcon,
            "Add to Deck Information:",
            "Track added to right playlist on Deck",
            "OK",
            nullptr);

        tableComponent.updateContent();

    }
}

void PlaylistComponent::deleteTrack(int id)
{
    auto fileIt = std::find(inputFiles.begin(), inputFiles.end(), interestedFiles[id]);
    auto titleIt = std::find(trackTitles.begin(), trackTitles.end(), interestedTitles[id]);

    auto fileID = std::distance(inputFiles.begin(), fileIt);
    auto titleID = std::distance(trackTitles.begin(), titleIt);

    inputFiles.erase(inputFiles.begin() + fileID);
    trackTitles.erase(trackTitles.begin() + titleID);

    interestedTitles.erase(interestedTitles.begin() + id);
    interestedFiles.erase(interestedFiles.begin() + id);
    interestedDuration.erase(interestedDuration.begin() + id);

    trackDurations.erase(trackDurations.begin() + id);

    juce::AlertWindow::showMessageBox(juce::AlertWindow::AlertIconType::InfoIcon,
            "Information:",
            "Track has been deleted from playlist",
            "OK",
            nullptr);
    
    tableComponent.updateContent();
}

void PlaylistComponent::getAudioLength(juce::URL audioURL)
{
    double trackLen = 0.0;

    auto* reader = formatManager.createReaderFor(audioURL.createInputStream(false));

    if (reader != nullptr) // good file!
    {
        std::unique_ptr<juce::AudioFormatReaderSource> newSource(new juce::AudioFormatReaderSource(reader,
            true));
        transportSource.setSource(newSource.get(), 0, nullptr, reader->sampleRate);
        readerSource.reset(newSource.release());
        double trackLen = transportSource.getLengthInSeconds(); // get length of audio
        std::string trackLength = std::to_string(trackLen);
        trackDurations.push_back(trackLength); // add audio length to vector
    }

    //Initialise interested durations as the full list.
    //This will be updated when text is entered in the search bar
    interestedDuration = trackDurations;
}

void PlaylistComponent::writingIntoFile()
{
   juce::File dataFile = juce::File::getCurrentWorkingDirectory().getChildFile("songData.txt");

    if (!dataFile.existsAsFile())
    {
        DBG("File doesn't exist ...");
    }
    else
    {
        DBG("File exists");
    }
   
    dataFile.replaceWithText("", false, false, "\n");
    juce::FileOutputStream _file(dataFile);

    if (!_file.openedOk())
    {
        DBG("not opened");
       
    }

    _file.setNewLineString("\n");
    if (trackTitles.size() >0) {
        for (int i = 0; i < trackTitles.size(); i++) {
            //DBG("is inside");
            _file.writeText(path[i].getFileName()+"\n", false, false, nullptr);
            _file.writeText(trackDurations[i] + "\n", false, false, nullptr);
            _file.writeText(path[i].toString(false)+"\n", false, false, nullptr);
           
        }
    }
    _file.flush();
}

void PlaylistComponent::readingFile()
{
   juce::File dataFile = juce::File::getCurrentWorkingDirectory().getChildFile("songData.txt");
   juce::FileInputStream _file(dataFile);

    if (!_file.openedOk())
    {
       DBG("Failed to open file");
            
    }
    else
    {
          while (!_file.isExhausted())
          {
                juce::String singleLine = _file.readNextLine();
                DBG(singleLine);
                trackTitles.push_back(singleLine.toStdString());
                singleLine = _file.readNextLine();
                DBG(singleLine);
                trackDurations.push_back(singleLine.toStdString());
                singleLine = _file.readNextLine();
                DBG(singleLine);
                path.push_back(singleLine);
          }
    }
}

//till here 3
*/
