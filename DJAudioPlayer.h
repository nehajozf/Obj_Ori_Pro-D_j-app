/*
  ==============================================================================

    DJAudioPlayer.h
    Created: 9 Feb 2023 6:04:38am
    Author:  Neha Joseph

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//new code 2
//#include "PlaylistComponent.h"
//#include "../JuceLibraryCode/JuceHeader.h"
//#include "PlaylistComponent.h"
//till here 2

class DJAudioPlayer : public juce::AudioSource{
    
public:
    
    DJAudioPlayer(juce::AudioFormatManager& _formatManager);
    ~DJAudioPlayer();
    
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    
    void loadURL(juce::URL audioURL);
    void setGain(double gain);
    void setSpeed(double ratio);
    void setPosition(double posInSecs);
    
    void setPositionRelative(double pos);
    
    void start();
    void stop();
    
   
    /** Get the relative position of the playhead*/
    double getPositionRelative();
    
    
    
private:
    
   // juce::AudioFormatManager formatManager;
    
    juce::AudioFormatManager& formatManager;
    
    std::unique_ptr<juce::AudioFormatReaderSource> readerSource;
    
    juce::AudioTransportSource transportSource;
    
    juce::ResamplingAudioSource resampleSource{&transportSource, false, 2};
    
};
