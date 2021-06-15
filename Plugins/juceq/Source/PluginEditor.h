#pragma once

#include "PluginProcessor.h"

struct CustomRotarySlider : juce::Slider {
    CustomRotarySlider() : juce::Slider(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag,
                                        juce::Slider::TextEntryBoxPosition::NoTextBox) {

    }
};

class JuceqAudioProcessorEditor : public juce::AudioProcessorEditor {
public:
    JuceqAudioProcessorEditor(JuceqAudioProcessor &);

    ~JuceqAudioProcessorEditor() override;

    void paint(juce::Graphics &) override;

    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    JuceqAudioProcessor &audioProcessor;
    CustomRotarySlider
            peakFreqSlider,
            peakGainSlider,
            peakQualitySlider,
            lowCutFreqSlider,
            highCutFreqSlider,
            lowCutSlopeSlider,
            highCutSlopeSlider;

    using APVTS = juce::AudioProcessorValueTreeState;
    using Attachment = APVTS::SliderAttachment;

    Attachment
            peakFreqSliderAttachment,
            peakGainSliderAttachment,
            peakQualitySliderAttachment,
            lowCutFreqSliderAttachment,
            highCutFreqSliderAttachment,
            lowCutSlopeSliderAttachment,
            highCutSlopeSliderAttachment;

    std::vector<juce::Component *> getComps();

    MonoChain monoChain;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JuceqAudioProcessorEditor)
};
