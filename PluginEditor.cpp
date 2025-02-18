

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SubbassAudioProcessorEditor::SubbassAudioProcessorEditor (SubbassAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
   
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    
    
    
    
    
    setSize(350, 437);
    
   // setResizable(true, true);
   // setResizeLimits(175, 218.5, 700, 600);
   // getConstrainer()->setFixedAspectRatio(1.0);

    addAndMakeVisible(gain);
    
    gain.setRange(-60.0f,30.0f,0.1f);
    gain.setSkewFactorFromMidPoint(0);
    gain.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    gain.setTextBoxStyle(juce::Slider::TextBoxBelow, false,75,25);
    gain.setTextValueSuffix("dB");
    gain.setColour(juce::Slider::ColourIds::textBoxTextColourId, juce::Colours::white);
    gain.centreWithSize(135, 250);
    gain.setDoubleClickReturnValue(true, 0.0);
    gain.setValue(20);
    gain.onValueChange = [this]() {
      float gainVal = juce::Decibels::decibelsToGain((float)gain.getValue());
      *dynamic_cast<juce::AudioParameterFloat*>(audioProcessor.getParameters()[0]) = gainVal;
       audioProcessor.GainM = gain.getValue();
     };
    gain.onValueChange();
    
    addAndMakeVisible(i);
    
    i.setRange(20.0f, 60.0f, 0.5f);
    i.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    i.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    i.setTextValueSuffix("Hz");
    i.setColour(juce::Slider::ColourIds::textBoxTextColourId, juce::Colours::white);
    i.setDoubleClickReturnValue(true, 0.0);
    i.onValueChange = [this]
        {
            audioProcessor.PreFc = i.getValue();
        };
    
    
    
    

}

SubbassAudioProcessorEditor::~SubbassAudioProcessorEditor()
{
  setLookAndFeel(nullptr);
}

//==============================================================================
void SubbassAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    
    
     g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

     g.setColour (juce::Colours::white);
   
   
    
 
    
    
    // Dial7.png;
  // auto myImage3 = juce::ImageCache::getFromMemory (BinaryData::Dial7_png, BinaryData::Dial7_pngSize);
   // g.drawImage (myImage3, getLocalBounds().toFloat());
  // g.drawImageAt(myImage3, 85, 100);
    
   
    
    g.setFont(juce::FontOptions("Bodoni 72 SmallCaps", 20.5f, juce::Font::plain));
    g.drawFittedText("I", getX() +0, getY() +25, getWidth(), getHeight(), juce::Justification::centredTop,1);
    
    g.setFont(juce::FontOptions("Bodoni 72 SmallCaps", 20.5f, juce::Font::plain));
    g.drawFittedText("Gain", getX() +100, getY() +25, getWidth(), getHeight(), juce::Justification::centredTop,1);

   
    
}

void SubbassAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    gain.setBounds(100,100, 150,150);
    i.setBounds(100,100, 150,150);
    

    

}

