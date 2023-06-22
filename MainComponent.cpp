#include "MainComponent.h"

#include <iostream>

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (800, 600);

    // Some platforms require permissions to open input channels so request that here
    if (juce::RuntimePermissions::isRequired (juce::RuntimePermissions::recordAudio)
        && ! juce::RuntimePermissions::isGranted (juce::RuntimePermissions::recordAudio))
    {
        juce::RuntimePermissions::request (juce::RuntimePermissions::recordAudio,
                                           [&] (bool granted) { setAudioChannels (granted ? 2 : 0, 2); });
    }
    else
    {
        // Specify the number of input and output channels that we want to open
        setAudioChannels (2, 2);
    }
    
    addAndMakeVisible(deckGUI1);
    
    addAndMakeVisible(deckGUI2);
    
    /*
    //other people new code
   // addAndMakeVisible(waveformDisplay1);
    //addAndMakeVisible(waveformDisplay2);
    
    //other people till here
   */
    
    addAndMakeVisible(playlistComponent);
    
    formatManager.registerBasicFormats();
    
    
    
//    addAndMakeVisible(playButton);
//
//    addAndMakeVisible(stopButton);
//
//    addAndMakeVisible(loadButton);
//
//
//    addAndMakeVisible(volSlider);
//
//    addAndMakeVisible(speedSlider);
//
//    addAndMakeVisible(posSlider);
    
    
//    playButton.addListener(this);
//
//    stopButton.addListener(this);
//
//    loadButton.addListener(this);
//
//
//    volSlider.addListener(this);
//
//    volSlider.setRange(0.0, 1.0);
//
//
//    speedSlider.addListener(this);
//
//    posSlider.addListener(this);
//
//    posSlider.setRange(0.0, 1.0);
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.

    // For more details, see the help for AudioProcessor::prepareToPlay()
    
    //phase = 0.0;
    
    //dphase = 0.0001;
    
    player1.prepareToPlay(samplesPerBlockExpected, sampleRate);
    
    player2.prepareToPlay(samplesPerBlockExpected, sampleRate);
    
    mixerSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
    
    mixerSource.addInputSource(&player1, false);
    
    mixerSource.addInputSource(&player2, false);
    
   // formatManager.registerBasicFormats();
    //juce::URL audioURL{"file:///Users/nehajoseph/Downloads/tracks/aon_inspired.mp3"};
    
  //  auto* reader = formatManager.createReaderFor(audioURL.createInputStream(false));
  //  if (reader != nullptr) // good file
   // {
    //  std::unique_ptr<juce::AudioFormatReaderSource> newSource (new juce::AudioFormatReaderSource (reader, true));
    //transportSource.setSource(newSource.get(), 0 , nullptr , reader->sampleRate);
   // readerSource.reset (newSource.release());
   // transportSource.start();
  //  }
    
    //transportSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
    
   // resampleSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
}

//void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
//{
    // Your audio-processing code goes here!

    // For more details, see the help for AudioProcessor::getNextAudioBlock()

    // Right now we are not producing any data, in which case we need to clear the buffer
    // (to prevent the output of random noise)
    
    
  //  auto* leftChan = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
    
  //  auto* rightChan = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
    
  //  for(auto i=0; i < bufferToFill.numSamples; ++i)
  //  {
        //double sample = rand.nextDouble() * 0.25;
        //double sample = fmod(phase, 0.2);
        
   //     double sample = sin(phase) * 0.1;
        
    //    leftChan[i] = sample;
     //   rightChan[i] = sample;
        
        //phase  += 0.005;
      //  phase  += dphase;
  //  }
    
    
    
    //bufferToFill.clearActiveBufferRegion();
//}




void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    // Your audio-processing code goes here!

    // For more details, see the help for AudioProcessor::getNextAudioBlock()

    // Right now we are not producing any data, in which case we need to clear the buffer
    // (to prevent the output of random noise)
    
   // transportSource.getNextAudioBlock(bufferToFill);
    
    //resampleSource.getNextAudioBlock(bufferToFill);
    
   // player1.getNextAudioBlock(bufferToFill);
    
    
    mixerSource.getNextAudioBlock(bufferToFill);
}







void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
    
   // transportSource.releaseResources();
    
    player1.releaseResources();
    
    player2.releaseResources();
    
    mixerSource.releaseResources();
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
    
//    g.setFont (20.0f);
//    g.drawText ("Welcome to OtoDeck Project", getLocalBounds(),
//                juce:: Justification::centred, true);  
    
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    
//    double rowH = getHeight()/6;
//
//    playButton.setBounds(0, 0, getWidth(), rowH);
//
//    stopButton.setBounds(0, rowH, getWidth(), rowH);
//
//    volSlider.setBounds(0, rowH * 2, getWidth(), rowH);
//
//    speedSlider.setBounds(0, rowH * 3, getWidth(), rowH);
//
//    posSlider.setBounds(0, rowH * 4, getWidth(), rowH);
//
//    loadButton.setBounds(0, rowH * 5, getWidth(), rowH);
    
    
    deckGUI1.setBounds(0, 0, getWidth()/2, getHeight() / 2);
    
    deckGUI2.setBounds(getWidth()/2, 0, getWidth()/2, getHeight() / 2);
    
    playlistComponent.setBounds(0, getHeight() / 2, getWidth(), getHeight() / 2);
    
    //new code
    
   // playlistComponent.setBounds(0, getHeight() / 2, getWidth(), getHeight() / 4);
    
    //till here
    
    
    
}

//can delete the whole code below

/*


void MainComponent::buttonClicked(juce::Button* button)
{
    
//    if(button == &playButton)
//    {
//        std::cout << "Play button was clicked" << std::endl;
//       // transportSource.start();
//        player1.start();
//    }
//
//    if(button == &stopButton)
//    {
//        std::cout << "Stop button was clicked" << std::endl;
//        //transportSource.stop();
//        player1.stop();
//    }
//
//
//    if (button == &loadButton)
//    {
//
//        // this does work in 6.1 but the syntax is a little funky
//        // https://docs.juce.com/master/classFileChooser.html#ac888983e4abdd8401ba7d6124ae64ff3
//        // - configure the dialogue
//        auto fileChooserFlags =
//        juce::FileBrowserComponent::canSelectFiles;
//        // - launch out of the main thread
//        // - note how we use a lambda function which you've probably
//        // not seen before. Please do not worry too much about that.
//        fChooser.launchAsync(fileChooserFlags, [this](const juce::FileChooser& chooser)
//        {
//            juce::File chosenFile = chooser.getResult();
//           // loadURL(juce::URL{chosenFile});
//            player1.loadURL(juce::URL{chooser.getResult()});
//
//        });
//    }
    

    
}




void MainComponent::sliderValueChanged (juce::Slider *slider)
{
//    if(slider == &volSlider)
//    {
//        //std::cout << "vol slider moved " << slider->getValue() <<std::endl;
//
//        //dphase = volSlider.getValue() * 0.01;
//
//        //transportSource.setGain(slider->getValue());
//
//        player1.setGain(slider->getValue());
//    }
//
//    if(slider == &speedSlider)
//    {
//       // resampleSource.setResamplingRatio(slider->getValue());
//        player1.setSpeed(slider->getValue());
//    }
//
//    if(slider == &posSlider)
//    {
//
//        //player1.setPosition(slider->getValue());
//        player1.setPositionRelative(slider->getValue());
//    }
}


//the below part does not exist anymore
// /*

void MainComponent::loadURL(juce::URL audioURL)
{
    
    
    auto* reader = formatManager.createReaderFor(audioURL.createInputStream(false));
    if (reader != nullptr) // good file
    {
      std::unique_ptr<juce::AudioFormatReaderSource> newSource (new juce::AudioFormatReaderSource (reader, true));
    transportSource.setSource(newSource.get(), 0 , nullptr , reader->sampleRate);
    readerSource.reset (newSource.release());
   // transportSource.start();
    }
 
}
*/


//new code 2
void MainComponent::timerCallback() { //Function loops every 500ms, checks whether user has loaded a playlist audio file into a deckGUI

    std::ifstream file("playlist.txt"); //Opens playlist.txt
    std::string str;
    std::vector<std::string> lines;
    while (std::getline(file, str)) //Reads the lines in playlist.txt
    {
        lines.push_back(str);
    }
    //If the user added a song from playlist into deckGUI playlist.txt will contain the audio file URL and a number indicating which deckGUI the user selected
    if (std::stoi(lines[1]) == 1) { //If user selects deck 1, line 2 will show 1
        deckGUI1.playlistToDeckGUI(); //plays audio file in deckGUI1
        
        std::ofstream myfile("playlist.txt");
        myfile << "" << std::endl << "0" << std::endl; //Changes line 2 from "1" to "0" which resets playlist.txt file and stops the timer from looping endlessly
        myfile.close(); //closes file
    }
    else if (std::stoi(lines[1]) == 2) { //If user selects deck 2, line 2 will show 2
        deckGUI2.playlistToDeckGUI(); //plays audio file in deckGUI2
        std::ofstream myfile("playlist.txt");
        myfile << "" << std::endl << "0" << std::endl; //Changes line 2 from "2" to "0" which resets playlist.txt file and stops the timer from looping endlessly
        myfile.close(); //closes file
    }
    
}
//till here 2
