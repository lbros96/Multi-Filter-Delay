#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MultidelayAudioProcessorEditor::MultidelayAudioProcessorEditor (MultidelayAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    setSize(600, 568);
    
    // First delay sliders and buttons //
    TimeSlider1.reset(new Slider("DelayTimeSlider"));
    addAndMakeVisible(TimeSlider1.get());
    TimeSlider1->setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    TimeSlider1->setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    TimeSlider1->setColour(Slider::thumbColourId, Colour(0xff3f7d20));
    TimeSlider1->setColour(Slider::textBoxTextColourId, Colours::black);
    TimeSlider1Value = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.getTreeState(), "DELAY_1_TIME",*TimeSlider1);

    TimeSlider1->setBounds(4, 124, 88, 96);

    SyncTime1_1.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime1_1.get());
    SyncTime1_1->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime1_1->setButtonText(TRANS("1"));
    SyncTime1_1->addListener(this);
    SyncTime1_1->setColour(TextButton::buttonColourId, Colour(0xff3f7d20));

    SyncTime1_1->setBounds(124, 132, 24, 16);

    SyncTime1_2.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime1_2.get());
    SyncTime1_2->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime1_2->setButtonText(TRANS("2"));
    SyncTime1_2->addListener(this);
    SyncTime1_2->setColour(TextButton::buttonColourId, Colour(0xff3f7d20));

    SyncTime1_2->setBounds(156, 132, 24, 16);

    SyncTime1_3.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime1_3.get());
    SyncTime1_3->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime1_3->setButtonText(TRANS("3"));
    SyncTime1_3->addListener(this);
    SyncTime1_3->setColour(TextButton::buttonColourId, Colour(0xff3f7d20));

    SyncTime1_3->setBounds(124, 156, 24, 16);

    SyncTime1_4.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime1_4.get());
    SyncTime1_4->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime1_4->setButtonText(TRANS("4"));
    SyncTime1_4->addListener(this);
    SyncTime1_4->setColour(TextButton::buttonColourId, Colour(0xff3f7d20));

    SyncTime1_4->setBounds(156, 156, 24, 16);

    SyncTime1_5.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime1_5.get());
    SyncTime1_5->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime1_5->setButtonText(TRANS("5"));
    SyncTime1_5->addListener(this);
    SyncTime1_5->setColour(TextButton::buttonColourId, Colour(0xff3f7d20));

    SyncTime1_5->setBounds(124, 180, 24, 16);

    SyncTime1_6.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime1_6.get());
    SyncTime1_6->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime1_6->setButtonText(TRANS("6"));
    SyncTime1_6->addListener(this);
    SyncTime1_6->setColour(TextButton::buttonColourId, Colour(0xff3f7d20));

    SyncTime1_6->setBounds(156, 180, 24, 16);

    SyncTime1_8.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime1_8.get());
    SyncTime1_8->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime1_8->setButtonText(TRANS("8"));
    SyncTime1_8->addListener(this);
    SyncTime1_8->setColour(TextButton::buttonColourId, Colour(0xff3f7d20));

    SyncTime1_8->setBounds(124, 204, 24, 16);

    SyncTime1_16.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime1_16.get());
    SyncTime1_16->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime1_16->setButtonText(TRANS("16"));
    SyncTime1_16->addListener(this);
    SyncTime1_16->setColour(TextButton::buttonColourId, Colour(0xff3f7d20));

    SyncTime1_16->setBounds(156, 204, 24, 16);

    FilterType1.addItem("No Filter", 1);
    FilterType1.addItem("Low-Pass", 2);
    FilterType1.addItem("High-Pass", 3);
    FilterType1.setJustificationType(Justification::centred);
    addAndMakeVisible(&FilterType1);
    FilterType1Value = std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(processor.getTreeState(), "DELAY_1_FILTERTYPE", FilterType1);
    FilterType1.setBounds(4, 292, 88, 32);

    FilterCutoff1.reset(new Slider("FilterCutoffKnob"));
    addAndMakeVisible(FilterCutoff1.get());
    FilterCutoff1->setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    FilterCutoff1->setTextValueSuffix("Hz");
    FilterCutoff1->setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    FilterCutoff1->setColour(Slider::thumbColourId, Colour(0xff3f7d20));
    FilterCutoff1->setColour(Slider::textBoxTextColourId, Colours::black);
    FilterCutoff1Value = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.getTreeState(), "DELAY_1_FILTERCUTOFF", *FilterCutoff1);

    FilterCutoff1->setBounds(108, 268, 80, 96);

    Feedback1.reset(new Slider("FeedbackSlider"));
    addAndMakeVisible(Feedback1.get());
    Feedback1->setSliderStyle(Slider::LinearBar);
    Feedback1->setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    Feedback1->setColour(Slider::trackColourId, Colours::chartreuse);
    Feedback1->setColour(Slider::textBoxTextColourId, Colours::black);
    Feedback1Value = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.getTreeState(), "DELAY_1_FEEDBACK", *Feedback1);

    Feedback1->setBounds(12, 420, 88, 32);

    PingPongToggle1.reset(new ToggleButton("PingPongToggle"));
    addAndMakeVisible(PingPongToggle1.get());
    PingPongToggle1->setButtonText(String());
    PingPongToggle1->setToggleState(true, dontSendNotification);
    PingPongToggle1->setColour(ToggleButton::textColourId, Colours::black);
    PingPong1Value = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.getTreeState(), "DELAY_1_PINGPONG", *PingPongToggle1);

    PingPongToggle1->setBounds(140, 415, 40, 40);

    OnOff1.reset(new ToggleButton("DelayOnOffToggle"));
    addAndMakeVisible(OnOff1.get());
    OnOff1->setButtonText(String());
    OnOff1->setToggleState(true, dontSendNotification);
    OnOff1->setColour(ToggleButton::textColourId, Colours::black);
    OnOff1Value = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.getTreeState(), "DELAY_1_ONOFF", *OnOff1);

    OnOff1->setBounds(52, 505, 40, 32);

    Gain1.reset(new Slider("GainSlider"));
    addAndMakeVisible(Gain1.get());
    Gain1->setRange(-6, 6, 0.1);
    Gain1->setTextValueSuffix("dB");
    Gain1->setSliderStyle(Slider::LinearBarVertical);
    Gain1->setTextBoxStyle(Slider::TextBoxLeft, false, 80, 20);
    Gain1->setColour(Slider::trackColourId, Colours::chartreuse);
    Gain1->setColour(Slider::textBoxOutlineColourId, Colours::chartreuse);
    Gain1Value = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.getTreeState(), "DELAY_1_GAIN", *Gain1);

    Gain1->setBounds(132, 468, 68, 100);

    // First delay sliders and buttons //

    //Second delay sliders and buttons //
    TimeSlider2.reset(new Slider("DelayTimeSlider"));
    addAndMakeVisible(TimeSlider2.get());
    TimeSlider2->setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    TimeSlider2->setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    TimeSlider2->setColour(Slider::thumbColourId, Colour(0xff79b158));
    TimeSlider2->setColour(Slider::textBoxTextColourId, Colours::black);
    TimeSlider2Value = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.getTreeState(), "DELAY_2_TIME", *TimeSlider2);

    TimeSlider2->setBounds(204, 127, 88, 96);


    SyncTime2_1.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime2_1.get());
    SyncTime2_1->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime2_1->setButtonText(TRANS("1"));
    SyncTime2_1->addListener(this);
    SyncTime2_1->setColour(TextButton::buttonColourId, Colour(0xff79b158));

    SyncTime2_1->setBounds(324, 135, 24, 16);

    SyncTime2_2.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime2_2.get());
    SyncTime2_2->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime2_2->setButtonText(TRANS("2"));
    SyncTime2_2->addListener(this);
    SyncTime2_2->setColour(TextButton::buttonColourId, Colour(0xff79b158));

    SyncTime2_2->setBounds(356, 135, 24, 16);

    SyncTime2_3.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime2_3.get());
    SyncTime2_3->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime2_3->setButtonText(TRANS("3"));
    SyncTime2_3->addListener(this);
    SyncTime2_3->setColour(TextButton::buttonColourId, Colour(0xff79b158));

    SyncTime2_3->setBounds(324, 159, 24, 16);

    SyncTime2_4.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime2_4.get());
    SyncTime2_4->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime2_4->setButtonText(TRANS("4"));
    SyncTime2_4->addListener(this);
    SyncTime2_4->setColour(TextButton::buttonColourId, Colour(0xff79b158));

    SyncTime2_4->setBounds(356, 159, 24, 16);

    SyncTime2_5.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime2_5.get());
    SyncTime2_5->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime2_5->setButtonText(TRANS("5"));
    SyncTime2_5->addListener(this);
    SyncTime2_5->setColour(TextButton::buttonColourId, Colour(0xff79b158));

    SyncTime2_5->setBounds(324, 183, 24, 16);

    SyncTime2_6.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime2_6.get());
    SyncTime2_6->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime2_6->setButtonText(TRANS("6"));
    SyncTime2_6->addListener(this);
    SyncTime2_6->setColour(TextButton::buttonColourId, Colour(0xff79b158));

    SyncTime2_6->setBounds(356, 183, 24, 16);

    SyncTime2_8.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime2_8.get());
    SyncTime2_8->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime2_8->setButtonText(TRANS("8"));
    SyncTime2_8->addListener(this);
    SyncTime2_8->setColour(TextButton::buttonColourId, Colour(0xff79b158));

    SyncTime2_8->setBounds(324, 207, 24, 16);

    SyncTime2_16.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime2_16.get());
    SyncTime2_16->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime2_16->setButtonText(TRANS("16"));
    SyncTime2_16->addListener(this);
    SyncTime2_16->setColour(TextButton::buttonColourId, Colour(0xff79b158));

    SyncTime2_16->setBounds(356, 207, 24, 16);

    FilterType2.addItem("No Filter", 1);
    FilterType2.addItem("Low-Pass", 2);
    FilterType2.addItem("High-Pass", 3);
    FilterType2.setJustificationType(Justification::centred);
    addAndMakeVisible(&FilterType2);
    FilterType2Value = std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(processor.getTreeState(), "DELAY_2_FILTERTYPE", FilterType2);
    FilterType2.setBounds(204, 292, 88, 32);

    Feedback2.reset(new Slider("FeedbackSlider"));
    addAndMakeVisible(Feedback2.get());
    Feedback2->setSliderStyle(Slider::LinearBar);
    Feedback2->setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    Feedback2->setColour(Slider::trackColourId, Colours::chartreuse);
    Feedback2->setColour(Slider::textBoxTextColourId, Colours::black);
    Feedback2Value = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.getTreeState(), "DELAY_2_FEEDBACK", *Feedback2);

    Feedback2->setBounds(212, 423, 88, 32);

    FilterCutoff2.reset(new Slider("FilterCutoffKnob"));
    addAndMakeVisible(FilterCutoff2.get());
    FilterCutoff2->setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    FilterCutoff2->setTextValueSuffix("Hz");
    FilterCutoff2->setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    FilterCutoff2->setColour(Slider::thumbColourId, Colour(0xff79b120));
    FilterCutoff2->setColour(Slider::textBoxTextColourId, Colours::black);
    FilterCutoff2Value = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.getTreeState(), "DELAY_2_FILTERCUTOFF", *FilterCutoff2);

    FilterCutoff2->setBounds(308, 268, 80, 96);

    PingPongToggle2.reset(new ToggleButton("PingPongToggle"));
    addAndMakeVisible(PingPongToggle2.get());
    PingPongToggle2->setButtonText(String());
    PingPongToggle2->setToggleState(true, dontSendNotification);
    PingPongToggle2->setColour(ToggleButton::textColourId, Colours::black);
    PingPong2Value = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.getTreeState(), "DELAY_2_PINGPONG", *PingPongToggle2);

    PingPongToggle2->setBounds(340, 415, 40, 40);

    OnOff2.reset(new ToggleButton("DelayOnOffToggle"));
    addAndMakeVisible(OnOff2.get());
    OnOff2->setButtonText(String());
    OnOff2->setColour(ToggleButton::textColourId, Colours::black);
    OnOff2Value = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.getTreeState(), "DELAY_2_ONOFF", *OnOff2);

    OnOff2->setBounds(252, 505, 40, 32);

    Gain2.reset(new Slider("GainSlider"));
    addAndMakeVisible(Gain2.get());
    Gain2->setTextValueSuffix("dB");
    Gain2->setSliderStyle(Slider::LinearBarVertical);
    Gain2->setTextBoxStyle(Slider::TextBoxLeft, false, 80, 20);
    Gain2->setColour(Slider::trackColourId, Colours::chartreuse);
    Gain2->setColour(Slider::textBoxOutlineColourId, Colours::chartreuse);
    Gain2Value = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.getTreeState(), "DELAY_2_GAIN", *Gain2);

    Gain2->setBounds(332, 468, 68, 100);

    //Second delay sliders and buttons//

    //Third delay sliders and buttons//
    TimeSlider3.reset(new Slider("DelayTimeSlider"));
    addAndMakeVisible(TimeSlider3.get());
    TimeSlider3->setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    TimeSlider3->setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    TimeSlider3->setColour(Slider::thumbColourId, Colour(0xff97cb73));
    TimeSlider3->setColour(Slider::textBoxTextColourId, Colours::black);
    TimeSlider3Value = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.getTreeState(), "DELAY_3_TIME", *TimeSlider3);

    TimeSlider3->setBounds(412, 128, 88, 96);

    SyncTime3_1.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime3_1.get());
    SyncTime3_1->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime3_1->setButtonText(TRANS("1"));
    SyncTime3_1->addListener(this);
    SyncTime3_1->setColour(TextButton::buttonColourId, Colour(0xff97cb73));

    SyncTime3_1->setBounds(524, 136, 24, 16);

    SyncTime3_2.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime3_2.get());
    SyncTime3_2->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime3_2->setButtonText(TRANS("2"));
    SyncTime3_2->addListener(this);
    SyncTime3_2->setColour(TextButton::buttonColourId, Colour(0xff97cb73));

    SyncTime3_2->setBounds(556, 136, 24, 16);

    SyncTime3_3.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime3_3.get());
    SyncTime3_3->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime3_3->setButtonText(TRANS("3"));
    SyncTime3_3->addListener(this);
    SyncTime3_3->setColour(TextButton::buttonColourId, Colour(0xff97cb73));

    SyncTime3_3->setBounds(524, 160, 24, 16);

    SyncTime3_4.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime3_4.get());
    SyncTime3_4->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime3_4->setButtonText(TRANS("4"));
    SyncTime3_4->addListener(this);
    SyncTime3_4->setColour(TextButton::buttonColourId, Colour(0xff97cb73));

    SyncTime3_4->setBounds(556, 160, 24, 16);

    SyncTime3_5.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime3_5.get());
    SyncTime3_5->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime3_5->setButtonText(TRANS("5"));
    SyncTime3_5->addListener(this);
    SyncTime3_5->setColour(TextButton::buttonColourId, Colour(0xff97cb73));

    SyncTime3_5->setBounds(524, 184, 24, 16);

    SyncTime3_6.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime3_6.get());
    SyncTime3_6->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime3_6->setButtonText(TRANS("6"));
    SyncTime3_6->addListener(this);
    SyncTime3_6->setColour(TextButton::buttonColourId, Colour(0xff97cb73));

    SyncTime3_6->setBounds(556, 184, 24, 16);

    SyncTime3_8.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime3_8.get());
    SyncTime3_8->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime3_8->setButtonText(TRANS("8"));
    SyncTime3_8->addListener(this);
    SyncTime3_8->setColour(TextButton::buttonColourId, Colour(0xff97cb73));

    SyncTime3_8->setBounds(524, 208, 24, 16);

    SyncTime3_16.reset(new TextButton("SyncButton"));
    addAndMakeVisible(SyncTime3_16.get());
    SyncTime3_16->setTooltip(TRANS("Sync delay time in terms of sixteenth notes"));
    SyncTime3_16->setButtonText(TRANS("16"));
    SyncTime3_16->addListener(this);
    SyncTime3_16->setColour(TextButton::buttonColourId, Colour(0xff97cb73));

    SyncTime3_16->setBounds(556, 208, 24, 16);

    FilterType3.addItem("No Filter", 1);
    FilterType3.addItem("Low-Pass", 2);
    FilterType3.addItem("High-Pass", 3);
    FilterType3.setJustificationType(Justification::centred);
    addAndMakeVisible(&FilterType3);
    FilterType3Value = std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(processor.getTreeState(), "DELAY_3_FILTERTYPE", FilterType3);
    FilterType3.setBounds(404, 292, 88, 32);

    Feedback3.reset(new Slider("FeedbackSlider"));
    addAndMakeVisible(Feedback3.get());
    Feedback3->setSliderStyle(Slider::LinearBar);
    Feedback3->setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    Feedback3->setColour(Slider::trackColourId, Colours::chartreuse);
    Feedback3->setColour(Slider::textBoxTextColourId, Colours::black);
    Feedback3Value = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.getTreeState(), "DELAY_3_FEEDBACK", *Feedback3);

    Feedback3->setBounds(412, 420, 88, 32);

    FilterCutoff3.reset(new Slider("FilterCutoffKnob"));
    addAndMakeVisible(FilterCutoff3.get());
    FilterCutoff3->setRange(CUTOFF_MIN, CUTOFF_MAX, 1.0f);

    FilterCutoff3->setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    FilterCutoff3->setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    FilterCutoff3->setColour(Slider::thumbColourId, Colour(0xff97cb73));
    FilterCutoff3->setColour(Slider::textBoxTextColourId, Colours::black);
    FilterCutoff3->setTextValueSuffix("Hz");
    FilterCutoff3Value = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.getTreeState(), "DELAY_3_FILTERCUTOFF", *FilterCutoff3);
    FilterCutoff3->setSkewFactorFromMidPoint(500.0f);

    FilterCutoff3->setBounds(516, 269, 80, 96);

    PingPongToggle3.reset(new ToggleButton("PingPongToggle"));
    addAndMakeVisible(PingPongToggle3.get());
    PingPongToggle3->setButtonText(String());
    PingPongToggle3->setToggleState(true, dontSendNotification);
    PingPongToggle3->setColour(ToggleButton::textColourId, Colours::black);
    PingPong3Value = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.getTreeState(), "DELAY_3_PINGPONG", *PingPongToggle3);

    PingPongToggle3->setBounds(540, 415, 40, 40);

    OnOff3.reset(new ToggleButton("DelayOnOffToggle"));
    addAndMakeVisible(OnOff3.get());
    OnOff3->setButtonText(String());
    OnOff3->setColour(ToggleButton::textColourId, Colours::black);
    OnOff3Value = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.getTreeState(), "DELAY_3_ONOFF", *OnOff3);

    OnOff3->setBounds(452, 505, 40, 32);

    Gain3.reset(new Slider("GainSlider"));
    addAndMakeVisible(Gain3.get());
    Gain3->setTextValueSuffix("dB");
    Gain3->setSliderStyle(Slider::LinearBarVertical);
    Gain3->setTextBoxStyle(Slider::TextBoxLeft, false, 80, 20);
    Gain3->setColour(Slider::trackColourId, Colours::chartreuse);
    Gain3->setColour(Slider::textBoxOutlineColourId, Colours::chartreuse);
    Gain3Value = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.getTreeState(), "DELAY_3_GAIN", *Gain3);

    Gain3->setBounds(532, 468, 68, 100);

    //Third delay sliders and buttons//

    DryWet.reset(new Slider("DryWetSlider"));
    addAndMakeVisible(DryWet.get());
    DryWet->setSliderStyle(Slider::LinearBarVertical);
    DryWet->setTextBoxStyle(Slider::TextBoxLeft, false, 80, 20);
    DryWet->setColour(Slider::trackColourId, Colours::chartreuse);
    DryWetValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.getTreeState(), "DRYWET", *DryWet);

    DryWet->setBounds(536, 28, 64, 64);
      
}

MultidelayAudioProcessorEditor::~MultidelayAudioProcessorEditor()
{
}

//==============================================================================
void MultidelayAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.fillAll(Colour(0xff393e41));

    {
        int x = 0, y = 0, width = 600, height = 468;
        Colour fillColour = Colour(0xff454955);
        Colour strokeColour = Colours::chartreuse;

        g.setColour(fillColour);
        g.fillRect(x, y, width, height);
        g.setColour(strokeColour);
        g.drawRect(x, y, width, height, 1);

    }

    {
        int x = 0, y = 92, width = 600, height = 144;
        Colour fillColour1 = Colour(0xfff3eff5), fillColour2 = Colour(0xffdbd7dd);

        g.setGradientFill(ColourGradient(fillColour1,
            0.0f - 0.0f + x,
            40.0f - 92.0f + y,
            fillColour2,
            256.0f - 0.0f + x,
            184.0f - 92.0f + y,
            true));
        g.fillRect(x, y, width, height);
    }

    {
        int x = 0, y = 232, width = 600, height = 144;
        Colour fillColour1 = Colour(0xffdbd7dd), fillColour2 = Colour(0xffc3bfc5);

        g.setGradientFill(ColourGradient(fillColour1,
            8.0f - 0.0f + x,
            184.0f - 232.0f + y,
            fillColour2,
            256.0f - 0.0f + x,
            328.0f - 232.0f + y,
            true));
        g.fillRect(x, y, width, height);
    }

    {
        int x = 0, y = 468, width = 600, height = 100;
        Colour fillColour1 = Colour(0xff938F95), fillColour2 = Colour(0xff938f95);
        g.setGradientFill(ColourGradient(fillColour1,
            8.0f - 0.0f + x,
            184.0f - 232.0f + y,
            fillColour2,
            256.0f - 0.0f + x,
            328.0f - 232.0f + y,
            true));
        g.fillRect(x, y, width, height);
    }

    {
        int x = 0, y = 468, width = 600, height = 100;
        Colour strokeColour = Colours::chartreuse;

        g.setColour(strokeColour);
        g.drawRect(x, y, width, height, 1);

    }

    {
        int x = 0, y = 376, width = 600, height = 92;
        Colour fillColour1 = Colour(0xffc3bfc5), fillColour2 = Colour(0xffaba7ad);

        g.setGradientFill(ColourGradient(fillColour1,
            0.0f - 0.0f + x,
            320.0f - 376.0f + y,
            fillColour2,
            256.0f - 0.0f + x,
            464.0f - 376.0f + y,
            true));
        g.fillRect(x, y, width, height);
    }

    {
        int x = 400, y = 92, width = 200, height = 476;
        Colour strokeColour = Colours::chartreuse;

        g.setColour(strokeColour);
        g.drawRect(x, y, width, height, 1);

    }

    {
        int x = 532, y = 0, width = 68, height = 30;
        String text(TRANS("Dry/Wet"));
        Colour fillColour = Colours::white;

        g.setColour(fillColour);
        g.setFont(Font(15.00f, Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            Justification::centred, true);
    }


    {
        int x = 4, y = 4, width = 392, height = 88;
        String text(TRANS("Multi-Filter-Delay"));
        Colour fillColour1 = Colours::azure, fillColour2 = Colours::chartreuse;

        g.setGradientFill(ColourGradient(fillColour1,
            152.0f - 4.0f + x,
            40.0f - 4.0f + y,
            fillColour2,
            400.0f - 4.0f + x,
            96.0f - 4.0f + y,
            false));
        g.setFont(Font(25.00f, Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            Justification::centred, true);
    }

    {
        int x = 504, y = 384, width = 96, height = 30;
        String text(TRANS("Ping Pong"));
        Colour fillColour = Colours::black;

        g.setColour(fillColour);
        g.setFont(Font(15.00f, Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            Justification::centred, true);
    }

    {
        int x = 500, y = 96, width = 96, height = 30;
        String text(TRANS("Sync"));
        Colour fillColour = Colours::black;

        g.setColour(fillColour);
        g.setFont(Font(15.00f, Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            Justification::centred, true);
    }

    {
        int x = 500, y = 240, width = 96, height = 30;
        String text(TRANS("Cutoff"));
        Colour fillColour = Colours::black;

        g.setColour(fillColour);
        g.setFont(Font(15.00f, Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            Justification::centred, true);
    }

    {
        int x = 404, y = 240, width = 96, height = 30;
        String text(TRANS("Filter"));
        Colour fillColour = Colours::black;

        g.setColour(fillColour);
        g.setFont(Font(15.00f, Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            Justification::centred, true);
    }

    {
        int x = 400, y = 384, width = 108, height = 28;
        String text(TRANS("Feedback"));
        Colour fillColour = Colours::black;

        g.setColour(fillColour);
        g.setFont(Font(15.00f, Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            Justification::centred, true);
    }

    {
        int x = 404, y = 96, width = 96, height = 30;
        String text(TRANS("Time (ms)"));
        Colour fillColour = Colours::black;

        g.setColour(fillColour);
        g.setFont(Font(15.00f, Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            Justification::centred, true);
    }

    {
        int x = 304, y = 384, width = 96, height = 30;
        String text(TRANS("Ping Pong"));
        Colour fillColour = Colours::black;

        g.setColour(fillColour);
        g.setFont(Font(15.00f, Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            Justification::centred, true);
    }

    {
        int x = 300, y = 96, width = 96, height = 30;
        String text(TRANS("Sync"));
        Colour fillColour = Colours::black;

        g.setColour(fillColour);
        g.setFont(Font(15.00f, Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            Justification::centred, true);
    }

    {
        int x = 300, y = 240, width = 96, height = 30;
        String text(TRANS("Cutoff"));
        Colour fillColour = Colours::black;

        g.setColour(fillColour);
        g.setFont(Font(15.00f, Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            Justification::centred, true);
    }

    {
        int x = 204, y = 240, width = 96, height = 30;
        String text(TRANS("Filter"));
        Colour fillColour = Colours::black;

        g.setColour(fillColour);
        g.setFont(Font(15.00f, Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            Justification::centred, true);
    }

    {
        int x = 200, y = 384, width = 108, height = 28;
        String text(TRANS("Feedback"));
        Colour fillColour = Colours::black;

        g.setColour(fillColour);
        g.setFont(Font(15.00f, Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            Justification::centred, true);
    }

    {
        int x = 204, y = 96, width = 96, height = 30;
        String text(TRANS("Time (ms)"));
        Colour fillColour = Colours::black;

        g.setColour(fillColour);
        g.setFont(Font(15.00f, Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            Justification::centred, true);
    }

    {
        int x = 10, y = 460, width = 120, height = 60;
        String text(TRANS("Delay 1"));
        Colour fillColour = Colours::chartreuse;
        g.setColour(fillColour);
        g.setFont(Font(20.00f, Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            Justification::centred, true);
    }

    {
        int x = 210, y = 460, width = 120, height = 60;
        String text(TRANS("Delay 2"));
        Colour fillColour = Colours::chartreuse;
        g.setColour(fillColour);
        g.setFont(Font(20.00f, Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            Justification::centred, true);
    }

    {
        int x = 410, y = 460, width = 120, height = 60;
        String text(TRANS("Delay 3"));
        Colour fillColour = Colours::chartreuse;
        g.setColour(fillColour);
        g.setFont(Font(20.00f, Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            Justification::centred, true);
    }

    {
        int x = 104, y = 384, width = 96, height = 30;
        String text(TRANS("Ping Pong"));
        Colour fillColour = Colours::black;
        g.setColour(fillColour);
        g.setFont(Font(15.00f, Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            Justification::centred, true);
    }

    {
        int x = 100, y = 96, width = 96, height = 30;
        String text(TRANS("Sync"));
        Colour fillColour = Colours::black;
        g.setColour(fillColour);
        g.setFont(Font(15.00f, Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            Justification::centred, true);
    }

    {
        int x = 100, y = 240, width = 96, height = 30;
        String text(TRANS("Cutoff"));
        Colour fillColour = Colours::black;
        g.setColour(fillColour);
        g.setFont(Font(15.00f, Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            Justification::centred, true);
    }

    {
        int x = 4, y = 240, width = 96, height = 30;
        String text(TRANS("Filter"));
        Colour fillColour = Colours::black;
        g.setColour(fillColour);
        g.setFont(Font(15.00f, Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            Justification::centred, true);
    }

    {
        int x = 0, y = 384, width = 108, height = 28;
        String text(TRANS("Feedback"));
        Colour fillColour = Colours::black;
        g.setColour(fillColour);
        g.setFont(Font(15.00f, Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            Justification::centred, true);
    }

    {
        int x = 4, y = 96, width = 96, height = 30;
        String text(TRANS("Time (ms)"));
        Colour fillColour = Colours::black;
        g.setColour(fillColour);
        g.setFont(Font(15.00f, Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            Justification::centred, true);
    }

    {
        int x = 200, y = 92, width = 200, height = 476;
        Colour strokeColour = Colours::chartreuse;
        g.setColour(strokeColour);
        g.drawRect(x, y, width, height, 1);

    }

    {
        int x = 0, y = 92, width = 200, height = 476;
        Colour strokeColour = Colours::chartreuse;
        g.setColour(strokeColour);
        g.drawRect(x, y, width, height, 1);

    }
    
}

void MultidelayAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    //gui.setBounds(getLocalBounds());
}


void MultidelayAudioProcessorEditor::buttonClicked(Button* button) {
    
    //Button events for the sync time buttons
    if (button == SyncTime1_1.get()) {
        float oneSixteenthTime = (60000.0 / 4.0) / processor.bpmHost;
        processor.setDelayTime(0, oneSixteenthTime);
        TimeSlider1->setValue(oneSixteenthTime);
    }
    else if (button == SyncTime1_2.get()) {
        float twoSixteenthTime = (60000.0 / 2.0) / processor.bpmHost;
        processor.setDelayTime(0, twoSixteenthTime);
        TimeSlider1->setValue(twoSixteenthTime);
    }
    else if (button == SyncTime1_3.get()) {
        float threeSixteenthTime = (60000.0 / (4.0 / 3.0)) / processor.bpmHost;
        processor.setDelayTime(0, threeSixteenthTime);
        TimeSlider1->setValue(threeSixteenthTime);
    }
    else if (button == SyncTime1_4.get()) {
        float fourSixteenthTime = 60000.0/ processor.bpmHost;
        processor.setDelayTime(0, fourSixteenthTime);
        TimeSlider1->setValue(fourSixteenthTime);
    }
    else if (button == SyncTime1_5.get()) {
        float fiveSixteenthTime = (60000.0 / (4.0 / 5.0)) / processor.bpmHost;
        processor.setDelayTime(0, fiveSixteenthTime);
        TimeSlider1->setValue(fiveSixteenthTime);
    }

    else if (button == SyncTime1_6.get()) {
        float sixSixteenthTime = (60000.0 / (4.0 / 6.0)) / processor.bpmHost;
        processor.setDelayTime(0, sixSixteenthTime);
        TimeSlider1->setValue(sixSixteenthTime);
    }

    else if (button == SyncTime1_8.get()) {
        float eightSixteenthTime = (60000.0 / 0.5) / processor.bpmHost;
        processor.setDelayTime(0, eightSixteenthTime);
        TimeSlider1->setValue(eightSixteenthTime);
    }

    else if (button == SyncTime1_16.get()) {
        float sixteenSixteenthTime = (60000.0 / 0.25) / processor.bpmHost;
        processor.setDelayTime(0, sixteenSixteenthTime);
        TimeSlider1->setValue(sixteenSixteenthTime);
    }

    else if (button == SyncTime2_1.get()) {
        float oneSixteenthTime = (60000.0 / 4.0) / processor.bpmHost;
        processor.setDelayTime(1, oneSixteenthTime);
        TimeSlider2->setValue(oneSixteenthTime);
    }
    else if (button == SyncTime2_2.get()) {
        float twoSixteenthTime = (60000.0 / 2.0) / processor.bpmHost;
        processor.setDelayTime(1, twoSixteenthTime);
        TimeSlider2->setValue(twoSixteenthTime);
    }
    else if (button == SyncTime2_3.get()) {
        float threeSixteenthTime = (60000.0 / (4.0 / 3.0)) / processor.bpmHost;
        processor.setDelayTime(1, threeSixteenthTime);
        TimeSlider2->setValue(threeSixteenthTime);
    }
    else if (button == SyncTime2_4.get()) {
        float fourSixteenthTime = 60000.0 / processor.bpmHost;
        processor.setDelayTime(1, fourSixteenthTime);
        TimeSlider2->setValue(fourSixteenthTime);
    }
    else if (button == SyncTime2_5.get()) {
        float fiveSixteenthTime = (60000.0 / (4.0 / 5.0)) / processor.bpmHost;
        processor.setDelayTime(1, fiveSixteenthTime);
        TimeSlider2->setValue(fiveSixteenthTime);
    }

    else if (button == SyncTime2_6.get()) {
        float sixSixteenthTime = (60000.0 / (4.0 / 6.0)) / processor.bpmHost;
        processor.setDelayTime(1, sixSixteenthTime);
        TimeSlider2->setValue(sixSixteenthTime);
    }

    else if (button == SyncTime2_8.get()) {
        float eightSixteenthTime = (60000.0 / 0.5) / processor.bpmHost;
        processor.setDelayTime(1, eightSixteenthTime);
        TimeSlider2->setValue(eightSixteenthTime);
    }

    else if (button == SyncTime2_16.get()) {
        float sixteenSixteenthTime = (60000.0 / 0.25) / processor.bpmHost;
        processor.setDelayTime(1, sixteenSixteenthTime);
        TimeSlider2->setValue(sixteenSixteenthTime);
    }

    else if (button == SyncTime3_1.get()) {
        float oneSixteenthTime = (60000.0 / 4.0) / processor.bpmHost;
        processor.setDelayTime(2, oneSixteenthTime);
        TimeSlider3->setValue(oneSixteenthTime);
    }
    else if (button == SyncTime3_2.get()) {
        float twoSixteenthTime = (60000.0 / 2.0) / processor.bpmHost;
        processor.setDelayTime(2, twoSixteenthTime);
        TimeSlider3->setValue(twoSixteenthTime);
    }
    else if (button == SyncTime3_3.get()) {
        float threeSixteenthTime = (60000.0 / (4.0 / 3.0)) / processor.bpmHost;
        processor.setDelayTime(2, threeSixteenthTime);
        TimeSlider3->setValue(threeSixteenthTime);
    }
    else if (button == SyncTime3_4.get()) {
        float fourSixteenthTime = 60000.0 / processor.bpmHost;
        processor.setDelayTime(2, fourSixteenthTime);
        TimeSlider3->setValue(fourSixteenthTime);
    }
    else if (button == SyncTime3_5.get()) {
        float fiveSixteenthTime = (60000.0 / (4.0 / 5.0)) / processor.bpmHost;
        processor.setDelayTime(2, fiveSixteenthTime);
        TimeSlider3->setValue(fiveSixteenthTime);
    }

    else if (button == SyncTime3_6.get()) {
        float sixSixteenthTime = (60000.0 / (4.0 / 6.0)) / processor.bpmHost;
        processor.setDelayTime(2, sixSixteenthTime);
        TimeSlider3->setValue(sixSixteenthTime);
    }

    else if (button == SyncTime3_8.get()) {
        float eightSixteenthTime = (60000.0 / 0.5) / processor.bpmHost;
        processor.setDelayTime(2, eightSixteenthTime);
        TimeSlider3->setValue(eightSixteenthTime);
    }

    else if (button == SyncTime3_16.get()) {
        float sixteenSixteenthTime = (60000.0 / 0.25) / processor.bpmHost;
        processor.setDelayTime(2, sixteenSixteenthTime);
        TimeSlider3->setValue(sixteenSixteenthTime);
    }
}

void MultidelayAudioProcessorEditor::setTimeValue(int delayNum, float value) {

}