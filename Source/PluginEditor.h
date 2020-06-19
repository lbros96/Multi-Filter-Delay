/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class MultidelayAudioProcessorEditor  : public AudioProcessorEditor,
                                        public Button::Listener
{
public:
    MultidelayAudioProcessorEditor (MultidelayAudioProcessor&);
    ~MultidelayAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

    void buttonClicked(Button* button);

    void setTimeValue(int delayNum, float value);


private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MultidelayAudioProcessor& processor;

    std::unique_ptr<Slider> TimeSlider1;
    std::unique_ptr<TextButton> SyncTime1_1;
    std::unique_ptr<TextButton> SyncTime1_2;
    std::unique_ptr<TextButton> SyncTime1_3;
    std::unique_ptr<TextButton> SyncTime1_4;
    std::unique_ptr<TextButton> SyncTime1_5;
    std::unique_ptr<TextButton> SyncTime1_6;
    std::unique_ptr<TextButton> SyncTime1_8;
    std::unique_ptr<TextButton> SyncTime1_16;
    ComboBox FilterType1;
    std::unique_ptr<Slider> FilterCutoff1;
    std::unique_ptr<Slider> Feedback1;
    std::unique_ptr<ToggleButton> OnOff1;
    std::unique_ptr<ToggleButton> PingPongToggle1;
    std::unique_ptr<Slider> Gain1;

    std::unique_ptr<Slider> TimeSlider2;    
    std::unique_ptr<TextButton> SyncTime2_1;
    std::unique_ptr<TextButton> SyncTime2_2;
    std::unique_ptr<TextButton> SyncTime2_3;
    std::unique_ptr<TextButton> SyncTime2_4;
    std::unique_ptr<TextButton> SyncTime2_5;
    std::unique_ptr<TextButton> SyncTime2_6;
    std::unique_ptr<TextButton> SyncTime2_8;
    std::unique_ptr<TextButton> SyncTime2_16;
    ComboBox FilterType2;
    std::unique_ptr<Slider> FilterCutoff2;
    std::unique_ptr<Slider> Feedback2;
    std::unique_ptr<ToggleButton> OnOff2;
    std::unique_ptr<ToggleButton> PingPongToggle2;
    std::unique_ptr<Slider> Gain2;

    std::unique_ptr<Slider> TimeSlider3;
    std::unique_ptr<TextButton> SyncTime3_1;
    std::unique_ptr<TextButton> SyncTime3_2;
    std::unique_ptr<TextButton> SyncTime3_3;
    std::unique_ptr<TextButton> SyncTime3_4;
    std::unique_ptr<TextButton> SyncTime3_5;
    std::unique_ptr<TextButton> SyncTime3_6;
    std::unique_ptr<TextButton> SyncTime3_8;
    std::unique_ptr<TextButton> SyncTime3_16;  
    ComboBox FilterType3;
    std::unique_ptr<Slider> FilterCutoff3;   
    std::unique_ptr<Slider> Feedback3;
    std::unique_ptr<ToggleButton> OnOff3;
    std::unique_ptr<ToggleButton> PingPongToggle3;
    std::unique_ptr<Slider> Gain3;
 
    std::unique_ptr<Slider> DryWet;


public:

    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> TimeSlider1Value;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> TimeSlider2Value;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> TimeSlider3Value;

    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> FilterType1Value;
    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> FilterType2Value;
    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> FilterType3Value;

    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> FilterCutoff1Value;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> FilterCutoff2Value;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> FilterCutoff3Value;

    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> Feedback1Value;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> Feedback2Value;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> Feedback3Value;

    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> PingPong1Value;
    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> PingPong2Value;
    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> PingPong3Value;

    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> OnOff1Value;
    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> OnOff2Value;
    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> OnOff3Value;

    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> Gain1Value;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> Gain2Value;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> Gain3Value;

    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> DryWetValue;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MultidelayAudioProcessorEditor)
};
