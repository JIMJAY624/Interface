

#include "CustomLookAndFeel.h"

void CustomLookAndFeel::drawRotarySlider(juce::Graphics& g, int, int, int width, int height, float sliderPosProportional, float, float,
                                         juce::Slider& slider) {
  auto transform = juce::RectanglePlacement(juce::RectanglePlacement::Flags::xRight | juce::RectanglePlacement::Flags::xLeft).getTransformToFit(juce::Rectangle<float>(0, 0, imgKnob.getWidth(), imgKnob.getHeight()), juce::Rectangle<float>(0, 0, width, height));
  auto angle = KNOB_ANGLE_SPAN * sliderPosProportional;
  transform = transform.rotated(angle, width / 2.0f, height / 2.0f
                                );
  g.drawImageTransformed(imgKnob, transform);
}

