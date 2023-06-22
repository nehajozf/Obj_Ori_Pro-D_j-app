/*
  ==============================================================================

    PlaylistComponent.h
    Created: 13 Feb 2023 5:44:44am
    Author:  Neha Joseph

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include <vector>

#include <string>

#include <iostream>
#include <fstream>
#include <ostream>


//other people new code

#include "DeckGUI.h"
#include "WaveformDisplay.h"
#include <fstream>

//other people till here

/*
//new code 3
#include <cmath>
#include <algorithm>
//till here 3
*/
//==============================================================================
/*
*/
class PlaylistComponent  : public juce::Component,
                           public juce::TableListBoxModel,
                           public juce::Button::Listener
                           //other people new code
                          // public juce::FileDragAndDropTarget
                           // till here


                           //new code 3
                          //  public juce::AudioSource,
                          //  public juce::FileDragAndDropTarget,
                          //  public juce::TextEditor::Listener
                           //till here 3
         
{
public:
    PlaylistComponent();
    
    //new code 3
   // PlaylistComponent(juce::AudioFormatManager& formatManager);
    //till here 3
    
    ~PlaylistComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    
    int getNumRows() override;
    
    void paintRowBackground(juce::Graphics &,
                            int rowNumber,
                            int width,
                            int height,
                            bool rowIsSelected) override;
    
    void paintCell(juce::Graphics &,
                   int rowNumber,
                   int columnId,
                   int width,
                   int height,
                   bool rowIsSelected) override;
    
    Component* refreshComponentForCell(int rowNumber,
                                       int columnId,
                                       bool isRowSelected,
                                       Component *existingComponentToUpdate) override;
    
    void buttonClicked(juce::Button* button) override;
    
    
    
    
  
    
    
    //other people new code 2
    void textEditorTextChanged(juce::TextEditor& editor);
    void deleteFile();
    void loadFileIntoDeck1();
    void loadFileIntoDeck2();
    juce::String fileToDeckGUI;
    std::string stdstring;
    
    
    // other code till here 2
    
    
 //   bool juce::FileChooser::browseForMultipleFilesToOpen(FilePreviewComponent * previewComponent = 0);
 //   FilePreviewComponent::FilePreviewComponent
    
    
    
    /*
    //new code 3
    
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
        
    void getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) override;
        
        void releaseResources() override;

       
        void  buttonClicked(juce::Button* button) override;
        
        bool isInterestedInFileDrag(const juce::StringArray& files) override;
        
        void filesDropped(const juce::StringArray& files, int x, int y) override;
        
        void textEditorTextChanged(juce::TextEditor&) override;
    
        std::vector<std::string> playListLeft;
        
        std::vector<std::string> playListRight;
    //till here 3
    
   */
    

private:
    //my code
   // juce::TableListBox tableComponent;
    
    
    
    
    std::vector<std::string> trackTitles;
    
   
    //other people code
    
    juce::TextButton loadPlaylistButton{ "Load Playlist" };
    
    void loadPlaylist();
    
    //other people till here
    
   
    //other people new code 2
    juce::AudioFormatManager formatManager;
    juce::Array<juce::File> myFiles;
    std::vector<std::string> existingFiles;
    double duration;
    juce::String fileName;
    juce::Array<double> myFilesDuration;
    juce::Array<juce::String> fileNames;
    juce::TableListBox tableComponent;
    juce::TextButton libraryLoadButton{"Load into library"};
    bool historyClicked = false;
    int duplicateIndex = -1;
    juce::TextButton libraryDeleteButton;
    juce::TextButton libraryDeck1;
    juce::TextButton libraryDeck2;
    juce::TextEditor librarySearch{ "Search for tracks..." };
    juce::String searchInput;
        
    double rowclicked;

    //other people till here 2
    
    
    
    /*
    //new code 3
    juce::AudioFormatManager& formatManager;
    juce::AudioTransportSource transportSource;
        std::unique_ptr< juce::AudioFormatReaderSource> readerSource;

        //playlist displayed as a table list
    juce::TableListBox tableComponent;

        //vectors to store music files metadata
        std::vector<std::string> inputFiles;
        std::vector<std::string> interestedFiles;
        std::vector<std::string> trackTitles;
        std::vector<std::string> interestedTitles;
        std::vector<std::string> trackDurations;
        std::vector<std::string> interestedDuration;

        std::vector< juce::URL> path;
    juce::TextButton saveLibButton{ "SAVE LIBRARY" };

        // Search bar and label to allow for searching functionality
    juce::TextEditor searchBar;
    juce::Label searchLabel;

        //user defined variables to process data
        void addToChannelList(std::string filepath, int channel);
        void deleteTrack(int id);
        void getAudioLength( juce::URL audioURL);

        void writingIntoFile();
        void readingFile();

    //till here 3
   */
   
    
    
    
  //  std::unique_ptr<juce::AudioFormatReaderSource> playSource;

   
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PlaylistComponent)
};
