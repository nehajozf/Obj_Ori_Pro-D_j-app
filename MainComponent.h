#pragma once

#include <JuceHeader.h>

#include "DJAudioPlayer.h"

#include "DeckGUI.h"

#include "PlaylistComponent.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::AudioAppComponent,
                      // public juce::Button::Listener,
                      // public juce::Slider::Listener
public juce::Timer
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;
    
    /** Implement Button::Listner */
   // void buttonClicked (juce::Button *) override;
    
    /** Implement Slider::Listner */
  //  void sliderValueChanged (juce::Slider *) override;
    
    
    //new code 2
    void timerCallback() override;
    //till here 2
    

private:
    //==============================================================================
    // Your private member variables go here...
    
//    juce::TextButton playButton{"PLAY"};
//
//    juce::TextButton stopButton{"STOP"};
//
//    juce::TextButton loadButton{"LOAD"};
//
//    juce::Slider volSlider;
//
//    juce::Slider speedSlider;
//
//    juce::Slider posSlider;

    
    //juce::Random rand;
    
   // double phase;
    
   // double dphase;
    
   // juce::AudioFormatManager formatManager;
    
    //std::unique_ptr<juce::AudioFormatReaderSource> readerSource;
    
   // juce::AudioTransportSource transportSource;
    
    //void loadURL(juce::URL audioURL);
    
   // juce::FileChooser fChooser{"Select a file..."};
    
    //juce::ResamplingAudioSource resampleSource{&transportSource, false, 2};
    
    
    juce::AudioFormatManager formatManager;
    
    juce::AudioThumbnailCache thumbCache{100};
    
    
    DJAudioPlayer player1{formatManager};
    
    DeckGUI deckGUI1{&player1, formatManager, thumbCache};
    
    //other people new code
   // DeckGUI deckGUI1{ &player1, &waveformDisplay1};
    //other people till here
    
    
    DJAudioPlayer player2{formatManager};
    
    DeckGUI deckGUI2{&player2, formatManager, thumbCache};
    
    //other people new code
   // DeckGUI deckGUI2{ &player2, &waveformDisplay2};
    //other people till here
    
    juce::MixerAudioSource mixerSource;
    
    /*
    //other people new code
    WaveformDisplay waveformDisplay1{ formatManager, thumbCache };
        WaveformDisplay waveformDisplay2{ formatManager, thumbCache };

        
        PlaylistComponent playlistComponent{ &player1, &player2, formatManager, &waveformDisplay1, &waveformDisplay2};
    //other people till here
    */
    
    PlaylistComponent playlistComponent;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
