

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
//#include "CustomLookAndFeel.h"

//==============================================================================
/**
*/
class SubbassAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SubbassAudioProcessorEditor (SubbassAudioProcessor&);
    ~SubbassAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SubbassAudioProcessor& audioProcessor;
    
    juce::Image background;
    juce::Image screw;
    juce::Slider gain;
    juce::Slider i;
    juce::Image dial7;

    
    // Custom look and feel
   // CustomLookAndFeel customLookAndFeel;
    
    //Creats SliderAttachment
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gainAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> intenseAttachment;
 
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SubbassAudioProcessorEditor)
};
