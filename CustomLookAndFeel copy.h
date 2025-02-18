

#pragma once

#include "BinaryData.h"
#include <juce_gui_basics/juce_gui_basics.h>


class CustomLookAndFeel : public juce::LookAndFeel_V4 {
public:
    CustomLookAndFeel() {
        imgKnob = juce::PNGImageFormat::loadFrom(BinaryData::knob_png, BinaryData::knob_pngSize);
    }
    
    // Sliders
    void drawRotarySlider(juce::Graphics& g, int, int, int width, int height, float sliderPosProportional, float, float,
                          juce::Slider& slider) override;
    
    
    
private:
    static constexpr float KNOB_ANGLE_SPAN = juce::MathConstants<float>::pi * 1.43f;
    juce::Image imgKnob;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CustomLookAndFeel)
};
