#pragma once

#include "PluginProcessor.h"

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

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JuceqAudioProcessorEditor)
};
