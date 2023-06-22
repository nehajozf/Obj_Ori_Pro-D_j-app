/*
  ==============================================================================

    DeckGUI.cpp
    Created: 10 Feb 2023 5:54:26am
    Author:  Neha Joseph

  ==============================================================================
*/

#include <JuceHeader.h>
#include "DeckGUI.h"

//==============================================================================
DeckGUI::DeckGUI(DJAudioPlayer* _player,
                 juce::AudioFormatManager & formatManagerToUse,
                 juce::AudioThumbnailCache & cacheToUse) : player(_player),
                                                           waveformDisplay(formatManagerToUse, cacheToUse)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    
    addAndMakeVisible(playButton);
    
    addAndMakeVisible(stopButton);
    
    addAndMakeVisible(loadButton);
    
    addAndMakeVisible(waveformDisplay);
    
    
    //new code 2
    addAndMakeVisible(trackName);
        addAndMakeVisible(loopButton);
    loopButton.addListener(this);
    //till here 2
    
    
    
    addAndMakeVisible(volSlider);
    
    addAndMakeVisible(speedSlider);
    
    addAndMakeVisible(posSlider);
    
    
    //new code
    
  //  addAndMakeVisible(posSliderLabel);
    
    
    
    volSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    speedSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    //posSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    
    
    volSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 80, 25);
    speedSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 80, 25);
 //   posSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 80, 25);
    
    
    posSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, true, 80, posSlider.getTextBoxHeight());
    
    
    //attaching text to the volume slider component
        volSliderLabel.setText("Volume", juce::NotificationType::dontSendNotification);
        volSliderLabel.attachToComponent(&volSlider, false);
    
    
    //attaching text to the speed slider component
        speedSliderLabel.setText("Speed", juce::NotificationType::dontSendNotification);
        speedSliderLabel.attachToComponent(&speedSlider, false);
    
    
    //attaching text to the pos slider component
      //  posSliderLabel.setText("Position", juce::NotificationType::dontSendNotification);
    //    posSliderLabel.attachToComponent(&posSlider, true);
    
    
    addAndMakeVisible (posSliderLabel);
    posSliderLabel.setText ("Position", juce::dontSendNotification);
    posSliderLabel.attachToComponent (&posSlider, true);
    
    
    
    //till here
    
    
    
    
    playButton.addListener(this);
    
    stopButton.addListener(this);
    
    loadButton.addListener(this);
    
    
    volSlider.addListener(this);
    speedSlider.addListener(this);
    posSlider.addListener(this);
    
    
    
    volSlider.setRange(0.0, 1.0);
    
    speedSlider.setRange(0.0, 100.0);
    
    posSlider.setRange(0.0, 1.0);
    
    startTimer(500);
 
    
    //new code 2
    trackName.setReadOnly(true);
        trackName.setTextToShowWhenEmpty("No track loaded", juce::Colours::orange);
    //till here 2
    

}

DeckGUI::~DeckGUI()
{
    
    stopTimer();
    
}

void DeckGUI::paint (juce::Graphics& g)
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
    g.drawText ("DeckGUI", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void DeckGUI::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    
    
    
    
    //double rowH = getHeight()/8;
    
 //   playButton.setBounds(0, 0, getWidth(), rowH);
    
  //  stopButton.setBounds(0, rowH, getWidth(), rowH);
    
//    volSlider.setBounds(0, rowH * 2, getWidth(), rowH);
//
//    speedSlider.setBounds(0, rowH * 3, getWidth(), rowH);
//
//    posSlider.setBounds(0, rowH * 4, getWidth(), rowH);
    
 //   waveformDisplay.setBounds(0, rowH * 5, getWidth(), rowH * 2);
    
   // loadButton.setBounds(0, rowH * 7, getWidth(), rowH);
    
    
/*
    //new code
    
    double rowH = getHeight()/18;
    
    const int border = 20;
    const int sliderWidth = getWidth()/2 - border;
    const int sliderHeight = getHeight() - border - 100;
    
    
    //playButton.setBounds(0, 0, getWidth(), rowH);
    playButton.setBounds(0, 0 , getWidth(), rowH * 1 + 8 );
    
   // stopButton.setBounds(0, rowH , getWidth(), rowH);
    stopButton.setBounds(0, rowH , getWidth(), rowH * 2);
    
    //volSlider.setBounds(0, rowH * 2, getWidth(), rowH * 2);
    
    volSlider.setBounds(-20, border + 40, sliderWidth, sliderHeight - 60);
    
   // speedSlider.setBounds(0, rowH * 4, getWidth(), rowH * 2);
    
    speedSlider.setBounds(getWidth()/2 + 40,border + 40, sliderWidth, sliderHeight - 60);
    
    //posSlider.setBounds(0, rowH * 6, getWidth(), rowH * 2);
    
    posSlider.setBounds(getWidth()/4 + 10 ,border + 40 , sliderWidth, sliderHeight - 60);
    
    waveformDisplay.setBounds(0, rowH * 12, getWidth(), rowH * 2);
    
    loadButton.setBounds(0, rowH * 14, getWidth(), rowH * 2);
   //till here
   
 */
   
    
    /*
    //new code
    
    auto labelposition = 55;//the sapce for the label
       // double rowH = getHeight() / 8.0;
    
    const int border = 20;
    const int sliderWidth = getWidth()/2 - border;
    const int sliderHeight = getHeight() - border - 100;
    
    
    double rowH = getHeight() / 10;
    
        playButton.setBounds(0, 0, getWidth(), rowH);
        stopButton.setBounds(0, rowH, getWidth(), rowH);
    loadButton.setBounds(0,rowH*2,getWidth(),rowH);
       // resumeButton.setBounds(0, rowH * 2, getWidth(), rowH-10);
        volSlider.setBounds(0, rowH * 2+40, getWidth() / 2, rowH * 4);
        speedSlider.setBounds(getWidth()/2, rowH * 2+40, getWidth()/2, rowH * 4);
       // posSlider.setBounds(labelposition , rowH * 7, getWidth() - 10 - labelposition, rowH);
    
   // posSlider.setBounds(getWidth()/4 + 10 ,border + 80 , sliderWidth, sliderHeight - 60);
    
    posSlider.setBounds(100, rowH * 8.5, getWidth() / 2 , rowH * 1.5);
    
    
    waveformDisplay.setBounds(0, rowH * 12, getWidth(), rowH * 2);
    
    
    volSliderLabel.setBounds(75,125,55,50);
    
    speedSliderLabel.setBounds(275,125,50,50);
    
    posSliderLabel.setBounds(35,236,60,60);
    
    //till here
*/
     

    
    
   
    //new code
    
    double rowH = getHeight() / 10;
    
    const int border = 20;
    const int sliderWidth = getWidth()/2 - border;
    const int sliderHeight = getHeight() - border - 100;
    
    
        playButton.setBounds(0, 0, getWidth(), rowH);
        stopButton.setBounds(0, rowH, getWidth(), rowH);
    loadButton.setBounds(0,rowH*2,getWidth(),rowH);
    
    volSlider.setBounds(0, rowH * 2+20, getWidth() / 2, rowH * 4);
    
    speedSlider.setBounds(getWidth()/2, rowH * 2+20, getWidth()/2, rowH * 4);
    
   // posSlider.setBounds(100, rowH * 7.2, getWidth() / 2 , rowH * 1.5);
    
    posSlider.setBounds(60, rowH * 6.8, getWidth() / 2 + 80 , rowH * 1.5);
    
    
    waveformDisplay.setBounds(0, rowH * 8, getWidth(), rowH * 2);
    
    
    volSliderLabel.setBounds(75,105,55,50);
    
    speedSliderLabel.setBounds(275,105,50,50);
    
   // posSliderLabel.setBounds(35,196,60,60);
    
    posSliderLabel.setBounds(0,196,60,60);
    
    
    //new code 2
    trackName.setColour(juce::TextEditor::backgroundColourId, juce::Colours::transparentBlack);
        trackName.setColour(juce::TextEditor::outlineColourId, juce::Colours::transparentBlack);
    //till here 2
    
    
    //till here
    
  
    
    
    
}



void DeckGUI::buttonClicked(juce::Button* button)
{
    
    if(button == &playButton)
    {
        std::cout << "Play button was clicked" << std::endl;
       // transportSource.start();
        player->start();
    }

    if(button == &stopButton)
    {
        std::cout << "Stop button was clicked" << std::endl;
        //transportSource.stop();
        player->stop();
    }


    if (button == &loadButton)
   {

        // this does work in 6.1 but the syntax is a little funky
        // https://docs.juce.com/master/classFileChooser.html#ac888983e4abdd8401ba7d6124ae64ff3
        // - configure the dialogue
//my code        auto fileChooserFlags =
 //my code       juce::FileBrowserComponent::canSelectFiles;
        // - launch out of the main thread
        // - note how we use a lambda function which you've probably
        // not seen before. Please do not worry too much about that.
//my code        fChooser.launchAsync(fileChooserFlags, [this](const juce::FileChooser& chooser)
       //my code        {
       //my code            juce::File chosenFile = chooser.getResult();
            //loadURL(juce::URL{chosenFile});
       //my code            player->loadURL(juce::URL{chooser.getResult()});
            
       //my code            waveformDisplay.loadURL(juce::URL{chooser.getResult()});
            
            //new code 2
       
            //trackName.setText(juce::URL{ chooser.getResult() }.getFileName(), //juce::NotificationType::dontSendNotification);
            //till here 2
       juce::FileChooser chooser{ "Select a file..." };
               if (chooser.browseForFileToOpen()) {
                   player->loadURL(juce::URL{ chooser.getResult() });
                   waveformDisplay.loadURL(juce::URL{ chooser.getResult() });
                   DBG(juce::URL{ chooser.getResult() }.getFileName());

                   trackName.setText(juce::URL{ chooser.getResult() }.getFileName(), juce::NotificationType::dontSendNotification);
               }
           }
       

  //my code      });
// my code    }
    

    
}


void DeckGUI::sliderValueChanged (juce::Slider *slider)
{
    
    //new
    //slider->setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    
//    volSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
//    speedSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
//    posSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    
    //till here
    
    if(slider == &volSlider)
    {
        //std::cout << "vol slider moved " << slider->getValue() <<std::endl;

        //dphase = volSlider.getValue() * 0.01;

        //transportSource.setGain(slider->getValue());

        player->setGain(slider->getValue());
    }

    if(slider == &speedSlider)
    {
       // resampleSource.setResamplingRatio(slider->getValue());
        player->setSpeed(slider->getValue());
    }

    if(slider == &posSlider)
    {

        //player1.setPosition(slider->getValue());
        player->setPositionRelative(slider->getValue());
    }
}



bool DeckGUI::isInterestedInFileDrag(const juce::StringArray &files)
{
    
    std::cout << "DeckGUI::isInterestedInFileDrag" << std::endl;
    
    return true;
}


void DeckGUI::filesDropped(const juce::StringArray &files, int x, int y)
{
    std::cout << "DeckGUI::filesDropped" << std::endl;
    
    if(files.size() == 1)
    {
        player->loadURL(juce::URL{juce::File{files[0]}});
    }
}


void DeckGUI::timerCallback()
{
   // std::cout << "DeckGUI::timerCallback" << std::endl;
    
    
    //new code 2
    if (std::to_string(loopButton.getToggleState()) == "1") { //If loop button is checked
           if (player->getPositionRelative() >= 1) {// and the position more than 1 meaning it is the end of the audio file
               player->setPositionRelative(0); // Sets position back to the start of the audio file
               player->start(); // Plays the audio file
           }
       }

       if (std::to_string(loopButton.getToggleState()) == "0") { //If loop button is not checked
           if (player->getPositionRelative() >= 1) { //and the position more than 1 meaning it is the end of the audio file
               player->setPositionRelative(0); //Sets position back to the start of the audio file
               player->stop(); // Stops the audio file
           }
       }
    //till here 2
    
    
    
    
    waveformDisplay.setPositionRelative(player->getPositionRelative());
}



//new code 2
void DeckGUI::playlistToDeckGUI() { //function rea

        std::ifstream file("playlist.txt"); //Opens playlist.txt which contains the audio file URL which the user loads from the playlist into the deck
        std::string str;
        std::getline(file, str);
        std::string URL = "file:///" + str; //adds file:/// to the audio file URL, which converts the URL into a file
        DBG(URL);
        juce::URL audioURL{ URL };
        player->loadURL(audioURL); //Loads the file into the DJAudioPlayer
        waveformDisplay.loadURL(audioURL); //Loads the file and returns the waveform of the audio file
        DBG(audioURL.getFileName());

        mtrackName = audioURL.getFileName(); //Gets the file name from the URL
        
        trackName.setText(mtrackName, juce::NotificationType::dontSendNotification);
        

}
//till here 2
