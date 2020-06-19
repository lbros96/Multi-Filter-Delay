#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MultidelayAudioProcessor::MultidelayAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
    : AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
        .withInput("Input", AudioChannelSet::stereo(), true)
#endif
        .withOutput("Output", AudioChannelSet::stereo(), true)
#endif
    ),
    treeState(*this, nullptr, "PARAMETERS", createParameterLayout())
#endif
{
    treeState.state.addListener(this);
}

MultidelayAudioProcessor::~MultidelayAudioProcessor()
{
}

AudioProcessorValueTreeState::ParameterLayout MultidelayAudioProcessor::createParameterLayout() {
    
    std::vector <std::unique_ptr<RangedAudioParameter>> parameters;

    parameters.push_back(std::make_unique<AudioParameterFloat>("DELAY_1_TIME", "Delay 1 Time", NormalisableRange<float>(TIME_MIN, TIME_MAX, 0.1f, 0.3f, false), TIME_DEFAULT));
    parameters.push_back(std::make_unique<AudioParameterFloat>("DELAY_2_TIME", "Delay 2 Time", NormalisableRange<float>(TIME_MIN, TIME_MAX, 0.1f, 0.3f, false), TIME_DEFAULT));
    parameters.push_back(std::make_unique<AudioParameterFloat>("DELAY_3_TIME", "Delay 3 Time", NormalisableRange<float>(TIME_MIN, TIME_MAX, 0.1f, 0.3f, false), TIME_DEFAULT));

    parameters.push_back(std::make_unique<AudioParameterChoice>("DELAY_1_FILTERTYPE", "Delay 1 Filter Type", StringArray("No Filter", "Low-Pass", "High-Pass"), 0));
    parameters.push_back(std::make_unique<AudioParameterChoice>("DELAY_2_FILTERTYPE", "Delay 2 Filter Type", StringArray("No Filter", "Low-Pass", "High-Pass"), 0));
    parameters.push_back(std::make_unique<AudioParameterChoice>("DELAY_3_FILTERTYPE", "Delay 3 Filter Type", StringArray("No Filter", "Low-Pass", "High-Pass"), 0));

    parameters.push_back(std::make_unique<AudioParameterFloat>("DELAY_1_FILTERCUTOFF", "Delay 1 Filter Cutoff", NormalisableRange<float>(CUTOFF_MIN, CUTOFF_MAX, 1.0f, 0.3f, false), CUTOFF_DEFAULT));
    parameters.push_back(std::make_unique<AudioParameterFloat>("DELAY_2_FILTERCUTOFF", "Delay 2 Filter Cutoff", NormalisableRange<float>(CUTOFF_MIN, CUTOFF_MAX, 1.0f, 0.3f, false), CUTOFF_DEFAULT));
    parameters.push_back(std::make_unique<AudioParameterFloat>("DELAY_3_FILTERCUTOFF", "Delay 3 Filter Cutoff", NormalisableRange<float>(CUTOFF_MIN, CUTOFF_MAX, 1.0f, 0.3f, false), CUTOFF_DEFAULT));

    parameters.push_back(std::make_unique<AudioParameterFloat>("DELAY_1_FEEDBACK", "Delay 1 Feedback", FEEDBACK_MIN, FEEDBACK_MAX, FEEDBACK_DEFAULT));
    parameters.push_back(std::make_unique<AudioParameterFloat>("DELAY_2_FEEDBACK", "Delay 2 Feedback", FEEDBACK_MIN, FEEDBACK_MAX, FEEDBACK_DEFAULT));
    parameters.push_back(std::make_unique<AudioParameterFloat>("DELAY_3_FEEDBACK", "Delay 3 Feedback", FEEDBACK_MIN, FEEDBACK_MAX, FEEDBACK_DEFAULT));

    parameters.push_back(std::make_unique<AudioParameterBool>("DELAY_1_PINGPONG", "Delay 1 Ping Pong", 0));
    parameters.push_back(std::make_unique<AudioParameterBool>("DELAY_2_PINGPONG", "Delay 2 Ping Pong", 0));
    parameters.push_back(std::make_unique<AudioParameterBool>("DELAY_3_PINGPONG", "Delay 3 Ping Pong", 0));

    parameters.push_back(std::make_unique<AudioParameterBool>("DELAY_1_ONOFF", "Delay 1 On/Off", 1));
    parameters.push_back(std::make_unique<AudioParameterBool>("DELAY_2_ONOFF", "Delay 2 On/Off", 0));
    parameters.push_back(std::make_unique<AudioParameterBool>("DELAY_3_ONOFF", "Delay 3 On/Off", 0));

    parameters.push_back(std::make_unique<AudioParameterFloat>("DELAY_1_GAIN", "Delay 1 Gain", GAIN_MIN, GAIN_MAX, GAIN_DEFAULT));
    parameters.push_back(std::make_unique<AudioParameterFloat>("DELAY_2_GAIN", "Delay 2 Gain", GAIN_MIN, GAIN_MAX, GAIN_DEFAULT));
    parameters.push_back(std::make_unique<AudioParameterFloat>("DELAY_3_GAIN", "Delay 3 Gain", GAIN_MIN, GAIN_MAX, GAIN_DEFAULT));

    parameters.push_back(std::make_unique<AudioParameterFloat>("DRYWET", "Dry/Wet", DRYWET_MIN, DRYWET_MAX, DRYWET_DEFAULT));


    return { parameters.begin(), parameters.end() };
}

void MultidelayAudioProcessor::updateParameters()
{
    auto time1 = treeState.getRawParameterValue("DELAY_1_TIME");
    auto time2 = treeState.getRawParameterValue("DELAY_2_TIME");
    auto time3 = treeState.getRawParameterValue("DELAY_3_TIME");
    auto pp1 = treeState.getRawParameterValue("DELAY_1_PINGPONG");
    auto pp2 = treeState.getRawParameterValue("DELAY_2_PINGPONG");
    auto pp3 = treeState.getRawParameterValue("DELAY_3_PINGPONG");
    auto feedback1 = treeState.getRawParameterValue("DELAY_1_FEEDBACK");
    auto feedback2 = treeState.getRawParameterValue("DELAY_2_FEEDBACK");
    auto feedback3 = treeState.getRawParameterValue("DELAY_3_FEEDBACK");
    auto filterType1 = treeState.getRawParameterValue("DELAY_1_FILTERTYPE");
    auto filterType2 = treeState.getRawParameterValue("DELAY_2_FILTERTYPE");
    auto filterType3 = treeState.getRawParameterValue("DELAY_3_FILTERTYPE");
    auto filterCutoff1 = treeState.getRawParameterValue("DELAY_1_FILTERCUTOFF");
    auto filterCutoff2 = treeState.getRawParameterValue("DELAY_2_FILTERCUTOFF");
    auto filterCutoff3 = treeState.getRawParameterValue("DELAY_3_FILTERCUTOFF");
    auto onOff1 = treeState.getRawParameterValue("DELAY_1_ONOFF");
    auto onOff2 = treeState.getRawParameterValue("DELAY_2_ONOFF");
    auto onOff3 = treeState.getRawParameterValue("DELAY_3_ONOFF");
    auto gain1 = treeState.getRawParameterValue("DELAY_1_GAIN");
    auto gain2 = treeState.getRawParameterValue("DELAY_2_GAIN");
    auto gain3 = treeState.getRawParameterValue("DELAY_3_GAIN");
    auto dryWet = treeState.getRawParameterValue("DRYWET");

    timeValues[0] = *time1;
    timeValues[1] = *time2;
    timeValues[2] = *time3;
    filterState[0] = *filterType1;
    filterState[1] = *filterType2;
    filterState[2] = *filterType3;
    filterCutoffs[0] = *filterCutoff1;
    filterCutoffs[1] = *filterCutoff2;
    filterCutoffs[2] = *filterCutoff3;
    pingPongDelays[0] = *pp1;
    pingPongDelays[1] = *pp2;
    pingPongDelays[2] = *pp3;
    feedbackValues[0] = *feedback1;
    feedbackValues[1] = *feedback2;
    feedbackValues[2] = *feedback3;
    delayActive[0] = *onOff1;
    delayActive[1] = *onOff2;
    delayActive[2] = *onOff3;
    delayGains[0] = *gain1;
    delayGains[1] = *gain2;
    delayGains[2] = *gain3;

    // Recalculate filter coefficients for each delay
    for (int i = 0; i < NUM_DELAYS; i++) {
        if (filterState[i] == LOW_PASS) {
            //Calculate Low Pass Filter Coefficients for this delay's filters
            for (int filter = 0; filter < 4; filter++) {
                delayFilters[i][filter].setCoefficients(coefficients.makeLowPass(mSampleRate, filterCutoffs[i]));
            }
        }
        else if (filterState[i] == HIGH_PASS) {
            //Calculate High Pass Filter Coefficients for this delay's filters
            for (int filter = 0; filter < 4; filter++) {
                delayFilters[i][filter].setCoefficients(coefficients.makeHighPass(mSampleRate, filterCutoffs[i]));
            }
        }
    }
    setDryWet(*dryWet);
}

void MultidelayAudioProcessor::valueTreePropertyChanged(ValueTree& treeWhosePropertyChanged, const Identifier& property) {
    shouldUpdateParameters = true;
}

//==============================================================================
const String MultidelayAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MultidelayAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool MultidelayAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool MultidelayAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double MultidelayAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MultidelayAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int MultidelayAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MultidelayAudioProcessor::setCurrentProgram (int index)
{
}

const String MultidelayAudioProcessor::getProgramName (int index)
{
    return {};
}

void MultidelayAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void MultidelayAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    const int numInputChannels = getTotalNumInputChannels();
    const int delayBufferSize = 5 * (sampleRate + samplesPerBlock);
    mSampleRate = sampleRate;

    updateParameters();

    //Initialize delay buffers, clear them and reset write positions to 0
    for (int i = 0; i < NUM_DELAYS; i++) {
        mDelayBuffers[i].setSize(numInputChannels, delayBufferSize);
        mDelayBuffers[i].clear();
        mWritePositions[i] = 0;
    }
}



void MultidelayAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool MultidelayAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void MultidelayAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    const int numSamples = buffer.getNumSamples();

    playHead = this->getPlayHead();
    playHead->getCurrentPosition(currentPositionInfo);
    bpmHost = currentPositionInfo.bpm;


    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    //Define the buffer length and delay buffer length
    const int bufferLength = buffer.getNumSamples();
    const int delayBufferLength = mDelayBuffers[0].getNumSamples();

    float sampleRate = getSampleRate();

    //Initialise Buffer for the dry input
    AudioSampleBuffer dryBuffer;

    // Initialise Buffer for Each Delay
    AudioSampleBuffer delayOutputs [NUM_DELAYS];

    dryBuffer.clear();
    dryBuffer.makeCopyOf(buffer);

    for (int i = 0; i < NUM_DELAYS; i++) {
        //Clear buffers for delay outputs
        delayOutputs[i].clear();
        //Make copy of input buffer
        delayOutputs[i].makeCopyOf(buffer);
    }

    //If something in the value tree has changed update the parameters
    if (shouldUpdateParameters) {
        updateParameters();
        shouldUpdateParameters = false;
    }

    //Clear the buffer to allow separation of dry and wet signal
    buffer.clear();

    //Reset local write position for each buffer
    int localWritePosition[NUM_DELAYS] = { 0 };

    //Loop through the delays
    for (int i = 0; i < NUM_DELAYS; i++) {

        //Calculate the current delay time in terms of samples
        float delayInSamples = mSampleRate * timeValues[i] / 1000.0f;

        //If the delay is a ping pong delay, proceed with ping pong delay method
        if (pingPongDelays[i] == true && totalNumInputChannels >= 2){

            //Initialise variables holding the write positions for both channels of the dry buffer, delay buffer and delay output buffer
            float* channelDataL = dryBuffer.getWritePointer(0);
            float* channelDataR = dryBuffer.getWritePointer(1);
            float* delayBufferDataL = mDelayBuffers[i].getWritePointer(0);
            float* delayBufferDataR = mDelayBuffers[i].getWritePointer(1);
            float* outputDataL = delayOutputs[i].getWritePointer(0);
            float* outputDataR = delayOutputs[i].getWritePointer(1);

            localWritePosition[i] = mWritePositions[i]; 

            //Loop through total number of samples
            for (int sample = 0; sample < numSamples; ++sample) {

                //Take input samples from left and right channel weighted by the ping pong delay balance value
                const float inL = currentBalances[i] * channelDataL[sample];
                const float inR = (1 - currentBalances[i]) * channelDataR[sample];
                float outL = 0.0f;
                float outR = 0.0f;

                //Calculate the current read position in terms of the current delay time, with wraparound
                float readPosition =
                    fmodf((float)localWritePosition[i] - delayInSamples + (float)delayBufferLength, delayBufferLength);
                int localReadPosition = floorf(readPosition);

                //Calculate output sample by interpolating between the two closest sample positions, weighted by proximity, for each channel
                if (localReadPosition != localWritePosition[i]) {
                    float fraction = readPosition - (float)localReadPosition;
                    float delayed1L = delayBufferDataL[(localReadPosition + 0)];
                    float delayed1R = delayBufferDataR[(localReadPosition + 0)];
                    float delayed2L = delayBufferDataL[(localReadPosition + 1) % delayBufferLength];
                    float delayed2R = delayBufferDataR[(localReadPosition + 1) % delayBufferLength];
                    outL = delayed1L + fraction * (delayed2L - delayed1L);
                    outR = delayed1R + fraction * (delayed2R - delayed1R);

                    //Write the samples for each channel to the delays output buffer and back into the delay buffer with feedback
                    outputDataL[sample] = outL;
                    outputDataR[sample] = outR;
                    delayBufferDataL[localWritePosition[i]] = inL + outR * feedbackValues[i];
                    delayBufferDataR[localWritePosition[i]] = inR + outL * feedbackValues[i];
                }

                if (++localWritePosition[i] >= delayBufferLength)
                    localWritePosition[i] -= delayBufferLength;
            }
        }
        //If the delay is not a ping pong delay, proceed with standard delay
        else{

            //Loop through each channel and apply delay
            for (int channel = 0; channel < totalNumInputChannels; ++channel)
            {
                //Initialise variables holding the write positions of the dry buffer, delay buffer and delay output buffer
                auto* channelData = dryBuffer.getWritePointer(channel);
                float* outputData = delayOutputs[i].getWritePointer(channel);
                float* delayBufferData = mDelayBuffers[i].getWritePointer(channel);

                localWritePosition[i] = mWritePositions[i];

                //Loop through total number of samples
                for (int sample = 0; sample < numSamples; ++sample) {
                    const float in = channelData[sample];
                    float out = 0.0f;

                    //Calculate the current read position in terms of the current delay time, with wraparound
                    float readPosition =
                        fmodf((float)localWritePosition[i] - delayInSamples + (float)delayBufferLength, delayBufferLength);
                    int localReadPosition = floorf(readPosition);

                    //Calculate output sample as by interpolating between the two closest sample positions, weighted by proximity
                    if (localReadPosition != localWritePosition[i]) {
                        float fraction = readPosition - (float)localReadPosition;
                        float delayed1 = delayBufferData[(localReadPosition + 0)];
                        float delayed2 = delayBufferData[(localReadPosition + 1) % delayBufferLength];
                        out = delayed1 + fraction * (delayed2 - delayed1);

                        //Write the sample to the delays output buffer and back into the delay buffer with feedback
                        outputData[sample] = out;
                        delayBufferData[localWritePosition[i]] = in + out * feedbackValues[i];
                    }
                    //If the write position has overran the buffer, loop back around to the start
                    if (++localWritePosition[i] >= delayBufferLength)
                        localWritePosition[i] -= delayBufferLength;
                }
            }
        }
        //Update the write position for the delay
        mWritePositions[i] = localWritePosition[i];
    }

    //Loop through the channels and add delay outputs to output buffer
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        //Add dry buffer to output, weighted by dry value
        buffer.addFrom(channel, 0, dryBuffer, channel, 0, numSamples, dryGain);

        //Add wet delay output buffers to output, weighted by wet value, if the delay is active
        for (int i = 0; i < NUM_DELAYS; i++) {
            if (delayActive[i]) {
                //If the filter type for this delay is not null, then filter the delay output.
                if (filterState[i] != NO_FILTER) {
                    delayFilters[i][2 * channel].processSamples(delayOutputs[i].getWritePointer(channel), numSamples);
                    delayFilters[i][(2 * channel) + 1].processSamples(delayOutputs[i].getWritePointer(channel), numSamples);
                }
                buffer.addFrom(channel, 0, delayOutputs[i], channel, 0, numSamples, wetGain*Decibels::decibelsToGain(delayGains[i]));
            }
        }
    }

    for (int channel = totalNumInputChannels; channel < totalNumOutputChannels; ++channel)
        buffer.clear(channel, 0, numSamples);
}

//==============================================================================
bool MultidelayAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* MultidelayAudioProcessor::createEditor()
{
    return new MultidelayAudioProcessorEditor (*this);
}

//==============================================================================
void MultidelayAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void MultidelayAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MultidelayAudioProcessor();
}
