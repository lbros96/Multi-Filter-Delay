/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#define NUM_DELAYS 3
#define NO_FILTER 0
#define LOW_PASS 1
#define HIGH_PASS 2

#define FEEDBACK_MIN 0.0f
#define FEEDBACK_MAX 0.95f
#define FEEDBACK_DEFAULT 0.0f

#define TIME_MIN 1.0f
#define TIME_MAX 5000.0f
#define TIME_DEFAULT 350.0f

#define CUTOFF_MIN 1.0f
#define CUTOFF_MAX 20000.0f
#define CUTOFF_DEFAULT 500.0f

#define DRYWET_MIN 0.0f
#define DRYWET_MAX 1.0f
#define DRYWET_DEFAULT 0.5f

#define GAIN_MIN -32.0f
#define GAIN_MAX 6.0f
#define GAIN_DEFAULT 0.0f

//==============================================================================
/**
*/
class MultidelayAudioProcessor  : public AudioProcessor,
                                  public ValueTree::Listener
{
public:
    //==============================================================================
    MultidelayAudioProcessor();
    ~MultidelayAudioProcessor();


    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    void updateParameters();


    //Setter Methods
    void setDelayTime(int delayNum, float delayTime) { timeValues[delayNum] = delayTime; }
    void setFilterCutoff(int delayNum, float filterCutoff) { filterCutoffs[delayNum] = filterCutoff; }
    void setDelayFeedback(int delayNum, float feedback) { feedbackValues[delayNum] = feedback; }
    void setActiveDelay(int delayNum, int state) { delayActive[delayNum] = state; }
    void setFilterState(int delayNum, int state) { filterState[delayNum] = state; }
    void setPingPong(int delayNum, int state) { pingPongDelays[delayNum] = state; }
    void setGain(float gain) { makeUpGain = gain; }
    void setDryWet(float dryWet) {
        if (dryWet <= 0.5f) {
            dryGain = 1.0f;
            wetGain = 1.0f - (abs(dryWet - 0.5)) * 2;
        } 
        else if (dryWet > 0.5f) {
            dryGain = (1.0f - dryWet) * 2;
            wetGain = 1.0f;
        }
    }

    AudioProcessorValueTreeState& getTreeState() { return treeState; }
    

    float level;
    int bpm;
    int bpmHost;

private:

    AudioBuffer<float> mDelayBuffers[NUM_DELAYS];

    int mWritePositions[NUM_DELAYS] = { 0 };
    int mSampleRate = { 44100 };

    //UI Parameters
    float makeUpGain = 0.0f;
    float dryGain = 1.0f;
    float wetGain = 1.0f;
    int delayActive[NUM_DELAYS];
    int filterState[NUM_DELAYS] = { 0 };
    float timeValues[NUM_DELAYS];
    float filterCutoffs[NUM_DELAYS];
    float feedbackValues[NUM_DELAYS];
    float currentBalances[NUM_DELAYS] = { 0.95f, 0.05f, 0.95f };
    float pingPongDelays[NUM_DELAYS] = { 0 };
    float delayGains[NUM_DELAYS] = { 0.0f };

    IIRFilter delayFilters[NUM_DELAYS][4];
    IIRCoefficients coefficients;

    AudioProcessorValueTreeState::ParameterLayout MultidelayAudioProcessor::createParameterLayout();
    AudioProcessorValueTreeState treeState;
    void valueTreePropertyChanged(ValueTree& treeWhosePropertyChanged, const Identifier& property) override;

    std::atomic<bool> shouldUpdateParameters = { false };

    AudioPlayHead* playHead;
    AudioPlayHead::CurrentPositionInfo currentPositionInfo;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MultidelayAudioProcessor)
};
