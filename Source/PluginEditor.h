#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"


class WTSynthMidiPluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    WTSynthMidiPluginAudioProcessorEditor (WTSynthMidiPluginAudioProcessor&);
    ~WTSynthMidiPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    WTSynthMidiPluginAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WTSynthMidiPluginAudioProcessorEditor)
};
